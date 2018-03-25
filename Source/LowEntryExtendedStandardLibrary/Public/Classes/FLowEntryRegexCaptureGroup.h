// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "FLowEntryRegexCaptureGroup.generated.h"


USTRUCT(BlueprintType)
struct LOWENTRYEXTENDEDSTANDARDLIBRARY_API FLowEntryRegexCaptureGroup
{
	GENERATED_BODY()


	/**
	* This is the number of the capture group, starting with 1.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		int32 CaptureGroupNumber;

	/**
	* This is the start index of the capture group match.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		int32 BeginIndex;

	/**
	* This is the end index of the capture group match.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		int32 EndIndex;

	/**
	* This is the text of the capture group match.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Low Entry|Extended Standard Library|Utilities|String")
		FString Match;
};
