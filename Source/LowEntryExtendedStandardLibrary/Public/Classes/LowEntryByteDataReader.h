#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"

#include "LowEntryLong.h"
#include "LowEntryDouble.h"

#include "LowEntryByteDataReader.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryByteDataReader : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryByteDataReader* Create(const TArray<uint8>& Bytes, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	int32 GetAndIncreasePosition(const int32 Increasement);
	int32 Remaining();
	int32 MaxElementsRemaining(const int32 MinimumSizePerElement);


protected:
	int32 GetUinteger();


public:
	UPROPERTY()
	TArray<uint8> Bytes;
	UPROPERTY()
	int32 Position = 0;


	/**
	* Gets a byte.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Byte"))
		uint8 GetByte();
	
	/**
	* Gets an integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Integer"))
		int32 GetInteger();
	
	/**
	* Gets a long (bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Long (bytes)"))
		ULowEntryLong* GetLongBytes();
	
	/**
	* Gets a float.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Float"))
		float GetFloat();
	
	/**
	* Gets a double (bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Double (bytes)"))
		ULowEntryDouble* GetDoubleBytes();
	
	/**
	* Gets a boolean.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Boolean"))
		bool GetBoolean();
	
	/**
	* Gets a String (UTF-8).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get String (Utf 8)"))
		FString GetStringUtf8();


	/**
	* Gets a byte array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Byte Array"))
		TArray<uint8> GetByteArray();

	/**
	* Gets an integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Integer Array"))
		TArray<int32> GetIntegerArray();

	/**
	* Gets a long (bytes) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Long (bytes) Array"))
		TArray<ULowEntryLong*> GetLongBytesArray();

	/**
	* Gets a float array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Float Array"))
		TArray<float> GetFloatArray();

	/**
	* Gets a double (byte) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Double (bytes) Array"))
		TArray<ULowEntryDouble*> GetDoubleBytesArray();

	/**
	* Gets a boolean array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Boolean Array"))
		TArray<bool> GetBooleanArray();

	/**
	* Gets a String (UTF-8) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get String (Utf 8) Array"))
		TArray<FString> GetStringUtf8Array();


	int32 SafeMultiply(const int32 A, const int32 B);
};
