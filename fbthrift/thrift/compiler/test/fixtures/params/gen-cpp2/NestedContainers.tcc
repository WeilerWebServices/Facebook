/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/compiler/test/fixtures/params/gen-cpp2/NestedContainers.h"

#include <thrift/lib/cpp2/gen/service_tcc.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_MAP, ::std::map<int32_t, ::std::vector<int32_t>>*>> NestedContainers_mapList_pargs;
typedef apache::thrift::ThriftPresult<true> NestedContainers_mapList_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_MAP, ::std::map<int32_t, ::std::set<int32_t>>*>> NestedContainers_mapSet_pargs;
typedef apache::thrift::ThriftPresult<true> NestedContainers_mapSet_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_LIST, ::std::vector<::std::map<int32_t, int32_t>>*>> NestedContainers_listMap_pargs;
typedef apache::thrift::ThriftPresult<true> NestedContainers_listMap_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_LIST, ::std::vector<::std::set<int32_t>>*>> NestedContainers_listSet_pargs;
typedef apache::thrift::ThriftPresult<true> NestedContainers_listSet_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_LIST, ::std::vector<::std::vector<::std::map<int32_t, ::std::map<int32_t, ::std::set<int32_t>>>>>*>> NestedContainers_turtles_pargs;
typedef apache::thrift::ThriftPresult<true> NestedContainers_turtles_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::_processInThread_mapList(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(serializedRequest), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &NestedContainersAsyncProcessor::process_mapList<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::process_mapList(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  NestedContainers_mapList_pargs args;
  auto uarg_foo = std::make_unique<::std::map<int32_t, ::std::vector<int32_t>>>();
  args.get<0>().value = uarg_foo.get();
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "NestedContainers.mapList", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), serializedRequest, ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "mapList");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(ctxStack), return_mapList<ProtocolIn_,ProtocolOut_>, throw_wrapped_mapList<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    return;
  }
  iface_->async_tm_mapList(std::move(callback), std::move(uarg_foo));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue NestedContainersAsyncProcessor::return_mapList(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  NestedContainers_mapList_presult result;
  return serializeResponse("mapList", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void NestedContainersAsyncProcessor::throw_wrapped_mapList(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "mapList");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::_processInThread_mapSet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(serializedRequest), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &NestedContainersAsyncProcessor::process_mapSet<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::process_mapSet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  NestedContainers_mapSet_pargs args;
  auto uarg_foo = std::make_unique<::std::map<int32_t, ::std::set<int32_t>>>();
  args.get<0>().value = uarg_foo.get();
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "NestedContainers.mapSet", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), serializedRequest, ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "mapSet");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(ctxStack), return_mapSet<ProtocolIn_,ProtocolOut_>, throw_wrapped_mapSet<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    return;
  }
  iface_->async_tm_mapSet(std::move(callback), std::move(uarg_foo));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue NestedContainersAsyncProcessor::return_mapSet(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  NestedContainers_mapSet_presult result;
  return serializeResponse("mapSet", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void NestedContainersAsyncProcessor::throw_wrapped_mapSet(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "mapSet");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::_processInThread_listMap(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(serializedRequest), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &NestedContainersAsyncProcessor::process_listMap<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::process_listMap(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  NestedContainers_listMap_pargs args;
  auto uarg_foo = std::make_unique<::std::vector<::std::map<int32_t, int32_t>>>();
  args.get<0>().value = uarg_foo.get();
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "NestedContainers.listMap", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), serializedRequest, ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "listMap");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(ctxStack), return_listMap<ProtocolIn_,ProtocolOut_>, throw_wrapped_listMap<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    return;
  }
  iface_->async_tm_listMap(std::move(callback), std::move(uarg_foo));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue NestedContainersAsyncProcessor::return_listMap(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  NestedContainers_listMap_presult result;
  return serializeResponse("listMap", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void NestedContainersAsyncProcessor::throw_wrapped_listMap(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "listMap");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::_processInThread_listSet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(serializedRequest), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &NestedContainersAsyncProcessor::process_listSet<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::process_listSet(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  NestedContainers_listSet_pargs args;
  auto uarg_foo = std::make_unique<::std::vector<::std::set<int32_t>>>();
  args.get<0>().value = uarg_foo.get();
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "NestedContainers.listSet", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), serializedRequest, ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "listSet");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(ctxStack), return_listSet<ProtocolIn_,ProtocolOut_>, throw_wrapped_listSet<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    return;
  }
  iface_->async_tm_listSet(std::move(callback), std::move(uarg_foo));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue NestedContainersAsyncProcessor::return_listSet(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  NestedContainers_listSet_presult result;
  return serializeResponse("listSet", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void NestedContainersAsyncProcessor::throw_wrapped_listSet(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "listSet");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::_processInThread_turtles(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(serializedRequest), ctx, eb, tm, pri, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &NestedContainersAsyncProcessor::process_turtles<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void NestedContainersAsyncProcessor::process_turtles(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  NestedContainers_turtles_pargs args;
  auto uarg_foo = std::make_unique<::std::vector<::std::vector<::std::map<int32_t, ::std::map<int32_t, ::std::set<int32_t>>>>>>();
  args.get<0>().value = uarg_foo.get();
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "NestedContainers.turtles", ctx));
  try {
    deserializeRequest<ProtocolIn_>(args, ctx->getMethodName(), serializedRequest, ctxStack.get());
  }
  catch (const std::exception& ex) {
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ex, std::move(req), ctx, eb, "turtles");
    return;
  }
  req->setStartedProcessing();
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(ctxStack), return_turtles<ProtocolIn_,ProtocolOut_>, throw_wrapped_turtles<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    return;
  }
  iface_->async_tm_turtles(std::move(callback), std::move(uarg_foo));
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue NestedContainersAsyncProcessor::return_turtles(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  NestedContainers_turtles_presult result;
  return serializeResponse("turtles", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void NestedContainersAsyncProcessor::throw_wrapped_turtles(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "turtles");
    return;
  }
}


} // cpp2