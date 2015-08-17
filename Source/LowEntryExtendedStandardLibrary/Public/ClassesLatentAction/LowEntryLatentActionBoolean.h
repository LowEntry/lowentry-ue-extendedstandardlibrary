#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "DelayAction.h"

#include "LowEntryLatentActionBoolean.generated.h"


#define LatentActionResultType bool
#define ULatentActionClass ULowEntryLatentActionBoolean
#define FLatentActionClass FLowEntryLatentActionBoolean


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryLatentActionBoolean : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULatentActionClass* Create();


public:
	bool Finished = false;
	LatentActionResultType Result = false;
	

	/**
	* Waits till the latent action is done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Boolean", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Wait Till Done", Keywords = "untill for end finished complete completion"))
		void WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result); // LatentActionResultType

	/**
	* Causes the latent action to be done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Boolean", Meta = (DisplayName = "Done", Keywords = "end finished complete completion"))
		void Done(bool Result); // LatentActionResultType

	/**
	* Returns true if the latent action is done.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Boolean", Meta = (DisplayName = "Is Done", Keywords = "end finished complete completion"))
		bool IsDone();

	/**
	* Returns the result.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|Boolean", Meta = (DisplayName = "Get Result", Keywords = "result return value"))
		void GetResult(bool& Result); // LatentActionResultType
};
