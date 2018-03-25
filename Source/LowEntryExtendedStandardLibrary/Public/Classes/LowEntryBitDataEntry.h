// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "LowEntryLong.h"
#include "LowEntryDouble.h"

#include "LowEntryBitDataEntry.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryBitDataEntry : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryBitDataEntry* CreateFromBit(const bool Value);
	static ULowEntryBitDataEntry* CreateFromByteLeastSignificantBits(const uint8 Value, const int32 BitCount);
	static ULowEntryBitDataEntry* CreateFromByteMostSignificantBits(const uint8 Value, const int32 BitCount);
	static ULowEntryBitDataEntry* CreateFromIntegerLeastSignificantBits(const int32 Value, const int32 BitCount);
	static ULowEntryBitDataEntry* CreateFromIntegerMostSignificantBits(const int32 Value, const int32 BitCount);

	static ULowEntryBitDataEntry* CreateFromByte(const uint8 Value);
	static ULowEntryBitDataEntry* CreateFromInteger(const int32 Value);
	static ULowEntryBitDataEntry* CreateFromPositiveInteger1(const int32 Value);
	static ULowEntryBitDataEntry* CreateFromPositiveInteger2(const int32 Value);
	static ULowEntryBitDataEntry* CreateFromPositiveInteger3(const int32 Value);
	static ULowEntryBitDataEntry* CreateFromLongBytes(ULowEntryLong* Value);

	static ULowEntryBitDataEntry* CreateFromFloat(const float Value);
	static ULowEntryBitDataEntry* CreateFromDoubleBytes(ULowEntryDouble* Value);

	static ULowEntryBitDataEntry* CreateFromBoolean(const bool Value);
	static ULowEntryBitDataEntry* CreateFromStringUtf8(const FString& Value);


	static ULowEntryBitDataEntry* CreateFromBitArray(const TArray<bool>& Value);
	static ULowEntryBitDataEntry* CreateFromByteArrayLeastSignificantBits(const TArray<uint8>& Value, const int32 BitCount);
	static ULowEntryBitDataEntry* CreateFromByteArrayMostSignificantBits(const TArray<uint8>& Value, const int32 BitCount);
	static ULowEntryBitDataEntry* CreateFromIntegerArrayLeastSignificantBits(const TArray<int32>& Value, const int32 BitCount);
	static ULowEntryBitDataEntry* CreateFromIntegerArrayMostSignificantBits(const TArray<int32>& Value, const int32 BitCount);

	static ULowEntryBitDataEntry* CreateFromByteArray(const TArray<uint8>& Value);
	static ULowEntryBitDataEntry* CreateFromIntegerArray(const TArray<int32>& Value);
	static ULowEntryBitDataEntry* CreateFromPositiveInteger1Array(const TArray<int32>& Value);
	static ULowEntryBitDataEntry* CreateFromPositiveInteger2Array(const TArray<int32>& Value);
	static ULowEntryBitDataEntry* CreateFromPositiveInteger3Array(const TArray<int32>& Value);
	static ULowEntryBitDataEntry* CreateFromLongBytesArray(const TArray<ULowEntryLong*>& Value);

	static ULowEntryBitDataEntry* CreateFromFloatArray(const TArray<float>& Value);
	static ULowEntryBitDataEntry* CreateFromDoubleBytesArray(const TArray<ULowEntryDouble*>& Value);

	static ULowEntryBitDataEntry* CreateFromBooleanArray(const TArray<bool>& Value);
	static ULowEntryBitDataEntry* CreateFromStringUtf8Array(const TArray<FString>& Value);


public:
	UPROPERTY()
	uint8 Type = 0;


	UPROPERTY()
	uint8 ByteValue;
	UPROPERTY()
	int32 IntegerValue;
	UPROPERTY()
	ULowEntryLong* LongBytesValue = NULL;

	UPROPERTY()
	float FloatValue;
	UPROPERTY()
	ULowEntryDouble* DoubleBytesValue = NULL;

	UPROPERTY()
	bool BooleanValue;
	UPROPERTY()
	FString StringUtf8Value;


	UPROPERTY()
	TArray<uint8> ByteArrayValue;
	UPROPERTY()
	TArray<int32> IntegerArrayValue;
	UPROPERTY()
	TArray<ULowEntryLong*> LongBytesArrayValue;

	UPROPERTY()
	TArray<float> FloatArrayValue;
	UPROPERTY()
	TArray<ULowEntryDouble*> DoubleBytesArrayValue;

	UPROPERTY()
	TArray<bool> BooleanArrayValue;
	UPROPERTY()
	TArray<FString> StringUtf8ArrayValue;


public:
	int32 GetBitCount();



	bool IsBit();
	void SetBit(const bool Value);
	bool GetBit();

	bool IsByteLeastSignificantBits();
	void SetByteLeastSignificantBits(const uint8 Value, const int32 BitCount);
	uint8 GetByteLeastSignificantBits();

	bool IsByteMostSignificantBits();
	void SetByteMostSignificantBits(const uint8 Value, const int32 BitCount);
	uint8 GetByteMostSignificantBits();

	bool IsIntegerLeastSignificantBits();
	void SetIntegerLeastSignificantBits(const int32 Value, const int32 BitCount);
	int32 GetIntegerLeastSignificantBits();

	bool IsIntegerMostSignificantBits();
	void SetIntegerMostSignificantBits(const int32 Value, const int32 BitCount);
	int32 GetIntegerMostSignificantBits();


	bool IsByte();
	void SetByte(const uint8 Value);
	uint8 GetByte();

	bool IsInteger();
	void SetInteger(const int32 Value);
	int32 GetInteger();

	bool IsPositiveInteger1();
	void SetPositiveInteger1(const int32 Value);
	int32 GetPositiveInteger1();

	bool IsPositiveInteger2();
	void SetPositiveInteger2(const int32 Value);
	int32 GetPositiveInteger2();

	bool IsPositiveInteger3();
	void SetPositiveInteger3(const int32 Value);
	int32 GetPositiveInteger3();

	bool IsLongBytes();
	void SetLongBytes(ULowEntryLong* Value);
	ULowEntryLong* GetLongBytes();


	bool IsFloat();
	void SetFloat(const float Value);
	float GetFloat();

	bool IsDoubleBytes();
	void SetDoubleBytes(ULowEntryDouble* Value);
	ULowEntryDouble* GetDoubleBytes();


	bool IsBoolean();
	void SetBoolean(const bool Value);
	bool GetBoolean();

	bool IsStringUtf8();
	void SetStringUtf8(const FString& Value);
	FString GetStringUtf8();



	bool IsBitArray();
	void SetBitArray(const TArray<bool>& Value);
	TArray<bool> GetBitArray();

	bool IsByteArrayLeastSignificantBits();
	void SetByteArrayLeastSignificantBits(const TArray<uint8>& Value, const int32 BitCount);
	TArray<uint8> GetByteArrayLeastSignificantBits();

	bool IsByteArrayMostSignificantBits();
	void SetByteArrayMostSignificantBits(const TArray<uint8>& Value, const int32 BitCount);
	TArray<uint8> GetByteArrayMostSignificantBits();

	bool IsIntegerArrayLeastSignificantBits();
	void SetIntegerArrayLeastSignificantBits(const TArray<int32>& Value, const int32 BitCount);
	TArray<int32> GetIntegerArrayLeastSignificantBits();

	bool IsIntegerArrayMostSignificantBits();
	void SetIntegerArrayMostSignificantBits(const TArray<int32>& Value, const int32 BitCount);
	TArray<int32> GetIntegerArrayMostSignificantBits();


	bool IsByteArray();
	void SetByteArray(const TArray<uint8>& Value);
	TArray<uint8> GetByteArray();

	bool IsIntegerArray();
	void SetIntegerArray(const TArray<int32>& Value);
	TArray<int32> GetIntegerArray();

	bool IsPositiveInteger1Array();
	void SetPositiveInteger1Array(const TArray<int32>& Value);
	TArray<int32> GetPositiveInteger1Array();

	bool IsPositiveInteger2Array();
	void SetPositiveInteger2Array(const TArray<int32>& Value);
	TArray<int32> GetPositiveInteger2Array();

	bool IsPositiveInteger3Array();
	void SetPositiveInteger3Array(const TArray<int32>& Value);
	TArray<int32> GetPositiveInteger3Array();

	bool IsLongBytesArray();
	void SetLongBytesArray(const TArray<ULowEntryLong*>& Value);
	TArray<ULowEntryLong*> GetLongBytesArray();


	bool IsFloatArray();
	void SetFloatArray(const TArray<float>& Value);
	TArray<float> GetFloatArray();

	bool IsDoubleBytesArray();
	void SetDoubleBytesArray(const TArray<ULowEntryDouble*>& Value);
	TArray<ULowEntryDouble*> GetDoubleBytesArray();


	bool IsBooleanArray();
	void SetBooleanArray(const TArray<bool>& Value);
	TArray<bool> GetBooleanArray();

	bool IsStringUtf8Array();
	void SetStringUtf8Array(const TArray<FString>& Value);
	TArray<FString> GetStringUtf8Array();
};
