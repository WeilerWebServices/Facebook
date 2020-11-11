/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/constants/gen-cpp2/module_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::cpp2::EmptyEnum> {
  using type = ::cpp2::EmptyEnum;
  static constexpr const std::size_t size = 0;
  static constexpr const std::array<type, size> values = {{
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
  }};
};
template <> struct TEnumDataStorage<::cpp2::City> {
  using type = ::cpp2::City;
  static constexpr const std::size_t size = 4;
  static constexpr const std::array<type, size> values = {{
    type::NYC,
    type::MPK,
    type::SEA,
    type::LON,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "NYC",
    "MPK",
    "SEA",
    "LON",
  }};
};
template <> struct TEnumDataStorage<::cpp2::Company> {
  using type = ::cpp2::Company;
  static constexpr const std::size_t size = 4;
  static constexpr const std::array<type, size> values = {{
    type::FACEBOOK,
    type::WHATSAPP,
    type::OCULUS,
    type::INSTAGRAM,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "FACEBOOK",
    "WHATSAPP",
    "OCULUS",
    "INSTAGRAM",
  }};
};

template <> struct TEnumDataStorage<::cpp2::union1::Type> {
  using type = ::cpp2::union1::Type;
  static constexpr const std::size_t size = 2;
  static constexpr const std::array<type, size> values = {{
    type::i,
    type::d,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "i",
    "d",
  }};
};

template <> struct TEnumDataStorage<::cpp2::union2::Type> {
  using type = ::cpp2::union2::Type;
  static constexpr const std::size_t size = 4;
  static constexpr const std::array<type, size> values = {{
    type::i,
    type::d,
    type::s,
    type::u,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
    "i",
    "d",
    "s",
    "u",
  }};
};

}} // apache::thrift