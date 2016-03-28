#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"

#include "LowEntryLong.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryLong : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryLong* Create();
	static ULowEntryLong* Create(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	static TArray<uint8> GetDefaultBytes();


public:
	UPROPERTY()
	TArray<uint8> Bytes;


	/**
	* Returns the bytes (always 8 bytes).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Get Bytes"))
		TArray<uint8> GetBytes();

	/**
	* Sets the bytes (will only add the first 8 bytes, will add 0 bytes if the given byte array was less than 8 bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Set Bytes", AdvancedDisplay = "1"))
		void SetBytes(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);
};
