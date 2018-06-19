// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "LowEntryDouble.generated.h"


class ULowEntryLong;


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryDouble : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryDouble* Create();
	static ULowEntryDouble* Create(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	static TArray<uint8> GetDefaultBytes();


public:
	UPROPERTY()
	TArray<uint8> Bytes;


	/**
	* Returns the bytes (always 8 bytes).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Get Bytes"))
		TArray<uint8> GetBytes();

	/**
	* Sets the bytes (will only add the first 8 bytes, will add 0 bytes if the given byte array was less than 8 bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Set Bytes", AdvancedDisplay = "1"))
		void SetBytes(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	double GetDouble();
	void SetDouble(const double Value);


	/**
	* Casts the long to a double.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Create Clone"))
		ULowEntryDouble* CreateClone();

	/**
	* Casts the double to a long.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Cast To Long (bytes)"))
		ULowEntryLong* CastToLongBytes();

	/**
	* Casts the double to a string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "To String"))
		FString CastToString(const int32 MinFractionalDigits = 1);


	/**
	* Add a float to this double.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Add (Float)"))
		void Float_Add(const float Value);

	/**
	* Subtracts a float from this double.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Subtract (Float)"))
		void Float_Subtract(const float Value);


	/**
	* Returns true if the double is equal to the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Equals (Float)"))
		bool Float_Equals(const float Value);

	/**
	* Returns true if the double is greater than the given float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Greater Than (Float)"))
		bool Float_GreaterThan(const float Value);

	/**
	* Returns true if the double is less than the given float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Less Than (Float)"))
		bool Float_LessThan(const float Value);

	/**
	* Returns true if the double is greater than the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Greater Than (Integer)"))
		bool Integer_GreaterThan(const int32 Value);

	/**
	* Returns true if the double is less than the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Less Than (Integer)"))
		bool Integer_LessThan(const int32 Value);


	/**
	* Add a float to this double.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Add (Double Bytes)"))
		void DoubleBytes_Add(ULowEntryDouble* Value);

	/**
	* Subtracts a float from this double.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Subtract (Double Bytes)"))
		void DoubleBytes_Subtract(ULowEntryDouble* Value);


	/**
	* Returns true if the double is equal to the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Equals (Double Bytes)"))
		bool DoubleBytes_Equals(ULowEntryDouble* Value);

	/**
	* Returns true if the double is greater than the given float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Greater Than (Double Bytes)"))
		bool DoubleBytes_GreaterThan(ULowEntryDouble* Value);

	/**
	* Returns true if the double is less than the given float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Less Than (Double Bytes)"))
		bool DoubleBytes_LessThan(ULowEntryDouble* Value);

	/**
	* Returns true if the double is greater than the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Greater Than (Long Bytes)"))
		bool LongBytes_GreaterThan(ULowEntryLong* Value);

	/**
	* Returns true if the double is less than the given integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Less Than (Long Bytes)"))
		bool LongBytes_LessThan(ULowEntryLong* Value);
};
