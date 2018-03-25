// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "DelayAction.h"

#include "LowEntryLatentActionFloat.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryLatentActionFloat : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryLatentActionFloat* Create();


public:
	UPROPERTY()
	bool Finished = false;
	UPROPERTY()
	float Result = 0;

	UPROPERTY()
	int32 KeepAliveCount = 0;
	

	/**
	* Waits till the latent action is done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Float", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Wait Till Done", Keywords = "untill for end finished complete completion"))
		void WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result_);

	void LatentActionDone();

	/**
	* Causes the latent action to be done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Float", Meta = (DisplayName = "Done", Keywords = "end finished complete completion"))
		void Done(float Result_);

	/**
	* Returns true if the latent action is done.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Float", Meta = (DisplayName = "Is Done", Keywords = "end finished complete completion"))
		bool IsDone();

	/**
	* Returns the result.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Float", Meta = (DisplayName = "Get Result", Keywords = "result return value"))
		void GetResult(float& Result_);
};
