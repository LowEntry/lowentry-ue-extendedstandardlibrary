#pragma once


#include "Engine.h"
#include "Core.h"

#include "FLowEntryRegexMatch.generated.h"


USTRUCT(BlueprintType)
struct LOWENTRYEXTENDEDSTANDARDLIBRARY_API FLowEntryRegexMatch
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		int32 BeginIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		int32 EndIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		FString Match;
};
