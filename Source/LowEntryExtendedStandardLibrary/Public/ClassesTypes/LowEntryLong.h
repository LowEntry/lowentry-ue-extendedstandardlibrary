// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "LowEntryLong.generated.h"


class ULowEntryDouble;


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


	int64 GetLong();
	void SetLong(const int64 Value);


	/**
	* Casts the long to a double.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Create Clone"))
		ULowEntryLong* CreateClone();

	/**
	* Casts the long to a double.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Cast To Double (bytes)"))
		ULowEntryDouble* CastToDoubleBytes();

	/**
	* Casts the long to a string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "To String"))
		FString CastToString();


	/**
	* Add an integer to this long.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Add (Integer)"))
		void Integer_Add(const int32 Value);

	/**
	* Subtracts an integer from this long.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Subtract (Integer)"))
		void Integer_Subtract(const int32 Value);


	/**
	* Returns true if the long is equal to the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Equals (Integer)"))
		bool Integer_Equals(const int32 Value);

	/**
	* Returns true if the long is greater than the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Greater Than (Integer)"))
		bool Integer_GreaterThan(const int32 Value);

	/**
	* Returns true if the long is less than the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Less Than (Integer)"))
		bool Integer_LessThan(const int32 Value);

	/**
	* Returns true if the long is greater than the given float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Greater Than (Float)"))
		bool Float_GreaterThan(const float Value);

	/**
	* Returns true if the long is less than the given float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Less Than (Float)"))
		bool Float_LessThan(const float Value);


	/**
	* Add a long to this long.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Add (Long Bytes)"))
		void LongBytes_Add(ULowEntryLong* Value);

	/**
	* Subtracts an integer from this long.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Subtract (Long Bytes)"))
		void LongBytes_Subtract(ULowEntryLong* Value);


	/**
	* Returns true if the long is equal to the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Equals (Long Bytes)"))
		bool LongBytes_Equals(ULowEntryLong* Value);

	/**
	* Returns true if the long is greater than the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Greater Than (Long Bytes)"))
		bool LongBytes_GreaterThan(ULowEntryLong* Value);

	/**
	* Returns true if the long is less than the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Less Than (Long Bytes)"))
		bool LongBytes_LessThan(ULowEntryLong* Value);

	/**
	* Returns true if the long is greater than the given float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Greater Than (Double Bytes)"))
		bool DoubleBytes_GreaterThan(ULowEntryDouble* Value);

	/**
	* Returns true if the long is less than the given float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Less Than (Double Bytes)"))
		bool DoubleBytes_LessThan(ULowEntryDouble* Value);
};
