/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/lib/cpp2/async/AsyncClient.h>

namespace apache {
namespace thrift {
namespace {
static InteractionId createInteraction(
    RequestChannel& channel,
    folly::StringPiece methodName) {
  DCHECK(
      !channel.getEventBase() || channel.getEventBase()->isInEventBaseThread());
  return channel.createInteraction(methodName);
}
} // namespace

GeneratedAsyncClient::GeneratedAsyncClient(
    std::shared_ptr<RequestChannel> channel)
    : channel_(std::move(channel)) {}

InteractionHandle::InteractionHandle(
    std::shared_ptr<RequestChannel> channel,
    folly::StringPiece methodName)
    : GeneratedAsyncClient(channel),
      interactionId_(createInteraction(*channel, methodName)) {
  DCHECK(interactionId_);
}

InteractionHandle::~InteractionHandle() {
  terminate();
}
InteractionHandle& InteractionHandle::operator=(InteractionHandle&& other) {
  if (this != &other) {
    terminate();
  }
  channel_ = std::move(other.channel_);
  interactionId_ = std::move(other.interactionId_);
  return *this;
}

void InteractionHandle::setInteraction(RpcOptions& rpcOptions) {
  DCHECK(interactionId_);
  rpcOptions.setInteractionId(interactionId_);
}

void InteractionHandle::terminate() {
  if (!channel_ || !interactionId_) {
    return;
  }
  auto* eb = channel_->getEventBase();
  if (eb) {
    folly::getKeepAliveToken(eb).add(
        [channel = channel_, id = std::move(interactionId_)](auto&&) mutable {
          channel->terminateInteraction(std::move(id));
        });
  } else {
    channel_->terminateInteraction(std::move(interactionId_));
  }
}

} // namespace thrift
} // namespace apache