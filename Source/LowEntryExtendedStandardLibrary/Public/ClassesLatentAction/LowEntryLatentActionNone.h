// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "DelayAction.h"

#include "LowEntryLatentActionNone.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryLatentActionNone : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryLatentActionNone* Create();


public:
	UPROPERTY()
	bool Finished = false;

	UPROPERTY()
	int32 KeepAliveCount = 0;


	/**
	* Waits till the latent action is done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|None", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Wait Till Done", Keywords = "untill for end finished complete completion"))
		void WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo);

	void LatentActionDone();

	/**
	* Causes the latent action to be done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|None", Meta = (DisplayName = "Done", Keywords = "end finished complete completion"))
		void Done();

	/**
	* Returns true if the latent action is done.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|None", Meta = (DisplayName = "Is Done", Keywords = "end finished complete completion"))
		bool IsDone();
};
