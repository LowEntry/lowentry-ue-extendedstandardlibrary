#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryByteDataWriter.h"
#include "LowEntryExtendedStandardLibrary.h"


// init >>
	ULowEntryByteDataWriter::ULowEntryByteDataWriter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryByteDataWriter* ULowEntryByteDataWriter::Create()
	{
		return NewObject<ULowEntryByteDataWriter>();
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
	AddRawBytes(ULowEntryExtendedStandardLibrary::IntegerToBytes(Value));
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
	AddByteArray(ULowEntryExtendedStandardLibrary::BooleanToBytes(Value));
}
void ULowEntryByteDataWriter::AddStringUtf8(const FString& Value)
{
	AddByteArray(ULowEntryExtendedStandardLibrary::StringToBytesUtf8(Value));
}


void ULowEntryByteDataWriter::AddByteArray(const TArray<uint8>& Value)
{
	AddInteger(Value.Num());
	AddRawBytes(Value);
}
void ULowEntryByteDataWriter::AddIntegerArray(const TArray<int32>& Value)
{
	AddInteger(Value.Num());
	for(int32 V : Value)
	{
		AddInteger(V);
	}
}
void ULowEntryByteDataWriter::AddLongBytesArray(const TArray<ULowEntryLong*>& Value)
{
	AddInteger(Value.Num());
	for(ULowEntryLong* V : Value)
	{
		AddLongBytes(V);
	}
}
void ULowEntryByteDataWriter::AddFloatArray(const TArray<float>& Value)
{
	AddInteger(Value.Num());
	for(float V : Value)
	{
		AddFloat(V);
	}
}
void ULowEntryByteDataWriter::AddDoubleBytesArray(const TArray<ULowEntryDouble*>& Value)
{
	AddInteger(Value.Num());
	for(ULowEntryDouble* V : Value)
	{
		AddDoubleBytes(V);
	}
}
void ULowEntryByteDataWriter::AddBooleanArray(const TArray<bool>& Value)
{
	AddInteger(Value.Num());
	for(bool V : Value)
	{
		AddBoolean(V);
	}
}
void ULowEntryByteDataWriter::AddStringUtf8Array(const TArray<FString>& Value)
{
	AddInteger(Value.Num());
	for(FString V : Value)
	{
		AddStringUtf8(V);
	}
}
