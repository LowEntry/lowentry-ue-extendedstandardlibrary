#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"

#include "LowEntryLong.h"
#include "LowEntryDouble.h"

#include "LowEntryByteDataWriter.generated.h"


class ULowEntryByteDataEntry;


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryByteDataWriter : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryByteDataWriter* Create();
	static ULowEntryByteDataWriter* CreateFromEntryArray(const TArray<ULowEntryByteDataEntry*>& Array);

	void AddRawByte(const uint8 Value);
	void AddRawBytes(const TArray<uint8>& Value);


public:
	TArray<uint8> Bytes;


	/**
	* Returns the byte data.
	*/
	/*UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Get Bytes"))*/
		TArray<uint8> GetBytes();


	/**
	* Adds a byte.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Byte"))
		void AddByte(const uint8 Value);

	/**
	* Adds an integer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Integer"))
		void AddInteger(const int32 Value);

	/**
	* Adds a long (bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Long (Bytes)"))
		void AddLongBytes(ULowEntryLong* Value);

	/**
	* Adds a float.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Float"))
		void AddFloat(const float Value);

	/**
	* Adds a double (bytes).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Double (Bytes)"))
		void AddDoubleBytes(ULowEntryDouble* Value);

	/**
	* Adds a boolean.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Boolean"))
		void AddBoolean(const bool Value);

	/**
	* Adds a String (UTF-8).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add String (Utf 8)"))
		void AddStringUtf8(const FString& Value);


	/**
	* Adds a byte array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Byte Array"))
		void AddByteArray(const TArray<uint8>& Value);

	/**
	* Adds an integer array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Integer Array"))
		void AddIntegerArray(const TArray<int32>& Value);
	
	/**
	* Adds a long (bytes) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Long (bytes) Array"))
		void AddLongBytesArray(const TArray<ULowEntryLong*>& Value);

	/**
	* Adds a float array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Float Array"))
		void AddFloatArray(const TArray<float>& Value);

	/**
	* Adds a double (bytes) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Double (bytes) Array"))
		void AddDoubleBytesArray(const TArray<ULowEntryDouble*>& Value);

	/**
	* Adds a boolean array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add Boolean Array"))
		void AddBooleanArray(const TArray<bool>& Value);

	/**
	* Adds a String (UTF-8) array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Add String (Utf 8) Array"))
		void AddStringUtf8Array(const TArray<FString>& Value);
};
