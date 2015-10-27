#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryDouble.h"


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
