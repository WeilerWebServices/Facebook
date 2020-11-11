/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/sink/gen-cpp2/SinkServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/sink/gen-cpp2/module_types.h"
#include <thrift/lib/cpp2/async/Sink.h>

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace cpp2 {

class SinkServiceSvAsyncIf {
 public:
  virtual ~SinkServiceSvAsyncIf() {}
  virtual void async_tm_method(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) = 0;
  virtual folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_method() = 0;
  virtual folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_method() = 0;
  virtual void async_tm_methodAndReponse(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ResponseAndSinkConsumer< ::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) = 0;
  virtual folly::Future<apache::thrift::ResponseAndSinkConsumer< ::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodAndReponse() = 0;
  virtual folly::SemiFuture<apache::thrift::ResponseAndSinkConsumer< ::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodAndReponse() = 0;
  virtual void async_tm_methodThrow(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) = 0;
  virtual folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodThrow() = 0;
  virtual folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodThrow() = 0;
  virtual void async_tm_methodSinkThrow(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) = 0;
  virtual folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodSinkThrow() = 0;
  virtual folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodSinkThrow() = 0;
  virtual void async_tm_methodFinalThrow(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) = 0;
  virtual folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodFinalThrow() = 0;
  virtual folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodFinalThrow() = 0;
  virtual void async_tm_methodBothThrow(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) = 0;
  virtual folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodBothThrow() = 0;
  virtual folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodBothThrow() = 0;
};

class SinkServiceAsyncProcessor;

class SinkServiceSvIf : public SinkServiceSvAsyncIf, public apache::thrift::ServerInterface {
 public:
  typedef SinkServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;


  virtual apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> method();
  folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_method() override;
  folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_method() override;
  void async_tm_method(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) override;
  virtual apache::thrift::ResponseAndSinkConsumer< ::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodAndReponse();
  folly::Future<apache::thrift::ResponseAndSinkConsumer< ::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodAndReponse() override;
  folly::SemiFuture<apache::thrift::ResponseAndSinkConsumer< ::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodAndReponse() override;
  void async_tm_methodAndReponse(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ResponseAndSinkConsumer< ::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) override;
  virtual apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodThrow();
  folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodThrow() override;
  folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodThrow() override;
  void async_tm_methodThrow(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) override;
  virtual apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodSinkThrow();
  folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodSinkThrow() override;
  folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodSinkThrow() override;
  void async_tm_methodSinkThrow(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) override;
  virtual apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodFinalThrow();
  folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodFinalThrow() override;
  folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodFinalThrow() override;
  void async_tm_methodFinalThrow(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) override;
  virtual apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodBothThrow();
  folly::Future<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> future_methodBothThrow() override;
  folly::SemiFuture<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>> semifuture_methodBothThrow() override;
  void async_tm_methodBothThrow(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>>> callback) override;
};

class SinkServiceSvNull : public SinkServiceSvIf {
 public:
  apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> method() override;
  apache::thrift::ResponseAndSinkConsumer< ::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodAndReponse() override;
  apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodThrow() override;
  apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodSinkThrow() override;
  apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodFinalThrow() override;
  apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse> methodBothThrow() override;
};

class SinkServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  SinkServiceSvIf* iface_;
 public:
  void processSerializedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
 protected:
  std::shared_ptr<folly::RequestContext> getBaseContextForRequest() override;
 public:
  using ProcessFunc = GeneratedAsyncProcessor::ProcessFunc<SinkServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFunc>;
  static const SinkServiceAsyncProcessor::ProcessMap& getBinaryProtocolProcessMap();
  static const SinkServiceAsyncProcessor::ProcessMap& getCompactProtocolProcessMap();
 private:
  static const SinkServiceAsyncProcessor::ProcessMap binaryProcessMap_;
  static const SinkServiceAsyncProcessor::ProcessMap compactProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_method(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_method(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static std::pair<folly::IOBufQueue, apache::thrift::detail::SinkConsumerImpl> return_method(apache::thrift::ContextStack* ctx, apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_method(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_methodAndReponse(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodAndReponse(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static std::pair<folly::IOBufQueue, apache::thrift::detail::SinkConsumerImpl> return_methodAndReponse(apache::thrift::ContextStack* ctx, apache::thrift::ResponseAndSinkConsumer< ::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodAndReponse(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_methodThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static std::pair<folly::IOBufQueue, apache::thrift::detail::SinkConsumerImpl> return_methodThrow(apache::thrift::ContextStack* ctx, apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_methodSinkThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodSinkThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static std::pair<folly::IOBufQueue, apache::thrift::detail::SinkConsumerImpl> return_methodSinkThrow(apache::thrift::ContextStack* ctx, apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodSinkThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_methodFinalThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodFinalThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static std::pair<folly::IOBufQueue, apache::thrift::detail::SinkConsumerImpl> return_methodFinalThrow(apache::thrift::ContextStack* ctx, apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodFinalThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_methodBothThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_methodBothThrow(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static std::pair<folly::IOBufQueue, apache::thrift::detail::SinkConsumerImpl> return_methodBothThrow(apache::thrift::ContextStack* ctx, apache::thrift::SinkConsumer< ::cpp2::SinkPayload, ::cpp2::FinalResponse>&& _return, folly::Executor::KeepAlive<> executor);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_methodBothThrow(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  SinkServiceAsyncProcessor(SinkServiceSvIf* iface) :
      iface_(iface) {}

  virtual ~SinkServiceAsyncProcessor() {}
};

} // cpp2