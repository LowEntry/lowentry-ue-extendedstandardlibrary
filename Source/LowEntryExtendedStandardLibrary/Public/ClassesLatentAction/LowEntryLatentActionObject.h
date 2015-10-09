#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "DelayAction.h"

#include "LowEntryLatentActionObject.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryLatentActionObject : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryLatentActionObject* Create();


public:
	bool Finished = false;
	UObject* Result = NULL;
	

	/**
	* Waits till the latent action is done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Object", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Wait Till Done", Keywords = "untill for end finished complete completion"))
		void WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, UObject*& Result);

	/**
	* Causes the latent action to be done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Object", Meta = (DisplayName = "Done", Keywords = "end finished complete completion"))
		void Done(UObject* Result);

	/**
	* Returns true if the latent action is done.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Object", Meta = (DisplayName = "Is Done", Keywords = "end finished complete completion"))
		bool IsDone();

	/**
	* Returns the result.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Object", Meta = (DisplayName = "Get Result", Keywords = "result return value"))
		void GetResult(UObject*& Result);
};
