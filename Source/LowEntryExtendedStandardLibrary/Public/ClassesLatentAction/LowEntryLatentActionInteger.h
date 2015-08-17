#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "DelayAction.h"

#include "LowEntryLatentActionInteger.generated.h"


#define LatentActionResultType int32
#define ULatentActionClass ULowEntryLatentActionInteger
#define FLatentActionClass FLowEntryLatentActionInteger


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryLatentActionInteger : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULatentActionClass* Create();


public:
	bool Finished = false;
	LatentActionResultType Result = 0;
	

	/**
	* Waits till the latent action is done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Integer", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Wait Till Done", Keywords = "untill for end finished complete completion"))
		void WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result); // LatentActionResultType

	/**
	* Causes the latent action to be done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Integer", Meta = (DisplayName = "Done", Keywords = "end finished complete completion"))
		void Done(int32 Result); // LatentActionResultType

	/**
	* Returns true if the latent action is done.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Integer", Meta = (DisplayName = "Is Done", Keywords = "end finished complete completion"))
		bool IsDone();

	/**
	* Returns the result.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Integer", Meta = (DisplayName = "Get Result", Keywords = "result return value"))
		void GetResult(int32& Result); // LatentActionResultType
};
