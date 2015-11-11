#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "Json.h"

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
	static ULowEntryByteDataEntry* CreateFromLongBytes(ULowEntryLong* Value);

	static ULowEntryByteDataEntry* CreateFromFloat(const float Value);
	static ULowEntryByteDataEntry* CreateFromDoubleBytes(ULowEntryDouble* Value);

	static ULowEntryByteDataEntry* CreateFromBoolean(const bool Value);
	static ULowEntryByteDataEntry* CreateFromStringUtf8(const FString& Value);


	static ULowEntryByteDataEntry* CreateFromByteArray(const TArray<uint8>& Value);
	static ULowEntryByteDataEntry* CreateFromIntegerArray(const TArray<int32>& Value);
	static ULowEntryByteDataEntry* CreateFromLongBytesArray(const TArray<ULowEntryLong*>& Value);

	static ULowEntryByteDataEntry* CreateFromFloatArray(const TArray<float>& Value);
	static ULowEntryByteDataEntry* CreateFromDoubleBytesArray(const TArray<ULowEntryDouble*>& Value);

	static ULowEntryByteDataEntry* CreateFromBooleanArray(const TArray<bool>& Value);
	static ULowEntryByteDataEntry* CreateFromStringUtf8Array(const TArray<FString>& Value);


public:
	uint8 Type = 0;


	uint8 ByteValue;
	int32 IntegerValue;
	ULowEntryLong* LongBytesValue = NULL;

	float FloatValue;
	ULowEntryDouble* DoubleBytesValue = NULL;

	bool BooleanValue;
	FString StringUtf8Value;


	TArray<uint8> ByteArrayValue;
	TArray<int32> IntegerArrayValue;
	TArray<ULowEntryLong*> LongBytesArrayValue;

	TArray<float> FloatArrayValue;
	TArray<ULowEntryDouble*> DoubleBytesArrayValue;

	TArray<bool> BooleanArrayValue;
	TArray<FString> StringUtf8ArrayValue;


public:
	bool IsByte();
	void SetByte(const uint8 Value);
	uint8 GetByte();

	bool IsInteger();
	void SetInteger(const int32 Value);
	int32 GetInteger();

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
