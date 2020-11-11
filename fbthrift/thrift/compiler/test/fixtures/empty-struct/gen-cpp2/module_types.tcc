/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/compiler/test/fixtures/empty-struct/gen-cpp2/module_types.h"

#include <thrift/lib/cpp2/gen/module_types_tcc.h>


namespace apache {
namespace thrift {
namespace detail {

template <>
struct TccStructTraits<::cpp2::Empty> {
  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};
template <>
struct TccStructTraits<::cpp2::Nada> {
  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

template <class Protocol_>
void Empty::readNoXfer(Protocol_* iprot) {
  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _loop;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

_loop:
  _readState.afterAdvanceFailure(iprot);
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<Empty>>();
  }

  switch (_readState.fieldId) {
    default:
    {
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t Empty::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Empty");
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Empty::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Empty");
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Empty::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("Empty");
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void Empty::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t Empty::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t Empty::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t Empty::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void Empty::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t Empty::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t Empty::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t Empty::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
namespace cpp2 {

template <class Protocol_>
void Nada::readNoXfer(Protocol_* iprot) {
  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;
  _readState.fieldId = 0;

  _readState.readStructBegin(iprot);

  _readState.readFieldBegin(iprot);
  if (_readState.atStop()) {
    this->__clear();
  } else {
    if (iprot->kUsesFieldNames()) {
      _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<Nada>>();
    }
    switch (_readState.fieldId) {
      default:
      {
        _readState.skip(iprot);
        break;
      }
    }
    _readState.readFieldEnd(iprot);
    _readState.readFieldBegin(iprot);
    if (UNLIKELY(!_readState.atStop())) {
      using apache::thrift::protocol::TProtocolException;
      TProtocolException::throwUnionMissingStop();
    }
  }
  _readState.readStructEnd(iprot);
}
template <class Protocol_>
uint32_t Nada::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Nada");
  switch(this->getType()) {
    case Nada::Type::__EMPTY__:;
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Nada::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Nada");
  switch(this->getType()) {
    case Nada::Type::__EMPTY__:;
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Nada::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("Nada");
  switch(this->getType()) {
    case Nada::Type::__EMPTY__:;
  }
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void Nada::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t Nada::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t Nada::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t Nada::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void Nada::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t Nada::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t Nada::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t Nada::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2