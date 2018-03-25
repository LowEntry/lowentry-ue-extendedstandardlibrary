// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "LowEntryLong.h"
#include "LowEntryDouble.h"

#include "LowEntryBitDataWriter.generated.h"


class ULowEntryBitDataEntry;


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryBitDataWriter : public UObject
{
	GENERATED_UCLASS_BODY()


private:
	const static uint8 mask[9];


public:
	static ULowEntryBitDataWriter* Create();
	static ULowEntryBitDataWriter* CreateFromEntryArray(const TArray<ULowEntryBitDataEntry*>& Array);

	void AddRawBit(const bool Value);
	void AddRawByte(const uint8 Value);
	void AddPartialRawByte(uint8 Value, int32 Bits);
	void AddRawBytes(const TArray<uint8>& Value);


protected:
	void AddUinteger(const int32 Value);


public:
	UPROPERTY()
	TArray<uint8> Bytes;
	UPROPERTY()
	uint8 CurrentByte = 0;
	UPROPERTY()
	int32 CurrentBytePosition = 0;


	/**
	* Returns the byte data.
	*/
	/*UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Get Bytes"))*/
		TArray<uint8> GetBytes();

	/**
	* Adds a bit.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Bit"))
		void AddBit(const bool Value);

	/**
	* Adds a byte, will only add a certain amount of bits from the given byte.
	*
	* For example, take 63 as the value (bitwise this is: 0011 1111).
	* If you use this blueprint with value 63 and bitcount 4, only the lowest 4 bits will be added, meaning only 1111 will be added, which will then have a value of 15 when read again.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Byte (Least Significant Bits Only)"))
		void AddByteLeastSignificantBits(const uint8 Value, const int32 BitCount);

	/**
	* Adds a byte, will only add a certain amount of bits from the given byte.
	*
	* For example, take 63 as the value (bitwise this is: 0011 1111).
	* If you use this blueprint with value 63 and bitcount 4, only the highest 4 bits will be added, meaning only 0011 will be added, which will then have a value of 48 when read again.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Byte (Most Significant Bits Only)"))
		void AddByteMostSignificantBits(const uint8 Value, const int32 BitCount);

	/**
	* Adds an integer, will only add a certain amount of bits from the given integer.
	*
	* For example, take 268435471 as the value (bitwise this is: 00010000 00000000 00000000 00001111).
	* If you use this blueprint with value 268435471 and bitcount 4, only the lowest 4 bits will be added, meaning only 1111 will be added, which will then have a value of 15 when read again.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Integer (Least Significant Bits Only)"))
		void AddIntegerLeastSignificantBits(const int32 Value, const int32 BitCount);

	/**
	* Adds an integer, will only add a certain amount of bits from the given integer.
	*
	* For example, take 268435471 as the value (bitwise this is: 00010000 00000000 00000000 00001111).
	* If you use this blueprint with value 268435471 and bitcount 4, only the highest 4 bits will be added, meaning only 0001 will be added, which will then have a value of 268435456 when read again.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Integer (Most Significant Bits Only)"))
		void AddIntegerMostSignificantBits(const int32 Value, int32 BitCount);

	/**
	* Adds a byte.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Byte"))
		void AddByte(const uint8 Value);

	/**
	* Adds an integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Integer"))
		void AddInteger(const int32 Value);

	/**
	* Adds a positive integer.
	*
	* Will store values below 128 in 1 byte, higher values will be stored in 4 bytes.
	*
	* The given integer has to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Positive Integer 1"))
		void AddPositiveInteger1(const int32 Value);

	/**
	* Adds a positive integer.
	*
	* Will store values below 32.768 in 2 bytes, higher values will be stored in 4 bytes.
	*
	* The given integer has to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Positive Integer 2"))
		void AddPositiveInteger2(const int32 Value);

	/**
	* Adds a positive integer.
	*
	* Will store values below 8.388.608 in 3 bytes, higher values will be stored in 4 bytes.
	*
	* The given integer has to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Positive Integer 3"))
		void AddPositiveInteger3(const int32 Value);

	/**
	* Adds a long (bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Long (Bytes)"))
		void AddLongBytes(ULowEntryLong* Value);

	/**
	* Adds a float.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Float"))
		void AddFloat(const float Value);

	/**
	* Adds a double (bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Double (Bytes)"))
		void AddDoubleBytes(ULowEntryDouble* Value);

	/**
	* Adds a boolean, this does the same as adding a bit.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Boolean"))
		void AddBoolean(const bool Value);

	/**
	* Adds a String (UTF-8).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add String (Utf 8)"))
		void AddStringUtf8(const FString& Value);


	/**
	* Adds a bit array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Bit Array"))
		void AddBitArray(const TArray<bool>& Value);

	/**
	* Adds a byte array, will only add a certain amount of bits from every given byte.
	*
	* For example, take 63 as the value (bitwise this is: 0011 1111).
	* If you use this blueprint with value [63, 63, 63] and bitcount 4, only the lowest 4 bits of each byte will be added, meaning only 1111 1111 1111 will be added, which will then have a value of 15 for each byte when read again.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Byte Array (Least Significant Bits Only)"))
		void AddByteArrayLeastSignificantBits(const TArray<uint8>& Value, const int32 BitCount);

	/**
	* Adds a byte array, will only add a certain amount of bits from every given byte.
	*
	* For example, take 63 as the value (bitwise this is: 0011 1111).
	* If you use this blueprint with value [63, 63, 63] and bitcount 4, only the highest 4 bits of each byte will be added, meaning only 0011 0011 0011 will be added, which will then have a value of 48 for each byte when read again.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Byte Array (Most Significant Bits Only)"))
		void AddByteArrayMostSignificantBits(const TArray<uint8>& Value, const int32 BitCount);

	/**
	* Adds an integer array, will only add a certain amount of bits from every given integer.
	*
	* For example, take 268435471 as the value (bitwise this is: 00010000 00000000 00000000 00001111).
	* If you use this blueprint with value [268435471, 268435471, 268435471] and bitcount 4, only the lowest 4 bits of each integer will be added, meaning only 1111 1111 1111 will be added, which will then have a value of 15 for each integer when read again.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Integer Array (Least Significant Bits Only)"))
		void AddIntegerArrayLeastSignificantBits(const TArray<int32>& Value, const int32 BitCount);

	/**
	* Adds an integer array, will only add a certain amount of bits from every given integer.
	*
	* For example, take 268435471 as the value (bitwise this is: 00010000 00000000 00000000 00001111).
	* If you use this blueprint with value [268435471, 268435471, 268435471] and bitcount 4, only the highest 4 bits of each integer will be added, meaning only 0001 0001 0001 will be added, which will then have a value of 268435456 for each integer when read again.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Integer Array (Most Significant Bits Only)"))
		void AddIntegerArrayMostSignificantBits(const TArray<int32>& Value, const int32 BitCount);

	/**
	* Adds a byte array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Byte Array"))
		void AddByteArray(const TArray<uint8>& Value);

	/**
	* Adds an integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Integer Array"))
		void AddIntegerArray(const TArray<int32>& Value);

	/**
	* Adds a positive integer array.
	*
	* Will store values below 128 in 1 byte, higher values will be stored in 4 bytes.
	*
	* The given integers have to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Positive Integer 1 Array"))
		void AddPositiveInteger1Array(const TArray<int32>& Value);

	/**
	* Adds a positive integer array.
	*
	* Will store values below 32.768 in 2 bytes, higher values will be stored in 4 bytes.
	*
	* The given integers have to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Positive Integer 2 Array"))
		void AddPositiveInteger2Array(const TArray<int32>& Value);

	/**
	* Adds a positive integer array.
	*
	* Will store values below 8.388.608 in 3 bytes, higher values will be stored in 4 bytes.
	*
	* The given integers have to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Positive Integer 3 Array"))
		void AddPositiveInteger3Array(const TArray<int32>& Value);

	/**
	* Adds a long (bytes) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Long (bytes) Array"))
		void AddLongBytesArray(const TArray<ULowEntryLong*>& Value);

	/**
	* Adds a float array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Float Array"))
		void AddFloatArray(const TArray<float>& Value);

	/**
	* Adds a double (bytes) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Double (bytes) Array"))
		void AddDoubleBytesArray(const TArray<ULowEntryDouble*>& Value);

	/**
	* Adds a boolean array, this does the same as adding a bit array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add Boolean Array"))
		void AddBooleanArray(const TArray<bool>& Value);

	/**
	* Adds a String (UTF-8) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Add String (Utf 8) Array"))
		void AddStringUtf8Array(const TArray<FString>& Value);
};
