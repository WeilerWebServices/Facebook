/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/templated-deserialize/gen-cpp2/module_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::cpp2::MyEnumA> {
  using type = ::cpp2::MyEnumA;
  static constexpr const std::size_t size = 3;
  static constexpr const std::array<type, size> values = {{
    type::fieldA,
    type::fieldB,
    type::fieldC,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "fieldA",
    "fieldB",
    "fieldC",
  }};
};

}} // apache::thrift