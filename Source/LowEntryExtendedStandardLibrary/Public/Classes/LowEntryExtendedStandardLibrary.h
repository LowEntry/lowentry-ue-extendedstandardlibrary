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
	* Returns a newline character (\n).
	* 
	* This blueprint will always return a \n character, no matter what Operating System it is running on.
	* 
	* Note: It is actually called a line feed, the blueprint is called Newline Character for recognition purposes.
	* On *nix systems \n is used as a newline character, on Windows \r\n is used as a newline character.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (FriendlyName = "Newline Character (\\n)", CompactNodeTitle = "\\n"))
		static FString NewlineCharacter();

	/**
	* Returns a Windows newline character (\r\n).
	* 
	* This blueprint will always return a \r\n character, no matter what Operating System it is running on.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (FriendlyName = "Windows Newline Character (\\r\\n)", CompactNodeTitle = "\\r\\n"))
		static FString WindowsNewlineCharacter();

	/**
	* Returns a carriage return (\r).
	* 
	* This blueprint will always return a \r character, no matter what Operating System it is running on.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (FriendlyName = "Carriage Return Character (\\r)", CompactNodeTitle = "\\r"))
		static FString CarriageReturnCharacter();

	/**
	* Returns a tab character (\t).
	* 
	* This blueprint will always return a \t character, no matter what Operating System it is running on.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (FriendlyName = "Tab Character (\\t)", CompactNodeTitle = "\\t"))
		static FString TabCharacter();



	/**
	* Returns the minimum value of the given values.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (FriendlyName = "Min (String)", CompactNodeTitle = "MIN", CommutativeAssociativeBinaryOperator = "true"))
		static FString MinString(const FString& A, const FString& B);

	/**
	* Returns the maximum value of the given values.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (FriendlyName = "Max (String)", CompactNodeTitle = "MAX", CommutativeAssociativeBinaryOperator = "true"))
		static FString MaxString(const FString& A, const FString& B);

	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (FriendlyName = "String < String", CompactNodeTitle = "<"))
		static bool LessStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (FriendlyName = "String > String", CompactNodeTitle = ">"))
		static bool GreaterStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (FriendlyName = "String <= String", CompactNodeTitle = "<="))
		static bool LessEqualStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (FriendlyName = "String >= String", CompactNodeTitle = ">="))
		static bool GreaterEqualStringString(const FString& A, const FString& B);



	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Integer < Float", CompactNodeTitle = "<"))
		static bool LessIntegerFloat(const int32 A, const float B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Integer > Float", CompactNodeTitle = ">"))
		static bool GreaterIntegerFloat(const int32 A, const float B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Integer <= Float", CompactNodeTitle = "<="))
		static bool LessEqualIntegerFloat(const int32 A, const float B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Integer >= Float", CompactNodeTitle = ">="))
		static bool GreaterEqualIntegerFloat(const int32 A, const float B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Integer < Byte", CompactNodeTitle = "<"))
		static bool LessIntegerByte(const int32 A, const uint8 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Integer > Byte", CompactNodeTitle = ">"))
		static bool GreaterIntegerByte(const int32 A, const uint8 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Integer <= Byte", CompactNodeTitle = "<="))
		static bool LessEqualIntegerByte(const int32 A, const uint8 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Integer >= Byte", CompactNodeTitle = ">="))
		static bool GreaterEqualIntegerByte(const int32 A, const uint8 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Float < Integer", CompactNodeTitle = "<"))
		static bool LessFloatInteger(const float A, const int32 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Float > Integer", CompactNodeTitle = ">"))
		static bool GreaterFloatInteger(const float A, const int32 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Float <= Integer", CompactNodeTitle = "<="))
		static bool LessEqualFloatInteger(const float A, const int32 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Float >= Integer", CompactNodeTitle = ">="))
		static bool GreaterEqualFloatInteger(const float A, const int32 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Float < Byte", CompactNodeTitle = "<"))
		static bool LessFloatByte(const float A, const uint8 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Float > Byte", CompactNodeTitle = ">"))
		static bool GreaterFloatByte(const float A, const uint8 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Float <= Byte", CompactNodeTitle = "<="))
		static bool LessEqualFloatByte(const float A, const uint8 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Float >= Byte", CompactNodeTitle = ">="))
		static bool GreaterEqualFloatByte(const float A, const uint8 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Byte < Integer", CompactNodeTitle = "<"))
		static bool LessByteInteger(const uint8 A, const int32 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Byte > Integer", CompactNodeTitle = ">"))
		static bool GreaterByteInteger(const uint8 A, const int32 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Byte <= Integer", CompactNodeTitle = "<="))
		static bool LessEqualByteInteger(const uint8 A, const int32 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Byte >= Integer", CompactNodeTitle = ">="))
		static bool GreaterEqualByteInteger(const uint8 A, const int32 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Byte < Float", CompactNodeTitle = "<"))
		static bool LessByteFloat(const uint8 A, const float B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Byte > Float", CompactNodeTitle = ">"))
		static bool GreaterByteFloat(const uint8 A, const float B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Byte <= Float", CompactNodeTitle = "<="))
		static bool LessEqualByteFloat(const uint8 A, const float B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (FriendlyName = "Byte >= Float", CompactNodeTitle = ">="))
		static bool GreaterEqualByteFloat(const uint8 A, const float B);



	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (FriendlyName = "Min & Max (String)"))
		static void MinAndMaxString(const FString& Value1, const FString& Value2, FString& MaxValue, FString& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (FriendlyName = "Min & Max (Integer)"))
		static void MinAndMaxInteger(const int32 Value1, const int32 Value2, int32& MaxValue, int32& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (FriendlyName = "Min & Max (Float)"))
		static void MinAndMaxFloat(const float Value1, const float Value2, float& MaxValue, float& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (FriendlyName = "Min & Max (Byte)"))
		static void MinAndMaxByte(const uint8 Value1, const uint8 Value2, uint8& MaxValue, uint8& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (FriendlyName = "Min & Max (DateTime)"))
		static void MinAndMaxDateTime(const FDateTime& Value1, const FDateTime& Value2, FDateTime& MaxValue, FDateTime& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (FriendlyName = "Min & Max (Timespan)"))
		static void MinAndMaxTimespan(const FTimespan& Value1, const FTimespan& Value2, FTimespan& MaxValue, FTimespan& MinValue);



	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Array|Max")
		static void MaxOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMaxValue, FString& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Array|Min")
		static void MinOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMinValue, FString& MinValue);

	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Array|Max")
		static void MaxOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMaxValue, FDateTime& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Array|Min")
		static void MinOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMinValue, FDateTime& MinValue);

	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Array|Max")
		static void MaxOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMaxValue, FTimespan& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Array|Min")
		static void MinOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMinValue, FTimespan& MinValue);



	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (FriendlyName = "Sort (String Array)"))
		static void SortStringArray(TArray<FString>& StringArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (FriendlyName = "Sort (Integer Array)"))
		static void SortIntegerArray(TArray<int32>& IntegerArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (FriendlyName = "Sort (Float Array)"))
		static void SortFloatArray(TArray<float>& FloatArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (FriendlyName = "Sort (Byte Array)"))
		static void SortByteArray(TArray<uint8>& ByteArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (FriendlyName = "Sort (DateTime Array)"))
		static void SortDateTimeArray(TArray<FDateTime>& DateTimeArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (FriendlyName = "Sort (Timespan Array)"))
		static void SortTimespanArray(TArray<FTimespan>& TimespanArray, const bool Reversed = false);



	/**
	* Perform a latent action with a random delay (specified in seconds).  Calling again while it is counting down will be ignored.
	*
	* @param WorldContext	World context.
	* @param MinDuration 	minimum length of delay (in seconds).
	* @param MaxDuration 	maximum length of delay (in seconds).
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Flow Control|Delay", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void	RandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, struct FLatentActionInfo LatentInfo);

	/**
	* Perform a latent action with a retriggerable random delay (specified in seconds).  Calling again while it is counting down will reset the countdown to a new random Duration.
	*
	* @param WorldContext	World context.
	* @param MinDuration 	minimum length of delay (in seconds).
	* @param MaxDuration 	maximum length of delay (in seconds).
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Flow Control|Delay", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void RetriggerableRandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, FLatentActionInfo LatentInfo);
};
