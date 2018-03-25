// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "LowEntryLong.h"
#include "LowEntryDouble.h"

#include "LowEntryBitDataReader.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryBitDataReader : public UObject
{
	GENERATED_UCLASS_BODY()


private:
	const static uint8 mask[9];


public:
	static ULowEntryBitDataReader* Create(const TArray<uint8>& Bytes, int32 Index = 0, int32 Length = 0x7FFFFFFF);
	static ULowEntryBitDataReader* CreateClone(const TArray<uint8>& Bytes, const int32 Position, const uint8 CurrentByte, const int32 CurrentBytePosition);

	int32 GetAndIncreasePosition(const int32 Increasement);
	int32 MaxElementsRemaining(const int32 MinimumSizePerElement);


protected:
	bool GetRawBit();
	uint8 GetRawByte();
	uint8 GetPartialRawByte(int32 Bits);
	int32 GetUinteger();


public:
	UPROPERTY()
	TArray<uint8> Bytes;
	UPROPERTY()
	int32 Position = 0;
	UPROPERTY()
	uint8 CurrentByte = 0;
	UPROPERTY()
	int32 CurrentBytePosition = 0;


	/**
	* Clones the clone of this BitDataReader.
	* 
	* Allows you to easily read and revert the position (by cloning, reading data with the clone, and then throwing the clone away).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader (Meta)", Meta = (DisplayName = "Get Clone"))
		ULowEntryBitDataReader* GetClone();

	/**
	* Returns the current position.
	*
	* Because this data writer works with bits, this blueprint will only work correctly till 268.435.455 bytes (256 MB), beyond that, please use the Get Clone blueprint to rollback the position instead.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Reader (Meta)", Meta = (DisplayName = "Get Position"))
		int32 GetPosition();

	/**
	* Sets the current position.
	*
	* Because this data writer works with bits, this blueprint will only work correctly till 268.435.455 bytes (256 MB), beyond that, please use the Get Clone blueprint to rollback the position instead.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader (Meta)", Meta = (DisplayName = "Set Position"))
		void SetPosition(const int32 Position_);

	/**
	* Sets the current position to 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader (Meta)", Meta = (DisplayName = "Reset"))
		void Reset();

	/**
	* Causes Remaining to return 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader (Meta)", Meta = (DisplayName = "Empty"))
		void Empty();

	/**
	* Returns the amount of bytes left.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Reader (Meta)", Meta = (DisplayName = "Get Remaining"))
		int32 Remaining();


	/**
	* Gets a bit.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Bit"))
		bool GetBit();

	/**
	* Gets a byte, will only retrieve a certain amount of bits to form the byte.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Byte (Least Significant Bits Only)"))
		uint8 GetByteLeastSignificantBits(const int32 BitCount);

	/**
	* Gets a byte, will only retrieve a certain amount of bits to form the byte.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Byte (Most Significant Bits Only)"))
		uint8 GetByteMostSignificantBits(const int32 BitCount);

	/**
	* Gets an integer, will only retrieve a certain amount of bits to form the integer.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Integer (Least Significant Bits Only)"))
		int32 GetIntegerLeastSignificantBits(const int32 BitCount);

	/**
	* Gets an integer, will only retrieve a certain amount of bits to form the integer.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Integer (Most Significant Bits Only)"))
		int32 GetIntegerMostSignificantBits(int32 BitCount);

	/**
	* Gets a byte.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Byte"))
		uint8 GetByte();
	
	/**
	* Gets an integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Integer"))
		int32 GetInteger();

	/**
	* Gets a positive integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Positive Integer 1"))
		int32 GetPositiveInteger1();

	/**
	* Gets a positive integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Positive Integer 2"))
		int32 GetPositiveInteger2();

	/**
	* Gets a positive integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Positive Integer 3"))
		int32 GetPositiveInteger3();
	
	/**
	* Gets a long (bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Long (bytes)"))
		ULowEntryLong* GetLongBytes();
	
	/**
	* Gets a float.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Float"))
		float GetFloat();
	
	/**
	* Gets a double (bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Double (bytes)"))
		ULowEntryDouble* GetDoubleBytes();
	
	/**
	* Gets a boolean, this does the same as getting a bit.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Boolean"))
		bool GetBoolean();
	
	/**
	* Gets a String (UTF-8).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get String (Utf 8)"))
		FString GetStringUtf8();


	/**
	* Gets a bit array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Bit Array"))
		TArray<bool> GetBitArray();

	/**
	* Gets a byte array, will only retrieve a certain amount of bits to form every byte.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Byte Array (Least Significant Bits Only)"))
		TArray<uint8> GetByteArrayLeastSignificantBits(const int32 BitCount);

	/**
	* Gets a byte array, will only retrieve a certain amount of bits to form every byte.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Byte Array (Most Significant Bits Only)"))
		TArray<uint8> GetByteArrayMostSignificantBits(const int32 BitCount);

	/**
	* Gets an integer array, will only retrieve a certain amount of bits to form every integer.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Integer Array (Least Significant Bits Only)"))
		TArray<int32> GetIntegerArrayLeastSignificantBits(const int32 BitCount);

	/**
	* Gets an integer array, will only retrieve a certain amount of bits to form every integer.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Integer Array (Most Significant Bits Only)"))
		TArray<int32> GetIntegerArrayMostSignificantBits(const int32 BitCount);

	/**
	* Gets a byte array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Byte Array"))
		TArray<uint8> GetByteArray();

	/**
	* Gets an integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Integer Array"))
		TArray<int32> GetIntegerArray();

	/**
	* Gets a positive integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Positive Integer 1 Array"))
		TArray<int32> GetPositiveInteger1Array();

	/**
	* Gets a positive integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Positive Integer 2 Array"))
		TArray<int32> GetPositiveInteger2Array();

	/**
	* Gets a positive integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Positive Integer 3 Array"))
		TArray<int32> GetPositiveInteger3Array();

	/**
	* Gets a long (bytes) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Long (bytes) Array"))
		TArray<ULowEntryLong*> GetLongBytesArray();

	/**
	* Gets a float array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Float Array"))
		TArray<float> GetFloatArray();

	/**
	* Gets a double (byte) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Double (bytes) Array"))
		TArray<ULowEntryDouble*> GetDoubleBytesArray();

	/**
	* Gets a boolean array, this does the same as getting a bit array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get Boolean Array"))
		TArray<bool> GetBooleanArray();

	/**
	* Gets a String (UTF-8) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Get String (Utf 8) Array"))
		TArray<FString> GetStringUtf8Array();


	int32 SafeMultiply(const int32 A, const int32 B);
};
