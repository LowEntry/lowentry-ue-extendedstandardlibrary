// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "LowEntryParsedHashcash.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryParsedHashcash : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryParsedHashcash* Create(const bool Valid_, const FString& Resource_, const FDateTime& Date_, const int32 Bits_);


public:
	UPROPERTY()
	bool Valid = false;

	UPROPERTY()
	FString Resource;

	UPROPERTY()
	FDateTime Date;

	UPROPERTY()
	int32 Bits = 0;


public:
	/**
	* Returns true if this Hashcash is valid, returns false if it is not valid.
	*/
	/*UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Parsed", Meta = (DisplayName = "Is Hashcash Valid"))*/
		bool IsHashcashValid();

	/**
	* Returns the resource (basically the service ID) of this Hashcash.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Parsed", Meta = (DisplayName = "Get Resource"))
		FString GetResource();

	/**
	* Returns the creation date (in UTC) of this Hashcash.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Parsed", Meta = (DisplayName = "Get Date"))
		FDateTime GetDate();

	/**
	* Returns the bits (the strength, the value) of this Hashcash.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Parsed", Meta = (DisplayName = "Get Bits"))
		int32 GetBits();


	/**
	* Converts the Parsed Hashcash to a String, for debugging purposes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Parsed", Meta = (DisplayName = "To String"))
		FString ToString();
};
