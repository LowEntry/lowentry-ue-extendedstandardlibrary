// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryLong.h"
#include "LowEntryDouble.h"
#include "LowEntryExtendedStandardLibrary.h"


// init >>
	ULowEntryLong::ULowEntryLong(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		Bytes.SetNumZeroed(8);
	}

	ULowEntryLong* ULowEntryLong::Create()
	{
		return NewObject<ULowEntryLong>();
	}

	ULowEntryLong* ULowEntryLong::Create(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
	{
		ULowEntryLong* Item = NewObject<ULowEntryLong>();
		Item->SetBytes(ByteArray, Index, Length);
		return Item;
	}
// init <<


TArray<uint8> ULowEntryLong::GetDefaultBytes()
{
	TArray<uint8> Bytes;
	Bytes.SetNumZeroed(8);
	return Bytes;
}


TArray<uint8> ULowEntryLong::GetBytes()
{
	return Bytes;
}

void ULowEntryLong::SetBytes(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
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


int64 ULowEntryLong::GetLong()
{
	return ULowEntryExtendedStandardLibrary::BytesToLong(Bytes);
}

void ULowEntryLong::SetLong(const int64 Value)
{
	Bytes = ULowEntryExtendedStandardLibrary::LongToBytes(Value);
}


ULowEntryLong* ULowEntryLong::CreateClone()
{
	return ULowEntryLong::Create(Bytes);
}

ULowEntryDouble* ULowEntryLong::CastToDoubleBytes()
{
	return ULowEntryExtendedStandardLibrary::BytesToDoubleBytes(ULowEntryExtendedStandardLibrary::DoubleToBytes((double) GetLong()));
}

FString ULowEntryLong::CastToString()
{
	return FString::Printf(TEXT("%lld"), GetLong());
}


void ULowEntryLong::Integer_Add(const int32 Value)
{
	SetLong(GetLong() + Value);
}

void ULowEntryLong::Integer_Subtract(const int32 Value)
{
	SetLong(GetLong() - Value);
}


bool ULowEntryLong::Integer_Equals(const int32 Value)
{
	return (GetLong() == Value);
}

bool ULowEntryLong::Integer_GreaterThan(const int32 Value)
{
	return (GetLong() > Value);
}

bool ULowEntryLong::Integer_LessThan(const int32 Value)
{
	return (GetLong() < Value);
}

bool ULowEntryLong::Float_GreaterThan(const float Value)
{
	return (GetLong() > Value);
}

bool ULowEntryLong::Float_LessThan(const float Value)
{
	return (GetLong() < Value);
}


void ULowEntryLong::LongBytes_Add(ULowEntryLong* Value)
{
	SetLong(GetLong() + ((Value == nullptr) ? 0 : Value->GetLong()));
}

void ULowEntryLong::LongBytes_Subtract(ULowEntryLong* Value)
{
	SetLong(GetLong() - ((Value == nullptr) ? 0 : Value->GetLong()));
}


bool ULowEntryLong::LongBytes_Equals(ULowEntryLong* Value)
{
	return (GetLong() == ((Value == nullptr) ? 0 : Value->GetLong()));
}

bool ULowEntryLong::LongBytes_GreaterThan(ULowEntryLong* Value)
{
	return (GetLong() > ((Value == nullptr) ? 0 : Value->GetLong()));
}

bool ULowEntryLong::LongBytes_LessThan(ULowEntryLong* Value)
{
	return (GetLong() < ((Value == nullptr) ? 0 : Value->GetLong()));
}

bool ULowEntryLong::DoubleBytes_GreaterThan(ULowEntryDouble* Value)
{
	return (GetLong() > ((Value == nullptr) ? 0 : Value->GetDouble()));
}

bool ULowEntryLong::DoubleBytes_LessThan(ULowEntryDouble* Value)
{
	return (GetLong() < ((Value == nullptr) ? 0 : Value->GetDouble()));
}
