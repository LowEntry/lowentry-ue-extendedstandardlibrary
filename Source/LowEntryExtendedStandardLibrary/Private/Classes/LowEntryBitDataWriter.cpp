// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryBitDataWriter.h"
#include "LowEntryBitDataEntry.h"
#include "LowEntryExtendedStandardLibrary.h"


const uint8 ULowEntryBitDataWriter::mask[9] = {((uint8) 0x00), ((uint8) 0x01), ((uint8) 0x03), ((uint8) 0x07), ((uint8) 0x0F), ((uint8) 0x1F), ((uint8) 0x3F), ((uint8) 0x7F), ((uint8) 0xFF)};


// init >>
	ULowEntryBitDataWriter::ULowEntryBitDataWriter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryBitDataWriter* ULowEntryBitDataWriter::Create()
	{
		return NewObject<ULowEntryBitDataWriter>();
	}
	ULowEntryBitDataWriter* ULowEntryBitDataWriter::CreateFromEntryArray(const TArray<ULowEntryBitDataEntry*>& Array)
	{
		ULowEntryBitDataWriter* Instance = NewObject<ULowEntryBitDataWriter>();
		for(int32 i = 0; i < Array.Num(); i++)
		{
			ULowEntryBitDataEntry* Item = Array[i];
			if(Item != nullptr)
			{
				if(Item->IsBit())
				{
					Instance->AddBit(Item->GetBit());
				}
				else if(Item->IsByteLeastSignificantBits())
				{
					Instance->AddByteLeastSignificantBits(Item->GetByteLeastSignificantBits(), Item->GetBitCount());
				}
				else if(Item->IsByteMostSignificantBits())
				{
					Instance->AddByteMostSignificantBits(Item->GetByteMostSignificantBits(), Item->GetBitCount());
				}
				else if(Item->IsIntegerLeastSignificantBits())
				{
					Instance->AddIntegerLeastSignificantBits(Item->GetIntegerLeastSignificantBits(), Item->GetBitCount());
				}
				else if(Item->IsIntegerMostSignificantBits())
				{
					Instance->AddIntegerMostSignificantBits(Item->GetIntegerMostSignificantBits(), Item->GetBitCount());
				}
				else if(Item->IsByte())
				{
					Instance->AddByte(Item->GetByte());
				}
				else if(Item->IsInteger())
				{
					Instance->AddInteger(Item->GetInteger());
				}
				else if(Item->IsPositiveInteger1())
				{
					Instance->AddPositiveInteger1(Item->GetPositiveInteger1());
				}
				else if(Item->IsPositiveInteger2())
				{
					Instance->AddPositiveInteger2(Item->GetPositiveInteger2());
				}
				else if(Item->IsPositiveInteger3())
				{
					Instance->AddPositiveInteger3(Item->GetPositiveInteger3());
				}
				else if(Item->IsLongBytes())
				{
					Instance->AddLongBytes(Item->GetLongBytes());
				}
				else if(Item->IsFloat())
				{
					Instance->AddFloat(Item->GetFloat());
				}
				else if(Item->IsDoubleBytes())
				{
					Instance->AddDoubleBytes(Item->GetDoubleBytes());
				}
				else if(Item->IsBoolean())
				{
					Instance->AddBoolean(Item->GetBoolean());
				}
				else if(Item->IsStringUtf8())
				{
					Instance->AddStringUtf8(Item->GetStringUtf8());
				}

				else if(Item->IsBitArray())
				{
					Instance->AddBitArray(Item->GetBitArray());
				}
				else if(Item->IsByteArrayLeastSignificantBits())
				{
					Instance->AddByteArrayLeastSignificantBits(Item->GetByteArrayLeastSignificantBits(), Item->GetBitCount());
				}
				else if(Item->IsByteArrayMostSignificantBits())
				{
					Instance->AddByteArrayMostSignificantBits(Item->GetByteArrayMostSignificantBits(), Item->GetBitCount());
				}
				else if(Item->IsIntegerArrayLeastSignificantBits())
				{
					Instance->AddIntegerArrayLeastSignificantBits(Item->GetIntegerArrayLeastSignificantBits(), Item->GetBitCount());
				}
				else if(Item->IsIntegerArrayMostSignificantBits())
				{
					Instance->AddIntegerArrayMostSignificantBits(Item->GetIntegerArrayMostSignificantBits(), Item->GetBitCount());
				}
				else if(Item->IsByteArray())
				{
					Instance->AddByteArray(Item->GetByteArray());
				}
				else if(Item->IsIntegerArray())
				{
					Instance->AddIntegerArray(Item->GetIntegerArray());
				}
				else if(Item->IsPositiveInteger1Array())
				{
					Instance->AddPositiveInteger1Array(Item->GetPositiveInteger1Array());
				}
				else if(Item->IsPositiveInteger2Array())
				{
					Instance->AddPositiveInteger2Array(Item->GetPositiveInteger2Array());
				}
				else if(Item->IsPositiveInteger3Array())
				{
					Instance->AddPositiveInteger3Array(Item->GetPositiveInteger3Array());
				}
				else if(Item->IsLongBytesArray())
				{
					Instance->AddLongBytesArray(Item->GetLongBytesArray());
				}
				else if(Item->IsFloatArray())
				{
					Instance->AddFloatArray(Item->GetFloatArray());
				}
				else if(Item->IsDoubleBytesArray())
				{
					Instance->AddDoubleBytesArray(Item->GetDoubleBytesArray());
				}
				else if(Item->IsBooleanArray())
				{
					Instance->AddBooleanArray(Item->GetBooleanArray());
				}
				else if(Item->IsStringUtf8Array())
				{
					Instance->AddStringUtf8Array(Item->GetStringUtf8Array());
				}
			}
		}
		return Instance;
	}
// init <<


void ULowEntryBitDataWriter::AddRawBit(const bool Value)
{
	if(Value)
	{
		CurrentByte |= (1 << CurrentBytePosition);
	}

	if(CurrentBytePosition == 7)
	{
		Bytes.Add(CurrentByte);
		CurrentByte = 0;
		CurrentBytePosition = 0;
	}
	else
	{
		CurrentBytePosition++;
	}
}

void ULowEntryBitDataWriter::AddRawByte(const uint8 Value)
{
	if(CurrentBytePosition == 0)
	{
		Bytes.Add(Value);
	}
	else
	{
		CurrentByte |= (Value << CurrentBytePosition);
		Bytes.Add(CurrentByte);
		CurrentByte = (uint8) ((Value >> (8 - CurrentBytePosition)) & mask[CurrentBytePosition]);
	}
}

void ULowEntryBitDataWriter::AddPartialRawByte(uint8 Value, int32 Bits)
{
	if(Bits == 0)
	{
		return;
	}
	if((Bits >= 8) || (Bits <= -8))
	{
		AddRawByte(Value);
		return;
	}

	if(Bits < 0)
	{
		Bits = -Bits;
		Value >>= (8 - Bits);
	}

	Value &= mask[Bits];

	CurrentByte |= (Value << CurrentBytePosition);
	CurrentBytePosition += Bits;

	if(CurrentBytePosition >= 8)
	{
		Bytes.Add(CurrentByte);
		CurrentBytePosition -= 8;
		if(CurrentBytePosition == 0)
		{
			CurrentByte = 0;
		}
		else
		{
			CurrentByte = (uint8) (Value >> (Bits - CurrentBytePosition)); // b is already masked
		}
	}
}

void ULowEntryBitDataWriter::AddRawBytes(const TArray<uint8>& Value)
{
	if(CurrentBytePosition == 0)
	{
		Bytes.Append(Value);
	}
	else
	{
		for(uint8 V : Value)
		{
			AddRawByte(V);
		}
	}
}


TArray<uint8> ULowEntryBitDataWriter::GetBytes()
{
	if(CurrentBytePosition == 0)
	{
		return Bytes;
	}
	else
	{
		TArray<uint8> Data = Bytes;
		Data.Add(CurrentByte);
		return Data;
	}
}


void ULowEntryBitDataWriter::AddBit(const bool Value)
{
	AddRawBit(Value);
}
void ULowEntryBitDataWriter::AddByteLeastSignificantBits(const uint8 Value, const int32 BitCount)
{
	if(BitCount > 0)
	{
		AddPartialRawByte(Value, BitCount);
	}
}
void ULowEntryBitDataWriter::AddByteMostSignificantBits(const uint8 Value, const int32 BitCount)
{
	if(BitCount > 0)
	{
		AddPartialRawByte(Value, -BitCount);
	}
}
void ULowEntryBitDataWriter::AddIntegerLeastSignificantBits(const int32 Value, const int32 BitCount)
{
	if(BitCount > 0)
	{
		if(BitCount >= 32)
		{
			AddRawByte(Value);
			AddRawByte(Value >> 8);
			AddRawByte(Value >> 16);
			AddRawByte(Value >> 24);
		}
		else if(BitCount > 24)
		{
			AddRawByte(Value);
			AddRawByte(Value >> 8);
			AddRawByte(Value >> 16);
			AddPartialRawByte((Value >> 24), (BitCount - 24));
		}
		else if(BitCount > 16)
		{
			AddRawByte(Value);
			AddRawByte(Value >> 8);
			AddPartialRawByte((Value >> 16), (BitCount - 16));
		}
		else if(BitCount > 8)
		{
			AddRawByte(Value);
			AddPartialRawByte((Value >> 8), (BitCount - 8));
		}
		else
		{
			AddPartialRawByte(Value, BitCount);
		}
	}
}
void ULowEntryBitDataWriter::AddIntegerMostSignificantBits(const int32 Value, int32 BitCount)
{
	if(BitCount > 0)
	{
		BitCount = -BitCount;
		if(BitCount <= -32)
		{
			AddRawByte(Value);
			AddRawByte(Value >> 8);
			AddRawByte(Value >> 16);
			AddRawByte(Value >> 24);
		}
		else if(BitCount < -24)
		{
			AddPartialRawByte((Value), (BitCount + 24));
			AddRawByte(Value >> 8);
			AddRawByte(Value >> 16);
			AddRawByte(Value >> 24);
		}
		else if(BitCount < -16)
		{
			AddPartialRawByte((Value >> 8), (BitCount + 16));
			AddRawByte(Value >> 16);
			AddRawByte(Value >> 24);
		}
		else if(BitCount < -8)
		{
			AddPartialRawByte((Value >> 16), (BitCount + 8));
			AddRawByte(Value >> 24);
		}
		else
		{
			AddPartialRawByte((Value >> 24), BitCount);
		}
	}
}
void ULowEntryBitDataWriter::AddByte(const uint8 Value)
{
	AddRawByte(Value);
}
void ULowEntryBitDataWriter::AddInteger(const int32 Value)
{
	AddRawByte(Value >> 24);
	AddRawByte(Value >> 16);
	AddRawByte(Value >> 8);
	AddRawByte(Value);
}
void ULowEntryBitDataWriter::AddUinteger(const int32 Value)
{
	if(Value <= 0)
	{
		AddRawByte(0);
	}
	else if(Value < 128)
	{
		AddRawByte(Value);
	}
	else
	{
		AddRawByte((Value >> 24) | (1 << 7));
		AddRawByte(Value >> 16);
		AddRawByte(Value >> 8);
		AddRawByte(Value);
	}
}
void ULowEntryBitDataWriter::AddPositiveInteger1(const int32 Value)
{
	if(Value <= 0)
	{
		AddRawByte(0);
	}
	else if(Value < 128)
	{
		AddRawByte(Value);
	}
	else
	{
		AddRawByte((Value >> 24) | (1 << 7));
		AddRawByte(Value >> 16);
		AddRawByte(Value >> 8);
		AddRawByte(Value);
	}
}
void ULowEntryBitDataWriter::AddPositiveInteger2(const int32 Value)
{
	if(Value <= 0)
	{
		AddRawByte(0);
		AddRawByte(0);
	}
	else if(Value < 32768)
	{
		AddRawByte(Value >> 8);
		AddRawByte(Value);
	}
	else
	{
		AddRawByte((Value >> 24) | (1 << 7));
		AddRawByte(Value >> 16);
		AddRawByte(Value >> 8);
		AddRawByte(Value);
	}
}
void ULowEntryBitDataWriter::AddPositiveInteger3(const int32 Value)
{
	if(Value <= 0)
	{
		AddRawByte(0);
		AddRawByte(0);
		AddRawByte(0);
	}
	else if(Value < 8388608)
	{
		AddRawByte(Value >> 16);
		AddRawByte(Value >> 8);
		AddRawByte(Value);
	}
	else
	{
		AddRawByte((Value >> 24) | (1 << 7));
		AddRawByte(Value >> 16);
		AddRawByte(Value >> 8);
		AddRawByte(Value);
	}
}
void ULowEntryBitDataWriter::AddLongBytes(ULowEntryLong* Value)
{
	if(Value != nullptr)
	{
		AddRawBytes(Value->Bytes);
	}
	else
	{
		AddRawBytes(ULowEntryLong::GetDefaultBytes());
	}
}
void ULowEntryBitDataWriter::AddFloat(const float Value)
{
	AddRawBytes(ULowEntryExtendedStandardLibrary::FloatToBytes(Value));
}
void ULowEntryBitDataWriter::AddDoubleBytes(ULowEntryDouble* Value)
{
	if(Value != nullptr)
	{
		AddRawBytes(Value->Bytes);
	}
	else
	{
		AddRawBytes(ULowEntryDouble::GetDefaultBytes());
	}
}
void ULowEntryBitDataWriter::AddBoolean(const bool Value)
{
	AddRawBit(Value);
}
void ULowEntryBitDataWriter::AddStringUtf8(const FString& Value)
{
	AddByteArray(ULowEntryExtendedStandardLibrary::StringToBytesUtf8(Value));
}


void ULowEntryBitDataWriter::AddBitArray(const TArray<bool>& Value)
{
	AddUinteger(Value.Num());
	for(bool V : Value)
	{
		AddBit(V);
	}
}
void ULowEntryBitDataWriter::AddByteArrayLeastSignificantBits(const TArray<uint8>& Value, const int32 BitCount)
{
	AddUinteger(Value.Num());
	for(uint8 V : Value)
	{
		AddByteLeastSignificantBits(V, BitCount);
	}
}
void ULowEntryBitDataWriter::AddByteArrayMostSignificantBits(const TArray<uint8>& Value, const int32 BitCount)
{
	AddUinteger(Value.Num());
	for(uint8 V : Value)
	{
		AddByteMostSignificantBits(V, BitCount);
	}
}
void ULowEntryBitDataWriter::AddIntegerArrayLeastSignificantBits(const TArray<int32>& Value, const int32 BitCount)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddIntegerLeastSignificantBits(V, BitCount);
	}
}
void ULowEntryBitDataWriter::AddIntegerArrayMostSignificantBits(const TArray<int32>& Value, const int32 BitCount)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddIntegerMostSignificantBits(V, BitCount);
	}
}
void ULowEntryBitDataWriter::AddByteArray(const TArray<uint8>& Value)
{
	AddUinteger(Value.Num());
	AddRawBytes(Value);
}
void ULowEntryBitDataWriter::AddIntegerArray(const TArray<int32>& Value)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddInteger(V);
	}
}
void ULowEntryBitDataWriter::AddPositiveInteger1Array(const TArray<int32>& Value)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddPositiveInteger1(V);
	}
}
void ULowEntryBitDataWriter::AddPositiveInteger2Array(const TArray<int32>& Value)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddPositiveInteger2(V);
	}
}
void ULowEntryBitDataWriter::AddPositiveInteger3Array(const TArray<int32>& Value)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddPositiveInteger3(V);
	}
}
void ULowEntryBitDataWriter::AddLongBytesArray(const TArray<ULowEntryLong*>& Value)
{
	AddUinteger(Value.Num());
	for(ULowEntryLong* V : Value)
	{
		AddLongBytes(V);
	}
}
void ULowEntryBitDataWriter::AddFloatArray(const TArray<float>& Value)
{
	AddUinteger(Value.Num());
	for(float V : Value)
	{
		AddFloat(V);
	}
}
void ULowEntryBitDataWriter::AddDoubleBytesArray(const TArray<ULowEntryDouble*>& Value)
{
	AddUinteger(Value.Num());
	for(ULowEntryDouble* V : Value)
	{
		AddDoubleBytes(V);
	}
}
void ULowEntryBitDataWriter::AddBooleanArray(const TArray<bool>& Value)
{
	AddUinteger(Value.Num());
	for(bool V : Value)
	{
		AddBoolean(V);
	}
}
void ULowEntryBitDataWriter::AddStringUtf8Array(const TArray<FString>& Value)
{
	AddUinteger(Value.Num());
	for(FString V : Value)
	{
		AddStringUtf8(V);
	}
}
