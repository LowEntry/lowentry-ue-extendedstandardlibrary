// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryExtendedStandardLibrary.h"

#include "LowEntryHashingBCryptLibrary.h"
#include "LowEntryHashingSha256Library.h"
#include "LowEntryHashingSha512Library.h"
#include "LowEntryHashingPearsonLibrary.h"
#include "LowEntryHashingHashcashLibrary.h"

#include "LowEntryLatentActionBoolean.h"
#include "LowEntryLatentActionFloat.h"
#include "LowEntryLatentActionInteger.h"
#include "LowEntryLatentActionNone.h"
#include "LowEntryLatentActionObject.h"
#include "LowEntryLatentActionString.h"

#include "LowEntryParsedHashcash.h"

#include "LowEntryByteArray.h"

#include "LowEntryByteDataEntry.h"
#include "LowEntryByteDataReader.h"
#include "LowEntryByteDataWriter.h"

#include "LowEntryBitDataEntry.h"
#include "LowEntryBitDataReader.h"
#include "LowEntryBitDataWriter.h"

#include "LowEntryLong.h"
#include "LowEntryDouble.h"

#include "LowEntryExecutionQueue.h"

#include "FLowEntryTickFrames.h"
#include "FLowEntryTickSeconds.h"

#include "FLowEntryDelayFramesAction.h"
#include "FLowEntryExecutionQueueAction.h"

#include "GenericTeamAgentInterface.h"

#include "Misc/Base64.h"
#include "Internationalization/Regex.h"

#include "HAL/PlatformApplicationMisc.h"

#include "GenericPlatform/GenericApplication.h"

#include "GameMapsSettings.h"


// init >>
	ULowEntryExtendedStandardLibrary::ULowEntryExtendedStandardLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}
// init <<


void ULowEntryExtendedStandardLibrary::KismetSystemLibraryPrintString(UObject* WorldContextObject, const FString& InString, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	FString Prefix;
	if(GEngine != nullptr)
	{
		WorldContextObject = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
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
			if(GEngine != nullptr)
			{
				GEngine->AddOnScreenDebugMessage((uint64) -1, ScreenDurationTime, TextColor.ToFColor(true), FinalString);
			}
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



bool ULowEntryExtendedStandardLibrary::WithEditor()
{
#if WITH_EDITOR
	return true;
#else
	return false;
#endif
}



bool ULowEntryExtendedStandardLibrary::Html5Platform()
{
#if false/*PLATFORM_HTML5*/
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

bool ULowEntryExtendedStandardLibrary::Windows32Platform()
{
#if PLATFORM_WINDOWS
	#ifdef _WIN64
		return false;
	#else
		return true;
	#endif
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::Windows64Platform()
{
#if PLATFORM_WINDOWS
	#ifdef _WIN64
		return true;
	#else
		return false;
	#endif
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::WindowsRtPlatform()
{
#ifdef PLATFORM_WINRT
	#if PLATFORM_WINRT
		return true;
	#else
		return false;
	#endif
#else
	return false;
#endif
}

bool ULowEntryExtendedStandardLibrary::WindowsRtArmPlatform()
{
#ifdef PLATFORM_WINRT_ARM
	#if PLATFORM_WINRT_ARM
		return true;
	#else
		return false;
	#endif
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

bool ULowEntryExtendedStandardLibrary::SwitchPlatform()
{
#if PLATFORM_SWITCH
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



FString ULowEntryExtendedStandardLibrary::GetProjectName()
{
	FString Result;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectName"),
		Result,
		GGameIni
	);
	return Result;
}

FString ULowEntryExtendedStandardLibrary::GetProjectVersion()
{
	FString Result;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		Result,
		GGameIni
	);
	return Result;
}



void ULowEntryExtendedStandardLibrary::GetBatteryState(ELowEntryBatteryState& State, bool& Success)
{
#if PLATFORM_ANDROID
	Success = true;
	FAndroidMisc::FBatteryState Data = FAndroidMisc::GetBatteryState();
	if(Data.State == FAndroidMisc::EBatteryState::BATTERY_STATE_CHARGING)
	{
		State = ELowEntryBatteryState::Charging;
	}
	else if(Data.State == FAndroidMisc::EBatteryState::BATTERY_STATE_DISCHARGING)
	{
		State = ELowEntryBatteryState::Discharging;
	}
	else if(Data.State == FAndroidMisc::EBatteryState::BATTERY_STATE_FULL)
	{
		State = ELowEntryBatteryState::Full;
	}
	else if(Data.State == FAndroidMisc::EBatteryState::BATTERY_STATE_NOT_CHARGING)
	{
		State = ELowEntryBatteryState::NotCharging;
	}
	else
	{
		State = ELowEntryBatteryState::Unknown;
	}
#else
	Success = false;
	State = ELowEntryBatteryState::Unknown;
#endif
}

void ULowEntryExtendedStandardLibrary::GetBatteryCharge(int32& Percentage, bool& Success)
{
#if PLATFORM_ANDROID
	Success = true;
	FAndroidMisc::FBatteryState Data = FAndroidMisc::GetBatteryState();
	Percentage = Data.Level;
#else
	Success = false;
	Percentage = 0;
#endif
}

void ULowEntryExtendedStandardLibrary::GetBatteryTemperature(float& Celsius, bool& Success)
{
#if PLATFORM_ANDROID
	Success = true;
	FAndroidMisc::FBatteryState Data = FAndroidMisc::GetBatteryState();
	Celsius = Data.Temperature;
#else
	Success = false;
	Celsius = 0;
#endif
}



void ULowEntryExtendedStandardLibrary::GetCurrentVolumePercentage(float& Percentage, bool& Success)
{
#if PLATFORM_ANDROID
	Success = true;
	Percentage = (FAndroidMisc::GetVolumeState(NULL) / 15.0f);
#else
	Success = false;
	Percentage = 0;
#endif
}



void ULowEntryExtendedStandardLibrary::GetAndroidVolume(int& Volume)
{
#if PLATFORM_ANDROID
	Volume = FAndroidMisc::GetVolumeState(NULL);
#else
	Volume = 0;
#endif
}

FString ULowEntryExtendedStandardLibrary::GetAndroidDeviceMake()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDeviceMake();
#else
	return TEXT("");
#endif
}

FString ULowEntryExtendedStandardLibrary::GetAndroidDeviceModel()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDeviceModel();
#else
	return TEXT("");
#endif
}

FString ULowEntryExtendedStandardLibrary::GetAndroidVersion()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetAndroidVersion();
#else
	return TEXT("");
#endif
}

FString ULowEntryExtendedStandardLibrary::GetAndroidOsLanguage()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetOSLanguage();
#else
	return TEXT("");
#endif
}

FString ULowEntryExtendedStandardLibrary::GetAndroidDefaultLocale()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDefaultLocale();
#else
	return TEXT("");
#endif
}

FString ULowEntryExtendedStandardLibrary::GetAndroidGpuFamily()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetGPUFamily();
#else
	return TEXT("");
#endif
}

FString ULowEntryExtendedStandardLibrary::GetAndroidGlVersion()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetGLVersion();
#else
	return TEXT("");
#endif
}

int32 ULowEntryExtendedStandardLibrary::GetAndroidBuildVersion()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetAndroidBuildVersion();
#else
	return -1;
#endif
}

bool ULowEntryExtendedStandardLibrary::IsAndroidDaydreamApplication()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::IsDaydreamApplication();
#else
	return false;
#endif
}

int32 ULowEntryExtendedStandardLibrary::GetAndroidNumberOfCores()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::NumberOfCores();
#else
	return -1;
#endif
}

bool ULowEntryExtendedStandardLibrary::AreAndroidHeadphonesPluggedIn()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::AreHeadPhonesPluggedIn();
#else
	return false;
#endif
}



void ULowEntryExtendedStandardLibrary::GetCurrentVolume(int32& Volume, bool& Success)
{
	Success = false;
	Volume = 0;
}

void ULowEntryExtendedStandardLibrary::GetMaximumVolume(int32& Volume, bool& Success)
{
	Success = false;
	Volume = 0;
}



void ULowEntryExtendedStandardLibrary::CreateObject(TSubclassOf<UObject> Class, UObject*& Object)
{
	Object = NewObject<UObject>((UObject*) GetTransientPackage(), Class);
}



void ULowEntryExtendedStandardLibrary::GetGenericTeamId(AActor* Target, uint8& TeamID)
{
	IGenericTeamAgentInterface* TeamAgentInterface = NULL;
	if(Target != nullptr)
	{
		TeamAgentInterface = Cast<IGenericTeamAgentInterface>(Target);
	}
	if(TeamAgentInterface == nullptr)
	{
		TeamID = FGenericTeamId::NoTeam;
	}
	else
	{
		TeamID = TeamAgentInterface->GetGenericTeamId();
	}
}

void ULowEntryExtendedStandardLibrary::SetGenericTeamId(AActor* Target, const uint8 TeamID)
{
	if(Target == nullptr)
	{
		return;
	}
	IGenericTeamAgentInterface* TeamAgentInterface = Cast<IGenericTeamAgentInterface>(Target);
	if(TeamAgentInterface == nullptr)
	{
		return;
	}
	TeamAgentInterface->SetGenericTeamId(TeamID);
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

	for(int32 i = 0; i < LengthA; i++)
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
		int32 RandomByte = FMath::Rand() % 256;
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

	int32 Length = (FMath::Rand() % (Diff + 1)) + Min;
	if(Length <= 0)
	{
		ByteArray.SetNum(0);
		return;
	}

	ByteArray.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		int32 RandomByte = FMath::Rand() % 256;
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
	bool Success = FBase64::Decode(Base64, ByteArray);
	if(!Success)
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


FString ULowEntryExtendedStandardLibrary::Base64ToBase64Url(const FString& Base64)
{
	FString Fixed = Base64;
	Fixed.ReplaceInline(TEXT("+"), TEXT("-"));
	Fixed.ReplaceInline(TEXT("/"), TEXT("_"));
	Fixed.ReplaceInline(TEXT("="), TEXT(""));
	return Fixed;
}

FString ULowEntryExtendedStandardLibrary::Base64UrlToBase64(const FString& Base64Url)
{
	FString Fixed = Base64Url;
	Fixed.ReplaceInline(TEXT("-"), TEXT("+"));
	Fixed.ReplaceInline(TEXT("_"), TEXT("/"));
	return Fixed;
}

TArray<uint8> ULowEntryExtendedStandardLibrary::Base64UrlToBytes(const FString& Base64Url)
{
	return Base64ToBytes(Base64UrlToBase64(Base64Url));
}

FString ULowEntryExtendedStandardLibrary::BytesToBase64Url(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	return Base64ToBase64Url(BytesToBase64(ByteArray, Index, Length));
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
	for(int32 i = 1; i <= Hex.Len(); i++)
	{
		String.AppendChar(Hex[i - 1]);
		if(((i % 2) == 0) && (i < (Hex.Len() - 1)))
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
	TArray<uint8> Bytes;
	Bytes.SetNum(String.Len() / 8);
	int32 Index = 0;
	for(int32 i = 0; i < String.Len(); i += 8)
	{
		uint8 b = 0;
		for(int32 j = 0; j < 8; j++)
		{
			if(String[i + j] == '0')
			{
				continue;
			}
			else if(String[i + j] == '1')
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


TArray<uint8> ULowEntryExtendedStandardLibrary::BitStringToBytes(const FString& Binary)
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
	TArray<uint8> Bytes;
	Bytes.SetNum(String.Len() / 8);
	int32 Index = 0;
	for(int32 i = 0; i < String.Len(); i += 8)
	{
		uint8 b = 0;
		for(int32 j = 0; j < 8; j++)
		{
			if(String[i + j] == '0')
			{
				continue;
			}
			else if(String[i + j] == '1')
			{
				b += (1 << j);
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

FString ULowEntryExtendedStandardLibrary::BytesToBitString(const TArray<uint8>& ByteArray, const bool AddSpaces, int32 Index, int32 Length)
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
		for(int32 j = 0; j < 8; j++)
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


uint8 ULowEntryExtendedStandardLibrary::BooleanToByte(const bool Value)
{
	if(Value)
	{
		return 0x01;
	}
	else
	{
		return 0x00;
	}
}

bool ULowEntryExtendedStandardLibrary::ByteToBoolean(const uint8 Byte)
{
	return (Byte == 0x01);
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
		return ByteArray[Index + 0];
	}
	if(Length <= 2)
	{
		return (ByteArray[Index + 0] << 8) | ByteArray[Index + 1];
	}
	if(Length <= 3)
	{
		return (ByteArray[Index + 0] << 16) | (ByteArray[Index + 1] << 8) | ByteArray[Index + 2];
	}
	return (ByteArray[Index + 0] << 24) | (ByteArray[Index + 1] << 16) | (ByteArray[Index + 2] << 8) | ByteArray[Index + 3];
}


TArray<uint8> ULowEntryExtendedStandardLibrary::LongToBytes(const int64 Value)
{
	TArray<uint8> ByteArray;
	ByteArray.SetNum(8);
	ByteArray[0] = (Value >> 56);
	ByteArray[1] = (Value >> 48);
	ByteArray[2] = (Value >> 40);
	ByteArray[3] = (Value >> 32);
	ByteArray[4] = (Value >> 24);
	ByteArray[5] = (Value >> 16);
	ByteArray[6] = (Value >> 8);
	ByteArray[7] = (Value);
	return ByteArray;
}

int64 ULowEntryExtendedStandardLibrary::BytesToLong(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
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
		return ((int64) ByteArray[Index + 0]);
	}
	if(Length <= 2)
	{
		return (((int64) ByteArray[Index + 0]) << 8) | ((int64) ByteArray[Index + 1]);
	}
	if(Length <= 3)
	{
		return (((int64) ByteArray[Index + 0]) << 16) | (((int64) ByteArray[Index + 1]) << 8) | ((int64) ByteArray[Index + 2]);
	}
	if(Length <= 4)
	{
		return (((int64) ByteArray[Index + 0]) << 24) | (((int64) ByteArray[Index + 1]) << 16) | (((int64) ByteArray[Index + 2]) << 8) | ((int64) ByteArray[Index + 3]);
	}
	if(Length <= 5)
	{
		return (((int64) ByteArray[Index + 0]) << 32) | (((int64) ByteArray[Index + 1]) << 24) | (((int64) ByteArray[Index + 2]) << 16) | (((int64) ByteArray[Index + 3]) << 8) | ((int64) ByteArray[Index + 4]);
	}
	if(Length <= 6)
	{
		return (((int64) ByteArray[Index + 0]) << 40) | (((int64) ByteArray[Index + 1]) << 32) | (((int64) ByteArray[Index + 2]) << 24) | (((int64) ByteArray[Index + 3]) << 16) | (((int64) ByteArray[Index + 4]) << 8) | ((int64) ByteArray[Index + 5]);
	}
	if(Length <= 7)
	{
		return (((int64) ByteArray[Index + 0]) << 48) | (((int64) ByteArray[Index + 1]) << 40) | (((int64) ByteArray[Index + 2]) << 32) | (((int64) ByteArray[Index + 3]) << 24) | (((int64) ByteArray[Index + 4]) << 16) | (((int64) ByteArray[Index + 5]) << 8) | ((int64) ByteArray[Index + 6]);
	}
	return (((int64) ByteArray[Index + 0]) << 56) | (((int64) ByteArray[Index + 1]) << 48) | (((int64) ByteArray[Index + 2]) << 40) | (((int64) ByteArray[Index + 3]) << 32) | (((int64) ByteArray[Index + 4]) << 24) | (((int64) ByteArray[Index + 5]) << 16) | (((int64) ByteArray[Index + 6]) << 8) | ((int64) ByteArray[Index + 7]);
}

ULowEntryLong* ULowEntryExtendedStandardLibrary::BytesToLongBytes(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	return ULowEntryLong::Create(ByteArray, Index, Length);
}

ULowEntryLong* ULowEntryExtendedStandardLibrary::ParseStringIntoLongBytes(const FString& String)
{
	return ULowEntryExtendedStandardLibrary::BytesToLongBytes(ULowEntryExtendedStandardLibrary::LongToBytes(FCString::Atoi64(*String)));
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


TArray<uint8> ULowEntryExtendedStandardLibrary::DoubleToBytes(const double Value)
{
	int64 LongValue = *((int64*) (&Value));
	return ULowEntryExtendedStandardLibrary::LongToBytes(LongValue);
}

double ULowEntryExtendedStandardLibrary::BytesToDouble(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	int64 LongValue = ULowEntryExtendedStandardLibrary::BytesToLong(ByteArray, Index, Length);
	return *((double*) (&LongValue));
}

ULowEntryDouble* ULowEntryExtendedStandardLibrary::BytesToDoubleBytes(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	return ULowEntryDouble::Create(ByteArray, Index, Length);
}

ULowEntryDouble* ULowEntryExtendedStandardLibrary::ParseStringIntoDoubleBytes(const FString& String)
{
	return ULowEntryExtendedStandardLibrary::BytesToDoubleBytes(ULowEntryExtendedStandardLibrary::DoubleToBytes(FCString::Atod(*String)));
}


TArray<uint8> ULowEntryExtendedStandardLibrary::ByteToBytes(const uint8 Value)
{
	TArray<uint8> ByteArray;
	ByteArray.SetNum(1);
	ByteArray[0] = Value;
	return ByteArray;
}

uint8 ULowEntryExtendedStandardLibrary::BytesToByte(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
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

	return ByteArray[Index];
}


void ULowEntryExtendedStandardLibrary::BitsToByte(const bool Bit1, const bool Bit2, const bool Bit3, const bool Bit4, const bool Bit5, const bool Bit6, const bool Bit7, const bool Bit8, uint8& Byte)
{
	uint8 B = 0;
	if(Bit8)
	{
		B |= (1 << 7);
	}
	if(Bit7)
	{
		B |= (1 << 6);
	}
	if(Bit6)
	{
		B |= (1 << 5);
	}
	if(Bit5)
	{
		B |= (1 << 4);
	}
	if(Bit4)
	{
		B |= (1 << 3);
	}
	if(Bit3)
	{
		B |= (1 << 2);
	}
	if(Bit2)
	{
		B |= (1 << 1);
	}
	if(Bit1)
	{
		B |= (1 << 0);
	}
	Byte = B;
}

void ULowEntryExtendedStandardLibrary::ByteToBits(const uint8 Byte, bool& Bit1, bool& Bit2, bool& Bit3, bool& Bit4, bool& Bit5, bool& Bit6, bool& Bit7, bool& Bit8)
{
	Bit8 = (((Byte >> 7) & 1) != 0);
	Bit7 = (((Byte >> 6) & 1) != 0);
	Bit6 = (((Byte >> 5) & 1) != 0);
	Bit5 = (((Byte >> 4) & 1) != 0);
	Bit4 = (((Byte >> 3) & 1) != 0);
	Bit3 = (((Byte >> 2) & 1) != 0);
	Bit2 = (((Byte >> 1) & 1) != 0);
	Bit1 = (((Byte >> 0) & 1) != 0);
}


bool ULowEntryExtendedStandardLibrary::IsBitSet(const uint8 B, const int32 Bit)
{
	return (((B >> (Bit - 1)) & 1) != 0);
}

uint8 ULowEntryExtendedStandardLibrary::GetByteWithBitSet(const uint8 Byte, const int32 Bit, const bool Value)
{
	if(Value)
	{
		return Byte | (1 << (Bit - 1));
	}
	else
	{
		return Byte & ~(1 << (Bit - 1));
	}
}



UTexture2D* ULowEntryExtendedStandardLibrary::BytesToImage(const TArray<uint8>& ByteArray, const ELowEntryImageFormat ImageFormat, int32 Index, int32 Length)
{
	if(ByteArray.Num() <= 0)
	{
		return NULL;
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
		return NULL;
	}

	IImageWrapperModule* ImageWrapperModule = FModuleManager::LoadModulePtr<IImageWrapperModule>("ImageWrapper");
	if(ImageWrapperModule == nullptr)
	{
		return NULL;
	}

	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule->CreateImageWrapper(ELowEntryImageFormatToUE4(ImageFormat));
	if(!ImageWrapper.IsValid() || !ImageWrapper->SetCompressed(ByteArray.GetData() + Index, Length))
	{
		return NULL;
	}

	TArray<uint8> Uncompressed;
	if(!ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, Uncompressed))
	{
		return NULL;
	}

	return ULowEntryExtendedStandardLibrary::DataToTexture2D(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), Uncompressed.GetData(), Uncompressed.Num());
}

UTexture2D* ULowEntryExtendedStandardLibrary::BytesToExistingImage(bool& ReusedGivenTexture2D, UTexture2D* Texture2D, const TArray<uint8>& ByteArray, const ELowEntryImageFormat ImageFormat, int32 Index, int32 Length)
{
	ReusedGivenTexture2D = false;
	if(ByteArray.Num() <= 0)
	{
		ReusedGivenTexture2D = (Texture2D == nullptr);
		return NULL;
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
		ReusedGivenTexture2D = (Texture2D == nullptr);
		return NULL;
	}

	IImageWrapperModule* ImageWrapperModule = FModuleManager::LoadModulePtr<IImageWrapperModule>("ImageWrapper");
	if(ImageWrapperModule == nullptr)
	{
		ReusedGivenTexture2D = (Texture2D == nullptr);
		return NULL;
	}

	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule->CreateImageWrapper(ELowEntryImageFormatToUE4(ImageFormat));
	if(!ImageWrapper.IsValid() || !ImageWrapper->SetCompressed(ByteArray.GetData() + Index, Length))
	{
		ReusedGivenTexture2D = (Texture2D == nullptr);
		return NULL;
	}

	TArray<uint8> Uncompressed;
	if(!ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, Uncompressed))
	{
		ReusedGivenTexture2D = (Texture2D == nullptr);
		return NULL;
	}

	UTexture2D* NewTexture2D = ULowEntryExtendedStandardLibrary::DataToExistingTexture2D(Texture2D, ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), Uncompressed.GetData(), Uncompressed.Num());
	ReusedGivenTexture2D = (Texture2D == NewTexture2D);
	return NewTexture2D;
}

void ULowEntryExtendedStandardLibrary::Texture2DToBytes(UTexture2D* Texture2D, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality)
{
	ByteArray = TArray<uint8>();

	if(Texture2D == nullptr)
	{
		return;
	}

#if WITH_EDITORONLY_DATA
	if(Texture2D->MipGenSettings != TMGS_NoMipmaps)
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in Texture2DToBytes, the given Texture2D has to have MipGenSettings set to NoMipmaps, otherwise the blueprint will always fail"));
		return;
	}
#endif

	bool ChangedTexture2D = false;
	bool PreviousSRGB = Texture2D->SRGB;
	TextureCompressionSettings PreviousCompressionSettings = Texture2D->CompressionSettings;

	if((PreviousSRGB != false) || (PreviousCompressionSettings != TC_VectorDisplacementmap))
	{
		ChangedTexture2D = true;
		Texture2D->SRGB = false;
		Texture2D->CompressionSettings = TC_VectorDisplacementmap;
		Texture2D->UpdateResource();
	}

	FTexture2DMipMap& Mip0 = Texture2D->PlatformData->Mips[0];
	int32 Mip0Width = Mip0.SizeX;
	int32 Mip0Height = Mip0.SizeY;

	auto Mip0Data = &Mip0.BulkData;
	if(Mip0Data == nullptr)
	{
		if(ChangedTexture2D)
		{
			Texture2D->SRGB = PreviousSRGB;
			Texture2D->CompressionSettings = PreviousCompressionSettings;
			Texture2D->UpdateResource();
		}
		return;
	}

	void* Mip0Pixels_ = Mip0Data->Lock(LOCK_READ_ONLY);
	FColor* Mip0Pixels = static_cast<FColor*>(Mip0Pixels_);
	if(Mip0Pixels == nullptr)
	{
		Mip0Data->Unlock();
		if(ChangedTexture2D)
		{
			Texture2D->SRGB = PreviousSRGB;
			Texture2D->CompressionSettings = PreviousCompressionSettings;
			Texture2D->UpdateResource();
		}
		return;
	}

	TArray<FColor> Pixels;
	int32 Total = Mip0Width * Mip0Height;
	Pixels.SetNum(Total);
	for(int32 i = 0; i < Total; i++)
	{
		Pixels[i] = Mip0Pixels[i];
	}
	Mip0Data->Unlock();

	if(ChangedTexture2D)
	{
		Texture2D->SRGB = PreviousSRGB;
		Texture2D->CompressionSettings = PreviousCompressionSettings;
		Texture2D->UpdateResource();
	}

	PixelsToBytes(Mip0Width, Mip0Height, Pixels, ImageFormat, ByteArray, CompressionQuality);
}



void ULowEntryExtendedStandardLibrary::BytesToPixels(const TArray<uint8>& ByteArray, const ELowEntryImageFormat ImageFormat, int32& Width, int32& Height, TArray<FColor>& Pixels, int32 Index, int32 Length)
{
	Width = 0;
	Height = 0;
	Pixels = TArray<FColor>();

	//UTexture2D* Texture2D = ULowEntryExtendedStandardLibrary::BytesToImage(ByteArray, ImageFormat, Index, Length);
	//if(Texture2D == nullptr)
	//{
	//	return;
	//}
	//
	//ULowEntryExtendedStandardLibrary::Texture2DToPixels(Texture2D, Width, Height, Pixels);
	//return;

	if(ByteArray.Num() <= 0)
	{
		return;
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
		return;
	}

	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(ELowEntryImageFormatToUE4(ImageFormat));
	if(!ImageWrapper.IsValid() || !ImageWrapper->SetCompressed(ByteArray.GetData() + Index, Length))
	{
		return;
	}

	TArray<uint8> Uncompressed;
	if(!ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, Uncompressed))
	{
		return;
	}

	const void* Raw = Uncompressed.GetData();
	const FColor* DataPixels = static_cast<const FColor*>(Raw);
	int32 DataWidth = ImageWrapper->GetWidth();
	int32 DataHeight = ImageWrapper->GetHeight();

	int32 Total = DataWidth * DataHeight;
	Pixels.SetNum(Total);
	for(int32 i = 0; i < Total; i++)
	{
		Pixels[i] = DataPixels[i];
	}
	Width = DataWidth;
	Height = DataHeight;
}

void ULowEntryExtendedStandardLibrary::PixelsToBytes(const int32 Width, const int32 Height, const TArray<FColor>& Pixels, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality)
{
	ByteArray = TArray<uint8>();

	//FImageUtils::CompressImageArray(Width, Height, Pixels, ByteArray);
	//return;

	if((Width <= 0) || (Height <= 0))
	{
		return;
	}

	if((CompressionQuality < 0) || (CompressionQuality > 100))
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in PixelsToBytes, an invalid CompressionQuality (%i) has been given, should be 1-100 or 0 for the default value"), CompressionQuality);
		return;
	}

	int32 Total = Width * Height;
	if(Total != Pixels.Num())
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in PixelsToBytes, the number of given Pixels (%i) don't match the given Width (%i) x Height (%i) (Width x Height: %i)"), Pixels.Num(), Width, Height, Total);
		return;
	}

	if(ImageFormat == ELowEntryImageFormat::Invalid)
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in PixelsToBytes, Invalid compression is not supported"));
		return;
	}
	if(ImageFormat == ELowEntryImageFormat::BMP)
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in PixelsToBytes, BMP compression is not supported"));
		return;
	}
	if(ImageFormat == ELowEntryImageFormat::ICO)
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in PixelsToBytes, ICO compression is not supported"));
		return;
	}
	if(ImageFormat == ELowEntryImageFormat::ICNS)
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in PixelsToBytes, ICNS compression is not supported"));
		return;
	}

	if(ImageFormat == ELowEntryImageFormat::GrayscaleJPEG)
	{
		// Images are saved as RGBA but FColors are stored as Gray
		TArray<uint8> MutablePixels;
		for(int32 i = 0; i < Total; i++)
		{
			MutablePixels.Add((uint8) FMath::RoundToDouble((0.2125 * Pixels[i].R) + (0.7154 * Pixels[i].G) + (0.0721 * Pixels[i].B)));
		}

		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(ELowEntryImageFormatToUE4(ImageFormat));
		if(!ImageWrapper.IsValid() || !ImageWrapper->SetRaw(MutablePixels.GetData(), MutablePixels.Num(), Width, Height, ERGBFormat::Gray, 8))
		{
			return;
		}

		ByteArray = ImageWrapper->GetCompressed(CompressionQuality);
	}
	else
	{
		// Images are saved as RGBA but FColors are stored as BGRA
		TArray<FColor> MutablePixels = Pixels;
		for(int32 i = 0; i < Total; i++)
		{
			MutablePixels[i].R = Pixels[i].B;
			MutablePixels[i].B = Pixels[i].R;
		}

		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(ELowEntryImageFormatToUE4(ImageFormat));
		if(!ImageWrapper.IsValid() || !ImageWrapper->SetRaw(&MutablePixels[0], MutablePixels.Num() * sizeof(FColor), Width, Height, ERGBFormat::RGBA, 8))
		{
			return;
		}

		ByteArray = ImageWrapper->GetCompressed(CompressionQuality);
	}
}


FColor ULowEntryExtendedStandardLibrary::GrayscalePixel(const FColor& Pixel)
{
	uint8 Gray = (uint8)FMath::RoundToDouble((0.2125 * Pixel.R) + (0.7154 * Pixel.G) + (0.0721 * Pixel.B));
	return FColor(Gray, Gray, Gray, Pixel.A);
}

TArray<FColor> ULowEntryExtendedStandardLibrary::GrayscalePixels(const TArray<FColor>& Pixels)
{
	TArray<FColor> Result;
	for(FColor Pixel : Pixels)
	{
		Result.Add(GrayscalePixel(Pixel));
	}
	return Result;
}


void ULowEntryExtendedStandardLibrary::Texture2DToPixels(UTexture2D* Texture2D, int32& Width, int32& Height, TArray<FColor>& Pixels)
{
	Width = 0;
	Height = 0;
	Pixels = TArray<FColor>();

	if(Texture2D == nullptr)
	{
		return;
	}

#if WITH_EDITORONLY_DATA
	if(Texture2D->MipGenSettings != TMGS_NoMipmaps)
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in ImageToPixels, the given Texture2D has to have MipGenSettings set to NoMipmaps, otherwise the blueprint will always fail"));
		return;
	}
#endif

	bool ChangedTexture2D = false;
	bool PreviousSRGB = Texture2D->SRGB;
	TextureCompressionSettings PreviousCompressionSettings = Texture2D->CompressionSettings;

	if((PreviousSRGB != false) || (PreviousCompressionSettings != TC_VectorDisplacementmap))
	{
		ChangedTexture2D = true;
		Texture2D->SRGB = false;
		Texture2D->CompressionSettings = TC_VectorDisplacementmap;
		Texture2D->UpdateResource();
	}

	FTexture2DMipMap& Mip0 = Texture2D->PlatformData->Mips[0];
	int32 Mip0Width = Mip0.SizeX;
	int32 Mip0Height = Mip0.SizeY;

	auto Mip0Data = &Mip0.BulkData;
	if(Mip0Data == nullptr)
	{
		if(ChangedTexture2D)
		{
			Texture2D->SRGB = PreviousSRGB;
			Texture2D->CompressionSettings = PreviousCompressionSettings;
			Texture2D->UpdateResource();
		}
		return;
	}

	void* Mip0Pixels_ = Mip0Data->Lock(LOCK_READ_ONLY);
	FColor* Mip0Pixels = static_cast<FColor*>(Mip0Pixels_);
	if(Mip0Pixels == nullptr)
	{
		Mip0Data->Unlock();
		if(ChangedTexture2D)
		{
			Texture2D->SRGB = PreviousSRGB;
			Texture2D->CompressionSettings = PreviousCompressionSettings;
			Texture2D->UpdateResource();
		}
		return;
	}

	Width = Mip0Width;
	Height = Mip0Height;
	int32 Total = Mip0Width * Mip0Height;
	Pixels.SetNum(Total);
	for(int32 i = 0; i < Total; i++)
	{
		Pixels[i] = Mip0Pixels[i];
	}
	Mip0Data->Unlock();

	if(ChangedTexture2D)
	{
		Texture2D->SRGB = PreviousSRGB;
		Texture2D->CompressionSettings = PreviousCompressionSettings;
		Texture2D->UpdateResource();
	}
}

UTexture2D* ULowEntryExtendedStandardLibrary::PixelsToTexture2D(const int32 Width, const int32 Height, const TArray<FColor>& Pixels)
{
	if((Pixels.Num() <= 0) || (Width <= 0) || (Height <= 0))
	{
		return NULL;
	}
	return ULowEntryExtendedStandardLibrary::DataToTexture2D(Width, Height, &Pixels[0], Pixels.Num() * sizeof(FColor));
}

UTexture2D* ULowEntryExtendedStandardLibrary::PixelsToExistingTexture2D(bool& ReusedGivenTexture2D, UTexture2D* Texture2D, const int32 Width, const int32 Height, const TArray<FColor>& Pixels)
{
	ReusedGivenTexture2D = false;
	if((Pixels.Num() <= 0) || (Width <= 0) || (Height <= 0))
	{
		ReusedGivenTexture2D = (Texture2D == nullptr);
		return NULL;
	}
	UTexture2D* NewTexture2D = ULowEntryExtendedStandardLibrary::DataToExistingTexture2D(Texture2D, Width, Height, &Pixels[0], Pixels.Num() * sizeof(FColor));
	ReusedGivenTexture2D = (Texture2D == NewTexture2D);
	return NewTexture2D;
}



UTexture2D* ULowEntryExtendedStandardLibrary::DataToTexture2D(int32 Width, int32 Height, const void* Src, SIZE_T Count)
{
	UTexture2D* Texture2D = UTexture2D::CreateTransient(Width, Height, EPixelFormat::PF_B8G8R8A8);
	if(Texture2D == nullptr)
	{
		return NULL;
	}
	Texture2D->bNoTiling = true;

	void* TextureData = Texture2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(TextureData, Src, Count);
	Texture2D->PlatformData->Mips[0].BulkData.Unlock();

	Texture2D->UpdateResource();
	return Texture2D;
}

UTexture2D* ULowEntryExtendedStandardLibrary::DataToExistingTexture2D(UTexture2D* Texture2D, int32 Width, int32 Height, const void* Src, SIZE_T Count)
{
	if((Texture2D == nullptr) || (Texture2D->GetSizeX() != Width) || (Texture2D->GetSizeY() != Height) || (Texture2D->GetPixelFormat() != EPixelFormat::PF_B8G8R8A8))
	{
		Texture2D = UTexture2D::CreateTransient(Width, Height, EPixelFormat::PF_B8G8R8A8);
	}
	if(Texture2D == nullptr)
	{
		return NULL;
	}
	Texture2D->bNoTiling = true;

	void* TextureData = Texture2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(TextureData, Src, Count);
	Texture2D->PlatformData->Mips[0].BulkData.Unlock();

	Texture2D->UpdateResource();
	return Texture2D;
}



void ULowEntryExtendedStandardLibrary::SceneCapture2DToBytes(ASceneCapture2D* SceneCapture2D, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality)
{
	ByteArray = TArray<uint8>();
	if(SceneCapture2D != nullptr)
	{
		SceneCaptureComponent2DToBytes(SceneCapture2D->GetCaptureComponent2D(), ImageFormat, ByteArray, CompressionQuality);
	}
}

void ULowEntryExtendedStandardLibrary::SceneCaptureComponent2DToBytes(USceneCaptureComponent2D* SceneCaptureComponent2D, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality)
{
	ByteArray = TArray<uint8>();
	if(SceneCaptureComponent2D != nullptr)
	{
		TextureRenderTarget2DToBytes(SceneCaptureComponent2D->TextureTarget, ImageFormat, ByteArray, CompressionQuality);
	}
}

void ULowEntryExtendedStandardLibrary::TextureRenderTarget2DToBytes(UTextureRenderTarget2D* TextureRenderTarget2D, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality)
{
	ByteArray = TArray<uint8>();

	if(TextureRenderTarget2D == nullptr)
	{
		return;
	}
	if(TextureRenderTarget2D->GetFormat() != PF_B8G8R8A8)
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in ImageToBytes, the TextureRenderTarget2D has a [Render Target Format] that is not supported, use [RTF RGBA8] instead ([PF_B8G8R8A8] in C++)"));
		return;
	}

	FRenderTarget* RenderTarget = TextureRenderTarget2D->GameThread_GetRenderTargetResource();
	if(RenderTarget == nullptr)
	{
		return;
	}

	TArray<FColor> Pixels;
	if(!RenderTarget->ReadPixels(Pixels))
	{
		return;
	}
	for(FColor& Pixel : Pixels)
	{
		Pixel.A = 255;
	}

	PixelsToBytes(TextureRenderTarget2D->SizeX, TextureRenderTarget2D->SizeY, Pixels, ImageFormat, ByteArray, CompressionQuality);
}


void ULowEntryExtendedStandardLibrary::SceneCapture2DToPixels(ASceneCapture2D* SceneCapture2D, int32& Width, int32& Height, TArray<FColor>& Pixels)
{
	if(SceneCapture2D == nullptr)
	{
		Width = 0;
		Height = 0;
		Pixels = TArray<FColor>();
		return;
	}
	SceneCaptureComponent2DToPixels(SceneCapture2D->GetCaptureComponent2D(), Width, Height, Pixels);
}

void ULowEntryExtendedStandardLibrary::SceneCaptureComponent2DToPixels(USceneCaptureComponent2D* SceneCaptureComponent2D, int32& Width, int32& Height, TArray<FColor>& Pixels)
{
	if(SceneCaptureComponent2D == nullptr)
	{
		Width = 0;
		Height = 0;
		Pixels = TArray<FColor>();
		return;
	}
	TextureRenderTarget2DToPixels(SceneCaptureComponent2D->TextureTarget, Width, Height, Pixels);
}

void ULowEntryExtendedStandardLibrary::TextureRenderTarget2DToPixels(UTextureRenderTarget2D* TextureRenderTarget2D, int32& Width, int32& Height, TArray<FColor>& Pixels)
{
	Width = 0;
	Height = 0;
	Pixels = TArray<FColor>();

	if(TextureRenderTarget2D == nullptr)
	{
		return;
	}
	if(TextureRenderTarget2D->GetFormat() != PF_B8G8R8A8)
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("in ImageToPixels, the TextureRenderTarget2D has a [Render Target Format] that is not supported, use [RTF RGBA8] instead ([PF_B8G8R8A8] in C++)"));
		return;
	}

	FRenderTarget* RenderTarget = TextureRenderTarget2D->GameThread_GetRenderTargetResource();
	if(RenderTarget == nullptr)
	{
		return;
	}

	if(!RenderTarget->ReadPixels(Pixels))
	{
		Pixels = TArray<FColor>();
		return;
	}
	FIntPoint Size = RenderTarget->GetSizeXY();
	Width = Size.X;
	Height = Size.Y;
	for(FColor& Pixel : Pixels)
	{
		Pixel.A = 255;
	}
}



void ULowEntryExtendedStandardLibrary::LoadVideo(UMediaSoundComponent* MediaSoundComponent, const FString& Url, bool& Success, UMediaPlayer*& Player, UMediaTexture*& Texture, const bool PlayOnOpen, const bool Loop)
{
	Success = false;
	Player = NULL;
	Texture = NULL;

	UMediaPlayer* LoadPlayer = NewObject<UMediaPlayer>();
	if(!LoadPlayer->OpenUrl(Url))
	{
		return;
	}

	Success = true;

	Player = LoadPlayer;
	Player->SetLooping(Loop);
	Player->PlayOnOpen = PlayOnOpen;

	Texture = NewObject<UMediaTexture>();
	Texture->SetMediaPlayer(Player);
	Texture->UpdateResource();

	if(MediaSoundComponent != nullptr)
	{
		MediaSoundComponent->SetMediaPlayer(Player);
	}
}



void ULowEntryExtendedStandardLibrary::TextureUpdateResource(UTexture* Texture)
{
	if(Texture != nullptr)
	{
		Texture->UpdateResource();
	}
}



void ULowEntryExtendedStandardLibrary::SceneCapture2D_GetFov(ASceneCapture2D* SceneCapture2D, float& Fov)
{
	Fov = SceneCapture2D->GetCaptureComponent2D()->FOVAngle;
}

void ULowEntryExtendedStandardLibrary::SceneCapture2D_SetFov(ASceneCapture2D* SceneCapture2D, const float Fov)
{
	SceneCapture2D->GetCaptureComponent2D()->FOVAngle = Fov;
}


void ULowEntryExtendedStandardLibrary::SceneCaptureComponent2D_GetFov(USceneCaptureComponent2D* SceneCaptureComponent2D, float& Fov)
{
	Fov = SceneCaptureComponent2D->FOVAngle;
}

void ULowEntryExtendedStandardLibrary::SceneCaptureComponent2D_SetFov(USceneCaptureComponent2D* SceneCaptureComponent2D, const float Fov)
{
	SceneCaptureComponent2D->FOVAngle = Fov;
}



TArray<uint8> ULowEntryExtendedStandardLibrary::Pearson(const TArray<uint8>& ByteArray, const int32 HashLength, int32 Index, int32 Length)
{
	return ULowEntryHashingPearsonLibrary::Hash(ByteArray, Index, Length, HashLength);
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

TArray<uint8> ULowEntryExtendedStandardLibrary::Sha256(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	return ULowEntryHashingSha256Library::Hash(ByteArray, Index, Length);
}

TArray<uint8> ULowEntryExtendedStandardLibrary::Sha512(const TArray<uint8>& ByteArray, int32 Index, int32 Length)
{
	return ULowEntryHashingSha512Library::Hash(ByteArray, Index, Length);
}

TArray<uint8> ULowEntryExtendedStandardLibrary::BCrypt(const TArray<uint8>& ByteArray, const TArray<uint8>& Salt, int32 Strength, int32 Index, int32 Length)
{
	return ULowEntryHashingBCryptLibrary::Hash(BytesSubArray(ByteArray, Index, Length), Salt, Strength);
}



TArray<uint8> ULowEntryExtendedStandardLibrary::HMAC(const TArray<uint8>& ByteArray, const TArray<uint8>& Key, ELowEntryHmacAlgorithm Algorithm, int32 Index, int32 Length)
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

	int32 BlockSize = HMAC_GetBlockSize(Algorithm);

	TArray<uint8> KeyBytes = Key;
	if(KeyBytes.Num() > BlockSize)
	{
		KeyBytes = HMAC_Hash(KeyBytes, Algorithm);// key = hash(key)
	}
	if(KeyBytes.Num() != BlockSize)
	{
		KeyBytes.SetNumZeroed(BlockSize);// key = key + 0x00 (till KeyBytes has BlockSize length)
	}

	TArray<uint8> ArrayO = KeyBytes;
	TArray<uint8> ArrayI = KeyBytes;
	for(int32 i = 0; i < KeyBytes.Num(); i++)
	{
		ArrayO[i] ^= 0x5c;// o_key_pad = 0x5c ^ key
		ArrayI[i] ^= 0x36;// i_key_pad = 0x36 ^ key
	}

	if(Length > 0)// (i_key_pad + message)
	{
		ArrayI.Append(ByteArray.GetData() + Index, Length);
	}
	ArrayI = HMAC_Hash(ArrayI, Algorithm);// hash(i_key_pad + message)
	ArrayO.Append(ArrayI.GetData(), ArrayI.Num());// (o_key_pad + hash(i_key_pad + message))
	return HMAC_Hash(ArrayO, Algorithm);// hash(o_key_pad + hash(i_key_pad + message))
}

int32 ULowEntryExtendedStandardLibrary::HMAC_GetBlockSize(ELowEntryHmacAlgorithm Algorithm)
{
	switch(Algorithm)
	{
		case ELowEntryHmacAlgorithm::MD5:
			return 64;
		case ELowEntryHmacAlgorithm::SHA1:
			return 64;
		case ELowEntryHmacAlgorithm::SHA256:
			return 64;
		case ELowEntryHmacAlgorithm::SHA512:
			return 128;
		default:
			UE_LOG(LogBlueprintUserMessages, Error, TEXT("Unsupported HMAC Algorithm, falls back to SHA-256"));
			return 64;// defaults to SHA-256
	}
}

TArray<uint8> ULowEntryExtendedStandardLibrary::HMAC_Hash(const TArray<uint8>& Array, ELowEntryHmacAlgorithm Algorithm)
{
	switch(Algorithm)
	{
		case ELowEntryHmacAlgorithm::MD5:
			return Md5(Array);
			break;
		case ELowEntryHmacAlgorithm::SHA1:
			return Sha1(Array);
			break;
		case ELowEntryHmacAlgorithm::SHA256:
			return Sha256(Array);
			break;
		case ELowEntryHmacAlgorithm::SHA512:
			return Sha512(Array);
			break;
		default:
			UE_LOG(LogBlueprintUserMessages, Error, TEXT("Unsupported HMAC Algorithm, falls back to SHA-256"));
			return Sha256(Array);// defaults to SHA-256
	}
}



TArray<FString> ULowEntryExtendedStandardLibrary::HashcashArray(const TArray<FString>& Resources, const int32 Bits)
{
	return ULowEntryHashingHashcashLibrary::hashArray(Resources, Bits);
}

TArray<FString> ULowEntryExtendedStandardLibrary::HashcashArrayCustomCreationDate(const TArray<FString>& Resources, const FDateTime& UtcDate, const int32 Bits)
{
	return ULowEntryHashingHashcashLibrary::hashArrayCustomCreationDate(Resources, UtcDate, Bits);
}

FString ULowEntryExtendedStandardLibrary::Hashcash(const FString& Resource, const int32 Bits)
{
	return ULowEntryHashingHashcashLibrary::hash(Resource, Bits);
}

FString ULowEntryExtendedStandardLibrary::HashcashCustomCreationDate(const FString& Resource, const FDateTime& UtcDate, const int32 Bits)
{
	return ULowEntryHashingHashcashLibrary::hashCustomCreationDate(Resource, UtcDate, Bits);
}


TArray<ULowEntryParsedHashcash*> ULowEntryExtendedStandardLibrary::HashcashParseArray(const TArray<FString>& Hashes)
{
	return ULowEntryHashingHashcashLibrary::parseArray(Hashes);
}

ULowEntryParsedHashcash* ULowEntryExtendedStandardLibrary::HashcashParse(const FString& Hash)
{
	return ULowEntryHashingHashcashLibrary::parse(Hash);
}


bool ULowEntryExtendedStandardLibrary::ParsedHashcashIsValid(ULowEntryParsedHashcash* Target)
{
	if(Target == nullptr)
	{
		return false;
	}
	return Target->IsHashcashValid();
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



void ULowEntryExtendedStandardLibrary::DateTime_ToIso8601(const FDateTime& DateTime, FString& String)
{
	String = DateTime.ToIso8601();
}

void ULowEntryExtendedStandardLibrary::DateTime_ToString(const FDateTime& DateTime, FString& String, const FString& Format)
{
	String = DateTime.ToString(*Format);
}

void ULowEntryExtendedStandardLibrary::DateTime_ToUnixTimestamp(const FDateTime& DateTime, ULowEntryLong*& Timestamp)
{
	FTimespan Time = DateTime - FDateTime::FromUnixTimestamp(0);
	Timestamp = ULowEntryLong::Create(ULowEntryExtendedStandardLibrary::LongToBytes((int64) Time.GetTotalMilliseconds()));

	// ignores milliseconds:
	//  Timestamp = ULowEntryLong::Create(ULowEntryExtendedStandardLibrary::LongToBytes(DateTime.ToUnixTimestamp() * 1000));
}

void ULowEntryExtendedStandardLibrary::DateTime_FromUnixTimestamp(ULowEntryLong* Timestamp, FDateTime& DateTime)
{
	if(Timestamp == nullptr)
	{
		DateTime = FDateTime::FromUnixTimestamp(0);
	}
	else
	{
		int64 Millis = ULowEntryExtendedStandardLibrary::BytesToLong(Timestamp->GetBytes());
		DateTime = FDateTime::FromUnixTimestamp(0) + FTimespan(Millis * (ETimespan::TicksPerSecond / 1000));

		//ignored milliseconds:
		// DateTime = FDateTime::FromUnixTimestamp(ULowEntryExtendedStandardLibrary::BytesToLong(Timestamp->GetBytes()) / 1000);
	}
}



void ULowEntryExtendedStandardLibrary::ConvertLocalDateToUtcDate(const FDateTime& Local, FDateTime& Utc)
{
	Utc = Local - (FDateTime::Now() - FDateTime::UtcNow());
}

void ULowEntryExtendedStandardLibrary::ConvertUtcDateToLocalDate(const FDateTime& Utc, FDateTime& Local)
{
	Local = Utc + (FDateTime::Now() - FDateTime::UtcNow());
}



TArray<FString> ULowEntryExtendedStandardLibrary::SortStringArray(const TArray<FString>& StringArray, const bool Reversed)
{
	TArray<FString> Array = StringArray;
	if(!Reversed)
	{
		Array.Sort([](const FString& A, const FString& B)
		{
			return A < B;
		});
	}
	else
	{
		Array.Sort([](const FString& A, const FString& B)
		{
			return A > B;
		});
	}
	return Array;
}

void ULowEntryExtendedStandardLibrary::SortStringArrayDirectly(UPARAM(ref) TArray<FString>& StringArray, const bool Reversed)
{
	if(!Reversed)
	{
		StringArray.Sort([](const FString& A, const FString& B)
		{
			return A < B;
		});
	}
	else
	{
		StringArray.Sort([](const FString& A, const FString& B)
		{
			return A > B;
		});
	}
}


TArray<int32> ULowEntryExtendedStandardLibrary::SortIntegerArray(const TArray<int32>& IntegerArray, const bool Reversed)
{
	TArray<int32> Array = IntegerArray;
	if(!Reversed)
	{
		Array.Sort([](const int32 A, const int32 B)
		{
			return A < B;
		});
	}
	else
	{
		Array.Sort([](const int32 A, const int32 B)
		{
			return A > B;
		});
	}
	return Array;
}

void ULowEntryExtendedStandardLibrary::SortIntegerArrayDirectly(UPARAM(ref) TArray<int32>& IntegerArray, const bool Reversed)
{
	if(!Reversed)
	{
		IntegerArray.Sort([](const int32 A, const int32 B)
		{
			return A < B;
		});
	}
	else
	{
		IntegerArray.Sort([](const int32 A, const int32 B)
		{
			return A > B;
		});
	}
}


TArray<float> ULowEntryExtendedStandardLibrary::SortFloatArray(const TArray<float>& FloatArray, const bool Reversed)
{
	TArray<float> Array = FloatArray;
	if(!Reversed)
	{
		Array.Sort([](const float A, const float B)
		{
			return A < B;
		});
	}
	else
	{
		Array.Sort([](const float A, const float B)
		{
			return A > B;
		});
	}
	return Array;
}

void ULowEntryExtendedStandardLibrary::SortFloatArrayDirectly(UPARAM(ref) TArray<float>& FloatArray, const bool Reversed)
{
	if(!Reversed)
	{
		FloatArray.Sort([](const float A, const float B)
		{
			return A < B;
		});
	}
	else
	{
		FloatArray.Sort([](const float A, const float B)
		{
			return A > B;
		});
	}
}


TArray<uint8> ULowEntryExtendedStandardLibrary::SortByteArray(const TArray<uint8>& ByteArray, const bool Reversed)
{
	TArray<uint8> Array = ByteArray;
	if(!Reversed)
	{
		Array.Sort([](const uint8 A, const uint8 B)
		{
			return A < B;
		});
	}
	else
	{
		Array.Sort([](const uint8 A, const uint8 B)
		{
			return A > B;
		});
	}
	return Array;
}

void ULowEntryExtendedStandardLibrary::SortByteArrayDirectly(UPARAM(ref) TArray<uint8>& ByteArray, const bool Reversed)
{
	if(!Reversed)
	{
		ByteArray.Sort([](const uint8 A, const uint8 B)
		{
			return A < B;
		});
	}
	else
	{
		ByteArray.Sort([](const uint8 A, const uint8 B)
		{
			return A > B;
		});
	}
}


TArray<FDateTime> ULowEntryExtendedStandardLibrary::SortDateTimeArray(const TArray<FDateTime>& DateTimeArray, const bool Reversed)
{
	TArray<FDateTime> Array = DateTimeArray;
	if(!Reversed)
	{
		Array.Sort([](const FDateTime& A, const FDateTime& B)
		{
			return A < B;
		});
	}
	else
	{
		Array.Sort([](const FDateTime& A, const FDateTime& B)
		{
			return A > B;
		});
	}
	return Array;
}

void ULowEntryExtendedStandardLibrary::SortDateTimeArrayDirectly(UPARAM(ref) TArray<FDateTime>& DateTimeArray, const bool Reversed)
{
	if(!Reversed)
	{
		DateTimeArray.Sort([](const FDateTime& A, const FDateTime& B)
		{
			return A < B;
		});
	}
	else
	{
		DateTimeArray.Sort([](const FDateTime& A, const FDateTime& B)
		{
			return A > B;
		});
	}
}


TArray<FTimespan> ULowEntryExtendedStandardLibrary::SortTimespanArray(const TArray<FTimespan>& TimespanArray, const bool Reversed)
{
	TArray<FTimespan> Array = TimespanArray;
	if(!Reversed)
	{
		Array.Sort([](const FTimespan& A, const FTimespan& B)
		{
			return A < B;
		});
	}
	else
	{
		Array.Sort([](const FTimespan& A, const FTimespan& B)
		{
			return A > B;
		});
	}
	return Array;
}

void ULowEntryExtendedStandardLibrary::SortTimespanArrayDirectly(UPARAM(ref) TArray<FTimespan>& TimespanArray, const bool Reversed)
{
	if(!Reversed)
	{
		TimespanArray.Sort([](const FTimespan& A, const FTimespan& B)
		{
			return A < B;
		});
	}
	else
	{
		TimespanArray.Sort([](const FTimespan& A, const FTimespan& B)
		{
			return A > B;
		});
	}
}


TArray<UObject*> ULowEntryExtendedStandardLibrary::SortObjectArray(const TArray<UObject*>& ObjectArray, FDelegateULowEntryExtendedStandardLibraryCompareObjects Comparator, const bool Reversed)
{
	TArray<UObject*> Array = ObjectArray;
	if(!Reversed)
	{
		Array.Sort([Comparator](UObject& A, UObject& B)
		{
			bool Result = false;
			Comparator.Execute(&A, &B, Result);
			return Result;
		});
	}
	else
	{
		Array.Sort([Comparator](UObject& A, UObject& B)
		{
			bool Result = false;
			Comparator.Execute(&A, &B, Result);
			return !Result;
		});
	}
	return Array;
}

void ULowEntryExtendedStandardLibrary::SortObjectArrayDirectly(UPARAM(ref) TArray<UObject*>& ObjectArray, FDelegateULowEntryExtendedStandardLibraryCompareObjects Comparator, const bool Reversed)
{
	if(!Reversed)
	{
		ObjectArray.Sort([Comparator](UObject& A, UObject& B)
		{
			bool Result = false;
			Comparator.Execute(&A, &B, Result);
			return Result;
		});
	}
	else
	{
		ObjectArray.Sort([Comparator](UObject& A, UObject& B)
		{
			bool Result = false;
			Comparator.Execute(&A, &B, Result);
			return !Result;
		});
	}
}



void ULowEntryExtendedStandardLibrary::RandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
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
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
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
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if(LatentActionManager.FindExistingAction<FLowEntryDelayFramesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryDelayFramesAction(Frames, LatentInfo));
		}
	}
}

void ULowEntryExtendedStandardLibrary::RetriggerableDelayFrames(UObject* WorldContextObject, int32 Frames, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FLowEntryDelayFramesAction* Action = LatentActionManager.FindExistingAction<FLowEntryDelayFramesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if(Action == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryDelayFramesAction(Frames, LatentInfo));
		}
		else
		{
			Action->FramesRemaining = Frames;
		}
	}
}

void ULowEntryExtendedStandardLibrary::RandomDelayFrames(UObject* WorldContextObject, int32 MinFrames, int32 MaxFrames, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if(LatentActionManager.FindExistingAction<FLowEntryDelayFramesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryDelayFramesAction(FMath::RandRange(MinFrames, MaxFrames), LatentInfo));
		}
	}
}

void ULowEntryExtendedStandardLibrary::RetriggerableRandomDelayFrames(UObject* WorldContextObject, int32 MinFrames, int32 MaxFrames, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FLowEntryDelayFramesAction* Action = LatentActionManager.FindExistingAction<FLowEntryDelayFramesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if(Action == NULL)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryDelayFramesAction(FMath::RandRange(MinFrames, MaxFrames), LatentInfo));
		}
		else
		{
			Action->FramesRemaining = FMath::RandRange(MinFrames, MaxFrames);
		}
	}
}



void ULowEntryExtendedStandardLibrary::QueueExecutions(UObject* WorldContextObject, ULowEntryExecutionQueue*& Queue, FLatentActionInfo LatentInfo)
{
	if(UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FLowEntryExecutionQueueAction* Action = LatentActionManager.FindExistingAction<FLowEntryExecutionQueueAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if(Action == NULL)
		{
			Queue = ULowEntryExecutionQueue::Create(1, true);
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryExecutionQueueAction(Queue, LatentInfo));
		}
		else
		{
			Queue = Action->GetOrCreateQueueAndIncreaseCount();
		}
	}
}

void ULowEntryExtendedStandardLibrary::NextQueueExecution(ULowEntryExecutionQueue* Queue)
{
	if((Queue != nullptr) && Queue->IsValidLowLevel() && !Queue->IsPendingKill())
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



bool ULowEntryExtendedStandardLibrary::RegexMatch(const FString& String, const FString& Pattern)
{
	FRegexPattern RegexPattern(Pattern);
	FRegexMatcher RegexMatcher(RegexPattern, String);
	return RegexMatcher.FindNext();
}

int32 ULowEntryExtendedStandardLibrary::RegexCount(const FString& String, const FString& Pattern)
{
	FRegexPattern RegexPattern(Pattern);
	FRegexMatcher RegexMatcher(RegexPattern, String);
	int32 Count = 0;
	int32 Length = String.Len();
	while(RegexMatcher.FindNext())
	{
		Count++;
		int32 e = RegexMatcher.GetMatchEnding();
		RegexMatcher.SetLimits(e, Length);
	}
	return Count;
}

TArray<FLowEntryRegexMatch> ULowEntryExtendedStandardLibrary::RegexGetMatches(const FString& String, const FString& Pattern)
{
	TArray<FLowEntryRegexMatch> Matches;

	int32 Length = String.Len();
	FRegexPattern RegexPattern(Pattern);
	FRegexMatcher RegexMatcher(RegexPattern, String);
	int32 MatchNumber = 0;
	while(RegexMatcher.FindNext())
	{
		MatchNumber++;
		int32 b = RegexMatcher.GetMatchBeginning();
		int32 e = RegexMatcher.GetMatchEnding();
		if((b < 0) || (e < 0))
		{
			continue;
		}

		TArray<FLowEntryRegexCaptureGroup> CaptureGroups;
		int32 CaptureGroupNumber = 0;
		while(true)
		{
			CaptureGroupNumber++;
			int32 gb = RegexMatcher.GetCaptureGroupBeginning(CaptureGroupNumber);
			int32 ge = RegexMatcher.GetCaptureGroupEnding(CaptureGroupNumber);
			if((gb < 0) || (ge < 0))
			{
				break;
			}
			FLowEntryRegexCaptureGroup GroupMatch;
			GroupMatch.CaptureGroupNumber = CaptureGroupNumber;
			GroupMatch.BeginIndex = gb;
			GroupMatch.EndIndex = ge;
			GroupMatch.Match = String.Mid(gb, ge - gb);
			CaptureGroups.Add(GroupMatch);
		}

		FLowEntryRegexMatch Match;
		Match.MatchNumber = MatchNumber;
		Match.BeginIndex = b;
		Match.EndIndex = e;
		Match.Match = String.Mid(b, e - b);
		Match.CaptureGroups = CaptureGroups;
		Matches.Add(Match);

		RegexMatcher.SetLimits(e, Length);
	}

	return Matches;
}

FString ULowEntryExtendedStandardLibrary::RegexReplace(const FString& String, const FString& Pattern, const FString& Replacement)
{
	int32 Length = String.Len();

	FString Result = TEXT("");
	int32 LastMatchEnding = 0;

	FRegexPattern RegexPattern(Pattern);
	FRegexMatcher RegexMatcher(RegexPattern, String);
	while(RegexMatcher.FindNext())
	{
		int32 b = RegexMatcher.GetMatchBeginning();
		int32 e = RegexMatcher.GetMatchEnding();

		for(int32 i = LastMatchEnding; i < b; i++)
		{
			Result += String[i];
		}
		Result += Replacement;

		RegexMatcher.SetLimits(e, Length);
		LastMatchEnding = e;
	}
	for(int32 i = LastMatchEnding; i < Length; i++)
	{
		Result += String[i];
	}
	return Result;
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
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if(World == nullptr)
	{
		return;
	}

	World->GetLatentActionManager().AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new FLowEntryTickFrames(LatentInfo, Ticks, FramesInterval, Tick));
}

void ULowEntryExtendedStandardLibrary::TickSeconds(UObject* WorldContextObject, FLatentActionInfo LatentInfo, const int32 Ticks, const float SecondsInterval, int32& Tick)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
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
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger1(const int32 Value)
{
	return ULowEntryByteDataEntry::CreateFromPositiveInteger1(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger2(const int32 Value)
{
	return ULowEntryByteDataEntry::CreateFromPositiveInteger2(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger3(const int32 Value)
{
	return ULowEntryByteDataEntry::CreateFromPositiveInteger3(Value);
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
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger1Array(const TArray<int32>& Value)
{
	return ULowEntryByteDataEntry::CreateFromPositiveInteger1Array(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger2Array(const TArray<int32>& Value)
{
	return ULowEntryByteDataEntry::CreateFromPositiveInteger2Array(Value);
}
ULowEntryByteDataEntry* ULowEntryExtendedStandardLibrary::ByteDataEntry_CreateFromPositiveInteger3Array(const TArray<int32>& Value)
{
	return ULowEntryByteDataEntry::CreateFromPositiveInteger3Array(Value);
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



ULowEntryBitDataReader* ULowEntryExtendedStandardLibrary::BitDataReader_Create(const TArray<uint8>& Bytes, int32 Index, int32 Length)
{
	return ULowEntryBitDataReader::Create(Bytes, Index, Length);
}



ULowEntryBitDataWriter* ULowEntryExtendedStandardLibrary::BitDataWriter_Create()
{
	return ULowEntryBitDataWriter::Create();
}

ULowEntryBitDataWriter* ULowEntryExtendedStandardLibrary::BitDataWriter_CreateFromEntryArray(const TArray<ULowEntryBitDataEntry*>& Array)
{
	return ULowEntryBitDataWriter::CreateFromEntryArray(Array);
}

ULowEntryBitDataWriter* ULowEntryExtendedStandardLibrary::BitDataWriter_CreateFromEntryArrayPure(const TArray<ULowEntryBitDataEntry*>& Array)
{
	return ULowEntryBitDataWriter::CreateFromEntryArray(Array);
}

TArray<uint8> ULowEntryExtendedStandardLibrary::BitDataWriter_GetBytes(ULowEntryBitDataWriter* BitDataWriter)
{
	return BitDataWriter->GetBytes();
}



ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBit(const bool Value)
{
	return ULowEntryBitDataEntry::CreateFromBit(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteLeastSignificantBits(const uint8 Value, const int32 BitCount)
{
	return ULowEntryBitDataEntry::CreateFromByteLeastSignificantBits(Value, BitCount);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteMostSignificantBits(const uint8 Value, const int32 BitCount)
{
	return ULowEntryBitDataEntry::CreateFromByteMostSignificantBits(Value, BitCount);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerLeastSignificantBits(const int32 Value, const int32 BitCount)
{
	return ULowEntryBitDataEntry::CreateFromIntegerLeastSignificantBits(Value, BitCount);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerMostSignificantBits(const int32 Value, const int32 BitCount)
{
	return ULowEntryBitDataEntry::CreateFromIntegerMostSignificantBits(Value, BitCount);
}

ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByte(const uint8 Value)
{
	return ULowEntryBitDataEntry::CreateFromByte(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromInteger(const int32 Value)
{
	return ULowEntryBitDataEntry::CreateFromInteger(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger1(const int32 Value)
{
	return ULowEntryBitDataEntry::CreateFromPositiveInteger1(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger2(const int32 Value)
{
	return ULowEntryBitDataEntry::CreateFromPositiveInteger2(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger3(const int32 Value)
{
	return ULowEntryBitDataEntry::CreateFromPositiveInteger3(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromLongBytes(ULowEntryLong* Value)
{
	return ULowEntryBitDataEntry::CreateFromLongBytes(Value);
}

ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromFloat(const float Value)
{
	return ULowEntryBitDataEntry::CreateFromFloat(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromDoubleBytes(ULowEntryDouble* Value)
{
	return ULowEntryBitDataEntry::CreateFromDoubleBytes(Value);
}

ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBoolean(const bool Value)
{
	return ULowEntryBitDataEntry::CreateFromBoolean(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromStringUtf8(const FString& Value)
{
	return ULowEntryBitDataEntry::CreateFromStringUtf8(Value);
}


ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBitArray(const TArray<bool>& Value)
{
	return ULowEntryBitDataEntry::CreateFromBitArray(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteArrayLeastSignificantBits(const TArray<uint8>& Value, const int32 BitCount)
{
	return ULowEntryBitDataEntry::CreateFromByteArrayLeastSignificantBits(Value, BitCount);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteArrayMostSignificantBits(const TArray<uint8>& Value, const int32 BitCount)
{
	return ULowEntryBitDataEntry::CreateFromByteArrayMostSignificantBits(Value, BitCount);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerArrayLeastSignificantBits(const TArray<int32>& Value, const int32 BitCount)
{
	return ULowEntryBitDataEntry::CreateFromIntegerArrayLeastSignificantBits(Value, BitCount);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerArrayMostSignificantBits(const TArray<int32>& Value, const int32 BitCount)
{
	return ULowEntryBitDataEntry::CreateFromIntegerArrayMostSignificantBits(Value, BitCount);
}

ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromByteArray(const TArray<uint8>& Value)
{
	return ULowEntryBitDataEntry::CreateFromByteArray(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromIntegerArray(const TArray<int32>& Value)
{
	return ULowEntryBitDataEntry::CreateFromIntegerArray(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger1Array(const TArray<int32>& Value)
{
	return ULowEntryBitDataEntry::CreateFromPositiveInteger1Array(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger2Array(const TArray<int32>& Value)
{
	return ULowEntryBitDataEntry::CreateFromPositiveInteger2Array(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromPositiveInteger3Array(const TArray<int32>& Value)
{
	return ULowEntryBitDataEntry::CreateFromPositiveInteger3Array(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromLongBytesArray(const TArray<ULowEntryLong*>& Value)
{
	return ULowEntryBitDataEntry::CreateFromLongBytesArray(Value);
}

ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromFloatArray(const TArray<float>& Value)
{
	return ULowEntryBitDataEntry::CreateFromFloatArray(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromDoubleBytesArray(const TArray<ULowEntryDouble*>& Value)
{
	return ULowEntryBitDataEntry::CreateFromDoubleBytesArray(Value);
}

ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromBooleanArray(const TArray<bool>& Value)
{
	return ULowEntryBitDataEntry::CreateFromBooleanArray(Value);
}
ULowEntryBitDataEntry* ULowEntryExtendedStandardLibrary::BitDataEntry_CreateFromStringUtf8Array(const TArray<FString>& Value)
{
	return ULowEntryBitDataEntry::CreateFromStringUtf8Array(Value);
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



void ULowEntryExtendedStandardLibrary::SetMousePosition(const int32 X, const int32 Y)
{
	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	FViewport* Viewport = ViewportClient->Viewport;
	if(Viewport == nullptr)
	{
		return;
	}

	FIntPoint Size = Viewport->GetSizeXY();
	if((Size.X <= 0) || (Size.Y <= 0))
	{
		return;
	}

	Viewport->SetMouse(FMath::Clamp(X, 0, Size.X), FMath::Clamp(Y, 0, Size.Y));
}

void ULowEntryExtendedStandardLibrary::GetMousePosition(bool& Success, int32& X, int32& Y)
{
	Success = false;
	X = 0;
	Y = 0;

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	FViewport* Viewport = ViewportClient->Viewport;
	if(Viewport == nullptr)
	{
		return;
	}

	int32 MouseX = Viewport->GetMouseX();
	int32 MouseY = Viewport->GetMouseY();
	if((MouseX < 0) || (MouseY < 0))
	{
		return;
	}

	FIntPoint Size = Viewport->GetSizeXY();
	if((Size.X <= 0) || (Size.Y <= 0))
	{
		return;
	}
	if((Size.X < MouseX) || (Size.Y < MouseY))
	{
		return;
	}

	Success = true;
	X = MouseX;
	Y = MouseY;
}


void ULowEntryExtendedStandardLibrary::SetMousePositionInPercentages(const float X, const float Y)
{
	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	FViewport* Viewport = ViewportClient->Viewport;
	if(Viewport == nullptr)
	{
		return;
	}

	FIntPoint Size = Viewport->GetSizeXY();
	Viewport->SetMouse(FMath::RoundToInt(Size.X * FMath::Clamp(X, 0.0f, 1.0f)), FMath::RoundToInt(Size.Y * FMath::Clamp(Y, 0.0f, 1.0f)));
}

void ULowEntryExtendedStandardLibrary::GetMousePositionInPercentages(bool& Success, float& X, float& Y)
{
	Success = false;
	X = 0;
	Y = 0;

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	FViewport* Viewport = ViewportClient->Viewport;
	if(Viewport == nullptr)
	{
		return;
	}

	int32 MouseX = Viewport->GetMouseX();
	int32 MouseY = Viewport->GetMouseY();
	if((MouseX < 0) || (MouseY < 0))
	{
		return;
	}

	FIntPoint Size = Viewport->GetSizeXY();
	if((Size.X <= 0) || (Size.Y <= 0))
	{
		return;
	}
	if((Size.X < MouseX) || (Size.Y < MouseY))
	{
		return;
	}

	Success = true;
	X = MouseX / (float) Size.X;
	Y = MouseY / (float) Size.Y;
}


void ULowEntryExtendedStandardLibrary::SetMouseLockedToViewport(const bool Locked)
{
	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SViewport> ViewportWidget = ViewportClient->GetGameViewportWidget();
	if(!ViewportWidget.IsValid())
	{
		return;
	}

	TArray<APlayerController*> LocalPlayerControllers;
	GEngine->GetAllLocalPlayerControllers(LocalPlayerControllers);

	for(APlayerController* LocalPlayerController : LocalPlayerControllers)
	{
		if(LocalPlayerController == nullptr)
		{
			continue;
		}

		ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(LocalPlayerController->Player);
		if(LocalPlayer == nullptr)
		{
			continue;
		}

		if(Locked)
		{
			LocalPlayer->GetSlateOperations().LockMouseToWidget(ViewportWidget.ToSharedRef());
		}
		else
		{
			LocalPlayer->GetSlateOperations().ReleaseMouseLock();
		}
	}
}



void ULowEntryExtendedStandardLibrary::GetPrimaryMonitorResolution(int32& Width, int32& Height)
{
	FDisplayMetrics DisplayMetrics;
	FDisplayMetrics::RebuildDisplayMetrics(DisplayMetrics);

	Width = DisplayMetrics.PrimaryDisplayWidth;
	Height = DisplayMetrics.PrimaryDisplayHeight;
}

void ULowEntryExtendedStandardLibrary::GetPrimaryMonitorWorkArea(int32& X, int32& Y, int32& Width, int32& Height)
{
	FDisplayMetrics DisplayMetrics;
	FDisplayMetrics::RebuildDisplayMetrics(DisplayMetrics);

	FPlatformRect Bounds = DisplayMetrics.PrimaryDisplayWorkAreaRect;
	X = Bounds.Left;
	Y = Bounds.Top;
	Width = Bounds.Right - Bounds.Left;
	Height = Bounds.Bottom - Bounds.Top;
}



void ULowEntryExtendedStandardLibrary::GetWindowBounds(bool& Success, int32& X, int32& Y, int32& Width, int32& Height)
{
	Success = false;
	X = 0;
	Y = 0;
	Width = 0;
	Height = 0;

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	FVector2D Position = Window->GetPositionInScreen();
	FVector2D Size = Window->GetSizeInScreen();

	Success = true;
	X = Position.X;
	Y = Position.Y;
	Width = Size.X;
	Height = Size.Y;
}

void ULowEntryExtendedStandardLibrary::GetWindowPosition(bool& Success, int32& X, int32& Y)
{
	Success = false;
	X = 0;
	Y = 0;

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	FVector2D Position = Window->GetPositionInScreen();

	Success = true;
	X = Position.X;
	Y = Position.Y;
}

void ULowEntryExtendedStandardLibrary::GetWindowSize(bool& Success, int32& Width, int32& Height)
{
	Success = false;
	Width = 0;
	Height = 0;

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	FVector2D Size = Window->GetSizeInScreen();

	Success = true;
	Width = Size.X;
	Height = Size.Y;
}

void ULowEntryExtendedStandardLibrary::GetWindowPositiomInPercentagesCentered(bool& Success, float& X, float& Y)
{
	Success = false;
	X = 0;
	Y = 0;

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	int32 ScreenX = 0;
	int32 ScreenY = 0;
	int32 ScreenWidth = 0;
	int32 ScreenHeight = 0;
	GetPrimaryMonitorWorkArea(ScreenX, ScreenY, ScreenWidth, ScreenHeight);

	FVector2D Position = Window->GetPositionInScreen();
	FVector2D WindowSize = Window->GetSizeInScreen();

	float NewScreenX = ((Position.X + (WindowSize.X / 2.0f)) - ScreenX) / ScreenWidth;
	float NewScreenY = ((Position.Y + (WindowSize.Y / 2.0f)) - ScreenY) / ScreenHeight;

	Success = true;
	X = NewScreenX;
	Y = NewScreenY;
}


void ULowEntryExtendedStandardLibrary::SetWindowPosition(const int32 X, const int32 Y)
{
	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	Window->MoveWindowTo(FVector2D((float) X, (float) Y));
}

void ULowEntryExtendedStandardLibrary::SetWindowSize(const int32 Width, const int32 Height)
{
	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	Window->Resize(FVector2D(Width, Height));
}

void ULowEntryExtendedStandardLibrary::SetWindowPositiomInPercentagesCentered(const float X, const float Y)
{
	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	int32 ScreenX = 0;
	int32 ScreenY = 0;
	int32 ScreenWidth = 0;
	int32 ScreenHeight = 0;
	GetPrimaryMonitorWorkArea(ScreenX, ScreenY, ScreenWidth, ScreenHeight);

	FVector2D WindowSize = Window->GetSizeInScreen();
	
	float NewScreenX = ScreenX + (ScreenWidth * X) - (WindowSize.X / 2.0f);
	float NewScreenY = ScreenY + (ScreenHeight * Y) - (WindowSize.Y / 2.0f);

	Window->MoveWindowTo(FVector2D(NewScreenX, NewScreenY));
}



void ULowEntryExtendedStandardLibrary::GetWindowBorderSize(bool& Success, FMargin& Margin)
{
	Success = false;
	Margin = FMargin();

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	FMargin BorderSize = Window->GetWindowBorderSize(true);

	Success = true;
	Margin = BorderSize;
}



void ULowEntryExtendedStandardLibrary::GetWindowMode(bool& Success, bool& Fullscreen, bool& IsFullscreenWindowed)
{
	Success = false;
	Fullscreen = false;
	IsFullscreenWindowed = false;

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	EWindowMode::Type Mode = Window->GetWindowMode();

	if(Mode == EWindowMode::Type::Fullscreen)
	{
		Success = true;
		Fullscreen = true;
	}
	else if(Mode == EWindowMode::Type::WindowedFullscreen)
	{
		Success = true;
		Fullscreen = true;
		IsFullscreenWindowed = true;
	}
	else if(Mode == EWindowMode::Type::Windowed)
	{
		Success = true;
	}
}

void ULowEntryExtendedStandardLibrary::SetWindowMode(const bool Fullscreen, const bool IsFullscreenWindowed)
{
	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if(!Window.IsValid())
	{
		return;
	}

	if(Fullscreen)
	{
		if(IsFullscreenWindowed)
		{
			Window->SetWindowMode(EWindowMode::Type::WindowedFullscreen);
		}
		else
		{
			Window->SetWindowMode(EWindowMode::Type::Fullscreen);
		}
	}
	else
	{
		Window->SetWindowMode(EWindowMode::Type::Windowed);
	}
}



void ULowEntryExtendedStandardLibrary::SetSplitScreenEnabled(const bool Enabled)
{
	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	ViewportClient->SetForceDisableSplitscreen(!Enabled);
}

void ULowEntryExtendedStandardLibrary::GetSplitScreenType(ELowEntrySplitScreenType& Type)
{
	Type = ELowEntrySplitScreenType::None;

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	Type = ELowEntrySplitScreenTypeFromUE4(ViewportClient->GetCurrentSplitscreenConfiguration());
}

void ULowEntryExtendedStandardLibrary::SetSplitScreenType_TwoPlayers(const ELowEntrySplitScreenTypeTwoPlayers Type)
{
	UGameMapsSettings* Settings = GetMutableDefault<UGameMapsSettings>();
	Settings->TwoPlayerSplitscreenLayout = ELowEntrySplitScreenTypeTwoPlayersToUE4(Type);

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	ViewportClient->UpdateActiveSplitscreenType();
}

void ULowEntryExtendedStandardLibrary::SetSplitScreenType_ThreePlayers(const ELowEntrySplitScreenTypeThreePlayers Type)
{
	UGameMapsSettings* Settings = GetMutableDefault<UGameMapsSettings>();
	Settings->ThreePlayerSplitscreenLayout = ELowEntrySplitScreenTypeThreePlayersToUE4(Type);

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	ViewportClient->UpdateActiveSplitscreenType();
}



void ULowEntryExtendedStandardLibrary::IsWorldRenderingEnabled(bool& Success, bool& Enabled)
{
	Success = false;
	Enabled = false;

	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	Success = true;
	Enabled = (ViewportClient->bDisableWorldRendering == 0);
}

void ULowEntryExtendedStandardLibrary::SetWorldRenderingEnabled(const bool Enabled)
{
	if(GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if(ViewportClient == nullptr)
	{
		return;
	}

	ViewportClient->bDisableWorldRendering = (Enabled ? 0 : 1);
}



FString ULowEntryExtendedStandardLibrary::ClipboardGet()
{
	FString Value = TEXT("");
	FPlatformApplicationMisc::ClipboardPaste(Value);
	return Value;
}

void ULowEntryExtendedStandardLibrary::ClipboardSet(const FString& Value)
{
	FPlatformApplicationMisc::ClipboardCopy(*Value);
}



void ULowEntryExtendedStandardLibrary::GetClassWithName(const FString& ClassName, UClass*& Class_, bool& Success)
{
	Class_ = NULL;
	Success = false;

	{// get class >>
		UClass* FoundClass = FindObject<UClass>(ANY_PACKAGE, *ClassName);
		if(FoundClass != nullptr)
		{
			Class_ = FoundClass;
			Success = true;
			return;
		}
	}// get class <<

	{// get class through redirector >>
		UObjectRedirector* RenamedClassRedirector = FindObject<UObjectRedirector>(ANY_PACKAGE, *ClassName);
		if((RenamedClassRedirector != nullptr) && (RenamedClassRedirector->DestinationObject != nullptr))
		{
			UClass* FoundClass = CastChecked<UClass>(RenamedClassRedirector->DestinationObject);
			if(FoundClass != nullptr)
			{
				Class_ = FoundClass;
				Success = true;
				return;
			}
		}
	}// get class through redirector <<
}



FVector2D ULowEntryExtendedStandardLibrary::Divide_Vector2dVector2d(const FVector2D& A, const FVector2D& B)
{
	return A / B;
}



FVector2D ULowEntryExtendedStandardLibrary::GetAbsoluteSize(const FGeometry& Geometry)
{
	FVector2D LocalSize = Geometry.GetLocalSize();
	return Geometry.LocalToAbsolute(LocalSize) - Geometry.LocalToAbsolute(FVector2D(0, 0));
}

FVector2D ULowEntryExtendedStandardLibrary::GetLocalToAbsoluteScale(const FGeometry& Geometry)
{
	FVector2D LocalSize = Geometry.GetLocalSize();
	FVector2D AbsoluteSize = Geometry.LocalToAbsolute(LocalSize) - Geometry.LocalToAbsolute(FVector2D(0, 0));
	return AbsoluteSize / LocalSize;
}

FVector2D ULowEntryExtendedStandardLibrary::GetAbsoluteToLocalScale(const FGeometry& Geometry)
{
	FVector2D LocalSize = Geometry.GetLocalSize();
	FVector2D AbsoluteSize = Geometry.LocalToAbsolute(LocalSize) - Geometry.LocalToAbsolute(FVector2D(0, 0));
	return LocalSize / AbsoluteSize;
}



void ULowEntryExtendedStandardLibrary::ClearAllUserFocus()
{
	if(!FSlateApplication::IsInitialized())
	{
		return;
	}
	FSlateApplication::Get().ClearAllUserFocus();
}

void ULowEntryExtendedStandardLibrary::ClearUserFocus(const int32 UserIndex)
{
	if(!FSlateApplication::IsInitialized())
	{
		return;
	}
	FSlateApplication::Get().ClearUserFocus(UserIndex);
}

void ULowEntryExtendedStandardLibrary::ClearKeyboardFocus()
{
	if(!FSlateApplication::IsInitialized())
	{
		return;
	}
	FSlateApplication::Get().ClearKeyboardFocus();
}

FName ULowEntryExtendedStandardLibrary::GetUserFocusedWidgetType(const int32 UserIndex)
{
	if(!FSlateApplication::IsInitialized())
	{
		return TEXT("");
	}
	TSharedPtr<SWidget> Widget = FSlateApplication::Get().GetUserFocusedWidget(UserIndex);
	if(!Widget.IsValid())
	{
		return TEXT("");
	}
	return Widget->GetType();
}

FName ULowEntryExtendedStandardLibrary::GetKeyboardFocusedWidgetType()
{
	if(!FSlateApplication::IsInitialized())
	{
		return TEXT("");
	}
	TSharedPtr<SWidget> Widget = FSlateApplication::Get().GetKeyboardFocusedWidget();
	if(!Widget.IsValid())
	{
		return TEXT("");
	}
	return Widget->GetType();
}



void ULowEntryExtendedStandardLibrary::ExecToBoolean(const ELowEntryExtendedStandardLibraryTrueOrFalse Branch, bool& Value)
{
	Value = (Branch == ELowEntryExtendedStandardLibraryTrueOrFalse::_True_);
}

void ULowEntryExtendedStandardLibrary::ExecToInteger(const ELowEntryExtendedStandardLibrary0to9 Branch, int32& Value)
{
	Value = (int32) Branch;
}

void ULowEntryExtendedStandardLibrary::ExecToByte(const ELowEntryExtendedStandardLibrary0to9 Branch, uint8& Value)
{
	Value = (uint8) Branch;
}



void ULowEntryExtendedStandardLibrary::CaseSwitchInteger(const int32 OnlyCheckFirstX, const int32 Value, const int32 _1__, const int32 _2__, const int32 _3__, const int32 _4__, const int32 _5__, const int32 _6__, const int32 _7__, const int32 _8__, const int32 _9__, const int32 _10__, ELowEntryExtendedStandardLibrary1to10other& Branch)
{
	Branch = ELowEntryExtendedStandardLibrary1to10other::Other;

	if(OnlyCheckFirstX < 1)
	{
		return;
	}
	if(Value == _1__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_1_;
		return;
	}

	if(OnlyCheckFirstX < 2)
	{
		return;
	}
	if(Value == _2__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_2_;
		return;
	}

	if(OnlyCheckFirstX < 3)
	{
		return;
	}
	if(Value == _3__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_3_;
		return;
	}

	if(OnlyCheckFirstX < 4)
	{
		return;
	}
	if(Value == _4__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_4_;
		return;
	}

	if(OnlyCheckFirstX < 5)
	{
		return;
	}
	if(Value == _5__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_5_;
		return;
	}

	if(OnlyCheckFirstX < 6)
	{
		return;
	}
	if(Value == _6__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_6_;
		return;
	}

	if(OnlyCheckFirstX < 7)
	{
		return;
	}
	if(Value == _7__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_7_;
		return;
	}

	if(OnlyCheckFirstX < 8)
	{
		return;
	}
	if(Value == _8__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_8_;
		return;
	}

	if(OnlyCheckFirstX < 9)
	{
		return;
	}
	if(Value == _9__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_9_;
		return;
	}

	if(OnlyCheckFirstX < 10)
	{
		return;
	}
	if(Value == _10__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_10_;
		return;
	}
}

void ULowEntryExtendedStandardLibrary::CaseSwitchByte(const int32 OnlyCheckFirstX, const uint8 Value, const uint8 _1__, const uint8 _2__, const uint8 _3__, const uint8 _4__, const uint8 _5__, const uint8 _6__, const uint8 _7__, const uint8 _8__, const uint8 _9__, const uint8 _10__, ELowEntryExtendedStandardLibrary1to10other& Branch)
{
	Branch = ELowEntryExtendedStandardLibrary1to10other::Other;

	if(OnlyCheckFirstX < 1)
	{
		return;
	}
	if(Value == _1__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_1_;
		return;
	}

	if(OnlyCheckFirstX < 2)
	{
		return;
	}
	if(Value == _2__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_2_;
		return;
	}

	if(OnlyCheckFirstX < 3)
	{
		return;
	}
	if(Value == _3__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_3_;
		return;
	}

	if(OnlyCheckFirstX < 4)
	{
		return;
	}
	if(Value == _4__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_4_;
		return;
	}

	if(OnlyCheckFirstX < 5)
	{
		return;
	}
	if(Value == _5__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_5_;
		return;
	}

	if(OnlyCheckFirstX < 6)
	{
		return;
	}
	if(Value == _6__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_6_;
		return;
	}

	if(OnlyCheckFirstX < 7)
	{
		return;
	}
	if(Value == _7__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_7_;
		return;
	}

	if(OnlyCheckFirstX < 8)
	{
		return;
	}
	if(Value == _8__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_8_;
		return;
	}

	if(OnlyCheckFirstX < 9)
	{
		return;
	}
	if(Value == _9__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_9_;
		return;
	}

	if(OnlyCheckFirstX < 10)
	{
		return;
	}
	if(Value == _10__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_10_;
		return;
	}
}

void ULowEntryExtendedStandardLibrary::CaseSwitchObject(const int32 OnlyCheckFirstX, const UObject* Value, const UObject* _1__, const UObject* _2__, const UObject* _3__, const UObject* _4__, const UObject* _5__, const UObject* _6__, const UObject* _7__, const UObject* _8__, const UObject* _9__, const UObject* _10__, ELowEntryExtendedStandardLibrary1to10other& Branch)
{
	Branch = ELowEntryExtendedStandardLibrary1to10other::Other;

	if(OnlyCheckFirstX < 1)
	{
		return;
	}
	if(Value == _1__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_1_;
		return;
	}

	if(OnlyCheckFirstX < 2)
	{
		return;
	}
	if(Value == _2__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_2_;
		return;
	}

	if(OnlyCheckFirstX < 3)
	{
		return;
	}
	if(Value == _3__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_3_;
		return;
	}

	if(OnlyCheckFirstX < 4)
	{
		return;
	}
	if(Value == _4__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_4_;
		return;
	}

	if(OnlyCheckFirstX < 5)
	{
		return;
	}
	if(Value == _5__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_5_;
		return;
	}

	if(OnlyCheckFirstX < 6)
	{
		return;
	}
	if(Value == _6__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_6_;
		return;
	}

	if(OnlyCheckFirstX < 7)
	{
		return;
	}
	if(Value == _7__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_7_;
		return;
	}

	if(OnlyCheckFirstX < 8)
	{
		return;
	}
	if(Value == _8__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_8_;
		return;
	}

	if(OnlyCheckFirstX < 9)
	{
		return;
	}
	if(Value == _9__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_9_;
		return;
	}

	if(OnlyCheckFirstX < 10)
	{
		return;
	}
	if(Value == _10__)
	{
		Branch = ELowEntryExtendedStandardLibrary1to10other::_10_;
		return;
	}
}



void ULowEntryExtendedStandardLibrary::PlayerControllerGetLocalPlayer(APlayerController* PlayerController, bool& Success, ULocalPlayer*& LocalPlayer)
{
	Success = false;
	LocalPlayer = NULL;
	if(PlayerController == nullptr)
	{
		return;
	}
	if(PlayerController->Player == nullptr)
	{
		return;
	}
	if(!PlayerController->Player->GetClass()->IsChildOf(ULocalPlayer::StaticClass()))
	{
		return;
	}
	LocalPlayer = (ULocalPlayer*)PlayerController->Player;
	if(LocalPlayer == nullptr)
	{
		return;
	}
	Success = true;
}



void ULowEntryExtendedStandardLibrary::SimpleKismetSystemLibraryPrintString(const FString& InString)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	float ScreenDurationTime = 5.0f;
	FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

	UE_LOG(LogBlueprintUserMessages, Log, TEXT("%s"), *InString);

	if(GAreScreenMessagesEnabled)
	{
		if(GEngine != nullptr)
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
	int32 Length = 0;
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
