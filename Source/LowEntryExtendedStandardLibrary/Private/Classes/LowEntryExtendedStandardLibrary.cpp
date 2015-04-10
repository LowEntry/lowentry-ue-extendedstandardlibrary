#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryExtendedStandardLibrary.h"



// init >>
	ULowEntryExtendedStandardLibrary::ULowEntryExtendedStandardLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}
// init <<
	


FString ULowEntryExtendedStandardLibrary::MinString(const FString& A, const FString& B)
{
	if(A >= B)
	{
		return B;
	}
	else
	{
		return A;
	}
}

FString ULowEntryExtendedStandardLibrary::MaxString(const FString& A, const FString& B)
{
	if(A >= B)
	{
		return A;
	}
	else
	{
		return B;
	}
}

bool ULowEntryExtendedStandardLibrary::LessStringString(const FString& A, const FString& B)
{
	return (A < B);
}

bool ULowEntryExtendedStandardLibrary::GreaterStringString(const FString& A, const FString& B)
{
	return (A > B);
}

bool ULowEntryExtendedStandardLibrary::LessEqualStringString(const FString& A, const FString& B)
{
	return (A <= B);
}

bool ULowEntryExtendedStandardLibrary::GreaterEqualStringString(const FString& A, const FString& B)
{
	return (A >= B);
}



void ULowEntryExtendedStandardLibrary::MinAndMaxString(const FString& Value1, const FString& Value2, FString& MaxValue, FString& MinValue)
{
	if(Value1 >= Value2)
	{
		MaxValue = Value1;
		MinValue = Value2;
	}
	else
	{
		MaxValue = Value2;
		MinValue = Value1;
	}
}

void ULowEntryExtendedStandardLibrary::MinAndMaxInteger(const int32 Value1, const int32 Value2, int32& MaxValue, int32& MinValue)
{
	if(Value1 >= Value2)
	{
		MaxValue = Value1;
		MinValue = Value2;
	}
	else
	{
		MaxValue = Value2;
		MinValue = Value1;
	}
}

void ULowEntryExtendedStandardLibrary::MinAndMaxFloat(const float Value1, const float Value2, float& MaxValue, float& MinValue)
{
	if(Value1 >= Value2)
	{
		MaxValue = Value1;
		MinValue = Value2;
	}
	else
	{
		MaxValue = Value2;
		MinValue = Value1;
	}
}

void ULowEntryExtendedStandardLibrary::MinAndMaxByte(const uint8 Value1, const uint8 Value2, uint8& MaxValue, uint8& MinValue)
{
	if(Value1 >= Value2)
	{
		MaxValue = Value1;
		MinValue = Value2;
	}
	else
	{
		MaxValue = Value2;
		MinValue = Value1;
	}
}

void ULowEntryExtendedStandardLibrary::MinAndMaxDateTime(const FDateTime& Value1, const FDateTime& Value2, FDateTime& MaxValue, FDateTime& MinValue)
{
	if(Value1 >= Value2)
	{
		MaxValue = Value1;
		MinValue = Value2;
	}
	else
	{
		MaxValue = Value2;
		MinValue = Value1;
	}
}

void ULowEntryExtendedStandardLibrary::MinAndMaxTimespan(const FTimespan& Value1, const FTimespan& Value2, FTimespan& MaxValue, FTimespan& MinValue)
{
	if(Value1 >= Value2)
	{
		MaxValue = Value1;
		MinValue = Value2;
	}
	else
	{
		MaxValue = Value2;
		MinValue = Value1;
	}
}



void ULowEntryExtendedStandardLibrary::MaxOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMaxValue, FString& MaxValue)
{
	MaxValue = FMath::Max(StringArray, &IndexOfMaxValue);
}

void ULowEntryExtendedStandardLibrary::MinOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMinValue, FString& MinValue)
{
	MinValue = FMath::Min(StringArray, &IndexOfMinValue);
}

void ULowEntryExtendedStandardLibrary::MaxOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMaxValue, FDateTime& MaxValue)
{
	MaxValue = FMath::Max(DateTimeArray, &IndexOfMaxValue);
}

void ULowEntryExtendedStandardLibrary::MinOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMinValue, FDateTime& MinValue)
{
	MinValue = FMath::Min(DateTimeArray, &IndexOfMinValue);
}

void ULowEntryExtendedStandardLibrary::MaxOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMaxValue, FTimespan& MaxValue)
{
	MaxValue = FMath::Max(TimespanArray, &IndexOfMaxValue);
}

void ULowEntryExtendedStandardLibrary::MinOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMinValue, FTimespan& MinValue)
{
	MinValue = FMath::Min(TimespanArray, &IndexOfMinValue);
}



void ULowEntryExtendedStandardLibrary::SortStringArray(TArray<FString>& StringArray, bool Reversed)
{
	if(!Reversed)
	{
		StringArray.Sort([] (const FString& A, const FString& B){
			return A < B;
		});
	}
	else
	{
		StringArray.Sort([] (const FString& A, const FString& B){
			return A > B;
		});
	}
}

void ULowEntryExtendedStandardLibrary::SortIntegerArray(TArray<int32>& IntegerArray, bool Reversed)
{
	if(!Reversed)
	{
		IntegerArray.Sort([] (const int32 A, const int32 B){
			return A < B;
		});
	}
	else
	{
		IntegerArray.Sort([] (const int32 A, const int32 B){
			return A > B;
		});
	}
}

void ULowEntryExtendedStandardLibrary::SortFloatArray(TArray<float>& FloatArray, bool Reversed)
{
	if(!Reversed)
	{
		FloatArray.Sort([] (const float A, const float B){
			return A < B;
		});
	}
	else
	{
		FloatArray.Sort([] (const float A, const float B){
			return A > B;
		});
	}
}

void ULowEntryExtendedStandardLibrary::SortByteArray(TArray<uint8>& ByteArray, bool Reversed)
{
	if(!Reversed)
	{
		ByteArray.Sort([] (const uint8 A, const uint8 B){
			return A < B;
		});
	}
	else
	{
		ByteArray.Sort([] (const uint8 A, const uint8 B){
			return A > B;
		});
	}
}

void ULowEntryExtendedStandardLibrary::SortDateTimeArray(TArray<FDateTime>& DateTimeArray, bool Reversed)
{
	if(!Reversed)
	{
		DateTimeArray.Sort([] (const FDateTime& A, const FDateTime& B){
			return A < B;
		});
	}
	else
	{
		DateTimeArray.Sort([] (const FDateTime& A, const FDateTime& B){
			return A > B;
		});
	}
}

void ULowEntryExtendedStandardLibrary::SortTimespanArray(TArray<FTimespan>& TimespanArray, bool Reversed)
{
	if(!Reversed)
	{
		TimespanArray.Sort([] (const FTimespan& A, const FTimespan& B){
			return A < B;
		});
	}
	else
	{
		TimespanArray.Sort([] (const FTimespan& A, const FTimespan& B){
			return A > B;
		});
	}
}



void ULowEntryExtendedStandardLibrary::RandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if(LatentActionManager.FindExistingAction<FDelayAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FDelayAction(FMath::FRandRange(MinDuration, MaxDuration), LatentInfo));
		}
	}
}

void ULowEntryExtendedStandardLibrary::RetriggerableRandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FDelayAction* Action = LatentActionManager.FindExistingAction<FDelayAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if(Action == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FDelayAction(FMath::FRandRange(MinDuration, MaxDuration), LatentInfo));
		}
		else
		{
			Action->TimeRemaining = FMath::FRandRange(MinDuration, MaxDuration);
		}
	}
}
