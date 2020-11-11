/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/basic-annotations/gen-cpp2/module_metadata.h"

namespace apache {
namespace thrift {
namespace detail {
namespace md {
using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;
using ThriftService = ::apache::thrift::metadata::ThriftService;
using ThriftServiceContext = ::apache::thrift::metadata::ThriftServiceContext;
using ThriftFunctionGenerator = void (*)(ThriftMetadata&, ThriftService&);

void EnumMetadata<::cpp2::MyEnum>::gen(ThriftMetadata& metadata) {
  auto res = metadata.enums_ref()->emplace("module.MyEnum", ::apache::thrift::metadata::ThriftEnum{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftEnum& enum_metadata = res.first->second;
  enum_metadata.name_ref() = "module.MyEnum";
  using EnumTraits = TEnumTraits<::cpp2::MyEnum>;
  for (std::size_t i = 0; i < EnumTraits::size; ++i) {
    enum_metadata.elements_ref()->emplace(static_cast<int32_t>(EnumTraits::values[i]), EnumTraits::names[i].str());
  }
}

const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::MyStructNestedAnnotation>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs_ref()->emplace("module.MyStructNestedAnnotation", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_MyStructNestedAnnotation = res.first->second;
  module_MyStructNestedAnnotation.name_ref() = "module.MyStructNestedAnnotation";
  module_MyStructNestedAnnotation.is_union_ref() = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_MyStructNestedAnnotation_fields[] = {
    std::make_tuple(1, "name", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
  };
  for (const auto& f : module_MyStructNestedAnnotation_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id_ref() = std::get<0>(f);
    field.name_ref() = std::get<1>(f);
    field.is_optional_ref() = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(*field.type_ref(), metadata);
    module_MyStructNestedAnnotation.fields_ref()->push_back(std::move(field));
  }
  return res.first->second;
}
const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::MyStructAnnotation>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs_ref()->emplace("module.MyStructAnnotation", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_MyStructAnnotation = res.first->second;
  module_MyStructAnnotation.name_ref() = "module.MyStructAnnotation";
  module_MyStructAnnotation.is_union_ref() = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_MyStructAnnotation_fields[] = {
    std::make_tuple(1, "count", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE)),
    std::make_tuple(2, "name", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
    std::make_tuple(3, "extra", true, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
    std::make_tuple(4, "nest", false, std::make_unique<Struct< ::cpp2::MyStructNestedAnnotation>>("module.MyStructNestedAnnotation")),
  };
  for (const auto& f : module_MyStructAnnotation_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id_ref() = std::get<0>(f);
    field.name_ref() = std::get<1>(f);
    field.is_optional_ref() = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(*field.type_ref(), metadata);
    module_MyStructAnnotation.fields_ref()->push_back(std::move(field));
  }
  return res.first->second;
}
const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::MyStruct>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs_ref()->emplace("module.MyStruct", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_MyStruct = res.first->second;
  module_MyStruct.name_ref() = "module.MyStruct";
  module_MyStruct.is_union_ref() = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_MyStruct_fields[] = {
    std::make_tuple(1, "major", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE)),
    std::make_tuple(2, "package", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
    std::make_tuple(3, "annotation_with_quote", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
    std::make_tuple(4, "class_", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
    std::make_tuple(5, "annotation_with_trailing_comma", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
    std::make_tuple(6, "empty_annotations", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
  };
  for (const auto& f : module_MyStruct_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id_ref() = std::get<0>(f);
    field.name_ref() = std::get<1>(f);
    field.is_optional_ref() = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(*field.type_ref(), metadata);
    module_MyStruct.fields_ref()->push_back(std::move(field));
  }
  return res.first->second;
}
const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::cpp2::SecretStruct>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs_ref()->emplace("module.SecretStruct", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& module_SecretStruct = res.first->second;
  module_SecretStruct.name_ref() = "module.SecretStruct";
  module_SecretStruct.is_union_ref() = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_SecretStruct_fields[] = {
    std::make_tuple(1, "id", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE)),
    std::make_tuple(2, "password", false, std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)),
  };
  for (const auto& f : module_SecretStruct_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id_ref() = std::get<0>(f);
    field.name_ref() = std::get<1>(f);
    field.is_optional_ref() = std::get<2>(f);
    std::get<3>(f)->writeAndGenType(*field.type_ref(), metadata);
    module_SecretStruct.fields_ref()->push_back(std::move(field));
  }
  return res.first->second;
}

void ServiceMetadata<::cpp2::MyServiceSvIf>::gen_ping(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "ping";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}
void ServiceMetadata<::cpp2::MyServiceSvIf>::gen_getRandomData(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "getRandomData";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}
void ServiceMetadata<::cpp2::MyServiceSvIf>::gen_hasDataById(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "hasDataById";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BOOL_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  ::apache::thrift::metadata::ThriftField module_MyService_hasDataById_id_1;
  module_MyService_hasDataById_id_1.id_ref() = 1;
  module_MyService_hasDataById_id_1.name_ref() = "id";
  module_MyService_hasDataById_id_1.is_optional_ref() = false;
  auto module_MyService_hasDataById_id_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE);
  module_MyService_hasDataById_id_1_type->writeAndGenType(*module_MyService_hasDataById_id_1.type_ref(), metadata);
  func.arguments_ref()->push_back(std::move(module_MyService_hasDataById_id_1));
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}
void ServiceMetadata<::cpp2::MyServiceSvIf>::gen_getDataById(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "getDataById";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  ::apache::thrift::metadata::ThriftField module_MyService_getDataById_id_1;
  module_MyService_getDataById_id_1.id_ref() = 1;
  module_MyService_getDataById_id_1.name_ref() = "id";
  module_MyService_getDataById_id_1.is_optional_ref() = false;
  auto module_MyService_getDataById_id_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE);
  module_MyService_getDataById_id_1_type->writeAndGenType(*module_MyService_getDataById_id_1.type_ref(), metadata);
  func.arguments_ref()->push_back(std::move(module_MyService_getDataById_id_1));
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}
void ServiceMetadata<::cpp2::MyServiceSvIf>::gen_putDataById(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "putDataById";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  ::apache::thrift::metadata::ThriftField module_MyService_putDataById_id_1;
  module_MyService_putDataById_id_1.id_ref() = 1;
  module_MyService_putDataById_id_1.name_ref() = "id";
  module_MyService_putDataById_id_1.is_optional_ref() = false;
  auto module_MyService_putDataById_id_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE);
  module_MyService_putDataById_id_1_type->writeAndGenType(*module_MyService_putDataById_id_1.type_ref(), metadata);
  func.arguments_ref()->push_back(std::move(module_MyService_putDataById_id_1));
  ::apache::thrift::metadata::ThriftField module_MyService_putDataById_data_2;
  module_MyService_putDataById_data_2.id_ref() = 2;
  module_MyService_putDataById_data_2.name_ref() = "data";
  module_MyService_putDataById_data_2.is_optional_ref() = false;
  auto module_MyService_putDataById_data_2_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE);
  module_MyService_putDataById_data_2_type->writeAndGenType(*module_MyService_putDataById_data_2.type_ref(), metadata);
  func.arguments_ref()->push_back(std::move(module_MyService_putDataById_data_2));
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}
void ServiceMetadata<::cpp2::MyServiceSvIf>::gen_lobDataById(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "lobDataById";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  ::apache::thrift::metadata::ThriftField module_MyService_lobDataById_id_1;
  module_MyService_lobDataById_id_1.id_ref() = 1;
  module_MyService_lobDataById_id_1.name_ref() = "id";
  module_MyService_lobDataById_id_1.is_optional_ref() = false;
  auto module_MyService_lobDataById_id_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_I64_TYPE);
  module_MyService_lobDataById_id_1_type->writeAndGenType(*module_MyService_lobDataById_id_1.type_ref(), metadata);
  func.arguments_ref()->push_back(std::move(module_MyService_lobDataById_id_1));
  ::apache::thrift::metadata::ThriftField module_MyService_lobDataById_data_2;
  module_MyService_lobDataById_data_2.id_ref() = 2;
  module_MyService_lobDataById_data_2.name_ref() = "data";
  module_MyService_lobDataById_data_2.is_optional_ref() = false;
  auto module_MyService_lobDataById_data_2_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE);
  module_MyService_lobDataById_data_2_type->writeAndGenType(*module_MyService_lobDataById_data_2.type_ref(), metadata);
  func.arguments_ref()->push_back(std::move(module_MyService_lobDataById_data_2));
  func.is_oneway_ref() = true;
  service.functions_ref()->push_back(std::move(func));
}
void ServiceMetadata<::cpp2::MyServiceSvIf>::gen_cppDoNothing(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "doNothing";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}

void ServiceMetadata<::cpp2::MyServiceSvIf>::gen(ThriftMetadata& metadata, ThriftServiceContext& context) {
  (void) metadata;
  ::apache::thrift::metadata::ThriftService module_MyService;
  module_MyService.name_ref() = "module.MyService";
  static const ThriftFunctionGenerator functions[] = {
    ServiceMetadata<::cpp2::MyServiceSvIf>::gen_ping,
    ServiceMetadata<::cpp2::MyServiceSvIf>::gen_getRandomData,
    ServiceMetadata<::cpp2::MyServiceSvIf>::gen_hasDataById,
    ServiceMetadata<::cpp2::MyServiceSvIf>::gen_getDataById,
    ServiceMetadata<::cpp2::MyServiceSvIf>::gen_putDataById,
    ServiceMetadata<::cpp2::MyServiceSvIf>::gen_lobDataById,
    ServiceMetadata<::cpp2::MyServiceSvIf>::gen_cppDoNothing,
  };
  for (auto& function_gen : functions) {
    function_gen(metadata, module_MyService);
  }
  context.service_info_ref() = std::move(module_MyService);
  ::apache::thrift::metadata::ThriftModuleContext module;
  module.name_ref() = "module";
  context.module_ref() = std::move(module);
}
void ServiceMetadata<::cpp2::MyServicePrioParentSvIf>::gen_ping(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "ping";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}
void ServiceMetadata<::cpp2::MyServicePrioParentSvIf>::gen_pong(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "pong";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}

void ServiceMetadata<::cpp2::MyServicePrioParentSvIf>::gen(ThriftMetadata& metadata, ThriftServiceContext& context) {
  (void) metadata;
  ::apache::thrift::metadata::ThriftService module_MyServicePrioParent;
  module_MyServicePrioParent.name_ref() = "module.MyServicePrioParent";
  static const ThriftFunctionGenerator functions[] = {
    ServiceMetadata<::cpp2::MyServicePrioParentSvIf>::gen_ping,
    ServiceMetadata<::cpp2::MyServicePrioParentSvIf>::gen_pong,
  };
  for (auto& function_gen : functions) {
    function_gen(metadata, module_MyServicePrioParent);
  }
  context.service_info_ref() = std::move(module_MyServicePrioParent);
  ::apache::thrift::metadata::ThriftModuleContext module;
  module.name_ref() = "module";
  context.module_ref() = std::move(module);
}
void ServiceMetadata<::cpp2::MyServicePrioChildSvIf>::gen_pang(ThriftMetadata& metadata, ThriftService& service) {
  ::apache::thrift::metadata::ThriftFunction func;
  (void)metadata;
  func.name_ref() = "pang";
  auto func_ret_type = std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_VOID_TYPE);
  func_ret_type->writeAndGenType(*func.return_type_ref(), metadata);
  func.is_oneway_ref() = false;
  service.functions_ref()->push_back(std::move(func));
}

void ServiceMetadata<::cpp2::MyServicePrioChildSvIf>::gen(ThriftMetadata& metadata, ThriftServiceContext& context) {
  (void) metadata;
  ::apache::thrift::metadata::ThriftService module_MyServicePrioChild;
  module_MyServicePrioChild.name_ref() = "module.MyServicePrioChild";
  static const ThriftFunctionGenerator functions[] = {
    ServiceMetadata<::cpp2::MyServicePrioChildSvIf>::gen_pang,
  };
  for (auto& function_gen : functions) {
    function_gen(metadata, module_MyServicePrioChild);
  }
  module_MyServicePrioChild.parent_ref() = "module.MyServicePrioParent";
  ThriftServiceContext module_MyServicePrioParent_parent_context;
  ServiceMetadata<::cpp2::MyServicePrioParentSvIf>::gen(metadata, module_MyServicePrioParent_parent_context);
  auto module_MyServicePrioParent_parent_name = module_MyServicePrioParent_parent_context.get_service_info().get_name();
  metadata.services_ref()->emplace(std::move(module_MyServicePrioParent_parent_name), std::move(*module_MyServicePrioParent_parent_context.service_info_ref()));
  context.service_info_ref() = std::move(module_MyServicePrioChild);
  ::apache::thrift::metadata::ThriftModuleContext module;
  module.name_ref() = "module";
  context.module_ref() = std::move(module);
}
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache