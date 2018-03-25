// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "LowEntryParsedHashcash.h"


class ULowEntryHashingHashcashLibrary
{
private:
	const static int32 VERSION = 1;
	const static int32 MAX_COUNTER = 1048576;

	const static FString DATE_FORMAT_STRING;

	const static TArray<TArray<uint8>> BASE_64_CACHE;


public:
	static TArray<FString> hashArray(const TArray<FString>& resource, const int32 bits);
	static TArray<FString> hashArrayCustomCreationDate(const TArray<FString>& resources, const FDateTime& date, const int32 bits);
	static FString hash(const FString& resource, const int32 bits);
	static FString hashCustomCreationDate(const FString& resource, const FDateTime& date, const int32 bits);

	static TArray<ULowEntryParsedHashcash*> parseArray(const TArray<FString>& Hashcashes);
	static ULowEntryParsedHashcash* parse(const FString& Hashcash);


private:
	static const TArray<TArray<uint8>> GenerateBase64Cache();
	static TArray<uint8> base64WithoutLeadingZeroBytes(const int32 value);
	static FString getDateString(const FDateTime& date);
	static FDateTime parseDateString(const FString& date);
	FORCEINLINE static int32 countLeadingZeroBits(const TArray<uint8>& values);
	FORCEINLINE static uint8 countLeadingZeroBits(const uint8 v);
};
