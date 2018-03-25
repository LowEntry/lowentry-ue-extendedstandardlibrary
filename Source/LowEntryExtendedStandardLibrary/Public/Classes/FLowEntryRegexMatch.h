// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "FLowEntryRegexCaptureGroup.h"

#include "FLowEntryRegexMatch.generated.h"


USTRUCT(BlueprintType)
struct LOWENTRYEXTENDEDSTANDARDLIBRARY_API FLowEntryRegexMatch
{
	GENERATED_BODY()


	/**
	* This is the number of the match, starting with 1.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		int32 MatchNumber;

	/**
	* This is the start index of the match.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		int32 BeginIndex;

	/**
	* This is the end index of the match.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		int32 EndIndex;

	/**
	* This is the text of the match.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		FString Match;

	/**
	* These are the capture group matches of the match.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		TArray<FLowEntryRegexCaptureGroup> CaptureGroups;
};
