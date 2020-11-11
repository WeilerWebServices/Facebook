#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cimport cython as __cython
from cpython.bytes cimport PyBytes_AsStringAndSize
from cpython.object cimport PyTypeObject, Py_LT, Py_LE, Py_EQ, Py_NE, Py_GT, Py_GE
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from libcpp.iterator cimport inserter as cinserter
from libcpp.utility cimport move as cmove
from cpython cimport bool as pbool
from cython.operator cimport dereference as deref, preincrement as inc, address as ptr_address
import thrift.py3.types
cimport thrift.py3.types
cimport thrift.py3.exceptions
from thrift.py3.types cimport (
    translate_cpp_enum_to_python,
    SetMetaClass as __SetMetaClass,
    constant_shared_ptr,
    default_inst,
    NOTSET as __NOTSET,
    EnumData as __EnumData,
    EnumFlagsData as __EnumFlagsData,
    UnionTypeEnumData as __UnionTypeEnumData,
    createEnumDataForUnionType as __createEnumDataForUnionType,
)
cimport thrift.py3.std_libcpp as std_libcpp
cimport thrift.py3.serializer as serializer
import folly.iobuf as __iobuf
from folly.optional cimport cOptional

import sys
from collections.abc import Sequence, Set, Mapping, Iterable
import weakref as __weakref
import builtins as _builtins

cimport module1.types_reflection as _types_reflection


cdef __EnumData __Enum_enum_data  = __EnumData.create(thrift.py3.types.createEnumData[cEnum](), Enum)


@__cython.internal
@__cython.auto_pickle(False)
cdef class __EnumMeta(thrift.py3.types.EnumMeta):

    def __get_by_name(cls, str name):
        return __Enum_enum_data.get_by_name(name)

    def __get_by_value(cls, int value):
        return __Enum_enum_data.get_by_value(value)

    def __get_all_names(cls):
        return __Enum_enum_data.get_all_names()

    def __len__(cls):
        return __Enum_enum_data.size()


@__cython.final
@__cython.auto_pickle(False)
cdef class Enum(thrift.py3.types.CompiledEnum):
    cdef get_by_name(self, str name):
        return __Enum_enum_data.get_by_name(name)



__SetMetaClass(<PyTypeObject*> Enum, <PyTypeObject*> __EnumMeta)



@__cython.auto_pickle(False)
cdef class Struct(thrift.py3.types.Struct):

    def __init__(
        Struct self, *,
        first=None,
        str second=None
    ):
        if first is not None:
            if not isinstance(first, int):
                raise TypeError(f'first is not a { int !r}.')
            first = <cint32_t> first

        self._cpp_obj = __fbthrift_move(Struct._make_instance(
          NULL,
          NULL,
          first,
          second,
        ))

    def __call__(
        Struct self,
        first=__NOTSET,
        second=__NOTSET
    ):
        ___NOTSET = __NOTSET  # Cheaper for larger structs
        cdef bint[2] __isNOTSET  # so make_instance is typed

        __fbthrift_changed = False
        if first is ___NOTSET:
            __isNOTSET[0] = True
            first = None
        else:
            __isNOTSET[0] = False
            __fbthrift_changed = True

        if second is ___NOTSET:
            __isNOTSET[1] = True
            second = None
        else:
            __isNOTSET[1] = False
            __fbthrift_changed = True


        if not __fbthrift_changed:
            return self

        if first is not None:
            if not isinstance(first, int):
                raise TypeError(f'first is not a { int !r}.')
            first = <cint32_t> first

        if second is not None:
            if not isinstance(second, str):
                raise TypeError(f'second is not a { str !r}.')

        __fbthrift_inst = <Struct>Struct.__new__(Struct)
        __fbthrift_inst._cpp_obj = __fbthrift_move(Struct._make_instance(
          self._cpp_obj.get(),
          __isNOTSET,
          first,
          second,
        ))
        return __fbthrift_inst

    @staticmethod
    cdef unique_ptr[cStruct] _make_instance(
        cStruct* base_instance,
        bint* __isNOTSET,
        object first ,
        str second 
    ) except *:
        cdef unique_ptr[cStruct] c_inst
        if base_instance:
            c_inst = make_unique[cStruct](deref(base_instance))
        else:
            c_inst = make_unique[cStruct]()

        if base_instance:
            # Convert None's to default value. (or unset)
            if not __isNOTSET[0] and first is None:
                deref(c_inst).first_ref().assign(default_inst[cStruct]().first_ref().value())
                deref(c_inst).__isset.first = False
                pass

            if not __isNOTSET[1] and second is None:
                deref(c_inst).second_ref().assign(default_inst[cStruct]().second_ref().value())
                deref(c_inst).__isset.second = False
                pass

        if first is not None:
            deref(c_inst).first_ref().assign(first)
            deref(c_inst).__isset.first = True
        if second is not None:
            deref(c_inst).second_ref().assign(thrift.py3.types.move(thrift.py3.types.bytes_to_string(second.encode('utf-8'))))
            deref(c_inst).__isset.second = True
        # in C++ you don't have to call move(), but this doesn't translate
        # into a C++ return statement, so you do here
        return __fbthrift_move_unique(c_inst)

    cdef object __fbthrift_isset(self):
        return thrift.py3.types._IsSet("Struct", {
          "first": deref(self._cpp_obj).first_ref().has_value(),
          "second": deref(self._cpp_obj).second_ref().has_value(),
        })

    def __iter__(self):
        yield 'first', self.first
        yield 'second', self.second

    @staticmethod
    cdef create(shared_ptr[cStruct] cpp_obj):
        __fbthrift_inst = <Struct>Struct.__new__(Struct)
        __fbthrift_inst._cpp_obj = __fbthrift_move_shared(cpp_obj)
        return __fbthrift_inst

    @property
    def first(self):

        return deref(self._cpp_obj).first_ref().value()

    @property
    def second(self):

        return (<bytes>deref(self._cpp_obj).second_ref().value()).decode('UTF-8')


    def __hash__(Struct self):
        return  super().__hash__()

    def __copy__(Struct self):
        cdef shared_ptr[cStruct] cpp_obj = make_shared[cStruct](
            deref(self._cpp_obj)
        )
        return Struct.create(__fbthrift_move_shared(cpp_obj))

    def __richcmp__(self, other, op):
        cdef int cop = op
        if not (
                isinstance(self, Struct) and
                isinstance(other, Struct)):
            if cop == Py_EQ:  # different types are never equal
                return False
            elif cop == Py_NE:  # different types are always notequal
                return True
            else:
                return NotImplemented

        cdef cStruct* cself = (<Struct>self)._cpp_obj.get()
        cdef cStruct* cother = (<Struct>other)._cpp_obj.get()
        if cop == Py_EQ:
            return deref(cself) == deref(cother)
        elif cop == Py_NE:
            return deref(cself) != deref(cother)
        elif cop == Py_LT:
            return deref(cself) < deref(cother)
        elif cop == Py_LE:
            return deref(cself) <= deref(cother)
        elif cop == Py_GT:
            return deref(cself) > deref(cother)
        elif cop == Py_GE:
            return deref(cself) >= deref(cother)
        else:
            return NotImplemented

    @staticmethod
    def __get_reflection__():
        return _types_reflection.get_reflection__Struct()

    cdef __iobuf.IOBuf _serialize(Struct self, __Protocol proto):
        cdef unique_ptr[__iobuf.cIOBuf] data
        with nogil:
            data = cmove(serializer.cserialize[cStruct](self._cpp_obj.get(), proto))
        return __iobuf.from_unique_ptr(cmove(data))

    cdef cuint32_t _deserialize(Struct self, const __iobuf.cIOBuf* buf, __Protocol proto) except? 0:
        cdef cuint32_t needed
        self._cpp_obj = make_shared[cStruct]()
        with nogil:
            needed = serializer.cdeserialize[cStruct](buf, self._cpp_obj.get(), proto)
        return needed


@__cython.auto_pickle(False)
cdef class List__Enum(thrift.py3.types.List):
    def __init__(self, items=None):
        if isinstance(items, List__Enum):
            self._cpp_obj = (<List__Enum> items)._cpp_obj
        else:
            self._cpp_obj = List__Enum._make_instance(items)

    @staticmethod
    cdef create(shared_ptr[vector[cEnum]] c_items):
        __fbthrift_inst = <List__Enum>List__Enum.__new__(List__Enum)
        __fbthrift_inst._cpp_obj = __fbthrift_move_shared(c_items)
        return __fbthrift_inst

    def __copy__(List__Enum self):
        cdef shared_ptr[vector[cEnum]] cpp_obj = make_shared[vector[cEnum]](
            deref(self._cpp_obj)
        )
        return List__Enum.create(__fbthrift_move_shared(cpp_obj))

    def __len__(self):
        return deref(self._cpp_obj).size()

    @staticmethod
    cdef shared_ptr[vector[cEnum]] _make_instance(object items) except *:
        cdef shared_ptr[vector[cEnum]] c_inst = make_shared[vector[cEnum]]()
        if items is not None:
            for item in items:
                if not isinstance(item, Enum):
                    raise TypeError(f"{item!r} is not of type Enum")
                deref(c_inst).push_back(<cEnum><int>item)
        return c_inst

    def __getitem__(self, object index_obj):
        cdef shared_ptr[vector[cEnum]] c_inst
        cdef cEnum citem
        if isinstance(index_obj, slice):
            c_inst = make_shared[vector[cEnum]]()
            sz = deref(self._cpp_obj).size()
            for index in range(*index_obj.indices(sz)):
                deref(c_inst).push_back(deref(self._cpp_obj)[index])
            return List__Enum.create(__fbthrift_move_shared(c_inst))
        else:
            index = <int?>index_obj
            size = len(self)
            # Convert a negative index
            if index < 0:
                index = size + index
            if index >= size or index < 0:
                raise IndexError('list index out of range')
            citem = deref(self._cpp_obj)[index]
            return translate_cpp_enum_to_python(Enum, <int> citem)

    def __contains__(self, item):
        if not self or item is None:
            return False
        if not isinstance(item, Enum):
            return False
        return std_libcpp.find[vector[cEnum].iterator, cEnum](deref(self._cpp_obj).begin(), deref(self._cpp_obj).end(), <cEnum><int>item) != deref(self._cpp_obj).end()

    def __iter__(self):
        if not self:
            return
        cdef cEnum citem
        cdef vector[cEnum].iterator loc = deref(self._cpp_obj).begin()
        while loc != deref(self._cpp_obj).end():
            citem = deref(loc)
            yield translate_cpp_enum_to_python(Enum, <int> citem)
            inc(loc)

    def __reversed__(self):
        if not self:
            return
        cdef cEnum citem
        cdef vector[cEnum].reverse_iterator loc = deref(self._cpp_obj).rbegin()
        while loc != deref(self._cpp_obj).rend():
            citem = deref(loc)
            yield translate_cpp_enum_to_python(Enum, <int> citem)
            inc(loc)

    def index(self, item, start not None=__NOTSET, stop not None=__NOTSET):
        err = ValueError(f'{item} is not in list')
        if not self or item is None:
            raise err
        offset_begin = offset_end = 0
        if stop is not __NOTSET or start is not __NOTSET:
            # Like self[start:stop].index(item)
            size = len(self)
            stop = stop if stop is not __NOTSET else size
            start = start if start is not __NOTSET else 0
            # Convert stop to a negative position.
            if stop > 0:
                stop = min(stop - size, 0)
            if stop <= -size:
                raise err  # List would be empty
            offset_end = -stop
            # Convert start to always be positive
            if start < 0:
                start = max(size + start, 0)
            if start >= size:
                raise err  # past end of list
            offset_begin = start

        if not isinstance(item, Enum):
            raise err
        cdef vector[cEnum].iterator end = std_libcpp.prev(deref(self._cpp_obj).end(), <cint64_t>offset_end)
        cdef vector[cEnum].iterator loc = std_libcpp.find[vector[cEnum].iterator, cEnum](
            std_libcpp.next(deref(self._cpp_obj).begin(), <cint64_t>offset_begin),
            end,
            <cEnum><int>item        )
        if loc != end:
            return <cint64_t> std_libcpp.distance(deref(self._cpp_obj).begin(), loc)
        raise err

    def count(self, item):
        if not self or item is None:
            return 0
        if not isinstance(item, Enum):
            return 0
        return <cint64_t> std_libcpp.count[vector[cEnum].iterator, cEnum](
            deref(self._cpp_obj).begin(), deref(self._cpp_obj).end(), <cEnum><int>item)

    @staticmethod
    def __get_reflection__():
        return _types_reflection.get_reflection__List__Enum()


Sequence.register(List__Enum)

c1 = Struct.create(constant_shared_ptr(cc1()))
e1s = List__Enum.create(constant_shared_ptr(ce1s()))