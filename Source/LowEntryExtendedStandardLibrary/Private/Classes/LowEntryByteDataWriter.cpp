// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryByteDataWriter.h"
#include "LowEntryByteDataEntry.h"
#include "LowEntryExtendedStandardLibrary.h"


// init >>
	ULowEntryByteDataWriter::ULowEntryByteDataWriter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryByteDataWriter* ULowEntryByteDataWriter::Create()
	{
		return NewObject<ULowEntryByteDataWriter>();
	}
	ULowEntryByteDataWriter* ULowEntryByteDataWriter::CreateFromEntryArray(const TArray<ULowEntryByteDataEntry*>& Array)
	{
		ULowEntryByteDataWriter* Instance = NewObject<ULowEntryByteDataWriter>();
		for(int32 i = 0; i < Array.Num(); i++)
		{
			ULowEntryByteDataEntry* Item = Array[i];
			if(Item != nullptr)
			{
				if(Item->IsByte())
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


void ULowEntryByteDataWriter::AddRawByte(const uint8 Value)
{
	Bytes.Add(Value);
}

void ULowEntryByteDataWriter::AddRawBytes(const TArray<uint8>& Value)
{
	Bytes.Append(Value);
}


TArray<uint8> ULowEntryByteDataWriter::GetBytes()
{
	return Bytes;
}


void ULowEntryByteDataWriter::AddByte(const uint8 Value)
{
	AddRawByte(Value);
}
void ULowEntryByteDataWriter::AddInteger(const int32 Value)
{
	AddRawByte(Value >> 24);
	AddRawByte(Value >> 16);
	AddRawByte(Value >> 8);
	AddRawByte(Value);
}
void ULowEntryByteDataWriter::AddUinteger(const int32 Value)
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
void ULowEntryByteDataWriter::AddPositiveInteger1(const int32 Value)
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
void ULowEntryByteDataWriter::AddPositiveInteger2(const int32 Value)
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
void ULowEntryByteDataWriter::AddPositiveInteger3(const int32 Value)
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
void ULowEntryByteDataWriter::AddLongBytes(ULowEntryLong* Value)
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
void ULowEntryByteDataWriter::AddFloat(const float Value)
{
	AddRawBytes(ULowEntryExtendedStandardLibrary::FloatToBytes(Value));
}
void ULowEntryByteDataWriter::AddDoubleBytes(ULowEntryDouble* Value)
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
void ULowEntryByteDataWriter::AddBoolean(const bool Value)
{
	if(Value)
	{
		AddRawByte(0x01);
	}
	else
	{
		AddRawByte(0x00);
	}
}
void ULowEntryByteDataWriter::AddStringUtf8(const FString& Value)
{
	AddByteArray(ULowEntryExtendedStandardLibrary::StringToBytesUtf8(Value));
}


void ULowEntryByteDataWriter::AddByteArray(const TArray<uint8>& Value)
{
	AddUinteger(Value.Num());
	AddRawBytes(Value);
}
void ULowEntryByteDataWriter::AddIntegerArray(const TArray<int32>& Value)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddInteger(V);
	}
}
void ULowEntryByteDataWriter::AddPositiveInteger1Array(const TArray<int32>& Value)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddPositiveInteger1(V);
	}
}
void ULowEntryByteDataWriter::AddPositiveInteger2Array(const TArray<int32>& Value)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddPositiveInteger2(V);
	}
}
void ULowEntryByteDataWriter::AddPositiveInteger3Array(const TArray<int32>& Value)
{
	AddUinteger(Value.Num());
	for(int32 V : Value)
	{
		AddPositiveInteger3(V);
	}
}
void ULowEntryByteDataWriter::AddLongBytesArray(const TArray<ULowEntryLong*>& Value)
{
	AddUinteger(Value.Num());
	for(ULowEntryLong* V : Value)
	{
		AddLongBytes(V);
	}
}
void ULowEntryByteDataWriter::AddFloatArray(const TArray<float>& Value)
{
	AddUinteger(Value.Num());
	for(float V : Value)
	{
		AddFloat(V);
	}
}
void ULowEntryByteDataWriter::AddDoubleBytesArray(const TArray<ULowEntryDouble*>& Value)
{
	AddUinteger(Value.Num());
	for(ULowEntryDouble* V : Value)
	{
		AddDoubleBytes(V);
	}
}
void ULowEntryByteDataWriter::AddBooleanArray(const TArray<bool>& Value)
{
	AddUinteger(Value.Num());
	uint8 B = 0;
	int32 BIndex = 0;
	for(bool V : Value)
	{
		if(V)
		{
			B |= (1 << (7 - BIndex));
		}
		BIndex++;
		if(BIndex == 8)
		{
			AddRawByte(B);
			B = 0;
			BIndex = 0;
		}
	}
	if(BIndex > 0)
	{
		AddRawByte(B);
	}
}
void ULowEntryByteDataWriter::AddStringUtf8Array(const TArray<FString>& Value)
{
	AddUinteger(Value.Num());
	for(FString V : Value)
	{
		AddStringUtf8(V);
	}
}
