#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryLong.h"


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
