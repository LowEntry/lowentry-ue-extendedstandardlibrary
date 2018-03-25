// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryBitDataEntry.h"


// init >>
	ULowEntryBitDataEntry::ULowEntryBitDataEntry(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromBit(const bool Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetBit(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromByteLeastSignificantBits(const uint8 Value, const int32 BitCount)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetByteLeastSignificantBits(Value, BitCount);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromByteMostSignificantBits(const uint8 Value, const int32 BitCount)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetByteMostSignificantBits(Value, BitCount);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromIntegerLeastSignificantBits(const int32 Value, const int32 BitCount)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetIntegerLeastSignificantBits(Value, BitCount);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromIntegerMostSignificantBits(const int32 Value, const int32 BitCount)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetIntegerMostSignificantBits(Value, BitCount);
		return Instance;
	}

	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromByte(const uint8 Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetByte(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromInteger(const int32 Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetInteger(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromPositiveInteger1(const int32 Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetPositiveInteger1(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromPositiveInteger2(const int32 Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetPositiveInteger2(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromPositiveInteger3(const int32 Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetPositiveInteger3(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromLongBytes(ULowEntryLong* Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetLongBytes(Value);
		return Instance;
	}

	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromFloat(const float Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetFloat(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromDoubleBytes(ULowEntryDouble* Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetDoubleBytes(Value);
		return Instance;
	}

	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromBoolean(const bool Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetBoolean(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromStringUtf8(const FString& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetStringUtf8(Value);
		return Instance;
	}


	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromBitArray(const TArray<bool>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetBitArray(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromByteArrayLeastSignificantBits(const TArray<uint8>& Value, const int32 BitCount)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetByteArrayLeastSignificantBits(Value, BitCount);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromByteArrayMostSignificantBits(const TArray<uint8>& Value, const int32 BitCount)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetByteArrayMostSignificantBits(Value, BitCount);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromIntegerArrayLeastSignificantBits(const TArray<int32>& Value, const int32 BitCount)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetIntegerArrayLeastSignificantBits(Value, BitCount);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromIntegerArrayMostSignificantBits(const TArray<int32>& Value, const int32 BitCount)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetIntegerArrayMostSignificantBits(Value, BitCount);
		return Instance;
	}

	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromByteArray(const TArray<uint8>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetByteArray(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromIntegerArray(const TArray<int32>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetIntegerArray(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromPositiveInteger1Array(const TArray<int32>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetPositiveInteger1Array(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromPositiveInteger2Array(const TArray<int32>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetPositiveInteger2Array(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromPositiveInteger3Array(const TArray<int32>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetPositiveInteger3Array(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromLongBytesArray(const TArray<ULowEntryLong*>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetLongBytesArray(Value);
		return Instance;
	}

	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromFloatArray(const TArray<float>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetFloatArray(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromDoubleBytesArray(const TArray<ULowEntryDouble*>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetDoubleBytesArray(Value);
		return Instance;
	}

	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromBooleanArray(const TArray<bool>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetBooleanArray(Value);
		return Instance;
	}
	ULowEntryBitDataEntry* ULowEntryBitDataEntry::CreateFromStringUtf8Array(const TArray<FString>& Value)
	{
		ULowEntryBitDataEntry* Instance = NewObject<ULowEntryBitDataEntry>();
		Instance->SetStringUtf8Array(Value);
		return Instance;
	}
// init <<


int32 ULowEntryBitDataEntry::GetBitCount()
{
	return IntegerValue;
}



bool ULowEntryBitDataEntry::IsBit()
{
	return (Type == 11);
}
void ULowEntryBitDataEntry::SetBit(const bool Value)
{
	Type = 11;
	BooleanValue = Value;
}
bool ULowEntryBitDataEntry::GetBit()
{
	return BooleanValue;
}

bool ULowEntryBitDataEntry::IsByteLeastSignificantBits()
{
	return (Type == 12);
}
void ULowEntryBitDataEntry::SetByteLeastSignificantBits(const uint8 Value, const int32 BitCount)
{
	Type = 12;
	ByteValue = Value;
	IntegerValue = BitCount;
}
uint8 ULowEntryBitDataEntry::GetByteLeastSignificantBits()
{
	return ByteValue;
}

bool ULowEntryBitDataEntry::IsByteMostSignificantBits()
{
	return (Type == 13);
}
void ULowEntryBitDataEntry::SetByteMostSignificantBits(const uint8 Value, const int32 BitCount)
{
	Type = 13;
	ByteValue = Value;
	IntegerValue = BitCount;
}
uint8 ULowEntryBitDataEntry::GetByteMostSignificantBits()
{
	return ByteValue;
}

bool ULowEntryBitDataEntry::IsIntegerLeastSignificantBits()
{
	return (Type == 14);
}
void ULowEntryBitDataEntry::SetIntegerLeastSignificantBits(const int32 Value, const int32 BitCount)
{
	Type = 14;
	IntegerValue = Value;
	IntegerValue = BitCount;
}
int32 ULowEntryBitDataEntry::GetIntegerLeastSignificantBits()
{
	return IntegerValue;
}

bool ULowEntryBitDataEntry::IsIntegerMostSignificantBits()
{
	return (Type == 15);
}
void ULowEntryBitDataEntry::SetIntegerMostSignificantBits(const int32 Value, const int32 BitCount)
{
	Type = 15;
	IntegerValue = Value;
	IntegerValue = BitCount;
}
int32 ULowEntryBitDataEntry::GetIntegerMostSignificantBits()
{
	return IntegerValue;
}


bool ULowEntryBitDataEntry::IsByte()
{
	return (Type == 1);
}
void ULowEntryBitDataEntry::SetByte(const uint8 Value)
{
	Type = 1;
	ByteValue = Value;
}
uint8 ULowEntryBitDataEntry::GetByte()
{
	return ByteValue;
}

bool ULowEntryBitDataEntry::IsInteger()
{
	return (Type == 2);
}
void ULowEntryBitDataEntry::SetInteger(const int32 Value)
{
	Type = 2;
	IntegerValue = Value;
}
int32 ULowEntryBitDataEntry::GetInteger()
{
	return IntegerValue;
}

bool ULowEntryBitDataEntry::IsPositiveInteger1()
{
	return (Type == 8);
}
void ULowEntryBitDataEntry::SetPositiveInteger1(const int32 Value)
{
	Type = 8;
	IntegerValue = Value;
}
int32 ULowEntryBitDataEntry::GetPositiveInteger1()
{
	return IntegerValue;
}

bool ULowEntryBitDataEntry::IsPositiveInteger2()
{
	return (Type == 9);
}
void ULowEntryBitDataEntry::SetPositiveInteger2(const int32 Value)
{
	Type = 9;
	IntegerValue = Value;
}
int32 ULowEntryBitDataEntry::GetPositiveInteger2()
{
	return IntegerValue;
}

bool ULowEntryBitDataEntry::IsPositiveInteger3()
{
	return (Type == 10);
}
void ULowEntryBitDataEntry::SetPositiveInteger3(const int32 Value)
{
	Type = 10;
	IntegerValue = Value;
}
int32 ULowEntryBitDataEntry::GetPositiveInteger3()
{
	return IntegerValue;
}

bool ULowEntryBitDataEntry::IsLongBytes()
{
	return (Type == 3);
}
void ULowEntryBitDataEntry::SetLongBytes(ULowEntryLong* Value)
{
	Type = 3;
	LongBytesValue = Value;
}
ULowEntryLong* ULowEntryBitDataEntry::GetLongBytes()
{
	return LongBytesValue;
}


bool ULowEntryBitDataEntry::IsFloat()
{
	return (Type == 4);
}
void ULowEntryBitDataEntry::SetFloat(const float Value)
{
	Type = 4;
	FloatValue = Value;
}
float ULowEntryBitDataEntry::GetFloat()
{
	return FloatValue;
}

bool ULowEntryBitDataEntry::IsDoubleBytes()
{
	return (Type == 5);
}
void ULowEntryBitDataEntry::SetDoubleBytes(ULowEntryDouble* Value)
{
	Type = 5;
	DoubleBytesValue = Value;
}
ULowEntryDouble* ULowEntryBitDataEntry::GetDoubleBytes()
{
	return DoubleBytesValue;
}


bool ULowEntryBitDataEntry::IsBoolean()
{
	return (Type == 6);
}
void ULowEntryBitDataEntry::SetBoolean(const bool Value)
{
	Type = 6;
	BooleanValue = Value;
}
bool ULowEntryBitDataEntry::GetBoolean()
{
	return BooleanValue;
}

bool ULowEntryBitDataEntry::IsStringUtf8()
{
	return (Type == 7);
}
void ULowEntryBitDataEntry::SetStringUtf8(const FString& Value)
{
	Type = 7;
	StringUtf8Value = Value;
}
FString ULowEntryBitDataEntry::GetStringUtf8()
{
	return StringUtf8Value;
}



bool ULowEntryBitDataEntry::IsBitArray()
{
	return (Type == 111);
}
void ULowEntryBitDataEntry::SetBitArray(const TArray<bool>& Value)
{
	Type = 111;
	BooleanArrayValue = Value;
}
TArray<bool> ULowEntryBitDataEntry::GetBitArray()
{
	return BooleanArrayValue;
}

bool ULowEntryBitDataEntry::IsByteArrayLeastSignificantBits()
{
	return (Type == 112);
}
void ULowEntryBitDataEntry::SetByteArrayLeastSignificantBits(const TArray<uint8>& Value, const int32 BitCount)
{
	Type = 112;
	ByteArrayValue = Value;
	IntegerValue = BitCount;
}
TArray<uint8> ULowEntryBitDataEntry::GetByteArrayLeastSignificantBits()
{
	return ByteArrayValue;
}

bool ULowEntryBitDataEntry::IsByteArrayMostSignificantBits()
{
	return (Type == 113);
}
void ULowEntryBitDataEntry::SetByteArrayMostSignificantBits(const TArray<uint8>& Value, const int32 BitCount)
{
	Type = 113;
	ByteArrayValue = Value;
	IntegerValue = BitCount;
}
TArray<uint8> ULowEntryBitDataEntry::GetByteArrayMostSignificantBits()
{
	return ByteArrayValue;
}

bool ULowEntryBitDataEntry::IsIntegerArrayLeastSignificantBits()
{
	return (Type == 114);
}
void ULowEntryBitDataEntry::SetIntegerArrayLeastSignificantBits(const TArray<int32>& Value, const int32 BitCount)
{
	Type = 114;
	IntegerArrayValue = Value;
	IntegerValue = BitCount;
}
TArray<int32> ULowEntryBitDataEntry::GetIntegerArrayLeastSignificantBits()
{
	return IntegerArrayValue;
}

bool ULowEntryBitDataEntry::IsIntegerArrayMostSignificantBits()
{
	return (Type == 115);
}
void ULowEntryBitDataEntry::SetIntegerArrayMostSignificantBits(const TArray<int32>& Value, const int32 BitCount)
{
	Type = 115;
	IntegerArrayValue = Value;
	IntegerValue = BitCount;
}
TArray<int32> ULowEntryBitDataEntry::GetIntegerArrayMostSignificantBits()
{
	return IntegerArrayValue;
}


bool ULowEntryBitDataEntry::IsByteArray()
{
	return (Type == 101);
}
void ULowEntryBitDataEntry::SetByteArray(const TArray<uint8>& Value)
{
	Type = 101;
	ByteArrayValue = Value;
}
TArray<uint8> ULowEntryBitDataEntry::GetByteArray()
{
	return ByteArrayValue;
}

bool ULowEntryBitDataEntry::IsIntegerArray()
{
	return (Type == 102);
}
void ULowEntryBitDataEntry::SetIntegerArray(const TArray<int32>& Value)
{
	Type = 102;
	IntegerArrayValue = Value;
}
TArray<int32> ULowEntryBitDataEntry::GetIntegerArray()
{
	return IntegerArrayValue;
}

bool ULowEntryBitDataEntry::IsPositiveInteger1Array()
{
	return (Type == 108);
}
void ULowEntryBitDataEntry::SetPositiveInteger1Array(const TArray<int32>& Value)
{
	Type = 108;
	IntegerArrayValue = Value;
}
TArray<int32> ULowEntryBitDataEntry::GetPositiveInteger1Array()
{
	return IntegerArrayValue;
}

bool ULowEntryBitDataEntry::IsPositiveInteger2Array()
{
	return (Type == 109);
}
void ULowEntryBitDataEntry::SetPositiveInteger2Array(const TArray<int32>& Value)
{
	Type = 109;
	IntegerArrayValue = Value;
}
TArray<int32> ULowEntryBitDataEntry::GetPositiveInteger2Array()
{
	return IntegerArrayValue;
}

bool ULowEntryBitDataEntry::IsPositiveInteger3Array()
{
	return (Type == 110);
}
void ULowEntryBitDataEntry::SetPositiveInteger3Array(const TArray<int32>& Value)
{
	Type = 110;
	IntegerArrayValue = Value;
}
TArray<int32> ULowEntryBitDataEntry::GetPositiveInteger3Array()
{
	return IntegerArrayValue;
}

bool ULowEntryBitDataEntry::IsLongBytesArray()
{
	return (Type == 103);
}
void ULowEntryBitDataEntry::SetLongBytesArray(const TArray<ULowEntryLong*>& Value)
{
	Type = 103;
	LongBytesArrayValue = Value;
}
TArray<ULowEntryLong*> ULowEntryBitDataEntry::GetLongBytesArray()
{
	return LongBytesArrayValue;
}


bool ULowEntryBitDataEntry::IsFloatArray()
{
	return (Type == 104);
}
void ULowEntryBitDataEntry::SetFloatArray(const TArray<float>& Value)
{
	Type = 104;
	FloatArrayValue = Value;
}
TArray<float> ULowEntryBitDataEntry::GetFloatArray()
{
	return FloatArrayValue;
}

bool ULowEntryBitDataEntry::IsDoubleBytesArray()
{
	return (Type == 105);
}
void ULowEntryBitDataEntry::SetDoubleBytesArray(const TArray<ULowEntryDouble*>& Value)
{
	Type = 105;
	DoubleBytesArrayValue = Value;
}
TArray<ULowEntryDouble*> ULowEntryBitDataEntry::GetDoubleBytesArray()
{
	return DoubleBytesArrayValue;
}


bool ULowEntryBitDataEntry::IsBooleanArray()
{
	return (Type == 106);
}
void ULowEntryBitDataEntry::SetBooleanArray(const TArray<bool>& Value)
{
	Type = 106;
	BooleanArrayValue = Value;
}
TArray<bool> ULowEntryBitDataEntry::GetBooleanArray()
{
	return BooleanArrayValue;
}

bool ULowEntryBitDataEntry::IsStringUtf8Array()
{
	return (Type == 107);
}
void ULowEntryBitDataEntry::SetStringUtf8Array(const TArray<FString>& Value)
{
	Type = 107;
	StringUtf8ArrayValue = Value;
}
TArray<FString> ULowEntryBitDataEntry::GetStringUtf8Array()
{
	return StringUtf8ArrayValue;
}
