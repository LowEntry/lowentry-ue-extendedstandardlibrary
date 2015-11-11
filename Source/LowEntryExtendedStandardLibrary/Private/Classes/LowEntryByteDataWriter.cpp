#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
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
