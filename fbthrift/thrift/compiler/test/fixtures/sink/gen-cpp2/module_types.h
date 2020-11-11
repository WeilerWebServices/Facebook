/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>



namespace apache {
namespace thrift {
namespace tag {
struct content;
struct content;
struct content;
struct sink;
struct reason;
struct reason;
struct reason;
} // namespace tag
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_content
#define APACHE_THRIFT_ACCESSOR_content
APACHE_THRIFT_DEFINE_ACCESSOR(content);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_content
#define APACHE_THRIFT_ACCESSOR_content
APACHE_THRIFT_DEFINE_ACCESSOR(content);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_content
#define APACHE_THRIFT_ACCESSOR_content
APACHE_THRIFT_DEFINE_ACCESSOR(content);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_sink
#define APACHE_THRIFT_ACCESSOR_sink
APACHE_THRIFT_DEFINE_ACCESSOR(sink);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_reason
#define APACHE_THRIFT_ACCESSOR_reason
APACHE_THRIFT_DEFINE_ACCESSOR(reason);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_reason
#define APACHE_THRIFT_ACCESSOR_reason
APACHE_THRIFT_DEFINE_ACCESSOR(reason);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_reason
#define APACHE_THRIFT_ACCESSOR_reason
APACHE_THRIFT_DEFINE_ACCESSOR(reason);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums

// END declare_enums
// BEGIN struct_indirection

// END struct_indirection
// BEGIN forward_declare
namespace cpp2 {
class InitialResponse;
class FinalResponse;
class SinkPayload;
class CompatibleWithKeywordSink;
class InitialException;
class SinkException1;
class SinkException2;
} // cpp2
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace cpp2 {
class InitialResponse final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;

 public:
  using __fbthrift_cpp2_type = InitialResponse;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  InitialResponse() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  InitialResponse(apache::thrift::FragileConstructor, ::std::string content__arg);

  InitialResponse(InitialResponse&&) = default;

  InitialResponse(const InitialResponse&) = default;


  InitialResponse& operator=(InitialResponse&&) = default;

  InitialResponse& operator=(const InitialResponse&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::std::string content;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool content;
  } __isset = {};
  bool operator==(const InitialResponse& rhs) const;
#ifndef SWIG
  friend bool operator!=(const InitialResponse& __x, const InitialResponse& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const InitialResponse& rhs) const;
#ifndef SWIG
  friend bool operator>(const InitialResponse& __x, const InitialResponse& __y) {
    return __y < __x;
  }
  friend bool operator<=(const InitialResponse& __x, const InitialResponse& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const InitialResponse& __x, const InitialResponse& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> content_ref() const& {
    return {this->content, __isset.content};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> content_ref() const&& {
    return {std::move(this->content), __isset.content};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> content_ref() & {
    return {this->content, __isset.content};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> content_ref() && {
    return {std::move(this->content), __isset.content};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  const ::std::string& get_content() const& {
    return content;
  }

  ::std::string get_content() && {
    return std::move(content);
  }

  template <typename T_InitialResponse_content_struct_setter = ::std::string>
  ::std::string& set_content(T_InitialResponse_content_struct_setter&& content_) {
    content = std::forward<T_InitialResponse_content_struct_setter>(content_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.content = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return content;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< InitialResponse >;
  friend void swap(InitialResponse& a, InitialResponse& b);
};

template <class Protocol_>
uint32_t InitialResponse::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class FinalResponse final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;

 public:
  using __fbthrift_cpp2_type = FinalResponse;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  FinalResponse() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  FinalResponse(apache::thrift::FragileConstructor, ::std::string content__arg);

  FinalResponse(FinalResponse&&) = default;

  FinalResponse(const FinalResponse&) = default;


  FinalResponse& operator=(FinalResponse&&) = default;

  FinalResponse& operator=(const FinalResponse&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::std::string content;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool content;
  } __isset = {};
  bool operator==(const FinalResponse& rhs) const;
#ifndef SWIG
  friend bool operator!=(const FinalResponse& __x, const FinalResponse& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const FinalResponse& rhs) const;
#ifndef SWIG
  friend bool operator>(const FinalResponse& __x, const FinalResponse& __y) {
    return __y < __x;
  }
  friend bool operator<=(const FinalResponse& __x, const FinalResponse& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const FinalResponse& __x, const FinalResponse& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> content_ref() const& {
    return {this->content, __isset.content};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> content_ref() const&& {
    return {std::move(this->content), __isset.content};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> content_ref() & {
    return {this->content, __isset.content};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> content_ref() && {
    return {std::move(this->content), __isset.content};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  const ::std::string& get_content() const& {
    return content;
  }

  ::std::string get_content() && {
    return std::move(content);
  }

  template <typename T_FinalResponse_content_struct_setter = ::std::string>
  ::std::string& set_content(T_FinalResponse_content_struct_setter&& content_) {
    content = std::forward<T_FinalResponse_content_struct_setter>(content_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.content = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return content;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< FinalResponse >;
  friend void swap(FinalResponse& a, FinalResponse& b);
};

template <class Protocol_>
uint32_t FinalResponse::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class SinkPayload final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;

 public:
  using __fbthrift_cpp2_type = SinkPayload;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  SinkPayload() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  SinkPayload(apache::thrift::FragileConstructor, ::std::string content__arg);

  SinkPayload(SinkPayload&&) = default;

  SinkPayload(const SinkPayload&) = default;


  SinkPayload& operator=(SinkPayload&&) = default;

  SinkPayload& operator=(const SinkPayload&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::std::string content;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool content;
  } __isset = {};
  bool operator==(const SinkPayload& rhs) const;
#ifndef SWIG
  friend bool operator!=(const SinkPayload& __x, const SinkPayload& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const SinkPayload& rhs) const;
#ifndef SWIG
  friend bool operator>(const SinkPayload& __x, const SinkPayload& __y) {
    return __y < __x;
  }
  friend bool operator<=(const SinkPayload& __x, const SinkPayload& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const SinkPayload& __x, const SinkPayload& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> content_ref() const& {
    return {this->content, __isset.content};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> content_ref() const&& {
    return {std::move(this->content), __isset.content};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> content_ref() & {
    return {this->content, __isset.content};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> content_ref() && {
    return {std::move(this->content), __isset.content};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  const ::std::string& get_content() const& {
    return content;
  }

  ::std::string get_content() && {
    return std::move(content);
  }

  template <typename T_SinkPayload_content_struct_setter = ::std::string>
  ::std::string& set_content(T_SinkPayload_content_struct_setter&& content_) {
    content = std::forward<T_SinkPayload_content_struct_setter>(content_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.content = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return content;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< SinkPayload >;
  friend void swap(SinkPayload& a, SinkPayload& b);
};

template <class Protocol_>
uint32_t SinkPayload::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class CompatibleWithKeywordSink final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;

 public:
  using __fbthrift_cpp2_type = CompatibleWithKeywordSink;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  CompatibleWithKeywordSink() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  CompatibleWithKeywordSink(apache::thrift::FragileConstructor, ::std::string sink__arg);

  CompatibleWithKeywordSink(CompatibleWithKeywordSink&&) = default;

  CompatibleWithKeywordSink(const CompatibleWithKeywordSink&) = default;


  CompatibleWithKeywordSink& operator=(CompatibleWithKeywordSink&&) = default;

  CompatibleWithKeywordSink& operator=(const CompatibleWithKeywordSink&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::std::string sink;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool sink;
  } __isset = {};
  bool operator==(const CompatibleWithKeywordSink& rhs) const;
#ifndef SWIG
  friend bool operator!=(const CompatibleWithKeywordSink& __x, const CompatibleWithKeywordSink& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const CompatibleWithKeywordSink& rhs) const;
#ifndef SWIG
  friend bool operator>(const CompatibleWithKeywordSink& __x, const CompatibleWithKeywordSink& __y) {
    return __y < __x;
  }
  friend bool operator<=(const CompatibleWithKeywordSink& __x, const CompatibleWithKeywordSink& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const CompatibleWithKeywordSink& __x, const CompatibleWithKeywordSink& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> sink_ref() const& {
    return {this->sink, __isset.sink};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> sink_ref() const&& {
    return {std::move(this->sink), __isset.sink};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> sink_ref() & {
    return {this->sink, __isset.sink};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> sink_ref() && {
    return {std::move(this->sink), __isset.sink};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  const ::std::string& get_sink() const& {
    return sink;
  }

  ::std::string get_sink() && {
    return std::move(sink);
  }

  template <typename T_CompatibleWithKeywordSink_sink_struct_setter = ::std::string>
  ::std::string& set_sink(T_CompatibleWithKeywordSink_sink_struct_setter&& sink_) {
    sink = std::forward<T_CompatibleWithKeywordSink_sink_struct_setter>(sink_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.sink = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return sink;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< CompatibleWithKeywordSink >;
  friend void swap(CompatibleWithKeywordSink& a, CompatibleWithKeywordSink& b);
};

template <class Protocol_>
uint32_t CompatibleWithKeywordSink::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class InitialException final : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;

 public:
  using __fbthrift_cpp2_type = InitialException;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  InitialException() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  InitialException(apache::thrift::FragileConstructor, ::std::string reason__arg);

  InitialException(InitialException&&) = default;

  InitialException(const InitialException&) = default;


  InitialException& operator=(InitialException&&) = default;

  InitialException& operator=(const InitialException&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::std::string reason;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool reason;
  } __isset = {};
  bool operator==(const InitialException& rhs) const;
#ifndef SWIG
  friend bool operator!=(const InitialException& __x, const InitialException& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const InitialException& rhs) const;
#ifndef SWIG
  friend bool operator>(const InitialException& __x, const InitialException& __y) {
    return __y < __x;
  }
  friend bool operator<=(const InitialException& __x, const InitialException& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const InitialException& __x, const InitialException& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> reason_ref() const& {
    return {this->reason, __isset.reason};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> reason_ref() const&& {
    return {std::move(this->reason), __isset.reason};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> reason_ref() & {
    return {this->reason, __isset.reason};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> reason_ref() && {
    return {std::move(this->reason), __isset.reason};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  const ::std::string& get_reason() const& {
    return reason;
  }

  ::std::string get_reason() && {
    return std::move(reason);
  }

  template <typename T_InitialException_reason_struct_setter = ::std::string>
  ::std::string& set_reason(T_InitialException_reason_struct_setter&& reason_) {
    reason = std::forward<T_InitialException_reason_struct_setter>(reason_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.reason = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return reason;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return "::cpp2::InitialException";
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< InitialException >;
  friend void swap(InitialException& a, InitialException& b);
};

template <class Protocol_>
uint32_t InitialException::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class SinkException1 final : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;

 public:
  using __fbthrift_cpp2_type = SinkException1;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  SinkException1() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  SinkException1(apache::thrift::FragileConstructor, ::std::string reason__arg);

  SinkException1(SinkException1&&) = default;

  SinkException1(const SinkException1&) = default;


  SinkException1& operator=(SinkException1&&) = default;

  SinkException1& operator=(const SinkException1&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  ::std::string reason;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool reason;
  } __isset = {};
  bool operator==(const SinkException1& rhs) const;
#ifndef SWIG
  friend bool operator!=(const SinkException1& __x, const SinkException1& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const SinkException1& rhs) const;
#ifndef SWIG
  friend bool operator>(const SinkException1& __x, const SinkException1& __y) {
    return __y < __x;
  }
  friend bool operator<=(const SinkException1& __x, const SinkException1& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const SinkException1& __x, const SinkException1& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> reason_ref() const& {
    return {this->reason, __isset.reason};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> reason_ref() const&& {
    return {std::move(this->reason), __isset.reason};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> reason_ref() & {
    return {this->reason, __isset.reason};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> reason_ref() && {
    return {std::move(this->reason), __isset.reason};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  const ::std::string& get_reason() const& {
    return reason;
  }

  ::std::string get_reason() && {
    return std::move(reason);
  }

  template <typename T_SinkException1_reason_struct_setter = ::std::string>
  ::std::string& set_reason(T_SinkException1_reason_struct_setter&& reason_) {
    reason = std::forward<T_SinkException1_reason_struct_setter>(reason_);
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.reason = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return reason;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return "::cpp2::SinkException1";
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< SinkException1 >;
  friend void swap(SinkException1& a, SinkException1& b);
};

template <class Protocol_>
uint32_t SinkException1::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2
namespace cpp2 {
class SinkException2 final : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;

 public:
  using __fbthrift_cpp2_type = SinkException2;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;


 public:

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  SinkException2() :
      reason(0) {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  SinkException2(apache::thrift::FragileConstructor, int64_t reason__arg);

  SinkException2(SinkException2&&) = default;

  SinkException2(const SinkException2&) = default;


  SinkException2& operator=(SinkException2&&) = default;

  SinkException2& operator=(const SinkException2&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();
 private:
  int64_t reason;

 public:
  [[deprecated("__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]]
  struct __isset {
    bool reason;
  } __isset = {};
  bool operator==(const SinkException2& rhs) const;
#ifndef SWIG
  friend bool operator!=(const SinkException2& __x, const SinkException2& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const SinkException2& rhs) const;
#ifndef SWIG
  friend bool operator>(const SinkException2& __x, const SinkException2& __y) {
    return __y < __x;
  }
  friend bool operator<=(const SinkException2& __x, const SinkException2& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const SinkException2& __x, const SinkException2& __y) {
    return !(__x < __y);
  }
#endif

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> reason_ref() const& {
    return {this->reason, __isset.reason};
  }

  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> reason_ref() const&& {
    return {std::move(this->reason), __isset.reason};
  }

  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> reason_ref() & {
    return {this->reason, __isset.reason};
  }

  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> reason_ref() && {
    return {std::move(this->reason), __isset.reason};
  }
THRIFT_IGNORE_ISSET_USE_WARNING_END

  int64_t get_reason() const {
    return reason;
  }

  int64_t& set_reason(int64_t reason_) {
    reason = reason_;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.reason = true;
THRIFT_IGNORE_ISSET_USE_WARNING_END
    return reason;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return "::cpp2::SinkException2";
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< SinkException2 >;
  friend void swap(SinkException2& a, SinkException2& b);
};

template <class Protocol_>
uint32_t SinkException2::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

} // cpp2