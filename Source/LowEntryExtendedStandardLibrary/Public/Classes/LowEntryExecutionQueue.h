// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "LowEntryExecutionQueue.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryExecutionQueue : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryExecutionQueue* Create();
	static ULowEntryExecutionQueue* Create(const int32 Count, const bool Next);


public:
	UPROPERTY()
	int32 Count = 0;
	UPROPERTY()
	bool Next = false;


	void IncreaseCount();
	void DecreaseCount();
};
