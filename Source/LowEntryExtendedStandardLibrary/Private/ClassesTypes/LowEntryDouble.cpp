// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryDouble.h"
#include "LowEntryLong.h"
#include "LowEntryExtendedStandardLibrary.h"


// init >>
	ULowEntryDouble::ULowEntryDouble(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		Bytes.SetNumZeroed(8);
	}

	ULowEntryDouble* ULowEntryDouble::Create()
	{
		return NewObject<ULowEntryDouble>();
	}

	ULowEntryDouble* ULowEntryDouble::Create(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
	{
		ULowEntryDouble* Item = NewObject<ULowEntryDouble>();
		Item->SetBytes(ByteArray, Index, Length);
		return Item;
	}
// init <<


TArray<uint8> ULowEntryDouble::GetDefaultBytes()
{
	TArray<uint8> Bytes;
	Bytes.SetNumZeroed(8);
	return Bytes;
}


TArray<uint8> ULowEntryDouble::GetBytes()
{
	return Bytes;
}

void ULowEntryDouble::SetBytes(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}

	if(Length >= 8)
	{
		for(int32 i = 0; i < 8; i++)
		{
			Bytes[i] = ByteArray[Index + i];
		}
	}
	else
	{
		for(int32 i = Length; i < 8; i++)
		{
			Bytes[i] = 0;
		}
		for(int32 i = 0; i < Length; i++)
		{
			Bytes[i] = ByteArray[Index + i];
		}
	}
}


double ULowEntryDouble::GetDouble()
{
	return ULowEntryExtendedStandardLibrary::BytesToDouble(Bytes);
}

void ULowEntryDouble::SetDouble(const double Value)
{
	Bytes = ULowEntryExtendedStandardLibrary::DoubleToBytes(Value);
}


ULowEntryDouble* ULowEntryDouble::CreateClone()
{
	return ULowEntryDouble::Create(Bytes);
}

ULowEntryLong* ULowEntryDouble::CastToLongBytes()
{
	return ULowEntryExtendedStandardLibrary::BytesToLongBytes(ULowEntryExtendedStandardLibrary::LongToBytes((int64) GetDouble()));
}

FString ULowEntryDouble::CastToString(const int32 MinFractionalDigits)
{
	return FString::SanitizeFloat(GetDouble(), MinFractionalDigits);
}


void ULowEntryDouble::Float_Add(const float Value)
{
	SetDouble(GetDouble() + Value);
}

void ULowEntryDouble::Float_Subtract(const float Value)
{
	SetDouble(GetDouble() - Value);
}


bool ULowEntryDouble::Float_Equals(const float Value)
{
	return (GetDouble() == Value);
}

bool ULowEntryDouble::Float_GreaterThan(const float Value)
{
	return (GetDouble() > Value);
}

bool ULowEntryDouble::Float_LessThan(const float Value)
{
	return (GetDouble() < Value);
}

bool ULowEntryDouble::Integer_GreaterThan(const int32 Value)
{
	return (GetDouble() > Value);
}

bool ULowEntryDouble::Integer_LessThan(const int32 Value)
{
	return (GetDouble() < Value);
}


void ULowEntryDouble::DoubleBytes_Add(ULowEntryDouble* Value)
{
	SetDouble(GetDouble() + ((Value == nullptr) ? 0 : Value->GetDouble()));
}

void ULowEntryDouble::DoubleBytes_Subtract(ULowEntryDouble* Value)
{
	SetDouble(GetDouble() - ((Value == nullptr) ? 0 : Value->GetDouble()));
}


bool ULowEntryDouble::DoubleBytes_Equals(ULowEntryDouble* Value)
{
	return (GetDouble() == ((Value == nullptr) ? 0 : Value->GetDouble()));
}

bool ULowEntryDouble::DoubleBytes_GreaterThan(ULowEntryDouble* Value)
{
	return (GetDouble() > ((Value == nullptr) ? 0 : Value->GetDouble()));
}

bool ULowEntryDouble::DoubleBytes_LessThan(ULowEntryDouble* Value)
{
	return (GetDouble() < ((Value == nullptr) ? 0 : Value->GetDouble()));
}

bool ULowEntryDouble::LongBytes_GreaterThan(ULowEntryLong* Value)
{
	return (GetDouble() > ((Value == nullptr) ? 0 : Value->GetLong()));
}

bool ULowEntryDouble::LongBytes_LessThan(ULowEntryLong* Value)
{
	return (GetDouble() < ((Value == nullptr) ? 0 : Value->GetLong()));
}
