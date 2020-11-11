/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/reflection/reflection.h>

#include <fatal/type/list.h>
#include <fatal/type/pair.h>
#include <fatal/type/sequence.h>

#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/enums_types.h"
namespace facebook { namespace ns { namespace qwerty {

namespace thrift_fatal_impl_detail {

struct facebook_ns_qwerty_enums__unique_strings_list {
  using AnEnumA = ::fatal::sequence<char, 'A', 'n', 'E', 'n', 'u', 'm', 'A'>;
  using AnEnumB = ::fatal::sequence<char, 'A', 'n', 'E', 'n', 'u', 'm', 'B'>;
  using AnEnumC = ::fatal::sequence<char, 'A', 'n', 'E', 'n', 'u', 'm', 'C'>;
  using AnEnumD = ::fatal::sequence<char, 'A', 'n', 'E', 'n', 'u', 'm', 'D'>;
  using AnEnumE = ::fatal::sequence<char, 'A', 'n', 'E', 'n', 'u', 'm', 'E'>;
  using ConstantMap1 = ::fatal::sequence<char, 'C', 'o', 'n', 's', 't', 'a', 'n', 't', 'M', 'a', 'p', '1'>;
  using ConstantMap2 = ::fatal::sequence<char, 'C', 'o', 'n', 's', 't', 'a', 'n', 't', 'M', 'a', 'p', '2'>;
  using FIELDA = ::fatal::sequence<char, 'F', 'I', 'E', 'L', 'D', 'A'>;
  using FIELDB = ::fatal::sequence<char, 'F', 'I', 'E', 'L', 'D', 'B'>;
  using FIELDC = ::fatal::sequence<char, 'F', 'I', 'E', 'L', 'D', 'C'>;
  using FIELDD = ::fatal::sequence<char, 'F', 'I', 'E', 'L', 'D', 'D'>;
  using MapEnumString = ::fatal::sequence<char, 'M', 'a', 'p', 'E', 'n', 'u', 'm', 'S', 't', 'r', 'i', 'n', 'g'>;
  using MapStringEnum = ::fatal::sequence<char, 'M', 'a', 'p', 'S', 't', 'r', 'i', 'n', 'g', 'E', 'n', 'u', 'm'>;
  using SomeStruct = ::fatal::sequence<char, 'S', 'o', 'm', 'e', 'S', 't', 'r', 'u', 'c', 't'>;
  using cpp2 = ::fatal::sequence<char, 'c', 'p', 'p', '2'>;
  using enums = ::fatal::sequence<char, 'e', 'n', 'u', 'm', 's'>;
  using facebook__ns__qwerty = ::fatal::sequence<char, 'f', 'a', 'c', 'e', 'b', 'o', 'o', 'k', ':', ':', 'n', 's', ':', ':', 'q', 'w', 'e', 'r', 't', 'y'>;
  using fieldA = ::fatal::sequence<char, 'f', 'i', 'e', 'l', 'd', 'A'>;
};

} // thrift_fatal_impl_detail
class enums_tags {
  struct facebook_ns_qwerty_enums__unique_languages_list {
    using cpp2 = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::cpp2;
  };

  struct facebook_ns_qwerty_enums__unique_enums_list {
    using AnEnumA = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumA;
    using AnEnumB = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumB;
    using AnEnumC = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumC;
    using AnEnumD = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumD;
    using AnEnumE = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumE;
  };

  struct facebook_ns_qwerty_enums__unique_unions_list {
  };

  struct facebook_ns_qwerty_enums__unique_structs_list {
    using SomeStruct = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::SomeStruct;
  };

  struct facebook_ns_qwerty_enums__unique_constants_list {
    using MapStringEnum = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::MapStringEnum;
    using MapEnumString = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::MapEnumString;
    using ConstantMap1 = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::ConstantMap1;
    using ConstantMap2 = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::ConstantMap2;
  };

  struct facebook_ns_qwerty_enums__unique_services_list {
  };

public:
  struct module {};

  using languages = facebook_ns_qwerty_enums__unique_languages_list;
  using enums = facebook_ns_qwerty_enums__unique_enums_list;
  using unions = facebook_ns_qwerty_enums__unique_unions_list;
  using structs = facebook_ns_qwerty_enums__unique_structs_list;
  using constants = facebook_ns_qwerty_enums__unique_constants_list;
  using services = facebook_ns_qwerty_enums__unique_services_list;

  using strings = thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list;
};

THRIFT_REGISTER_REFLECTION_METADATA(
  enums_tags::module,
  thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::enums,
  // languages
  ::fatal::list<
    ::fatal::pair<thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::cpp2, thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::facebook__ns__qwerty>
  >,
  // enums
  ::fatal::list<
    ::fatal::pair<AnEnumA, thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumA>,
    ::fatal::pair<AnEnumB, thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumB>,
    ::fatal::pair<AnEnumC, thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumC>,
    ::fatal::pair<AnEnumD, thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumD>,
    ::fatal::pair<AnEnumE, thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::AnEnumE>
  >,
  // unions
  ::fatal::list<
  >,
  // structs
  ::fatal::list<
    ::fatal::pair<SomeStruct, thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::SomeStruct>
  >,
  // constants
  ::fatal::list<
    thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::MapStringEnum,
    thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::MapEnumString,
    thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::ConstantMap1,
    thrift_fatal_impl_detail::facebook_ns_qwerty_enums__unique_strings_list::ConstantMap2
  >,
  // services
  ::fatal::list<
  >
);

}}} // facebook::ns::qwerty
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/enums_fatal_types.h"