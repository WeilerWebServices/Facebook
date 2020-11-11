/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/basic-stack-arguments/gen-cpp2/module_types.h"

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace cpp2 {

class MyServiceAsyncClient : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "MyService";
  }



  virtual void hasDataById(std::unique_ptr<apache::thrift::RequestCallback> callback, int64_t id);
  virtual void hasDataById(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int64_t id);
 protected:
  void hasDataByIdImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int64_t id);
 public:

  virtual bool sync_hasDataById(int64_t id);
  virtual bool sync_hasDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id);

  virtual folly::Future<bool> future_hasDataById(int64_t id);
  virtual folly::SemiFuture<bool> semifuture_hasDataById(int64_t id);
  virtual folly::Future<bool> future_hasDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id);
  virtual folly::SemiFuture<bool> semifuture_hasDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id);
  virtual folly::Future<std::pair<bool, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_hasDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id);
  virtual folly::SemiFuture<std::pair<bool, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_hasDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id);
  FOLLY_NODISCARD [[deprecated("To be replaced by new API soon")]] virtual folly::Try<apache::thrift::RpcResponseComplete<bool>> sync_complete_hasDataById(
      apache::thrift::RpcOptions& rpcOptions,  int64_t id);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<bool> co_hasDataById(int64_t id) {
    auto _task = semifuture_hasDataById(id);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
  template <int = 0>
  folly::coro::Task<bool> co_hasDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id) {
    auto _task = semifuture_hasDataById(rpcOptions, id);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<bool, std::unique_ptr<apache::thrift::transport::THeader>>> header_co_hasDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id) {
    auto _task = header_semifuture_hasDataById(rpcOptions, id);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES

  virtual void hasDataById(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int64_t id);


  static folly::exception_wrapper recv_wrapped_hasDataById(bool& _return, ::apache::thrift::ClientReceiveState& state);
  static bool recv_hasDataById(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual bool recv_instance_hasDataById(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_hasDataById(bool& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void hasDataByIdT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int64_t id);
 public:

  virtual void getDataById(std::unique_ptr<apache::thrift::RequestCallback> callback, int64_t id);
  virtual void getDataById(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int64_t id);
 protected:
  void getDataByIdImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int64_t id);
 public:

  virtual void sync_getDataById(::std::string& _return, int64_t id);
  virtual void sync_getDataById(apache::thrift::RpcOptions& rpcOptions, ::std::string& _return, int64_t id);

  virtual folly::Future<::std::string> future_getDataById(int64_t id);
  virtual folly::SemiFuture<::std::string> semifuture_getDataById(int64_t id);
  virtual folly::Future<::std::string> future_getDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id);
  virtual folly::SemiFuture<::std::string> semifuture_getDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id);
  virtual folly::Future<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_getDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id);
  virtual folly::SemiFuture<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_getDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id);
  FOLLY_NODISCARD [[deprecated("To be replaced by new API soon")]] virtual folly::Try<apache::thrift::RpcResponseComplete<::std::string>> sync_complete_getDataById(
      apache::thrift::RpcOptions& rpcOptions,  int64_t id);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<::std::string> co_getDataById(int64_t id) {
    auto _task = semifuture_getDataById(id);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
  template <int = 0>
  folly::coro::Task<::std::string> co_getDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id) {
    auto _task = semifuture_getDataById(rpcOptions, id);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> header_co_getDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id) {
    auto _task = header_semifuture_getDataById(rpcOptions, id);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES

  virtual void getDataById(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int64_t id);


  static folly::exception_wrapper recv_wrapped_getDataById(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
  static void recv_getDataById(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_getDataById(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_getDataById(::std::string& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void getDataByIdT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int64_t id);
 public:

  virtual void putDataById(std::unique_ptr<apache::thrift::RequestCallback> callback, int64_t id, const ::std::string& data);
  virtual void putDataById(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int64_t id, const ::std::string& data);
 protected:
  void putDataByIdImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int64_t id, const ::std::string& data);
 public:

  virtual void sync_putDataById(int64_t id, const ::std::string& data);
  virtual void sync_putDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data);

  virtual folly::Future<folly::Unit> future_putDataById(int64_t id, const ::std::string& data);
  virtual folly::SemiFuture<folly::Unit> semifuture_putDataById(int64_t id, const ::std::string& data);
  virtual folly::Future<folly::Unit> future_putDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data);
  virtual folly::SemiFuture<folly::Unit> semifuture_putDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data);
  virtual folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_future_putDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data);
  virtual folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> header_semifuture_putDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data);
  FOLLY_NODISCARD [[deprecated("To be replaced by new API soon")]] virtual folly::Try<apache::thrift::RpcResponseComplete<void>> sync_complete_putDataById(
      apache::thrift::RpcOptions& rpcOptions,  int64_t id, const ::std::string& data);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_putDataById(int64_t id, const ::std::string& data) {
    auto _task = semifuture_putDataById(id, data);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
  template <int = 0>
  folly::coro::Task<void> co_putDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data) {
    auto _task = semifuture_putDataById(rpcOptions, id, data);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES

  virtual void putDataById(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int64_t id, const ::std::string& data);


  static folly::exception_wrapper recv_wrapped_putDataById(::apache::thrift::ClientReceiveState& state);
  static void recv_putDataById(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_putDataById(::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_putDataById(::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  void putDataByIdT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int64_t id, const ::std::string& data);
 public:

  virtual void lobDataById(std::unique_ptr<apache::thrift::RequestCallback> callback, int64_t id, const ::std::string& data);
  virtual void lobDataById(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, int64_t id, const ::std::string& data);
 protected:
  void lobDataByIdImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int64_t id, const ::std::string& data);
 public:

  virtual void sync_lobDataById(int64_t id, const ::std::string& data);
  virtual void sync_lobDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data);

  virtual folly::Future<folly::Unit> future_lobDataById(int64_t id, const ::std::string& data);
  virtual folly::SemiFuture<folly::Unit> semifuture_lobDataById(int64_t id, const ::std::string& data);
  virtual folly::Future<folly::Unit> future_lobDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data);
  virtual folly::SemiFuture<folly::Unit> semifuture_lobDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_lobDataById(int64_t id, const ::std::string& data) {
    auto _task = semifuture_lobDataById(id, data);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
  template <int = 0>
  folly::coro::Task<void> co_lobDataById(apache::thrift::RpcOptions& rpcOptions, int64_t id, const ::std::string& data) {
    auto _task = semifuture_lobDataById(rpcOptions, id, data);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
#endif // FOLLY_HAS_COROUTINES

  virtual void lobDataById(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, int64_t id, const ::std::string& data);


 private:
  template <typename Protocol_>
  void lobDataByIdT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback, int64_t id, const ::std::string& data);
 public:
};

} // cpp2