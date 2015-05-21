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
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (DisplayName = "Newline Character (\\n)", CompactNodeTitle = "\\n"))
		static FString NewlineCharacter();

	/**
	* Returns a Windows newline character (\r\n).
	* 
	* This blueprint will always return a \r\n character, no matter what Operating System it is running on.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (DisplayName = "Windows Newline Character (\\r\\n)", CompactNodeTitle = "\\r\\n"))
		static FString WindowsNewlineCharacter();

	/**
	* Returns a carriage return (\r).
	* 
	* This blueprint will always return a \r character, no matter what Operating System it is running on.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (DisplayName = "Carriage Return Character (\\r)", CompactNodeTitle = "\\r"))
		static FString CarriageReturnCharacter();

	/**
	* Returns a tab character (\t).
	* 
	* This blueprint will always return a \t character, no matter what Operating System it is running on.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Character", Meta = (DisplayName = "Tab Character (\\t)", CompactNodeTitle = "\\t"))
		static FString TabCharacter();



	/**
	* Returns the minimum value of the given values.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Min (String)", CompactNodeTitle = "MIN", CommutativeAssociativeBinaryOperator = "true"))
		static FString MinString(const FString& A, const FString& B);

	/**
	* Returns the maximum value of the given values.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Max (String)", CompactNodeTitle = "MAX", CommutativeAssociativeBinaryOperator = "true"))
		static FString MaxString(const FString& A, const FString& B);

	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "String < String", CompactNodeTitle = "<"))
		static bool LessStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "String > String", CompactNodeTitle = ">"))
		static bool GreaterStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "String <= String", CompactNodeTitle = "<="))
		static bool LessEqualStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "String >= String", CompactNodeTitle = ">="))
		static bool GreaterEqualStringString(const FString& A, const FString& B);



	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer < Float", CompactNodeTitle = "<"))
		static bool LessIntegerFloat(const int32 A, const float B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer > Float", CompactNodeTitle = ">"))
		static bool GreaterIntegerFloat(const int32 A, const float B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer <= Float", CompactNodeTitle = "<="))
		static bool LessEqualIntegerFloat(const int32 A, const float B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer >= Float", CompactNodeTitle = ">="))
		static bool GreaterEqualIntegerFloat(const int32 A, const float B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer < Byte", CompactNodeTitle = "<"))
		static bool LessIntegerByte(const int32 A, const uint8 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer > Byte", CompactNodeTitle = ">"))
		static bool GreaterIntegerByte(const int32 A, const uint8 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer <= Byte", CompactNodeTitle = "<="))
		static bool LessEqualIntegerByte(const int32 A, const uint8 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Integer >= Byte", CompactNodeTitle = ">="))
		static bool GreaterEqualIntegerByte(const int32 A, const uint8 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float < Integer", CompactNodeTitle = "<"))
		static bool LessFloatInteger(const float A, const int32 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float > Integer", CompactNodeTitle = ">"))
		static bool GreaterFloatInteger(const float A, const int32 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float <= Integer", CompactNodeTitle = "<="))
		static bool LessEqualFloatInteger(const float A, const int32 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float >= Integer", CompactNodeTitle = ">="))
		static bool GreaterEqualFloatInteger(const float A, const int32 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float < Byte", CompactNodeTitle = "<"))
		static bool LessFloatByte(const float A, const uint8 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float > Byte", CompactNodeTitle = ">"))
		static bool GreaterFloatByte(const float A, const uint8 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float <= Byte", CompactNodeTitle = "<="))
		static bool LessEqualFloatByte(const float A, const uint8 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Float >= Byte", CompactNodeTitle = ">="))
		static bool GreaterEqualFloatByte(const float A, const uint8 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte < Integer", CompactNodeTitle = "<"))
		static bool LessByteInteger(const uint8 A, const int32 B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte > Integer", CompactNodeTitle = ">"))
		static bool GreaterByteInteger(const uint8 A, const int32 B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte <= Integer", CompactNodeTitle = "<="))
		static bool LessEqualByteInteger(const uint8 A, const int32 B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte >= Integer", CompactNodeTitle = ">="))
		static bool GreaterEqualByteInteger(const uint8 A, const int32 B);


	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte < Float", CompactNodeTitle = "<"))
		static bool LessByteFloat(const uint8 A, const float B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte > Float", CompactNodeTitle = ">"))
		static bool GreaterByteFloat(const uint8 A, const float B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte <= Float", CompactNodeTitle = "<="))
		static bool LessEqualByteFloat(const uint8 A, const float B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "Byte >= Float", CompactNodeTitle = ">="))
		static bool GreaterEqualByteFloat(const uint8 A, const float B);



	/**
	* Rounds to the given Decimals.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (DisplayName = "Round (With Decimals)"))
		static float RoundDecimals(float Number, int32 Decimals);



	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (DisplayName = "Min & Max (String)"))
		static void MinAndMaxString(const FString& Value1, const FString& Value2, FString& MaxValue, FString& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (DisplayName = "Min & Max (Integer)"))
		static void MinAndMaxInteger(const int32 Value1, const int32 Value2, int32& MaxValue, int32& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (DisplayName = "Min & Max (Float)"))
		static void MinAndMaxFloat(const float Value1, const float Value2, float& MaxValue, float& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (DisplayName = "Min & Max (Byte)"))
		static void MinAndMaxByte(const uint8 Value1, const uint8 Value2, uint8& MaxValue, uint8& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (DisplayName = "Min & Max (DateTime)"))
		static void MinAndMaxDateTime(const FDateTime& Value1, const FDateTime& Value2, FDateTime& MaxValue, FDateTime& MinValue);

	/**
	* Returns the minimum and maximum value of the two given values.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Min & Max", Meta = (DisplayName = "Min & Max (Timespan)"))
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
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (DisplayName = "Sort (String Array)"))
		static void SortStringArray(TArray<FString>& StringArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (DisplayName = "Sort (Integer Array)"))
		static void SortIntegerArray(TArray<int32>& IntegerArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (DisplayName = "Sort (Float Array)"))
		static void SortFloatArray(TArray<float>& FloatArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (DisplayName = "Sort (Byte Array)"))
		static void SortByteArray(TArray<uint8>& ByteArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (DisplayName = "Sort (DateTime Array)"))
		static void SortDateTimeArray(TArray<FDateTime>& DateTimeArray, const bool Reversed = false);

	/**
	* Sorts the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Array|Sort", Meta = (DisplayName = "Sort (Timespan Array)"))
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



	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Float"))
		static float LocalFloat(float Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Integer"))
		static int32 LocalInteger(int32 Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Byte"))
		static uint8 LocalByte(uint8 Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Boolean"))
		static bool LocalBoolean(bool Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local String"))
		static FString LocalString(const FString& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Name"))
		static FName LocalName(const FName& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Text"))
		static FText LocalText(const FText& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Vector"))
		static FVector LocalVector(const FVector& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Rotator"))
		static FRotator LocalRotator(const FRotator& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Date Time"))
		static FDateTime LocalDateTime(const FDateTime& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Timespan"))
		static FTimespan LocalTimespan(const FTimespan& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Class"))
		static UClass* LocalClass(UClass* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Object"))
		static UObject* LocalObject(UObject* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Actor"))
		static AActor* LocalActor(AActor* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Actor Component"))
		static UActorComponent* LocalActorComponent(UActorComponent* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Pawn"))
		static APawn* LocalPawn(APawn* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Enum"))
		static UEnum* LocalEnum(UEnum* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Struct"))
		static UStruct* LocalStruct(UStruct* Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Interface"))
		static TScriptInterface<IInterface> LocalInterface(TScriptInterface<IInterface> Value);



	/**
	* Converts an Array of Strings to a String.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Implode"))
		static FString ArrayToString(const TArray<FString>& Array, const FString& Delimiter = TEXT(""));



	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Float Array"))
		static TArray<float> LocalFloatArray(const TArray<float>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Integer Array"))
		static TArray<int32> LocalIntegerArray(const TArray<int32>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Byte Array"))
		static TArray<uint8> LocalByteArray(const TArray<uint8>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Boolean Array"))
		static TArray<bool> LocalBooleanArray(const TArray<bool>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local String Array"))
		static TArray<FString> LocalStringArray(const TArray<FString>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Name Array"))
		static TArray<FName> LocalNameArray(const TArray<FName>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Text Array"))
		static TArray<FText> LocalTextArray(const TArray<FText>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Vector Array"))
		static TArray<FVector> LocalVectorArray(const TArray<FVector>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Rotator Array"))
		static TArray<FRotator> LocalRotatorArray(const TArray<FRotator>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Date Time Array"))
		static TArray<FDateTime> LocalDateTimeArray(const TArray<FDateTime>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Timespan Array"))
		static TArray<FTimespan> LocalTimespanArray(const TArray<FTimespan>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Class Array"))
		static TArray<TSubclassOf<UObject>> LocalClassArray(const TArray<TSubclassOf<UObject>>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Object Array"))
		static TArray<UObject*> LocalObjectArray(const TArray<UObject*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Actor Array"))
		static TArray<AActor*> LocalActorArray(const TArray<AActor*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Actor Component Array"))
		static TArray<UActorComponent*> LocalActorComponentArray(const TArray<UActorComponent*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Pawn Array"))
		static TArray<APawn*> LocalPawnArray(const TArray<APawn*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Enum Array"))
		static TArray<UEnum*> LocalEnumArray(const TArray<UEnum*>& Value);

	/**
	* Creates a local variable.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Local", Meta = (DisplayName = "Local Struct Array"))
		static TArray<UStruct*> LocalStructArray(const TArray<UStruct*>& Value);
};
