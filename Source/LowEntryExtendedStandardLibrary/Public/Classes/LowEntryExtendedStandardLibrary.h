#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "DelayAction.h"
#include "Engine/LatentActionManager.h"

#include "LowEntryExtendedStandardLibrary.generated.h"


UCLASS()
class ULowEntryExtendedStandardLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()



public:
	/**
	* Returns the minimum value of the given values.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "Min (String)", CompactNodeTitle = "MIN", CommutativeAssociativeBinaryOperator = "true"))
		static FString MinString(const FString& A, const FString& B);

	/**
	* Returns the maximum value of the given values.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "Max (String)", CompactNodeTitle = "MAX", CommutativeAssociativeBinaryOperator = "true"))
		static FString MaxString(const FString& A, const FString& B);

	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "String < String", CompactNodeTitle = "<"))
		static bool LessStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "String > String", CompactNodeTitle = ">"))
		static bool GreaterStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "String <= String", CompactNodeTitle = "<="))
		static bool LessEqualStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "String >= String", CompactNodeTitle = ">="))
		static bool GreaterEqualStringString(const FString& A, const FString& B);



	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "Min & Max (String)"))
		static void MinAndMaxString(const FString& Value1, const FString& Value2, FString& MaxValue, FString& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "Min & Max (Integer)"))
		static void MinAndMaxInteger(const int32 Value1, const int32 Value2, int32& MaxValue, int32& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "Min & Max (Float)"))
		static void MinAndMaxFloat(const float Value1, const float Value2, float& MaxValue, float& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "Min & Max (Byte)"))
		static void MinAndMaxByte(const uint8 Value1, const uint8 Value2, uint8& MaxValue, uint8& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "Min & Max (DateTime)"))
		static void MinAndMaxDateTime(const FDateTime& Value1, const FDateTime& Value2, FDateTime& MaxValue, FDateTime& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Utilities", Meta = (FriendlyName = "Min & Max (Timespan)"))
		static void MinAndMaxTimespan(const FTimespan& Value1, const FTimespan& Value2, FTimespan& MaxValue, FTimespan& MinValue);



	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities")
		static void MaxOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMaxValue, FString& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities")
		static void MinOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMinValue, FString& MinValue);

	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities")
		static void MaxOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMaxValue, FDateTime& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities")
		static void MinOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMinValue, FDateTime& MinValue);

	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities")
		static void MaxOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMaxValue, FTimespan& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Advanced Standard Library|Utilities")
		static void MinOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMinValue, FTimespan& MinValue);



	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Array", Meta = (FriendlyName = "Sort (String Array)"))
		static void SortStringArray(TArray<FString>& StringArray, bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Array", Meta = (FriendlyName = "Sort (Integer Array)"))
		static void SortIntegerArray(TArray<int32>& IntegerArray, bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Array", Meta = (FriendlyName = "Sort (Float Array)"))
		static void SortFloatArray(TArray<float>& FloatArray, bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Array", Meta = (FriendlyName = "Sort (Byte Array)"))
		static void SortByteArray(TArray<uint8>& ByteArray, bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Array", Meta = (FriendlyName = "Sort (DateTime Array)"))
		static void SortDateTimeArray(TArray<FDateTime>& DateTimeArray, bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Array", Meta = (FriendlyName = "Sort (Timespan Array)"))
		static void SortTimespanArray(TArray<FTimespan>& TimespanArray, bool Reversed = false);



	/**
	* Perform a latent action with a random delay (specified in seconds).  Calling again while it is counting down will be ignored.
	*
	* @param WorldContext	World context.
	* @param MinDuration 	minimum length of delay (in seconds).
	* @param MaxDuration 	maximum length of delay (in seconds).
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Flow Control", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void	RandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, struct FLatentActionInfo LatentInfo);

	/**
	* Perform a latent action with a retriggerable random delay (specified in seconds).  Calling again while it is counting down will reset the countdown to a new random Duration.
	*
	* @param WorldContext	World context.
	* @param MinDuration 	minimum length of delay (in seconds).
	* @param MaxDuration 	maximum length of delay (in seconds).
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Advanced Standard Library|Flow Control", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void RetriggerableRandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, FLatentActionInfo LatentInfo);



//public: // Object
//	/**
//	* Creates a new Json Object.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Object|Other", Meta = (FriendlyName = "Create Json Object"))
//		static ULowEntryJsonObject* Object_Create();
//
//	/**
//	* Creates a new Json Object and fills it with a copy of the data from the given Json Object.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Object|Other", Meta = (FriendlyName = "Clone (Json Object)"))
//		static ULowEntryJsonObject* Object_Clone(const ULowEntryJsonObject* JsonObject);
//
//	/**
//	* Creates a new Json Object and fills it with a copy of the data from the two given Json Objects.
//	* When both of the two given Json Objects have a value set on same key, the key in the new Json Object will be set to the value that has been set in Json Object 2.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Object|Other", Meta = (FriendlyName = "Merge (Json Object)"))
//		static ULowEntryJsonObject* Object_Merge(const ULowEntryJsonObject* JsonObject1, const ULowEntryJsonObject* JsonObject2);
//
//
//	/**
//	* Creates a Json String from the given Json Object.
//	*/
//	UFUNCTION(BlueprintPure, Category = "Low Entry|Json|Json|Stringify", Meta = (FriendlyName = "To Json String (Json Object)"))
//		static FString Object_ToJsonString(const ULowEntryJsonObject* JsonObject);
//
//	/**
//	* Creates a String Array and fills it with the keys present in the given Json Object.
//	*/
//	UFUNCTION(BlueprintPure, Category = "Low Entry|Json|Object|Other", Meta = (FriendlyName = "Get Keys (Json Object)"))
//		static TArray<FString> Object_GetKeys(const ULowEntryJsonObject* JsonObject);
//
//	/**
//	* Creates a Json Array and fills it with the values present in the given Json Object.
//	*/
//	UFUNCTION(BlueprintPure, Category = "Low Entry|Json|Object|Other", Meta = (FriendlyName = "Get Values (Json Object)"))
//		static ULowEntryJsonArray* Object_GetValues(const ULowEntryJsonObject* JsonObject);
//
//	/**
//	* Returns the number of entries in the given Json Object.
//	*/
//	UFUNCTION(BlueprintPure, Category = "Low Entry|Json|Object|Other", Meta = (FriendlyName = "Length (Json Object)"))
//		static int32 Object_Length(const ULowEntryJsonObject* JsonObject);
//
//
//
//public: // Object Iterator
//	/**
//	* Creates a new Json Object Iterator that will iterate over the keys and values of the given Json Object.
//	*
//	* The Json Object Iterator will only iterate over the keys and values present in the Json Object at the time of creating this Json Object Iterator.
//	* It will always keep iterating over the same keys and values, even when the Json Object has been changed, deleted, cleared, etc.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Object|Iterator", Meta = (FriendlyName = "Create Json Object Iterator"))
//		static ULowEntryJsonObjectIterator* ObjectIterator_Create(const ULowEntryJsonObject* JsonObject);
//
//	/**
//	* Creates a new Json Object Iterator that will iterate over the same keys and values as the given Json Object Iterator.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Object|Iterator", Meta = (FriendlyName = "Clone Json Object Iterator"))
//		static ULowEntryJsonObjectIterator* ObjectIterator_Clone(const ULowEntryJsonObjectIterator* JsonObjectIterator);
//
//
//	/**
//	* Returns the String Array the given Json Object Iterator iterates over.
//	*/
//	UFUNCTION(BlueprintPure, Category = "Low Entry|Json|Object|Iterator", Meta = (FriendlyName = "Get Keys (Json Object Iterator)"))
//		static TArray<FString> ObjectIterator_GetKeys(const ULowEntryJsonObjectIterator* JsonObjectIterator);
//
//	/**
//	* Returns the Json Array the given Json Object Iterator iterates over.
//	*/
//	UFUNCTION(BlueprintPure, Category = "Low Entry|Json|Object|Iterator", Meta = (FriendlyName = "Get Values (Json Object Iterator)"))
//		static ULowEntryJsonArray* ObjectIterator_GetValues(const ULowEntryJsonObjectIterator* JsonObjectIterator);
//
//	/**
//	* Returns the number of entries the given Json Object Iterator iterates over.
//	*/
//	UFUNCTION(BlueprintPure, Category = "Low Entry|Json|Object|Iterator", Meta = (FriendlyName = "Length (Json Object Iterator)"))
//		static int32 ObjectIterator_Length(const ULowEntryJsonObjectIterator* JsonObjectIterator);
//
//
//
//public: // Array
//	/**
//	* Creates a new Json Array.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Create Json Array"))
//		static ULowEntryJsonArray* Array_Create();
//
//	/**
//	* Creates a new Json Array and fills it with the given Strings.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Create Json Array (String Array)"))
//		static ULowEntryJsonArray* Array_CreateFromStringArray(const TArray<FString>& Data);
//
//	/**
//	* Creates a new Json Array and fills it with the given Integers.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Create Json Array (Integer Array)"))
//		static ULowEntryJsonArray* Array_CreateFromIntegerArray(const TArray<int32>& Data);
//
//	/**
//	* Creates a new Json Array and fills it with the given Floats.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Create Json Array (Float Array)"))
//		static ULowEntryJsonArray* Array_CreateFromFloatArray(const TArray<float>& Data);
//
//	/**
//	* Creates a new Json Array and fills it with the given Bytes.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Create Json Array (Byte Array)"))
//		static ULowEntryJsonArray* Array_CreateFromByteArray(const TArray<uint8>& Data);
//
//	/**
//	* Creates a new Json Array and fills it with the given Booleans.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Create Json Array (Boolean Array)"))
//		static ULowEntryJsonArray* Array_CreateFromBooleanArray(const TArray<bool>& Data);
//
//	/**
//	* Creates a new Json Array and fills it with copies of the given Json Objects.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Create Json Array (Json Object Array)"))
//		static ULowEntryJsonArray* Array_CreateFromJsonObjectArray(const TArray<ULowEntryJsonObject*>& Data);
//
//	/**
//	* Creates a new Json Array and fills it with copies of the given Json Arrays.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Create Json Array (Json Array Array)"))
//		static ULowEntryJsonArray* Array_CreateFromJsonArrayArray(const TArray<ULowEntryJsonArray*>& Data);
//
//	/**
//	* Creates a new Json Array and fills it with copies of the values of the given Json Values.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Create Json Array (Json Value Array)"))
//		static ULowEntryJsonArray* Array_CreateFromJsonValueArray(const TArray<ULowEntryJsonValue*>& Data);
//
//	/**
//	* Creates a new Json Array and fills it with a copy of the data from the given Json Array.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Clone (Json Array)"))
//		static ULowEntryJsonArray* Array_Clone(const ULowEntryJsonArray* JsonArray);
//
//	/**
//	* Creates a new Json Array and fills it with a copy of the data from the two given Json Arrays.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Merge (Json Array)"))
//		static ULowEntryJsonArray* Array_Merge(const ULowEntryJsonArray* JsonArray1, const ULowEntryJsonArray* JsonArray2);
//
//
//	/**
//	* Creates a Json String from the given Json Array.
//	*/
//	UFUNCTION(BlueprintPure, Category = "Low Entry|Json|Json|Stringify", Meta = (FriendlyName = "To Json String (Json Array)"))
//		static FString Array_ToJsonString(const ULowEntryJsonArray* JsonArray);
//
//	/**
//	* Returns the number of entries in the given Json Array.
//	*/
//	UFUNCTION(BlueprintPure, Category = "Low Entry|Json|Array|Other", Meta = (FriendlyName = "Length (Json Array)"))
//		static int32 Array_Length(const ULowEntryJsonArray* JsonArray);
//
//
//
//public: // Value
//	/**
//	* Creates a new Json Value and sets its value to null.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Create Json Value"))
//		static ULowEntryJsonValue* Value_Create();
//
//	/**
//	* Creates a new Json Value and sets its value to null.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Create Json Value (Null)"))
//		static ULowEntryJsonValue* Value_CreateFromNull();
//
//	/**
//	* Creates a new Json Value and sets its value to the given String.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Create Json Value (String)"))
//		static ULowEntryJsonValue* Value_CreateFromString(const FString& Data);
//
//	/**
//	* Creates a new Json Value and sets its value to the given Integer.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Create Json Value (Integer)"))
//		static ULowEntryJsonValue* Value_CreateFromInteger(const int32 Data);
//
//	/**
//	* Creates a new Json Value and sets its value to the given Float.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Create Json Value (Float)"))
//		static ULowEntryJsonValue* Value_CreateFromFloat(const float Data);
//
//	/**
//	* Creates a new Json Value and sets its value to the given Byte.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Create Json Value (Byte)"))
//		static ULowEntryJsonValue* Value_CreateFromByte(const uint8 Data);
//
//	/**
//	* Creates a new Json Value and sets its value to the given Boolean.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Create Json Value (Boolean)"))
//		static ULowEntryJsonValue* Value_CreateFromBoolean(const bool Data);
//
//	/**
//	* Creates a new Json Value and sets its value to a copy the given Json Object.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Create Json Value (Json Object)"))
//		static ULowEntryJsonValue* Value_CreateFromJsonObject(const ULowEntryJsonObject* Data);
//
//	/**
//	* Creates a new Json Value and sets its value to a copy the given Json Array.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Create Json Value (Json Array)"))
//		static ULowEntryJsonValue* Value_CreateFromJsonArray(const ULowEntryJsonArray* Data);
//
//	/**
//	* Creates a new Json Value and sets its value to a copy of the value of the given Json Value.
//	*/
//	UFUNCTION(BlueprintCallable, Category = "Low Entry|Json|Value|Other", Meta = (FriendlyName = "Clone (Json Value)"))
//		static ULowEntryJsonValue* Value_Clone(const ULowEntryJsonValue* JsonValue);
};
