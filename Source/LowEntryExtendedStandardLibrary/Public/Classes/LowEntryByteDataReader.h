// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
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
	static ULowEntryByteDataReader* CreateClone(const TArray<uint8>& Bytes, const int32 Position);

	int32 GetAndIncreasePosition(const int32 Increasement);
	int32 MaxElementsRemaining(const int32 MinimumSizePerElement);


protected:
	int32 GetUinteger();


public:
	UPROPERTY()
	TArray<uint8> Bytes;
	UPROPERTY()
	int32 Position = 0;


	/**
	* Clones the clone of this ByteDataReader.
	* 
	* Allows you to easily read and revert the position (by cloning, reading data with the clone, and then throwing the clone away).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)", Meta = (DisplayName = "Get Clone"))
		ULowEntryByteDataReader* GetClone();

	/**
	* Returns the current position.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)", Meta = (DisplayName = "Get Position"))
		int32 GetPosition();

	/**
	* Sets the current position.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)", Meta = (DisplayName = "Set Position"))
		void SetPosition(const int32 Position_);

	/**
	* Sets the current position to 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)", Meta = (DisplayName = "Reset"))
		void Reset();

	/**
	* Causes Remaining to return 0.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)", Meta = (DisplayName = "Empty"))
		void Empty();

	/**
	* Returns the amount of bytes left.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Reader (Meta)", Meta = (DisplayName = "Get Remaining"))
		int32 Remaining();


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
	* Gets a positive integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Positive Integer 1"))
		int32 GetPositiveInteger1();

	/**
	* Gets a positive integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Positive Integer 2"))
		int32 GetPositiveInteger2();

	/**
	* Gets a positive integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Positive Integer 3"))
		int32 GetPositiveInteger3();
	
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
	* Gets a positive integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Positive Integer 1 Array"))
		TArray<int32> GetPositiveInteger1Array();

	/**
	* Gets a positive integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Positive Integer 2 Array"))
		TArray<int32> GetPositiveInteger2Array();

	/**
	* Gets a positive integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Get Positive Integer 3 Array"))
		TArray<int32> GetPositiveInteger3Array();

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
