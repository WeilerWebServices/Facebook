/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/includes/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/includes/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/includes/gen-cpp2/module_data.h"


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyStruct>::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) noexcept {
  using TType = apache::thrift::protocol::TType;
  constexpr size_t _size = 3;
  static constexpr folly::StringPiece _names[] = {
    "MyIncludedField",
    "MyOtherIncludedField",
    "MyIncludedInt",
  };
  static constexpr int16_t _ids[] = {
    1,
    2,
    3,
  };
  static constexpr TType _types[] = {
    TType::T_STRUCT,
    TType::T_STRUCT,
    TType::T_I64,
  };
  static constexpr st::translate_field_name_table
      table{_size, _names, _ids, _types};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyStruct::MyStruct(apache::thrift::FragileConstructor,  ::cpp2::Included MyIncludedField__arg,  ::cpp2::Included MyOtherIncludedField__arg,  ::cpp2::IncludedInt64 MyIncludedInt__arg) :
    MyIncludedField(std::move(MyIncludedField__arg)),
    MyOtherIncludedField(std::move(MyOtherIncludedField__arg)),
    MyIncludedInt(std::move(MyIncludedInt__arg)) {
  __isset.MyIncludedField = true;
  __isset.MyOtherIncludedField = true;
  __isset.MyIncludedInt = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void MyStruct::__clear() {
  // clear all fields
  ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::clear(&MyIncludedField);
  ::apache::thrift::Cpp2Ops<  ::cpp2::Included>::clear(&MyOtherIncludedField);
  MyIncludedInt = 42LL;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool MyStruct::operator==(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.MyIncludedField == rhs.MyIncludedField)) {
    return false;
  }
  if (!(lhs.MyOtherIncludedField == rhs.MyOtherIncludedField)) {
    return false;
  }
  if (!(lhs.MyIncludedInt == rhs.MyIncludedInt)) {
    return false;
  }
  return true;
}

bool MyStruct::operator<(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.MyIncludedField == rhs.MyIncludedField)) {
    return lhs.MyIncludedField < rhs.MyIncludedField;
  }
  if (!(lhs.MyOtherIncludedField == rhs.MyOtherIncludedField)) {
    return lhs.MyOtherIncludedField < rhs.MyOtherIncludedField;
  }
  if (!(lhs.MyIncludedInt == rhs.MyIncludedInt)) {
    return lhs.MyIncludedInt < rhs.MyIncludedInt;
  }
  return false;
}

const  ::cpp2::Included& MyStruct::get_MyIncludedField() const& {
  return MyIncludedField;
}

 ::cpp2::Included MyStruct::get_MyIncludedField() && {
  return std::move(MyIncludedField);
}

const  ::cpp2::Included& MyStruct::get_MyOtherIncludedField() const& {
  return MyOtherIncludedField;
}

 ::cpp2::Included MyStruct::get_MyOtherIncludedField() && {
  return std::move(MyOtherIncludedField);
}


void swap(MyStruct& a, MyStruct& b) {
  using ::std::swap;
  swap(a.MyIncludedField_ref().value(), b.MyIncludedField_ref().value());
  swap(a.MyOtherIncludedField_ref().value(), b.MyOtherIncludedField_ref().value());
  swap(a.MyIncludedInt_ref().value(), b.MyIncludedInt_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void MyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        MyStruct,
        ::apache::thrift::type_class::structure,
         ::cpp2::Included>,
    "inconsistent use of json option");
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        MyStruct,
        ::apache::thrift::type_class::structure,
         ::cpp2::Included>,
    "inconsistent use of json option");

static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        MyStruct,
        ::apache::thrift::type_class::structure,
         ::cpp2::Included>,
    "inconsistent use of nimble option");
static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        MyStruct,
        ::apache::thrift::type_class::structure,
         ::cpp2::Included>,
    "inconsistent use of nimble option");

} // cpp2