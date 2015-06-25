#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryExtendedStandardLibrary.h"



// init >>
	ULowEntryExtendedStandardLibrary::ULowEntryExtendedStandardLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}
// init <<



TArray<uint8> ULowEntryExtendedStandardLibrary::StringToBytesUtf8(const FString& String)
{
	int32 Size = String.Len();
	if(Size <= 0)
	{
		return TArray<uint8>();
	}

	TArray<uint8> ByteArray;
	const TCHAR* Chars = String.GetCharArray().GetData();
	ByteArray.Append((uint8*) TCHAR_TO_UTF8(Chars), Size);
	return ByteArray;
}

FString ULowEntryExtendedStandardLibrary::BytesToStringUtf8(const TArray<uint8>& ByteArray)
{
	int32 Size = ByteArray.Num();
	if(Size <= 0)
	{
		return TEXT("");
	}

	FString String = TEXT("");
	const uint8* Bytes = ByteArray.GetData();
	String.AppendChars(UTF8_TO_TCHAR(Bytes), Size);
	return String;
}


TArray<uint8> ULowEntryExtendedStandardLibrary::HexToBytes(const FString& String)
{
	int32 Size = String.Len();
	if(Size <= 0)
	{
		return TArray<uint8>();
	}

	for(TCHAR c : String)
	{
		if(!CheckTCharIsHex(c))
		{
			return TArray<uint8>();
		}
	}

	uint8* Bytes = new uint8[Size];
	int32 ByteCount = ::HexToBytes(String, Bytes);
	TArray<uint8> ByteArray;
	ByteArray.Append(Bytes, ByteCount + 1);
	delete [] Bytes;
	return ByteArray;
}

FString ULowEntryExtendedStandardLibrary::BytesToHex(const TArray<uint8>& ByteArray)
{
	int32 Size = ByteArray.Num();
	if(Size <= 0)
	{
		return TEXT("");
	}
	return ::BytesToHex(ByteArray.GetData(), Size);
}


TArray<uint8> ULowEntryExtendedStandardLibrary::Base64ToBytes(const FString& Base64)
{
	TArray<uint8> ByteArray;
	bool success = FBase64::Decode(Base64, ByteArray);
	if(!success)
	{
		return TArray<uint8>();
	}
	return ByteArray;
}

FString ULowEntryExtendedStandardLibrary::BytesToBase64(const TArray<uint8>& ByteArray)
{
	return FBase64::Encode(ByteArray);
}



TArray<uint8> ULowEntryExtendedStandardLibrary::Md5(const TArray<uint8>& ByteArray)
{
	FMD5 Hasher;
	int32 Size = ByteArray.Num();
	if(Size > 0)
	{
		const uint8* Bytes = ByteArray.GetData();
		Hasher.Update((uint8*) Bytes, Size);
	}

	uint8 DigestBytes[16];
	Hasher.Final(DigestBytes);
	TArray<uint8> DigestByteArray;
	DigestByteArray.Append(DigestBytes, 16);
	return DigestByteArray;
}

TArray<uint8> ULowEntryExtendedStandardLibrary::Sha1(const TArray<uint8>& ByteArray)
{
	FSHA1 Hasher;
	int32 Size = ByteArray.Num();
	if(Size > 0)
	{
		const uint8* Bytes = ByteArray.GetData();
		Hasher.Update((uint8*) Bytes, Size);
	}

	uint8 DigestBytes[FSHA1::DigestSize];
	Hasher.Final();
	Hasher.GetHash(DigestBytes);
	TArray<uint8> DigestByteArray;
	DigestByteArray.Append(DigestBytes, FSHA1::DigestSize);
	return DigestByteArray;
}



FString ULowEntryExtendedStandardLibrary::NewlineCharacter()
{
	return TEXT("\n");
}

FString ULowEntryExtendedStandardLibrary::WindowsNewlineCharacter()
{
	return TEXT("\r\n");
}

FString ULowEntryExtendedStandardLibrary::CarriageReturnCharacter()
{
	return TEXT("\r");
}

FString ULowEntryExtendedStandardLibrary::TabCharacter()
{
	return TEXT("\t");
}
	


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



bool ULowEntryExtendedStandardLibrary::LessIntegerFloat(const int32 A, const float B)
{
	return (A < B);
}

bool ULowEntryExtendedStandardLibrary::GreaterIntegerFloat(const int32 A, const float B)
{
	return (A > B);
}

bool ULowEntryExtendedStandardLibrary::LessEqualIntegerFloat(const int32 A, const float B)
{
	return (A <= B);
}

bool ULowEntryExtendedStandardLibrary::GreaterEqualIntegerFloat(const int32 A, const float B)
{
	return (A >= B);
}


bool ULowEntryExtendedStandardLibrary::LessIntegerByte(const int32 A, const uint8 B)
{
	return (A < B);
}

bool ULowEntryExtendedStandardLibrary::GreaterIntegerByte(const int32 A, const uint8 B)
{
	return (A > B);
}

bool ULowEntryExtendedStandardLibrary::LessEqualIntegerByte(const int32 A, const uint8 B)
{
	return (A <= B);
}

bool ULowEntryExtendedStandardLibrary::GreaterEqualIntegerByte(const int32 A, const uint8 B)
{
	return (A >= B);
}


bool ULowEntryExtendedStandardLibrary::LessFloatInteger(const float A, const int32 B)
{
	return (A < B);
}

bool ULowEntryExtendedStandardLibrary::GreaterFloatInteger(const float A, const int32 B)
{
	return (A > B);
}

bool ULowEntryExtendedStandardLibrary::LessEqualFloatInteger(const float A, const int32 B)
{
	return (A <= B);
}

bool ULowEntryExtendedStandardLibrary::GreaterEqualFloatInteger(const float A, const int32 B)
{
	return (A >= B);
}


bool ULowEntryExtendedStandardLibrary::LessFloatByte(const float A, const uint8 B)
{
	return (A < B);
}

bool ULowEntryExtendedStandardLibrary::GreaterFloatByte(const float A, const uint8 B)
{
	return (A > B);
}

bool ULowEntryExtendedStandardLibrary::LessEqualFloatByte(const float A, const uint8 B)
{
	return (A <= B);
}

bool ULowEntryExtendedStandardLibrary::GreaterEqualFloatByte(const float A, const uint8 B)
{
	return (A >= B);
}


bool ULowEntryExtendedStandardLibrary::LessByteInteger(const uint8 A, const int32 B)
{
	return (A < B);
}

bool ULowEntryExtendedStandardLibrary::GreaterByteInteger(const uint8 A, const int32 B)
{
	return (A > B);
}

bool ULowEntryExtendedStandardLibrary::LessEqualByteInteger(const uint8 A, const int32 B)
{
	return (A <= B);
}

bool ULowEntryExtendedStandardLibrary::GreaterEqualByteInteger(const uint8 A, const int32 B)
{
	return (A >= B);
}


bool ULowEntryExtendedStandardLibrary::LessByteFloat(const uint8 A, const float B)
{
	return (A < B);
}

bool ULowEntryExtendedStandardLibrary::GreaterByteFloat(const uint8 A, const float B)
{
	return (A > B);
}

bool ULowEntryExtendedStandardLibrary::LessEqualByteFloat(const uint8 A, const float B)
{
	return (A <= B);
}

bool ULowEntryExtendedStandardLibrary::GreaterEqualByteFloat(const uint8 A, const float B)
{
	return (A >= B);
}



float ULowEntryExtendedStandardLibrary::RoundDecimals(float Number, int32 Decimals)
{
	if(Number == 0)
	{
		return Number;
	}
	if(Decimals > 0)
	{
		int64 Multiplier = 1;
		for(int32 i = 1; i <= Decimals; i++)
		{
			Multiplier *= 10;
		}
		float MultiplierFloat = (float) Multiplier;
		return FMath::RoundToFloat(Number * MultiplierFloat) / MultiplierFloat;
	}
	if(Decimals < 0)
	{
		int64 Divider = 1;
		for(int32 i = -1; i >= Decimals; i--)
		{
			Divider *= 10;
		}
		float DividerFloat = (float) Divider;
		return FMath::RoundToFloat(Number / DividerFloat) * DividerFloat;
	}
	return FMath::RoundToFloat(Number);
}

float ULowEntryExtendedStandardLibrary::CeilDecimals(float Number, int32 Decimals)
{
	if(Number == 0)
	{
		return Number;
	}
	if(Decimals > 0)
	{
		int64 Multiplier = 1;
		for(int32 i = 1; i <= Decimals; i++)
		{
			Multiplier *= 10;
		}
		float MultiplierFloat = (float) Multiplier;
		return FMath::CeilToFloat(Number * MultiplierFloat) / MultiplierFloat;
	}
	if(Decimals < 0)
	{
		int64 Divider = 1;
		for(int32 i = -1; i >= Decimals; i--)
		{
			Divider *= 10;
		}
		float DividerFloat = (float) Divider;
		return FMath::CeilToFloat(Number / DividerFloat) * DividerFloat;
	}
	return FMath::CeilToFloat(Number);
}

float ULowEntryExtendedStandardLibrary::FloorDecimals(float Number, int32 Decimals)
{
	if(Number == 0)
	{
		return Number;
	}
	if(Decimals > 0)
	{
		int64 Multiplier = 1;
		for(int32 i = 1; i <= Decimals; i++)
		{
			Multiplier *= 10;
		}
		float MultiplierFloat = (float) Multiplier;
		return FMath::FloorToFloat(Number * MultiplierFloat) / MultiplierFloat;
	}
	if(Decimals < 0)
	{
		int64 Divider = 1;
		for(int32 i = -1; i >= Decimals; i--)
		{
			Divider *= 10;
		}
		float DividerFloat = (float) Divider;
		return FMath::FloorToFloat(Number / DividerFloat) * DividerFloat;
	}
	return FMath::FloorToFloat(Number);
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



void ULowEntryExtendedStandardLibrary::SortStringArray(TArray<FString>& StringArray, const bool Reversed)
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

void ULowEntryExtendedStandardLibrary::SortIntegerArray(TArray<int32>& IntegerArray, const bool Reversed)
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

void ULowEntryExtendedStandardLibrary::SortFloatArray(TArray<float>& FloatArray, const bool Reversed)
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

void ULowEntryExtendedStandardLibrary::SortByteArray(TArray<uint8>& ByteArray, const bool Reversed)
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

void ULowEntryExtendedStandardLibrary::SortDateTimeArray(TArray<FDateTime>& DateTimeArray, const bool Reversed)
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

void ULowEntryExtendedStandardLibrary::SortTimespanArray(TArray<FTimespan>& TimespanArray, const bool Reversed)
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



FString ULowEntryExtendedStandardLibrary::CreateString(const int32 Length, const FString& Filler)
{
	if(Length <= 0)
	{
		return TEXT("");
	}

	FString FillerString = Filler;
	int32 Steps = FillerString.Len();
	if(Steps <= 0)
	{
		FillerString = TEXT(" ");
		Steps = FillerString.Len();
	}
	int32 Overflow = (Steps - (Length % Steps)) % Steps;

	FString String = TEXT("");
	String.Reserve(Length);
	if(Overflow <= 0)
	{
		for(int32 i = 0; i < Length; i += Steps)
		{
			String.Append(FillerString);
		}
	}
	else
	{
		for(int32 i = Steps; i < Length; i += Steps)
		{
			String.Append(FillerString);
		}
		String.Append(FillerString.Left(Steps - Overflow));
	}
	return String;
}



FString ULowEntryExtendedStandardLibrary::RemoveCharactersExcept(const FString& String, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep)
{
	if(String.Len() <= 0)
	{
		return String;
	}

	FString NewString;
	NewString.Reserve(String.Len());

	for(TCHAR Char : String)
	{
		if(KeepLowercaseAZ && (Char >= 'a') && (Char <= 'z'))
		{
			NewString.AppendChar(Char);
			continue;
		}
		if(KeepUppercaseAZ && (Char >= 'A') && (Char <= 'Z'))
		{
			NewString.AppendChar(Char);
			continue;
		}
		if(KeepNumbers && (Char >= '0') && (Char <= '9'))
		{
			NewString.AppendChar(Char);
			continue;
		}

		for(TCHAR KeepChar : OtherCharactersToKeep)
		{
			if(Char == KeepChar)
			{
				NewString.AppendChar(Char);
				break;
			}
		}
	}

	return NewString;
}

FString ULowEntryExtendedStandardLibrary::ReplaceCharactersExcept(const FString& String, const FString& ReplacementCharacter, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep)
{
	if(String.Len() <= 0)
	{
		return String;
	}

	FString NewString;
	NewString.Reserve(FMath::Max(String.Len(), (ReplacementCharacter.Len() * String.Len())));

	for(TCHAR Char : String)
	{
		if(KeepLowercaseAZ && (Char >= 'a') && (Char <= 'z'))
		{
			NewString.AppendChar(Char);
			continue;
		}
		if(KeepUppercaseAZ && (Char >= 'A') && (Char <= 'Z'))
		{
			NewString.AppendChar(Char);
			continue;
		}
		if(KeepNumbers && (Char >= '0') && (Char <= '9'))
		{
			NewString.AppendChar(Char);
			continue;
		}

		bool Keep = false;
		for(TCHAR KeepChar : OtherCharactersToKeep)
		{
			if(Char == KeepChar)
			{
				NewString.AppendChar(Char);
				Keep = true;
				break;
			}
		}
		if(Keep)
		{
			continue;
		}

		NewString.Append(ReplacementCharacter);
	}

	return NewString;
}



float										ULowEntryExtendedStandardLibrary::LocalFloat(float Value)														{ return Value; }
int32										ULowEntryExtendedStandardLibrary::LocalInteger(int32 Value)														{ return Value; }
uint8										ULowEntryExtendedStandardLibrary::LocalByte(uint8 Value)														{ return Value; }
bool										ULowEntryExtendedStandardLibrary::LocalBoolean(bool Value)														{ return Value; }
FString										ULowEntryExtendedStandardLibrary::LocalString(const FString& Value)												{ return Value; }
FName										ULowEntryExtendedStandardLibrary::LocalName(const FName& Value)													{ return Value; }
FText										ULowEntryExtendedStandardLibrary::LocalText(const FText& Value)													{ return Value; }
FVector										ULowEntryExtendedStandardLibrary::LocalVector(const FVector& Value)												{ return Value; }
FRotator									ULowEntryExtendedStandardLibrary::LocalRotator(const FRotator& Value)											{ return Value; }
FDateTime									ULowEntryExtendedStandardLibrary::LocalDateTime(const FDateTime& Value)											{ return Value; }
FTimespan									ULowEntryExtendedStandardLibrary::LocalTimespan(const FTimespan& Value)											{ return Value; }
UClass*										ULowEntryExtendedStandardLibrary::LocalClass(UClass* Value)														{ return Value; }
UObject*									ULowEntryExtendedStandardLibrary::LocalObject(UObject* Value)													{ return Value; }
AActor*										ULowEntryExtendedStandardLibrary::LocalActor(AActor* Value)														{ return Value; }
UActorComponent*							ULowEntryExtendedStandardLibrary::LocalActorComponent(UActorComponent* Value)									{ return Value; }
APawn*										ULowEntryExtendedStandardLibrary::LocalPawn(APawn* Value)														{ return Value; }
UEnum*										ULowEntryExtendedStandardLibrary::LocalEnum(UEnum* Value)														{ return Value; }
UStruct*									ULowEntryExtendedStandardLibrary::LocalStruct(UStruct* Value)													{ return Value; }
TScriptInterface<IInterface>				ULowEntryExtendedStandardLibrary::LocalInterface(TScriptInterface<IInterface> Value)							{ return Value; }



TArray<float>								ULowEntryExtendedStandardLibrary::LocalFloatArray(const TArray<float>& Value)									{ return Value; }
TArray<int32>								ULowEntryExtendedStandardLibrary::LocalIntegerArray(const TArray<int32>& Value)									{ return Value; }
TArray<uint8>								ULowEntryExtendedStandardLibrary::LocalByteArray(const TArray<uint8>& Value)									{ return Value; }
TArray<bool>								ULowEntryExtendedStandardLibrary::LocalBooleanArray(const TArray<bool>& Value)									{ return Value; }
TArray<FString>								ULowEntryExtendedStandardLibrary::LocalStringArray(const TArray<FString>& Value)								{ return Value; }
TArray<FName>								ULowEntryExtendedStandardLibrary::LocalNameArray(const TArray<FName>& Value)									{ return Value; }
TArray<FText>								ULowEntryExtendedStandardLibrary::LocalTextArray(const TArray<FText>& Value)									{ return Value; }
TArray<FVector>								ULowEntryExtendedStandardLibrary::LocalVectorArray(const TArray<FVector>& Value)								{ return Value; }
TArray<FRotator>							ULowEntryExtendedStandardLibrary::LocalRotatorArray(const TArray<FRotator>& Value)								{ return Value; }
TArray<FDateTime>							ULowEntryExtendedStandardLibrary::LocalDateTimeArray(const TArray<FDateTime>& Value)							{ return Value; }
TArray<FTimespan>							ULowEntryExtendedStandardLibrary::LocalTimespanArray(const TArray<FTimespan>& Value)							{ return Value; }
TArray<TSubclassOf<UObject>>				ULowEntryExtendedStandardLibrary::LocalClassArray(const TArray<TSubclassOf<UObject>>& Value)					{ return Value; }
TArray<UObject*>							ULowEntryExtendedStandardLibrary::LocalObjectArray(const TArray<UObject*>& Value)								{ return Value; }
TArray<AActor*>								ULowEntryExtendedStandardLibrary::LocalActorArray(const TArray<AActor*>& Value)									{ return Value; }
TArray<UActorComponent*>					ULowEntryExtendedStandardLibrary::LocalActorComponentArray(const TArray<UActorComponent*>& Value)				{ return Value; }
TArray<APawn*>								ULowEntryExtendedStandardLibrary::LocalPawnArray(const TArray<APawn*>& Value)									{ return Value; }
TArray<UEnum*>								ULowEntryExtendedStandardLibrary::LocalEnumArray(const TArray<UEnum*>& Value)									{ return Value; }
TArray<UStruct*>							ULowEntryExtendedStandardLibrary::LocalStructArray(const TArray<UStruct*>& Value)								{ return Value; }



void ULowEntryExtendedStandardLibrary::Crash()
{
	for(int32 i = 1; i <= 100; i++)
	{
		UE_LOG(LogBlueprintUserMessages, Log, TEXT("This crash was caused by LowEntryExtendedStandardLibrary::Crash() and was meant to happen."));
	}
	*((uint32*) 0) = 0xDEAD;
}



void ULowEntryExtendedStandardLibrary::HostGame(UObject* WorldContextObject, const FString& Map, const FString& Args, APlayerController* Player)
{
	APlayerController* TargetPC = Player ? Player : UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if(TargetPC)
	{
		TargetPC->ConsoleCommand(TEXT("open ") + Map + TEXT("?listen ") + Args, true);
	}
}

void ULowEntryExtendedStandardLibrary::JoinGame(UObject* WorldContextObject, const FString& ServerAddress, const FString& Args, APlayerController* Player)
{
	APlayerController* TargetPC = Player ? Player : UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if(TargetPC)
	{
		TargetPC->ConsoleCommand(TEXT("open ") + ServerAddress + TEXT(" ") + Args, true);
	}
}

void ULowEntryExtendedStandardLibrary::ServerChangeMap(UObject* WorldContextObject, const FString& Map, const FString& Args, APlayerController* Player)
{
	APlayerController* TargetPC = Player ? Player : UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if(TargetPC)
	{
		TargetPC->ConsoleCommand(TEXT("servertravel ") + Map + TEXT(" ") + Args, true);
	}
}

void ULowEntryExtendedStandardLibrary::ChangeMap(UObject* WorldContextObject, const FString& Map, const FString& Args, APlayerController* Player)
{
	APlayerController* TargetPC = Player ? Player : UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if(TargetPC)
	{
		TargetPC->ConsoleCommand(TEXT("open ") + Map + TEXT(" ") + Args, true);
	}
}
