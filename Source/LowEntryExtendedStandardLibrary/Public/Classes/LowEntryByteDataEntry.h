// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "LowEntryLong.h"
#include "LowEntryDouble.h"

#include "LowEntryByteDataEntry.generated.h"


UCLASS(BlueprintType)
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryByteDataEntry : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryByteDataEntry* CreateFromByte(const uint8 Value);
	static ULowEntryByteDataEntry* CreateFromInteger(const int32 Value);
	static ULowEntryByteDataEntry* CreateFromPositiveInteger1(const int32 Value);
	static ULowEntryByteDataEntry* CreateFromPositiveInteger2(const int32 Value);
	static ULowEntryByteDataEntry* CreateFromPositiveInteger3(const int32 Value);
	static ULowEntryByteDataEntry* CreateFromLongBytes(ULowEntryLong* Value);

	static ULowEntryByteDataEntry* CreateFromFloat(const float Value);
	static ULowEntryByteDataEntry* CreateFromDoubleBytes(ULowEntryDouble* Value);

	static ULowEntryByteDataEntry* CreateFromBoolean(const bool Value);
	static ULowEntryByteDataEntry* CreateFromStringUtf8(const FString& Value);


	static ULowEntryByteDataEntry* CreateFromByteArray(const TArray<uint8>& Value);
	static ULowEntryByteDataEntry* CreateFromIntegerArray(const TArray<int32>& Value);
	static ULowEntryByteDataEntry* CreateFromPositiveInteger1Array(const TArray<int32>& Value);
	static ULowEntryByteDataEntry* CreateFromPositiveInteger2Array(const TArray<int32>& Value);
	static ULowEntryByteDataEntry* CreateFromPositiveInteger3Array(const TArray<int32>& Value);
	static ULowEntryByteDataEntry* CreateFromLongBytesArray(const TArray<ULowEntryLong*>& Value);

	static ULowEntryByteDataEntry* CreateFromFloatArray(const TArray<float>& Value);
	static ULowEntryByteDataEntry* CreateFromDoubleBytesArray(const TArray<ULowEntryDouble*>& Value);

	static ULowEntryByteDataEntry* CreateFromBooleanArray(const TArray<bool>& Value);
	static ULowEntryByteDataEntry* CreateFromStringUtf8Array(const TArray<FString>& Value);


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
