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

#pragma once

#include <forward_list>

#include <folly/ExceptionWrapper.h>
#include <folly/io/async/EventBase.h>
#include <thrift/lib/cpp/concurrency/ThreadManager.h>

namespace apache {
namespace thrift {

class InteractionId {
 public:
  InteractionId(InteractionId&& other) noexcept {
    id_ = other.id_;
    other.release();
  }
  InteractionId& operator=(InteractionId&& other) {
    if (this != &other) {
      CHECK_EQ(id_, 0) << "Interactions must always be terminated";
      id_ = other.id_;
      other.release();
    }
    return *this;
  }
  InteractionId(const InteractionId&) = delete;
  InteractionId& operator=(const InteractionId&) = delete;
  ~InteractionId() {
    CHECK_EQ(id_, 0) << "Interactions must always be terminated";
  }

  operator int64_t() const {
    return id_;
  }

  void bind(int64_t id) {
    CHECK_EQ(id_, 0) << "Can only bind dummy id objects";
    id_ = id;
  }

 private:
  InteractionId(int64_t id) : id_(id) {}

  void release() {
    id_ = 0;
  }

  int64_t id_;

  friend class RequestChannel;
};

class Tile {
 public:
  virtual ~Tile() = default;

  virtual bool __fbthrift_isError() const {
    return false;
  }
  virtual bool __fbthrift_isPromise() const {
    return false;
  }

  void __fbthrift_acquireRef(folly::EventBase& eb) {
    eb.dcheckIsInEventBaseThread();
    ++refCount_;
  }
  void __fbthrift_releaseRef(
      concurrency::ThreadManager& tm,
      folly::EventBase& eb) {
    eb.dcheckIsInEventBaseThread();
    DCHECK_GT(refCount_, 0u);

    if (--refCount_ == 0 && terminationRequested_) {
      tm.add([this] { delete this; });
    }
  }

 private:
  bool terminationRequested_{false};
  size_t refCount_{0};
  friend class GeneratedAsyncProcessor;
  friend class TilePromise;
};

class TilePromise final : public Tile {
 public:
  void addContinuation(std::shared_ptr<concurrency::Runnable> task) {
    continuations_.push_front(std::move(task));
  }

  template <typename InteractionEventTask>
  void
  fulfill(Tile& tile, concurrency::ThreadManager& tm, folly::EventBase& eb) {
    DCHECK(!continuations_.empty());
    continuations_.reverse();
    for (auto& task : continuations_) {
      tile.__fbthrift_acquireRef(eb);
      dynamic_cast<InteractionEventTask&>(*task).setTile(tile);
      --refCount_;
      tm.add(
          std::move(task),
          0, // timeout
          0, // expiration
          true); // upstream
    }
    continuations_.clear();
    DCHECK_EQ(refCount_, 0u);
  }

  bool __fbthrift_isPromise() const override {
    return true;
  }

 private:
  std::forward_list<std::shared_ptr<concurrency::Runnable>> continuations_;
  bool destructionRequested_{false}; // set when connection is closed to prevent
                                     // continuations from running
  friend class GeneratedAsyncProcessor;
};

class ErrorTile final : public Tile {
 public:
  explicit ErrorTile(folly::exception_wrapper ex) : ex_(std::move(ex)) {}

  folly::exception_wrapper get() const {
    return ex_;
  }

  bool __fbthrift_isError() const override {
    return true;
  }

 private:
  folly::exception_wrapper ex_;
};

} // namespace thrift
} // namespace apache
