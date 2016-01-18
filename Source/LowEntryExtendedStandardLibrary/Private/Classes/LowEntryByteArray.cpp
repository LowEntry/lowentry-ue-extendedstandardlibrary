#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryByteArray.h"


// init >>
	ULowEntryByteArray::ULowEntryByteArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryByteArray* ULowEntryByteArray::CreateFromByteArray(const TArray<uint8>& Value)
	{
		ULowEntryByteArray* Instance = NewObject<ULowEntryByteArray>();
		Instance->ByteArray = Value;
		return Instance;
	}
// init <<
