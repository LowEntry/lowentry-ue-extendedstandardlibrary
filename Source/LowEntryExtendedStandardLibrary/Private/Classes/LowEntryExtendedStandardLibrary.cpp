#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryExtendedStandardLibrary.h"



// init >>
	ULowEntryExtendedStandardLibrary::ULowEntryExtendedStandardLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}
// init <<


void ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(UObject* WorldContextObject, const FString& InString, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	WorldContextObject = GEngine->GetWorldFromContextObject(WorldContextObject, false);
	FString Prefix;
	if(WorldContextObject)
	{
		UWorld *World = WorldContextObject->GetWorld();
		if(World->WorldType == EWorldType::PIE)
		{
			switch(World->GetNetMode())
			{
				case NM_Client:
					Prefix = FString::Printf(TEXT("Client %d: "), GPlayInEditorID - 1);
					break;
				case NM_DedicatedServer:
				case NM_ListenServer:
					Prefix = FString::Printf(TEXT("Server: "));
					break;
			}
		}
	}

	const FString FinalString = Prefix + InString;

	if(bPrintToLog)
	{
		UE_LOG(LogBlueprintUserMessages, Log, TEXT("%s"), *FinalString);
	}
	else
	{
		UE_LOG(LogBlueprintUserMessages, Verbose, TEXT("%s"), *FinalString);
	}

	if(bPrintToScreen)
	{
		if(GAreScreenMessagesEnabled)
		{
			GEngine->AddOnScreenDebugMessage((uint64) -1, ScreenDurationTime, TextColor.ToFColor(true), FinalString);
		}
	}
#endif
}



bool ULowEntryExtendedStandardLibrary::DebugBuild()
{
#if UE_BUILD_DEBUG
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::DevelopmentBuild()
{
#if UE_BUILD_DEVELOPMENT
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::TestBuild()
{
#if UE_BUILD_TEST
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::ShippingBuild()
{
#if UE_BUILD_SHIPPING
	return true;
#else
	return false;
#endif
}



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

FString ULowEntryExtendedStandardLibrary::BytesToHex(const TArray<uint8>& ByteArray, const bool AddSpaces)
{
	int32 Size = ByteArray.Num();
	if(Size <= 0)
	{
		return TEXT("");
	}
	FString Hex = ::BytesToHex(ByteArray.GetData(), Size);
	if(!AddSpaces)
	{
		return Hex;
	}
	FString String;
	String.Reserve((Hex.Len() / 2) * 3);
	TArray<TCHAR> Chars = Hex.GetCharArray();
	for(int i = 1; i <= Chars.Num(); i++)
	{
		String.AppendChar(Chars[i - 1]);
		if(((i % 2) == 0) && (i < Chars.Num()))
		{
			String.Append(TEXT(" "));
		}
	}
	return String;
}


TArray<uint8> ULowEntryExtendedStandardLibrary::BinaryToBytes(const FString& Binary)
{
	if(Binary.Len() <= 0)
	{
		return TArray<uint8>();
	}
	FString String = Binary.Replace(TEXT(" "), TEXT(""));
	if((String.Len() <= 0) || ((String.Len() % 8) != 0))
	{
		return TArray<uint8>();
	}
	TArray<TCHAR> Bits = String.GetCharArray();
	TArray<uint8> Bytes;
	Bytes.SetNum(String.Len() / 8);
	int32 Index = 0;
	for(int i = 0; i < String.Len(); i += 8)
	{
		uint8 b = 0;
		for(int j = 0; j < 8; j++)
		{
			if(Bits[i + j] == '0')
			{
				continue;
			}
			else if(Bits[i + j] == '1')
			{
				b += (1 << (7 - j));
			}
			else
			{
				// encountered invalid character
				return TArray<uint8>();
			}
		}
		Bytes[Index] = b;
		Index++;
	}
	return Bytes;
}

FString ULowEntryExtendedStandardLibrary::BytesToBinary(const TArray<uint8>& ByteArray, const bool AddSpaces)
{
	if(ByteArray.Num() <= 0)
	{
		return TEXT("");
	}
	FString String;
	String.Reserve(ByteArray.Num() * (AddSpaces ? 9 : 8));
	for(int32 i = 1; i <= ByteArray.Num(); i++)
	{
		for(int32 j = 7; j >= 0; j--)
		{
			if((ByteArray[i - 1] & (1 << j)) > 0)
			{
				String.Append(TEXT("1"));
			}
			else
			{
				String.Append(TEXT("0"));
			}
		}
		if(AddSpaces && (i < ByteArray.Num()))
		{
			String.Append(TEXT(" "));
		}
	}
	return String;
}


TArray<uint8> ULowEntryExtendedStandardLibrary::IntegerToBytes(const int32 Value)
{
	TArray<uint8> ByteArray;
	ByteArray.SetNum(4);
	ByteArray[0] = (Value >> 24);
	ByteArray[1] = (Value >> 16);
	ByteArray[2] = (Value >> 8);
	ByteArray[3] = (Value);
	return ByteArray;
}

int32 ULowEntryExtendedStandardLibrary::BytesToInteger(const TArray<uint8>& ByteArray)
{
	if(ByteArray.Num() <= 0)
	{
		return 0;
	}
	if(ByteArray.Num() <= 1)
	{
		return (ByteArray[3] & 0xFF);
	}
	if(ByteArray.Num() <= 2)
	{
		return ((ByteArray[2] & 0xFF) << 8) | (ByteArray[3] & 0xFF);
	}
	if(ByteArray.Num() <= 3)
	{
		return ((ByteArray[1] & 0xFF) << 16) | ((ByteArray[2] & 0xFF) << 8) | (ByteArray[3] & 0xFF);
	}
	return (ByteArray[0] << 24) | ((ByteArray[1] & 0xFF) << 16) | ((ByteArray[2] & 0xFF) << 8) | (ByteArray[3] & 0xFF);
}


TArray<uint8> ULowEntryExtendedStandardLibrary::FloatToBytes(const float Value)
{
	int32 IntValue = *((int32*) (&Value));
	return ULowEntryExtendedStandardLibrary::IntegerToBytes(IntValue);
}

float ULowEntryExtendedStandardLibrary::BytesToFloat(const TArray<uint8>& ByteArray)
{
	int32 IntValue = ULowEntryExtendedStandardLibrary::BytesToInteger(ByteArray);
	return *((float*) (&IntValue));
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



TArray<FString> ULowEntryExtendedStandardLibrary::SortStringArray(const TArray<FString>& StringArray, const bool Reversed)
{
	TArray<FString> Array = StringArray;
	if(!Reversed)
	{
		Array.Sort([](const FString& A, const FString& B){
			return A < B;
		});
	}
	else
	{
		Array.Sort([](const FString& A, const FString& B){
			return A > B;
		});
	}
	return Array;
}

TArray<int32> ULowEntryExtendedStandardLibrary::SortIntegerArray(const TArray<int32>& IntegerArray, const bool Reversed)
{
	TArray<int32> Array = IntegerArray;
	if(!Reversed)
	{
		Array.Sort([] (const int32 A, const int32 B){
			return A < B;
		});
	}
	else
	{
		Array.Sort([] (const int32 A, const int32 B){
			return A > B;
		});
	}
	return Array;
}

TArray<float> ULowEntryExtendedStandardLibrary::SortFloatArray(const TArray<float>& FloatArray, const bool Reversed)
{
	TArray<float> Array = FloatArray;
	if(!Reversed)
	{
		Array.Sort([] (const float A, const float B){
			return A < B;
		});
	}
	else
	{
		Array.Sort([] (const float A, const float B){
			return A > B;
		});
	}
	return Array;
}

TArray<uint8> ULowEntryExtendedStandardLibrary::SortByteArray(const TArray<uint8>& ByteArray, const bool Reversed)
{
	TArray<uint8> Array = ByteArray;
	if(!Reversed)
	{
		Array.Sort([] (const uint8 A, const uint8 B){
			return A < B;
		});
	}
	else
	{
		Array.Sort([] (const uint8 A, const uint8 B){
			return A > B;
		});
	}
	return Array;
}

TArray<FDateTime> ULowEntryExtendedStandardLibrary::SortDateTimeArray(const TArray<FDateTime>& DateTimeArray, const bool Reversed)
{
	TArray<FDateTime> Array = DateTimeArray;
	if(!Reversed)
	{
		Array.Sort([] (const FDateTime& A, const FDateTime& B){
			return A < B;
		});
	}
	else
	{
		Array.Sort([] (const FDateTime& A, const FDateTime& B){
			return A > B;
		});
	}
	return Array;
}

TArray<FTimespan> ULowEntryExtendedStandardLibrary::SortTimespanArray(const TArray<FTimespan>& TimespanArray, const bool Reversed)
{
	TArray<FTimespan> Array = TimespanArray;
	if(!Reversed)
	{
		Array.Sort([] (const FTimespan& A, const FTimespan& B){
			return A < B;
		});
	}
	else
	{
		Array.Sort([] (const FTimespan& A, const FTimespan& B){
			return A > B;
		});
	}
	return Array;
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



float										ULowEntryExtendedStandardLibrary::PurePrintFloat(UObject* WorldContextObject, float Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)														{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
int32										ULowEntryExtendedStandardLibrary::PurePrintInteger(UObject* WorldContextObject, int32 Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)													{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
uint8										ULowEntryExtendedStandardLibrary::PurePrintByte(UObject* WorldContextObject, uint8 Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)														{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
bool										ULowEntryExtendedStandardLibrary::PurePrintBoolean(UObject* WorldContextObject, bool Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)													{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
FString										ULowEntryExtendedStandardLibrary::PurePrintString(UObject* WorldContextObject, const FString& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)											{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
FName										ULowEntryExtendedStandardLibrary::PurePrintName(UObject* WorldContextObject, const FName& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)												{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
FText										ULowEntryExtendedStandardLibrary::PurePrintText(UObject* WorldContextObject, const FText& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)												{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
FVector										ULowEntryExtendedStandardLibrary::PurePrintVector(UObject* WorldContextObject, const FVector& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)											{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
FRotator									ULowEntryExtendedStandardLibrary::PurePrintRotator(UObject* WorldContextObject, const FRotator& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)											{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
FDateTime									ULowEntryExtendedStandardLibrary::PurePrintDateTime(UObject* WorldContextObject, const FDateTime& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)										{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
FTimespan									ULowEntryExtendedStandardLibrary::PurePrintTimespan(UObject* WorldContextObject, const FTimespan& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)										{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
UClass*										ULowEntryExtendedStandardLibrary::PurePrintClass(UObject* WorldContextObject, UClass* Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)													{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
UObject*									ULowEntryExtendedStandardLibrary::PurePrintObject(UObject* WorldContextObject, UObject* Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)													{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
AActor*										ULowEntryExtendedStandardLibrary::PurePrintActor(UObject* WorldContextObject, AActor* Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)													{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
UActorComponent*							ULowEntryExtendedStandardLibrary::PurePrintActorComponent(UObject* WorldContextObject, UActorComponent* Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)									{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
APawn*										ULowEntryExtendedStandardLibrary::PurePrintPawn(UObject* WorldContextObject, APawn* Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)														{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
UEnum*										ULowEntryExtendedStandardLibrary::PurePrintEnum(UObject* WorldContextObject, UEnum* Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)														{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
UStruct*									ULowEntryExtendedStandardLibrary::PurePrintStruct(UObject* WorldContextObject, UStruct* Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)													{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TScriptInterface<IInterface>				ULowEntryExtendedStandardLibrary::PurePrintInterface(UObject* WorldContextObject, TScriptInterface<IInterface> Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)							{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }



TArray<float>								ULowEntryExtendedStandardLibrary::PurePrintFloatArray(UObject* WorldContextObject, const TArray<float>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)									{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<int32>								ULowEntryExtendedStandardLibrary::PurePrintIntegerArray(UObject* WorldContextObject, const TArray<int32>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)								{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<uint8>								ULowEntryExtendedStandardLibrary::PurePrintByteArray(UObject* WorldContextObject, const TArray<uint8>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)									{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<bool>								ULowEntryExtendedStandardLibrary::PurePrintBooleanArray(UObject* WorldContextObject, const TArray<bool>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)								{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<FString>								ULowEntryExtendedStandardLibrary::PurePrintStringArray(UObject* WorldContextObject, const TArray<FString>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)								{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<FName>								ULowEntryExtendedStandardLibrary::PurePrintNameArray(UObject* WorldContextObject, const TArray<FName>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)									{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<FText>								ULowEntryExtendedStandardLibrary::PurePrintTextArray(UObject* WorldContextObject, const TArray<FText>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)									{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<FVector>								ULowEntryExtendedStandardLibrary::PurePrintVectorArray(UObject* WorldContextObject, const TArray<FVector>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)								{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<FRotator>							ULowEntryExtendedStandardLibrary::PurePrintRotatorArray(UObject* WorldContextObject, const TArray<FRotator>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)							{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<FDateTime>							ULowEntryExtendedStandardLibrary::PurePrintDateTimeArray(UObject* WorldContextObject, const TArray<FDateTime>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)							{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<FTimespan>							ULowEntryExtendedStandardLibrary::PurePrintTimespanArray(UObject* WorldContextObject, const TArray<FTimespan>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)							{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<TSubclassOf<UObject>>				ULowEntryExtendedStandardLibrary::PurePrintClassArray(UObject* WorldContextObject, const TArray<TSubclassOf<UObject>>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)					{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<UObject*>							ULowEntryExtendedStandardLibrary::PurePrintObjectArray(UObject* WorldContextObject, const TArray<UObject*>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)								{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<AActor*>								ULowEntryExtendedStandardLibrary::PurePrintActorArray(UObject* WorldContextObject, const TArray<AActor*>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)								{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<UActorComponent*>					ULowEntryExtendedStandardLibrary::PurePrintActorComponentArray(UObject* WorldContextObject, const TArray<UActorComponent*>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)				{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<APawn*>								ULowEntryExtendedStandardLibrary::PurePrintPawnArray(UObject* WorldContextObject, const TArray<APawn*>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)									{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<UEnum*>								ULowEntryExtendedStandardLibrary::PurePrintEnumArray(UObject* WorldContextObject, const TArray<UEnum*>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)									{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }
TArray<UStruct*>							ULowEntryExtendedStandardLibrary::PurePrintStructArray(UObject* WorldContextObject, const TArray<UStruct*>& Value, const FString& Message, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)								{ ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(WorldContextObject, Message, ScreenDurationTime, bPrintToScreen, bPrintToLog, TextColor); return Value; }



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
