#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "Json.h"

#include "LowEntryLong.h"
#include "LowEntryDouble.h"

#include "LowEntryByteArray.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryByteArray : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryByteArray* CreateFromByteArray(const TArray<uint8>& Value);


public:
	TArray<uint8> ByteArray;
};
