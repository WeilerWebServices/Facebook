/*
 *  Copyright (c) 2017-present, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#include "CarbonTestMessages.h"

namespace carbon {
namespace test {

constexpr const char* const TestRequest::name;

void TestRequest::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case -1: {
        reader.readField(_carbon_simplestruct_, fieldType);
        break;
      }
      case 1: {
        reader.readField(key(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      case 3: {
        reader.readField(testBool(), fieldType);
        break;
      }
      case 4: {
        reader.readField(testChar(), fieldType);
        break;
      }
      case 5: {
        reader.readField(testInt8(), fieldType);
        break;
      }
      case 6: {
        reader.readField(testInt16(), fieldType);
        break;
      }
      case 7: {
        reader.readField(testInt32(), fieldType);
        break;
      }
      case 8: {
        reader.readField(testInt64(), fieldType);
        break;
      }
      case 9: {
        reader.readField(testUInt8(), fieldType);
        break;
      }
      case 10: {
        reader.readField(testUInt16(), fieldType);
        break;
      }
      case 11: {
        reader.readField(testUInt32(), fieldType);
        break;
      }
      case 12: {
        reader.readField(testUInt64(), fieldType);
        break;
      }
      case 13: {
        reader.readField(testFloat(), fieldType);
        break;
      }
      case 14: {
        reader.readField(testDouble(), fieldType);
        break;
      }
      case 15: {
        reader.readField(testShortString(), fieldType);
        break;
      }
      case 16: {
        reader.readField(testLongString(), fieldType);
        break;
      }
      case 17: {
        reader.readField(testIobuf(), fieldType);
        break;
      }
      case 18: {
        reader.readField(testStruct(), fieldType);
        break;
      }
      case 19: {
        reader.readField(testList(), fieldType);
        break;
      }
      case 20: {
        reader.readField(testOptionalString(), fieldType);
        break;
      }
      case 21: {
        reader.readField(testOptionalIobuf(), fieldType);
        break;
      }
      case 22: {
        reader.readField(testEnumVec(), fieldType);
        break;
      }
      case 23: {
        reader.readField(testUnion(), fieldType);
        break;
      }
      case 24: {
        reader.readField(testNestedVec(), fieldType);
        break;
      }
      case 25: {
        reader.readField(testUMap(), fieldType);
        break;
      }
      case 26: {
        reader.readField(testMap(), fieldType);
        break;
      }
      case 27: {
        reader.readField(testComplexMap(), fieldType);
        break;
      }
      case 28: {
        reader.readField(testUSet(), fieldType);
        break;
      }
      case 29: {
        reader.readField(testSet(), fieldType);
        break;
      }
      case 30: {
        reader.readField(testOptionalBool(), fieldType);
        break;
      }
      case 31: {
        reader.readField(testOptionalVec(), fieldType);
        break;
      }
      case 32: {
        reader.readField(testIOBufList(), fieldType);
        break;
      }
      case 33: {
        reader.readField(testF14FastMap(), fieldType);
        break;
      }
      case 34: {
        reader.readField(testF14NodeMap(), fieldType);
        break;
      }
      case 35: {
        reader.readField(testF14ValueMap(), fieldType);
        break;
      }
      case 36: {
        reader.readField(testF14VectorMap(), fieldType);
        break;
      }
      case 37: {
        reader.readField(testF14FastSet(), fieldType);
        break;
      }
      case 38: {
        reader.readField(testF14NodeSet(), fieldType);
        break;
      }
      case 39: {
        reader.readField(testF14ValueSet(), fieldType);
        break;
      }
      case 40: {
        reader.readField(testF14VectorSet(), fieldType);
        break;
      }
      case 41: {
        reader.readField(testOptionalKeywordString(), fieldType);
        break;
      }
      case 42: {
        reader.readField(testOptionalKeywordIobuf(), fieldType);
        break;
      }
      case 43: {
        reader.readField(testOptionalKeywordBool(), fieldType);
        break;
      }
      case 100: {
        reader.readField(testType(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void TestReply::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result(), fieldType);
        break;
      }
      case 2: {
        reader.readField(valInt32(), fieldType);
        break;
      }
      case 3: {
        reader.readField(valInt64(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

constexpr const char* const TestRequestStringKey::name;

void TestRequestStringKey::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(key(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void TestReplyStringKey::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(result(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void TestOptionalBool::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(optionalBool(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void TestOptionalUnion::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readRawInto(emplace<1>());
        break;
      }
      case 2: {
        reader.readRawInto(emplace<2>());
        break;
      }
      case 3: {
        reader.readRawInto(emplace<3>());
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void TestUnion::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readRawInto(emplace<1>());
        break;
      }
      case 2: {
        reader.readRawInto(emplace<2>());
        break;
      }
      case 3: {
        reader.readRawInto(emplace<3>());
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void TestF14Containers::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(fastMap(), fieldType);
        break;
      }
      case 2: {
        reader.readField(nodeMap(), fieldType);
        break;
      }
      case 3: {
        reader.readField(valueMap(), fieldType);
        break;
      }
      case 4: {
        reader.readField(vectorMap(), fieldType);
        break;
      }
      case 5: {
        reader.readField(fastSet(), fieldType);
        break;
      }
      case 6: {
        reader.readField(nodeSet(), fieldType);
        break;
      }
      case 7: {
        reader.readField(valueSet(), fieldType);
        break;
      }
      case 8: {
        reader.readField(vectorSet(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void TestStdContainers::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(fastMap(), fieldType);
        break;
      }
      case 2: {
        reader.readField(nodeMap(), fieldType);
        break;
      }
      case 3: {
        reader.readField(valueMap(), fieldType);
        break;
      }
      case 4: {
        reader.readField(vectorMap(), fieldType);
        break;
      }
      case 5: {
        reader.readField(fastSet(), fieldType);
        break;
      }
      case 6: {
        reader.readField(nodeSet(), fieldType);
        break;
      }
      case 7: {
        reader.readField(valueSet(), fieldType);
        break;
      }
      case 8: {
        reader.readField(vectorSet(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

std::string enumEnumUInt64ToString(EnumUInt64 val) {
  switch (val) {
    case EnumUInt64::AAA:
      return "AAA";
    case EnumUInt64::BBB:
      return "BBB";
    case EnumUInt64::CCC:
      return "CCC";
  }
  return "<INVALID_OPTION>";
}

std::string enumEnumUInt32ToString(EnumUInt32 val) {
  switch (val) {
    case EnumUInt32::AAA:
      return "AAA";
    case EnumUInt32::BBB:
      return "BBB";
    case EnumUInt32::CCC:
      return "CCC";
  }
  return "<INVALID_OPTION>";
}

std::string enumEnumUInt16ToString(EnumUInt16 val) {
  switch (val) {
    case EnumUInt16::AAA:
      return "AAA";
    case EnumUInt16::BBB:
      return "BBB";
    case EnumUInt16::CCC:
      return "CCC";
  }
  return "<INVALID_OPTION>";
}

std::string enumEnumUInt8ToString(EnumUInt8 val) {
  switch (val) {
    case EnumUInt8::AAA:
      return "AAA";
    case EnumUInt8::BBB:
      return "BBB";
    case EnumUInt8::CCC:
      return "CCC";
  }
  return "<INVALID_OPTION>";
}

std::string enumEnumInt64ToString(EnumInt64 val) {
  switch (val) {
    case EnumInt64::AAA:
      return "AAA";
    case EnumInt64::BBB:
      return "BBB";
    case EnumInt64::CCC:
      return "CCC";
  }
  return "<INVALID_OPTION>";
}

std::string enumEnumInt32ToString(EnumInt32 val) {
  switch (val) {
    case EnumInt32::AAA:
      return "AAA";
    case EnumInt32::BBB:
      return "BBB";
    case EnumInt32::CCC:
      return "CCC";
  }
  return "<INVALID_OPTION>";
}

std::string enumEnumInt16ToString(EnumInt16 val) {
  switch (val) {
    case EnumInt16::AAA:
      return "AAA";
    case EnumInt16::BBB:
      return "BBB";
    case EnumInt16::CCC:
      return "CCC";
  }
  return "<INVALID_OPTION>";
}

std::string enumEnumInt8ToString(EnumInt8 val) {
  switch (val) {
    case EnumInt8::AAA:
      return "AAA";
    case EnumInt8::BBB:
      return "BBB";
    case EnumInt8::CCC:
      return "CCC";
  }
  return "<INVALID_OPTION>";
}

void StructWithEnumUInt64::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithEnumUInt32::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithEnumUInt16::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithEnumUInt8::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithEnumInt64::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithEnumInt32::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithEnumInt16::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithEnumInt8::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithOptionalEnumUInt64::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testEmptyEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithOptionalEnumUInt32::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testEmptyEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithOptionalEnumUInt16::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testEmptyEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithOptionalEnumUInt8::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testEmptyEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithOptionalEnumInt64::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testEmptyEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithOptionalEnumInt32::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testEmptyEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithOptionalEnumInt16::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testEmptyEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}

void StructWithOptionalEnumInt8::deserialize(carbon::CarbonProtocolReader& reader) {
  reader.readStructBegin();
  while (true) {
    const auto pr = reader.readFieldHeader();
    const auto fieldType = pr.first;
    const auto fieldId = pr.second;

    if (fieldType == carbon::FieldType::Stop) {
      break;
    }

    switch (fieldId) {
      case 1: {
        reader.readField(testEnum(), fieldType);
        break;
      }
      case 2: {
        reader.readField(testEmptyEnum(), fieldType);
        break;
      }
      default: {
        reader.skip(fieldType);
        break;
      }
    }
  }
  reader.readStructEnd();
}
} // namespace test
} // namespace carbon