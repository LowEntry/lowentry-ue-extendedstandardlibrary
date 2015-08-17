#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "DelayAction.h"

#include "LowEntryLatentActionString.generated.h"


#define LatentActionResultType FString
#define ULatentActionClass ULowEntryLatentActionString
#define FLatentActionClass FLowEntryLatentActionString


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryLatentActionString : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULatentActionClass* Create();


public:
	bool Finished = false;
	LatentActionResultType Result;
	

	/**
	* Waits till the latent action is done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|String", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Wait Till Done", Keywords = "untill for end finished complete completion"))
		void WaitTillDone(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result); // LatentActionResultType

	/**
	* Causes the latent action to be done.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|String", Meta = (DisplayName = "Done", Keywords = "end finished complete completion"))
		void Done(FString Result); // LatentActionResultType

	/**
	* Returns true if the latent action is done.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|String", Meta = (DisplayName = "Is Done", Keywords = "end finished complete completion"))
		bool IsDone();

	/**
	* Returns the result.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Latent Action|String", Meta = (DisplayName = "Get Result", Keywords = "result return value"))
		void GetResult(FString& Result); // LatentActionResultType
};
