// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "DelayAction.h"

#include "LowEntryLatentActionBoolean.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryLatentActionBoolean : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryLatentActionBoolean* Create();


public:
	UPROPERTY()
	bool Finished = false;
	UPROPERTY()
	bool Result = false;

	UPROPERTY()
	int32 KeepAliveCount = 0;
	

	/**
	* Waits till the latent action is done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Boolean", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Wait Till Done", Keywords = "untill for end finished complete completion"))
		void WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result_);

	void LatentActionDone();

	/**
	* Causes the latent action to be done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Boolean", Meta = (DisplayName = "Done", Keywords = "end finished complete completion"))
		void Done(bool Result_);

	/**
	* Returns true if the latent action is done.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Boolean", Meta = (DisplayName = "Is Done", Keywords = "end finished complete completion"))
		bool IsDone();

	/**
	* Returns the result.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Boolean", Meta = (DisplayName = "Get Result", Keywords = "result return value"))
		void GetResult(bool& Result_);
};
