/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/stream/gen-cpp2/PubSubStreamingServiceAsyncClient.h"
#include "thrift/compiler/test/fixtures/stream/gen-cpp2/module_types.h"
#include <thrift/lib/cpp2/async/ServerStream.h>

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

class PubSubStreamingServiceSvAsyncIf {
 public:
  virtual ~PubSubStreamingServiceSvAsyncIf() {}
  virtual void async_tm_returnstream(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ServerStream<int32_t>>> callback, int32_t i32_from, int32_t i32_to) = 0;
  virtual folly::Future<apache::thrift::ServerStream<int32_t>> future_returnstream(int32_t i32_from, int32_t i32_to) = 0;
  virtual folly::SemiFuture<apache::thrift::ServerStream<int32_t>> semifuture_returnstream(int32_t i32_from, int32_t i32_to) = 0;
  virtual void async_tm_streamthrows(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ServerStream<int32_t>>> callback, int32_t foo) = 0;
  virtual folly::Future<apache::thrift::ServerStream<int32_t>> future_streamthrows(int32_t foo) = 0;
  virtual folly::SemiFuture<apache::thrift::ServerStream<int32_t>> semifuture_streamthrows(int32_t foo) = 0;
  virtual void async_tm_boththrows(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ServerStream<int32_t>>> callback, int32_t foo) = 0;
  virtual folly::Future<apache::thrift::ServerStream<int32_t>> future_boththrows(int32_t foo) = 0;
  virtual folly::SemiFuture<apache::thrift::ServerStream<int32_t>> semifuture_boththrows(int32_t foo) = 0;
  virtual void async_tm_responseandstreamthrows(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ResponseAndServerStream<int32_t,int32_t>>> callback, int32_t foo) = 0;
  virtual folly::Future<apache::thrift::ResponseAndServerStream<int32_t,int32_t>> future_responseandstreamthrows(int32_t foo) = 0;
  virtual folly::SemiFuture<apache::thrift::ResponseAndServerStream<int32_t,int32_t>> semifuture_responseandstreamthrows(int32_t foo) = 0;
};

class PubSubStreamingServiceAsyncProcessor;

class PubSubStreamingServiceSvIf : public PubSubStreamingServiceSvAsyncIf, public apache::thrift::ServerInterface {
 public:
  typedef PubSubStreamingServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;


  virtual apache::thrift::ServerStream<int32_t> returnstream(int32_t /*i32_from*/, int32_t /*i32_to*/);
  folly::Future<apache::thrift::ServerStream<int32_t>> future_returnstream(int32_t i32_from, int32_t i32_to) override;
  folly::SemiFuture<apache::thrift::ServerStream<int32_t>> semifuture_returnstream(int32_t i32_from, int32_t i32_to) override;
  void async_tm_returnstream(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ServerStream<int32_t>>> callback, int32_t i32_from, int32_t i32_to) override;
  virtual apache::thrift::ServerStream<int32_t> streamthrows(int32_t /*foo*/);
  folly::Future<apache::thrift::ServerStream<int32_t>> future_streamthrows(int32_t foo) override;
  folly::SemiFuture<apache::thrift::ServerStream<int32_t>> semifuture_streamthrows(int32_t foo) override;
  void async_tm_streamthrows(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ServerStream<int32_t>>> callback, int32_t foo) override;
  virtual apache::thrift::ServerStream<int32_t> boththrows(int32_t /*foo*/);
  folly::Future<apache::thrift::ServerStream<int32_t>> future_boththrows(int32_t foo) override;
  folly::SemiFuture<apache::thrift::ServerStream<int32_t>> semifuture_boththrows(int32_t foo) override;
  void async_tm_boththrows(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ServerStream<int32_t>>> callback, int32_t foo) override;
  virtual apache::thrift::ResponseAndServerStream<int32_t,int32_t> responseandstreamthrows(int32_t /*foo*/);
  folly::Future<apache::thrift::ResponseAndServerStream<int32_t,int32_t>> future_responseandstreamthrows(int32_t foo) override;
  folly::SemiFuture<apache::thrift::ResponseAndServerStream<int32_t,int32_t>> semifuture_responseandstreamthrows(int32_t foo) override;
  void async_tm_responseandstreamthrows(std::unique_ptr<apache::thrift::HandlerCallback<apache::thrift::ResponseAndServerStream<int32_t,int32_t>>> callback, int32_t foo) override;
};

class PubSubStreamingServiceSvNull : public PubSubStreamingServiceSvIf {
 public:
};

class PubSubStreamingServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  PubSubStreamingServiceSvIf* iface_;
 public:
  void processSerializedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
 protected:
  std::shared_ptr<folly::RequestContext> getBaseContextForRequest() override;
 public:
  using ProcessFunc = GeneratedAsyncProcessor::ProcessFunc<PubSubStreamingServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFunc>;
  static const PubSubStreamingServiceAsyncProcessor::ProcessMap& getBinaryProtocolProcessMap();
  static const PubSubStreamingServiceAsyncProcessor::ProcessMap& getCompactProtocolProcessMap();
 private:
  static const PubSubStreamingServiceAsyncProcessor::ProcessMap binaryProcessMap_;
  static const PubSubStreamingServiceAsyncProcessor::ProcessMap compactProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_returnstream(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_returnstream(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_returnstream(int32_t protoSeqId, apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, apache::thrift::ServerStream<int32_t> _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_returnstream(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_streamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_streamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_streamthrows(int32_t protoSeqId, apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, apache::thrift::ServerStream<int32_t> _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_streamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_boththrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_boththrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_boththrows(int32_t protoSeqId, apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, apache::thrift::ServerStream<int32_t> _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_boththrows(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_responseandstreamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_responseandstreamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::ResponseAndServerStreamFactory return_responseandstreamthrows(int32_t protoSeqId, apache::thrift::ContextStack* ctx, folly::Executor::KeepAlive<> executor, apache::thrift::ResponseAndServerStream<int32_t,int32_t> _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_responseandstreamthrows(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  PubSubStreamingServiceAsyncProcessor(PubSubStreamingServiceSvIf* iface) :
      iface_(iface) {}

  virtual ~PubSubStreamingServiceAsyncProcessor() {}
};

} // cpp2