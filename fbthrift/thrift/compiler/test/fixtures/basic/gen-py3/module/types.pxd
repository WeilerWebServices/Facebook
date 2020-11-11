#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from libc.stdint cimport (
    int8_t as cint8_t,
    int16_t as cint16_t,
    int32_t as cint32_t,
    int64_t as cint64_t,
    uint32_t as cuint32_t,
)
from libcpp.string cimport string
from libcpp cimport bool as cbool, nullptr, nullptr_t
from cpython cimport bool as pbool
from libcpp.memory cimport shared_ptr, unique_ptr
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap, pair as cpair
from thrift.py3.exceptions cimport cTException
cimport folly.iobuf as __iobuf
cimport thrift.py3.exceptions
cimport thrift.py3.types
from thrift.py3.common cimport Protocol as __Protocol
from thrift.py3.types cimport (
    bstring,
    move,
    field_ref as __field_ref,
    optional_field_ref as __optional_field_ref,
    required_field_ref as __required_field_ref,
)
from folly.optional cimport cOptional
cdef extern from "src/gen-py3/module/types.h":
  pass


cdef extern from "src/gen-cpp2/module_types.h" namespace "::cpp2":
    cdef cppclass cMyEnum "::cpp2::MyEnum":
        pass





cdef class MyEnum(thrift.py3.types.CompiledEnum):
    pass

cdef extern from "src/gen-cpp2/module_types_custom_protocol.h" namespace "::cpp2":
    cdef cppclass cMyStruct__isset "::cpp2::MyStruct::__isset":
        bint MyIntField
        bint MyStringField
        bint MyDataField
        bint myEnum

    cdef cppclass cMyStruct "::cpp2::MyStruct":
        cMyStruct() except +
        cMyStruct(const cMyStruct&) except +
        bint operator==(cMyStruct&)
        bint operator!=(cMyStruct&)
        bint operator<(cMyStruct&)
        bint operator>(cMyStruct&)
        bint operator<=(cMyStruct&)
        bint operator>=(cMyStruct&)
        __field_ref[cint64_t] MyIntField_ref()
        cint64_t MyIntField
        __field_ref[string] MyStringField_ref()
        string MyStringField
        __field_ref[cMyDataItem] MyDataField_ref()
        cMyDataItem MyDataField
        __field_ref[cMyEnum] myEnum_ref()
        cMyEnum myEnum
        cMyStruct__isset __isset

    cdef cppclass cMyDataItem__isset "::cpp2::MyDataItem::__isset":
        pass

    cdef cppclass cMyDataItem "::cpp2::MyDataItem":
        cMyDataItem() except +
        cMyDataItem(const cMyDataItem&) except +
        bint operator==(cMyDataItem&)
        bint operator!=(cMyDataItem&)
        bint operator<(cMyDataItem&)
        bint operator>(cMyDataItem&)
        bint operator<=(cMyDataItem&)
        bint operator>=(cMyDataItem&)
        cMyDataItem__isset __isset

    cdef enum cMyUnion__type "::cpp2::MyUnion::Type":
        cMyUnion__type___EMPTY__ "::cpp2::MyUnion::Type::__EMPTY__",
        cMyUnion__type_myEnum "::cpp2::MyUnion::Type::myEnum",
        cMyUnion__type_myStruct "::cpp2::MyUnion::Type::myStruct",
        cMyUnion__type_myDataItem "::cpp2::MyUnion::Type::myDataItem",

    cdef cppclass cMyUnion "::cpp2::MyUnion":
        cMyUnion() except +
        cMyUnion(const cMyUnion&) except +
        bint operator==(cMyUnion&)
        bint operator!=(cMyUnion&)
        bint operator<(cMyUnion&)
        bint operator>(cMyUnion&)
        bint operator<=(cMyUnion&)
        bint operator>=(cMyUnion&)
        cMyUnion__type getType() const
        const cMyEnum& get_myEnum() const
        cMyEnum& set_myEnum(const cMyEnum&)
        const cMyStruct& get_myStruct() const
        cMyStruct& set_myStruct(const cMyStruct&)
        const cMyDataItem& get_myDataItem() const
        cMyDataItem& set_myDataItem(const cMyDataItem&)

    cdef shared_ptr[cMyDataItem] reference_shared_ptr_MyDataField "::thrift::py3::reference_shared_ptr<::cpp2::MyDataItem>"(shared_ptr[cMyStruct]&, cMyDataItem&)
    cdef shared_ptr[cMyStruct] reference_shared_ptr_myStruct "::thrift::py3::reference_shared_ptr<::cpp2::MyStruct>"(shared_ptr[cMyUnion]&, cMyStruct&)
    cdef shared_ptr[cMyDataItem] reference_shared_ptr_myDataItem "::thrift::py3::reference_shared_ptr<::cpp2::MyDataItem>"(shared_ptr[cMyUnion]&, cMyDataItem&)

cdef extern from "<utility>" namespace "std" nogil:
    cdef shared_ptr[cMyStruct] __fbthrift_move "std::move"(unique_ptr[cMyStruct])
    cdef shared_ptr[cMyStruct] __fbthrift_move_shared "std::move"(shared_ptr[cMyStruct])
    cdef unique_ptr[cMyStruct] __fbthrift_move_unique "std::move"(unique_ptr[cMyStruct])
    cdef shared_ptr[cMyDataItem] __fbthrift_move "std::move"(unique_ptr[cMyDataItem])
    cdef shared_ptr[cMyDataItem] __fbthrift_move_shared "std::move"(shared_ptr[cMyDataItem])
    cdef unique_ptr[cMyDataItem] __fbthrift_move_unique "std::move"(unique_ptr[cMyDataItem])
    cdef shared_ptr[cMyUnion] __fbthrift_move "std::move"(unique_ptr[cMyUnion])
    cdef shared_ptr[cMyUnion] __fbthrift_move_shared "std::move"(shared_ptr[cMyUnion])
    cdef unique_ptr[cMyUnion] __fbthrift_move_unique "std::move"(unique_ptr[cMyUnion])

cdef extern from "<memory>" namespace "std" nogil:
    cdef shared_ptr[const cMyStruct] const_pointer_cast "std::const_pointer_cast<const ::cpp2::MyStruct>"(shared_ptr[cMyStruct])
    cdef shared_ptr[const cMyDataItem] const_pointer_cast "std::const_pointer_cast<const ::cpp2::MyDataItem>"(shared_ptr[cMyDataItem])
    cdef shared_ptr[const cMyUnion] const_pointer_cast "std::const_pointer_cast<const ::cpp2::MyUnion>"(shared_ptr[cMyUnion])



cdef class MyStruct(thrift.py3.types.Struct):
    cdef shared_ptr[cMyStruct] _cpp_obj
    cdef MyDataItem __field_MyDataField

    @staticmethod
    cdef unique_ptr[cMyStruct] _make_instance(
        cMyStruct* base_instance,
        bint* __isNOTSET,
        object MyIntField,
        str MyStringField,
        MyDataItem MyDataField,
        MyEnum myEnum
    ) except *

    @staticmethod
    cdef create(shared_ptr[cMyStruct])



cdef class MyDataItem(thrift.py3.types.Struct):
    cdef shared_ptr[cMyDataItem] _cpp_obj

    @staticmethod
    cdef unique_ptr[cMyDataItem] _make_instance(
        cMyDataItem* base_instance,
        bint* __isNOTSET
    ) except *

    @staticmethod
    cdef create(shared_ptr[cMyDataItem])

cdef class __MyUnionType(thrift.py3.types.CompiledEnum):
    pass




cdef class MyUnion(thrift.py3.types.Union):
    cdef shared_ptr[cMyUnion] _cpp_obj
    cdef readonly __MyUnionType type
    cdef readonly object value
    cdef _load_cache(MyUnion self)

    @staticmethod
    cdef unique_ptr[cMyUnion] _make_instance(
        cMyUnion* base_instance,
        MyEnum myEnum,
        MyStruct myStruct,
        MyDataItem myDataItem
    ) except *

    @staticmethod
    cdef create(shared_ptr[cMyUnion])




