// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "LowEntryByteArray.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryByteArray : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryByteArray* CreateFromByteArray(const TArray<uint8>& Value);


public:
	UPROPERTY()
	TArray<uint8> ByteArray;
};
