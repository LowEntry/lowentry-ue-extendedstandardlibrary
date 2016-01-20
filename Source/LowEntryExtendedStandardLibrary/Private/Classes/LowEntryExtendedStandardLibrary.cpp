#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryExtendedStandardLibrary.h"

#include "LowEntryLatentActionBoolean.h"
#include "LowEntryLatentActionFloat.h"
#include "LowEntryLatentActionInteger.h"
#include "LowEntryLatentActionNone.h"
#include "LowEntryLatentActionObject.h"
#include "LowEntryLatentActionString.h"

#include "LowEntryByteArray.h"

#include "LowEntryByteDataEntry.h"
#include "LowEntryByteDataReader.h"
#include "LowEntryByteDataWriter.h"

#include "LowEntryLong.h"
#include "LowEntryDouble.h"

#include "LowEntryExecutionQueue.h"

#include "FLowEntryTickFrames.h"
#include "FLowEntryTickSeconds.h"

#include "FDelayFramesAction.h"

#include "FExecutionQueueAction.h"


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



bool ULowEntryExtendedStandardLibrary::Html5Platform()
{
#if PLATFORM_HTML5
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::WindowsPlatform()
{
#if PLATFORM_WINDOWS
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::WindowsRtPlatform()
{
#if PLATFORM_WINRT
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::WindowsRtArmPlatform()
{
#if PLATFORM_WINRT_ARM
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::LinuxPlatform()
{
#if PLATFORM_LINUX
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::MacPlatform()
{
#if PLATFORM_MAC
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::Ps4Platform()
{
#if PLATFORM_PS4
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::XboxOnePlatform()
{
#if PLATFORM_XBOXONE
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::AndroidPlatform()
{
#if PLATFORM_ANDROID
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::IosPlatform()
{
#if PLATFORM_IOS
	return true;
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::DesktopPlatform()
{
#if PLATFORM_DESKTOP
	return true;
#else
	return false;
#endif
}



void ULowEntryExtendedStandardLibrary::CreateObject(UClass* Class, UObject*& Object)
{
	Object = NewObject<UObject>((UObject*) GetTransientPackage(), Class);
}



void ULowEntryExtendedStandardLibrary::SoundClass_SetVolume(USoundClass* SoundClass, const float Volume)
{
	if(SoundClass == nullptr)
	{
		return;
	}
	SoundClass->Properties.Volume = Volume;
}

float ULowEntryExtendedStandardLibrary::SoundClass_GetVolume(USoundClass* SoundClass)
{
	if(SoundClass == nullptr)
	{
		return 0;
	}
	return SoundClass->Properties.Volume;
}

void ULowEntryExtendedStandardLibrary::SoundClass_SetPitch(USoundClass* SoundClass, const float Pitch)
{
	if(SoundClass == nullptr)
	{
		return;
	}
	SoundClass->Properties.Pitch = Pitch;
}

float ULowEntryExtendedStandardLibrary::SoundClass_GetPitch(USoundClass* SoundClass)
{
	if(SoundClass == nullptr)
	{
		return 0;
	}
	return SoundClass->Properties.Pitch;
}



void ULowEntryExtendedStandardLibrary::LatentAction_Create_Boolean(ULowEntryLatentActionBoolean*& LatentAction)
{
	LatentAction = ULowEntryLatentActionBoolean::Create();
}

void ULowEntryExtendedStandardLibrary::LatentAction_Create_Float(ULowEntryLatentActionFloat*& LatentAction)
{
	LatentAction = ULowEntryLatentActionFloat::Create();
}

void ULowEntryExtendedStandardLibrary::LatentAction_Create_Integer(ULowEntryLatentActionInteger*& LatentAction)
{
	LatentAction = ULowEntryLatentActionInteger::Create();
}

void ULowEntryExtendedStandardLibrary::LatentAction_Create_None(ULowEntryLatentActionNone*& LatentAction)
{
	LatentAction = ULowEntryLatentActionNone::Create();
}

void ULowEntryExtendedStandardLibrary::LatentAction_Create_Object(ULowEntryLatentActionObject*& LatentAction)
{
	LatentAction = ULowEntryLatentActionObject::Create();
}

void ULowEntryExtendedStandardLibrary::LatentAction_Create_String(ULowEntryLatentActionString*& LatentAction)
{
	LatentAction = ULowEntryLatentActionString::Create();
}



bool ULowEntryExtendedStandardLibrary::AreBytesEqual(const TArray<uint8>& A, const TArray<uint8>& B, int32 IndexA, int32 LengthA, int32 IndexB, int32 LengthB)
{
	if(IndexA < 0)
	{
		LengthA += IndexA;
		IndexA = 0;
	}
	if(LengthA > (A.Num() - IndexA))
	{
		LengthA = A.Num() - IndexA;
	}
	if(LengthA < 0)
	{
		LengthA = 0;
	}

	if(IndexB < 0)
	{
		LengthB += IndexB;
		IndexB = 0;
	}
	if(LengthB > (B.Num() - IndexB))
	{
		LengthB = B.Num() - IndexB;
	}
	if(LengthB < 0)
	{
		LengthB = 0;
	}

	if(LengthA != LengthB)
	{
		return false;
	}

	for(int i = 0; i < LengthA; i++)
	{
		if(A[IndexA + i] != B[IndexB + i])
		{
			return false;
		}
	}
	return true;
}



void ULowEntryExtendedStandardLibrary::SplitBytes(const TArray<uint8>& ByteArray, const int32 LengthA, TArray<uint8>& A, TArray<uint8>& B)
{
	if(LengthA <= 0)
	{
		A = TArray<uint8>();
		B = ByteArray;
		return;
	}
	if(LengthA >= ByteArray.Num())
	{
		A = ByteArray;
		B = TArray<uint8>();
		return;
	}

	A = TArray<uint8>();
	A.Append(ByteArray.GetData(), LengthA);
	
	B = TArray<uint8>();
	B.Append(ByteArray.GetData() + LengthA, ByteArray.Num() - LengthA);
}

TArray<uint8> ULowEntryExtendedStandardLibrary::MergeBytes(TArray<uint8> A, TArray<uint8> B)
{
	if(A.Num() <= 0)
	{
		return B;
	}
	if(B.Num() <= 0)
	{
		return A;
	}

	TArray<uint8> ReturnArray = TArray<uint8>();
	ReturnArray.Reserve(A.Num() + B.Num());
	ReturnArray.Append(A.GetData(), A.Num());
	ReturnArray.Append(B.GetData(), B.Num());

	return ReturnArray;
}

TArray<uint8> ULowEntryExtendedStandardLibrary::BytesSubArray(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	if(ByteArray.Num() <= 0)
	{
		return TArray<uint8>();
	}

	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}
	if(Length <= 0)
	{
		return TArray<uint8>();
	}

	if((Index == 0) && (Length == ByteArray.Num()))
	{
		return ByteArray;
	}
	TArray<uint8> ReturnArray = TArray<uint8>();
	ReturnArray.Append(ByteArray.GetData() + Index, Length);
	return ReturnArray;
}



void ULowEntryExtendedStandardLibrary::GenerateRandomBytes(const int32 Length, TArray<uint8>& ByteArray)
{
	if(Length <= 0)
	{
		ByteArray.SetNum(0);
		return;
	}

	ByteArray.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		int32 RandomByte = FMath::Rand() % 255;
		ByteArray[i] = RandomByte;
	}
}

void ULowEntryExtendedStandardLibrary::GenerateRandomBytesRandomLength(int32 MinLength, int32 MaxLength, TArray<uint8>& ByteArray)
{
	if(MinLength < 0)
	{
		MinLength = 0;
	}
	if(MaxLength < 0)
	{
		MaxLength = 0;
	}

	int32 Diff = 0;
	int32 Min = 0;
	if(MaxLength >= MinLength)
	{
		Diff = MaxLength - MinLength;
		Min = MinLength;
	}
	else
	{
		Diff = MinLength - MaxLength;
		Min = MaxLength;
	}
	if(Min < 0)
	{
		Min = 0;
	}
	if(Diff < 0)
	{
		Diff = 0;
	}

	if((Min == 0) && (Diff == 0))
	{
		ByteArray.SetNum(0);
		return;
	}

	int Length = (FMath::Rand() % (Diff + 1)) + Min;
	if(Length <= 0)
	{
		ByteArray.SetNum(0);
		return;
	}

	ByteArray.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		int32 RandomByte = FMath::Rand() % 255;
		ByteArray[i] = RandomByte;
	}
}



TArray<uint8> ULowEntryExtendedStandardLibrary::StringToBytesUtf8(const FString& String)
{
	if(String.Len() <= 0)
	{
		return TArray<uint8>();
	}

	TArray<uint8> ByteArray;
	FTCHARToUTF8 Src = FTCHARToUTF8(String.GetCharArray().GetData());
	ByteArray.Append((uint8*) Src.Get(), Src.Length());
	return ByteArray;
}

FString ULowEntryExtendedStandardLibrary::BytesToStringUtf8(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	if(ByteArray.Num() <= 0)
	{
		return TEXT("");
	}

	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}
	if(Length <= 0)
	{
		return TEXT("");
	}

	FString String = TEXT("");
	FUTF8ToTCHAR Src = FUTF8ToTCHAR((const ANSICHAR*) (ByteArray.GetData() + Index), Length);
	String.AppendChars(Src.Get(), Src.Length());
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

FString ULowEntryExtendedStandardLibrary::BytesToBase64(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	if(ByteArray.Num() <= 0)
	{
		return TEXT("");
	}

	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}
	if(Length <= 0)
	{
		return TEXT("");
	}

	if((Index == 0) && (Length == ByteArray.Num()))
	{
		return FBase64::Encode(ByteArray);
	}
	return FBase64::Encode(BytesSubArray(ByteArray, Index, Length));
}


TArray<uint8> ULowEntryExtendedStandardLibrary::HexToBytes(const FString& Hex)
{
	FString String = Hex.Replace(TEXT(" "), TEXT(""));
	if(String.Len() <= 0)
	{
		return TArray<uint8>();
	}

	for(TCHAR c : String)
	{
		if(!::CheckTCharIsHex(c))
		{
			return TArray<uint8>();
		}
	}

	uint8* Bytes = new uint8[String.Len()];
	int32 ByteCount = ::HexToBytes(String, Bytes);
	TArray<uint8> ByteArray;
	ByteArray.Append(Bytes, ByteCount);
	delete [] Bytes;
	return ByteArray;
}

FString ULowEntryExtendedStandardLibrary::BytesToHex(const TArray<uint8>& ByteArray, const bool AddSpaces, int32 Index, int32 Length)
{
	if(ByteArray.Num() <= 0)
	{
		return TEXT("");
	}

	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}
	if(Length <= 0)
	{
		return TEXT("");
	}

	FString Hex = ::BytesToHex(ByteArray.GetData() + Index, Length);
	if(!AddSpaces)
	{
		return Hex;
	}
	FString String;
	String.Reserve((Hex.Len() / 2) * 3);
	TArray<TCHAR> Chars = Hex.GetCharArray();
	for(int32 i = 1; i <= Chars.Num(); i++)
	{
		String.AppendChar(Chars[i - 1]);
		if(((i % 2) == 0) && (i < (Chars.Num() - 1)))
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
	for(int32 i = 0; i < String.Len(); i += 8)
	{
		uint8 b = 0;
		for(int32 j = 0; j < 8; j++)
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

FString ULowEntryExtendedStandardLibrary::BytesToBinary(const TArray<uint8>& ByteArray, const bool AddSpaces, int32 Index, int32 Length)
{
	if(ByteArray.Num() <= 0)
	{
		return TEXT("");
	}

	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}
	if(Length <= 0)
	{
		return TEXT("");
	}

	FString String;
	String.Reserve(Length * (AddSpaces ? 9 : 8));
	for(int32 i = 1; i <= Length; i++)
	{
		for(int32 j = 7; j >= 0; j--)
		{
			if((ByteArray[Index + (i - 1)] & (1 << j)) > 0)
			{
				String.Append(TEXT("1"));
			}
			else
			{
				String.Append(TEXT("0"));
			}
		}
		if(AddSpaces && (i < Length))
		{
			String.Append(TEXT(" "));
		}
	}
	return String;
}


TArray<uint8> ULowEntryExtendedStandardLibrary::BooleanToBytes(const bool Value)
{
	TArray<uint8> ByteArray;
	ByteArray.SetNum(1);
	if(Value)
	{
		ByteArray[0] = 0x01;
	}
	else
	{
		ByteArray[0] = 0x00;
	}
	return ByteArray;
}

bool ULowEntryExtendedStandardLibrary::BytesToBoolean(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	if(ByteArray.Num() <= 0)
	{
		return false;
	}

	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}
	if(Length <= 0)
	{
		return false;
	}

	return (ByteArray[Index] == 0x01);
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

int32 ULowEntryExtendedStandardLibrary::BytesToInteger(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	if(ByteArray.Num() <= 0)
	{
		return 0;
	}

	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}
	if(Length <= 0)
	{
		return 0;
	}

	if(Length <= 1)
	{
		return (ByteArray[Index + 0] & 0xFF);
	}
	if(Length <= 2)
	{
		return ((ByteArray[Index + 0] & 0xFF) << 8) | (ByteArray[Index + 1] & 0xFF);
	}
	if(Length <= 3)
	{
		return ((ByteArray[Index + 0] & 0xFF) << 16) | ((ByteArray[Index + 1] & 0xFF) << 8) | (ByteArray[Index + 2] & 0xFF);
	}
	return (ByteArray[Index + 0] << 24) | ((ByteArray[Index + 1] & 0xFF) << 16) | ((ByteArray[Index + 2] & 0xFF) << 8) | (ByteArray[Index + 3] & 0xFF);
}


TArray<uint8> ULowEntryExtendedStandardLibrary::FloatToBytes(const float Value)
{
	int32 IntValue = *((int32*) (&Value));
	return ULowEntryExtendedStandardLibrary::IntegerToBytes(IntValue);
}

float ULowEntryExtendedStandardLibrary::BytesToFloat(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	int32 IntValue = ULowEntryExtendedStandardLibrary::BytesToInteger(ByteArray, Index, Length);
	return *((float*) (&IntValue));
}



TArray<uint8> ULowEntryExtendedStandardLibrary::Md5(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}

	FMD5 Hasher;
	if(Length > 0)
	{
		const uint8* Bytes = ByteArray.GetData();
		Hasher.Update((uint8*) Bytes + Index, Length);
	}

	uint8 DigestBytes[16];
	Hasher.Final(DigestBytes);
	TArray<uint8> DigestByteArray;
	DigestByteArray.Append(DigestBytes, 16);
	return DigestByteArray;
}

TArray<uint8> ULowEntryExtendedStandardLibrary::Sha1(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > ByteArray.Num() - Index)
	{
		Length = ByteArray.Num() - Index;
	}

	FSHA1 Hasher;
	if(Length > 0)
	{
		const uint8* Bytes = ByteArray.GetData();
		Hasher.Update((uint8*) Bytes + Index, Length);
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
	


FString ULowEntryExtendedStandardLibrary::MinString(FString A, FString B)
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

FString ULowEntryExtendedStandardLibrary::MaxString(FString A, FString B)
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



void ULowEntryExtendedStandardLibrary::DelayFrames(UObject* WorldContextObject, int32 Frames, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if(LatentActionManager.FindExistingAction<FDelayFramesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FDelayFramesAction(Frames, LatentInfo));
		}
	}
}

void ULowEntryExtendedStandardLibrary::RetriggerableDelayFrames(UObject* WorldContextObject, int32 Frames, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FDelayFramesAction* Action = LatentActionManager.FindExistingAction<FDelayFramesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if(Action == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FDelayFramesAction(Frames, LatentInfo));
		}
		else
		{
			Action->FramesRemaining = Frames;
		}
	}
}

void ULowEntryExtendedStandardLibrary::RandomDelayFrames(UObject* WorldContextObject, int32 MinFrames, int32 MaxFrames, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if(LatentActionManager.FindExistingAction<FDelayFramesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FDelayFramesAction(FMath::RandRange(MinFrames, MaxFrames), LatentInfo));
		}
	}
}

void ULowEntryExtendedStandardLibrary::RetriggerableRandomDelayFrames(UObject* WorldContextObject, int32 MinFrames, int32 MaxFrames, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FDelayFramesAction* Action = LatentActionManager.FindExistingAction<FDelayFramesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if(Action == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FDelayFramesAction(FMath::RandRange(MinFrames, MaxFrames), LatentInfo));
		}
		else
		{
			Action->FramesRemaining = FMath::RandRange(MinFrames, MaxFrames);
		}
	}
}



void ULowEntryExtendedStandardLibrary::QueueExecutions(UObject* WorldContextObject, ULowEntryExecutionQueue*& Queue, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FExecutionQueueAction* Action = LatentActionManager.FindExistingAction<FExecutionQueueAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if(Action == NULL)
		{
			Queue = ULowEntryExecutionQueue::Create(1, true);
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FExecutionQueueAction(Queue, LatentInfo));
		}
		else
		{
			Queue = Action->Queue;
			Queue->Count++;
		}
	}
}

void ULowEntryExtendedStandardLibrary::NextQueueExecution(ULowEntryExecutionQueue* Queue)
{
	if(Queue != nullptr)
	{
		Queue->Next = true;
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



void ULowEntryExtendedStandardLibrary::Crash()
{
	for(int32 i = 1; i <= 100; i++)
	{
		UE_LOG(LogBlueprintUserMessages, Log, TEXT("This crash was caused by LowEntryExtendedStandardLibrary::Crash() and was meant to happen."));
	}
	FDebug::AssertFailed("This crash was caused by LowEntryExtendedStandardLibrary::Crash() and was meant to happen.", __FILE__, __LINE__);
}



void ULowEntryExtendedStandardLibrary::HostGame(UObject* WorldContextObject, const FString& Map, const FString& Args, APlayerController* Player)
{
	APlayerController* TargetPC = Player ? Player : UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if(TargetPC)
	{
		TargetPC->ConsoleCommand(TEXT("open ") + Map + TEXT("?listen") + Args, true);
	}
}

void ULowEntryExtendedStandardLibrary::JoinGame(UObject* WorldContextObject, const FString& ServerAddress, const FString& Args, APlayerController* Player)
{
	APlayerController* TargetPC = Player ? Player : UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if(TargetPC)
	{
		TargetPC->ConsoleCommand(TEXT("open ") + ServerAddress + Args, true);
	}
}

void ULowEntryExtendedStandardLibrary::ServerChangeMap(UObject* WorldContextObject, const FString& Map, const FString& Args, APlayerController* Player)
{
	APlayerController* TargetPC = Player ? Player : UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if(TargetPC)
	{
		TargetPC->ConsoleCommand(TEXT("servertravel ") + Map + Args, true);
	}
}

void ULowEntryExtendedStandardLibrary::ChangeMap(UObject* WorldContextObject, const FString& Map, const FString& Args, APlayerController* Player)
{
	APlayerController* TargetPC = Player ? Player : UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if(TargetPC)
	{
		TargetPC->ConsoleCommand(TEXT("open ") + Map + Args, true);
	}
}



void ULowEntryExtendedStandardLibrary::TickFrames(UObject* WorldContextObject, FLatentActionInfo LatentInfo, const int32 Ticks, const int32 FramesInterval, int32& Tick)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryTickFrames(LatentInfo, Ticks, FramesInterval, Tick));
}

void ULowEntryExtendedStandardLibrary::TickSeconds(UObject* WorldContextObject, FLatentActionInfo LatentInfo, const int32 Ticks, const float SecondsInterval, int32& Tick)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryTickSeconds(LatentInfo, Ticks, SecondsInterval, Tick));
}



ULowEntryByteDataReader* ULowEntryExtendedStandardLibrary::ByteDataReader_Create(const TArray<uint8>& Bytes, int32 Index, int32 Length)
{
	return ULowEntryByteDataReader::Create(Bytes, Index, Length);
}



ULowEntryByteDataWriter* ULowEntryExtendedStandardLibrary::ByteDataWriter_Create()
{
	return ULowEntryByteDataWriter::Create();
}

ULowEntryByteDataWriter* ULowEntryExtendedStandardLibrary::ByteDataWriter_CreateFromEntryArray(const TArray<ULowEntryByteDataEntry*>& Array)
{
	return ULowEntryByteDataWriter::CreateFromEntryArray(Array);
}

ULowEntryByteDataWriter* ULowEntryExtendedStandardLibrary::ByteDataWriter_CreateFromEntryArrayPure(const TArray<ULowEntryByteDataEntry*>& Array)
{
	return ULowEntryByteDataWriter::CreateFromEntryArray(Array);
}

TArray<uint8> ULowEntryExtendedStandardLibrary::ByteDataWriter_GetBytes(ULowEntryByteDataWriter* ByteDataWriter)
{
	return ByteDataWriter->GetBytes();
}



ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromByte(const uint8 Value)
{
	return ULowEntryByteDataEntry::CreateFromByte(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromInteger(const int32 Value)
{
	return ULowEntryByteDataEntry::CreateFromInteger(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromLongBytes(ULowEntryLong* Value)
{
	return ULowEntryByteDataEntry::CreateFromLongBytes(Value);
}

ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromFloat(const float Value)
{
	return ULowEntryByteDataEntry::CreateFromFloat(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromDoubleBytes(ULowEntryDouble* Value)
{
	return ULowEntryByteDataEntry::CreateFromDoubleBytes(Value);
}

ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromBoolean(const bool Value)
{
	return ULowEntryByteDataEntry::CreateFromBoolean(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromStringUtf8(const FString& Value)
{
	return ULowEntryByteDataEntry::CreateFromStringUtf8(Value);
}


ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromByteArray(const TArray<uint8>& Value)
{
	return ULowEntryByteDataEntry::CreateFromByteArray(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromIntegerArray(const TArray<int32>& Value)
{
	return ULowEntryByteDataEntry::CreateFromIntegerArray(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromLongBytesArray(const TArray<ULowEntryLong*>& Value)
{
	return ULowEntryByteDataEntry::CreateFromLongBytesArray(Value);
}

ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromFloatArray(const TArray<float>& Value)
{
	return ULowEntryByteDataEntry::CreateFromFloatArray(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromDoubleBytesArray(const TArray<ULowEntryDouble*>& Value)
{
	return ULowEntryByteDataEntry::CreateFromDoubleBytesArray(Value);
}

ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromBooleanArray(const TArray<bool>& Value)
{
	return ULowEntryByteDataEntry::CreateFromBooleanArray(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromStringUtf8Array(const TArray<FString>& Value)
{
	return ULowEntryByteDataEntry::CreateFromStringUtf8Array(Value);
}



ULowEntryLong* ULowEntryExtendedStandardLibrary::Long_CreateZero()
{
	return ULowEntryLong::Create();
}

ULowEntryLong* ULowEntryExtendedStandardLibrary::Long_Create(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	return ULowEntryLong::Create(ByteArray, Index, Length);
}

ULowEntryDouble* ULowEntryExtendedStandardLibrary::Double_CreateZero()
{
	return ULowEntryDouble::Create();
}

ULowEntryDouble* ULowEntryExtendedStandardLibrary::Double_Create(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	return ULowEntryDouble::Create(ByteArray, Index, Length);
}



void ULowEntryExtendedStandardLibrary::SimpleKismetSystemLibraryPrintString(const FString& InString)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	float ScreenDurationTime = 5.0f;
	bool bPrintToScreen = true;
	bool bPrintToLog = true;
	FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

	if(bPrintToLog)
	{
		UE_LOG(LogBlueprintUserMessages, Log, TEXT("%s"), *InString);
	}
	else
	{
		UE_LOG(LogBlueprintUserMessages, Verbose, TEXT("%s"), *InString);
	}

	if(bPrintToScreen)
	{
		if(GAreScreenMessagesEnabled)
		{
			GEngine->AddOnScreenDebugMessage((uint64) -1, ScreenDurationTime, TextColor.ToFColor(true), InString);
		}
	}
#endif
}

ULowEntryByteArray* ULowEntryExtendedStandardLibrary::EncapsulateByteArray(const TArray<uint8>& ByteArray)
{
	return ULowEntryByteArray::CreateFromByteArray(ByteArray);
}

TArray<uint8> ULowEntryExtendedStandardLibrary::MergeEncapsulatedByteArrays(const TArray<ULowEntryByteArray*>& ByteArrays)
{
	if(ByteArrays.Num() <= 0)
	{
		return TArray<uint8>();
	}
	if(ByteArrays.Num() == 1)
	{
		ULowEntryByteArray* Array = ByteArrays[0];
		if(Array == nullptr)
		{
			return TArray<uint8>();
		}
		return Array->ByteArray;
	}
	int Length = 0;
	for(ULowEntryByteArray* Array : ByteArrays)
	{
		if(Array != nullptr)
		{
			Length += Array->ByteArray.Num();
		}
	}
	if(Length <= 0)
	{
		return TArray<uint8>();
	}
	TArray<uint8> Merged = TArray<uint8>();
	Merged.Reserve(Length);
	for(ULowEntryByteArray* Array : ByteArrays)
	{
		if(Array != nullptr)
		{
			Merged.Append(Array->ByteArray);
		}
	}
	return Merged;
}
