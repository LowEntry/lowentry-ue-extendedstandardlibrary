// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryParsedHashcash.h"


// init >>
	ULowEntryParsedHashcash::ULowEntryParsedHashcash(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryParsedHashcash* ULowEntryParsedHashcash::Create(const bool Valid_, const FString& Resource_, const FDateTime& Date_, const int32 Bits_)
	{
		ULowEntryParsedHashcash* Instance = NewObject<ULowEntryParsedHashcash>();
		Instance->Valid = Valid_;
		Instance->Resource = Resource_;
		Instance->Date = Date_;
		Instance->Bits = Bits_;
		return Instance;
	}
// init <<


bool ULowEntryParsedHashcash::IsHashcashValid()
{
	return Valid;
}

FString ULowEntryParsedHashcash::GetResource()
{
	return Resource;
}

FDateTime ULowEntryParsedHashcash::GetDate()
{
	return Date;
}

int32 ULowEntryParsedHashcash::GetBits()
{
	return Bits;
}


FString ULowEntryParsedHashcash::ToString()
{
	if(!Valid)
	{
		return TEXT("{invalid}");
	}
	return TEXT("{resource=\"") + Resource + TEXT("\", date=\"") + Date.ToString() + TEXT("\", bits=") + FString::FromInt(Bits) + TEXT("}");
}
