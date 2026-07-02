// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "DelayAction.h"
#include "StructUtils/InstancedStruct.h"

#include "LowEntryLatentActionStruct.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryLatentActionStruct : public UObject
{
	GENERATED_UCLASS_BODY()
public:
	static ULowEntryLatentActionStruct* Create();


public:
	UPROPERTY()
	bool Finished = false;
	UPROPERTY()
	FInstancedStruct Result;

	UPROPERTY()
	int32 KeepAliveCount = 0;


	/**
	* Waits till the latent action is done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Struct", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Wait Till Done", Keywords = "untill for end finished complete completion"))
	void WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FInstancedStruct& Result_);

	void LatentActionDone();

	/**
	* Causes the latent action to be done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Struct", Meta = (DisplayName = "Done", Keywords = "end finished complete completion"))
	void Done(const FInstancedStruct& Result_);

	/**
	* Returns true if the latent action is done.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Struct", Meta = (DisplayName = "Is Done", Keywords = "end finished complete completion"))
	bool IsDone();

	/**
	* Returns the result.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Struct", Meta = (DisplayName = "Get Result", Keywords = "result return value"))
	void GetResult(FInstancedStruct& Result_);
};
