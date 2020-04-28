// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/Engine.h"
#include "Engine/SceneCapture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/Texture2D.h"
#include "Engine/LocalPlayer.h"
#include "Engine/GameViewportClient.h"
#include "Engine/World.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Slate/SceneViewport.h"
#include "Widgets/SViewport.h"
#include "Framework/Application/SlateApplication.h"

#include "DelayAction.h"
#include "Engine/LatentActionManager.h"

#include "FLowEntryRegexMatch.h"

#include "IImageWrapper.h"
#include "IImageWrapperModule.h"

#include "ELowEntryExtendedStandardLibrary0to9.h"
#include "ELowEntryExtendedStandardLibrary1to10other.h"
#include "ELowEntryExtendedStandardLibraryTrueOrFalse.h"

#include "ELowEntryBatteryState.h"

#include "ELowEntryImageFormat.h"
#include "ELowEntryRGBFormat.h"

#include "ELowEntryHmacAlgorithm.h"

#include "IMediaModule.h"
#include "IMediaPlayer.h"
#include "MediaPlayer.h"
#include "MediaTexture.h"
#include "MediaSoundComponent.h"

#include "ImageUtils.h"

#include "ELowEntrySplitScreenType.h"
#include "ELowEntrySplitScreenTypeTwoPlayers.h"
#include "ELowEntrySplitScreenTypeThreePlayers.h"

#include "LowEntryExtendedStandardLibrary.generated.h"


class ULowEntryLatentActionBoolean;
class ULowEntryLatentActionFloat;
class ULowEntryLatentActionInteger;
class ULowEntryLatentActionNone;
class ULowEntryLatentActionObject;
class ULowEntryLatentActionString;

class ULowEntryParsedHashcash;

class ULowEntryByteArray;

class ULowEntryByteDataEntry;
class ULowEntryByteDataReader;
class ULowEntryByteDataWriter;

class ULowEntryBitDataEntry;
class ULowEntryBitDataReader;
class ULowEntryBitDataWriter;

class ULowEntryLong;
class ULowEntryDouble;

class ULowEntryExecutionQueue;


DECLARE_DYNAMIC_DELEGATE_ThreeParams(FDelegateULowEntryExtendedStandardLibraryCompareObjects, UObject*, ObjectA, UObject*, ObjectB, bool&, Result);


UCLASS()
class LOWENTRYEXTENDEDSTANDARDLIBRARY_API ULowEntryExtendedStandardLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()



public:
	static void KismetSystemLibraryPrintString(UObject* WorldContextObject, const FString& InString, const float ScreenDurationTime, const bool bPrintToScreen, const bool bPrintToLog, const FLinearColor TextColor);



public:
	/**
	* Returns true if this is a debug build (UE_BUILD_DEBUG), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Debug Build", Keywords = "compile export mode version type build platform"))
		static bool DebugBuild();

	/**
	* Returns true if this is a debug build (UE_BUILD_DEVELOPMENT), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Development Build", Keywords = "compile export mode version type build platform"))
		static bool DevelopmentBuild();

	/**
	* Returns true if this is a debug build (UE_BUILD_TEST), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Test Build", Keywords = "compile export mode version type build platform"))
		static bool TestBuild();

	/**
	* Returns true if this is a debug build (UE_BUILD_SHIPPING), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Shipping Build", Keywords = "compile export mode version type build platform"))
		static bool ShippingBuild();



	/**
	* Returns true if this is inside the editor (WITH_EDITOR), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "With Editor", Keywords = "compile export mode version type build platform in inside using"))
		static bool WithEditor();



	/**
	* Returns true if this is the Html5 platform (PLATFORM_HTML5), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Html5 Platform", Keywords = "compile export mode version type build platform"))
		static bool Html5Platform();

	/**
	* Returns true if this is the Windows platform (PLATFORM_WINDOWS), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Windows Platform", Keywords = "compile export mode version type build platform"))
		static bool WindowsPlatform();

	/**
	* Returns true if this is the Windows platform running on 32 bit (PLATFORM_WINDOWS and not _WIN64), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Windows Platform (32 bit)", Keywords = "compile export mode version type build platform"))
		static bool Windows32Platform();

	/**
	* Returns true if this is the Windows platform running on 64 bit (PLATFORM_WINDOWS and _WIN64), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Windows Platform (64 bit)", Keywords = "compile export mode version type build platform"))
		static bool Windows64Platform();

	/**
	* Returns true if this is the Windows RT platform (PLATFORM_WINRT), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Windows Rt Platform", Keywords = "compile export mode version type build platform"))
		static bool WindowsRtPlatform();

	/**
	* Returns true if this is the Windows RT ARM platform (PLATFORM_WINRT_ARM), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Windows Rt Arm Platform", Keywords = "compile export mode version type build platform"))
		static bool WindowsRtArmPlatform();

	/**
	* Returns true if this is the Linux platform (PLATFORM_LINUX), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Linux Platform", Keywords = "compile export mode version type build platform"))
		static bool LinuxPlatform();

	/**
	* Returns true if this is the Mac platform (PLATFORM_MAC), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Mac Platform", Keywords = "compile export mode version type build platform"))
		static bool MacPlatform();

	/**
	* Returns true if this is the PS4 platform (PLATFORM_PS4), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Ps4 Platform", Keywords = "compile export mode version type build platform"))
		static bool Ps4Platform();

	/**
	* Returns true if this is the Xbox One platform (PLATFORM_XBOXONE), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Xbox One Platform", Keywords = "compile export mode version type build platform"))
		static bool XboxOnePlatform();

	/**
	* Returns true if this is the Switch platform (PLATFORM_SWITCH), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Switch Platform", Keywords = "compile export mode version type build platform"))
		static bool SwitchPlatform();

	/**
	* Returns true if this is the Android platform (PLATFORM_ANDROID), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Android Platform", Keywords = "compile export mode version type build platform"))
		static bool AndroidPlatform();

	/**
	* Returns true if this is the IOS platform (PLATFORM_IOS), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Ios Platform", Keywords = "compile export mode version type build platform"))
		static bool IosPlatform();

	/**
	* Returns true if this is a desktop (PLATFORM_DESKTOP), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Desktop", Keywords = "compile export mode version type build platform"))
		static bool DesktopPlatform();



	/**
	* Returns the project name from the project settings.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Config", Meta = (DisplayName = "Get Project Name", Keywords = "settings configuration parameters"))
		static FString GetProjectName();

	/**
	* Returns the project version from the project settings.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Config", Meta = (DisplayName = "Get Project Version", Keywords = "settings configuration parameters"))
		static FString GetProjectVersion();



	/**
	* Returns the battery state.
	* 
	* Currently only works on Android devices.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Battery", Meta = (DisplayName = "Get Battery State", Keywords = "android"))
		static void GetBatteryState(ELowEntryBatteryState& State, bool& Success);

	/**
	* Returns the battery charge (in percentages, from 0% to 100%).
	* 
	* Currently only works on Android devices.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Battery", Meta = (DisplayName = "Get Battery Charge", Keywords = "life live android"))
		static void GetBatteryCharge(int32& Percentage, bool& Success);

	/**
	* Returns the battery temperature (in degrees of Celsius).
	*
	* Currently only works on Android devices.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Battery", Meta = (DisplayName = "Get Battery Temperature", Keywords = "degrees android"))
		static void GetBatteryTemperature(float& Celsius, bool& Success);



	/**
	* Returns the current system volume in percentages, from 0.0 to 1.0.
	*
	* Currently only works on Android devices. If you only care about getting the volume on Android, you might as well use the "Get Android Volume" blueprint instead.
	*
	* Note: This blueprint is not used to retrieve or change the sound volume in-game, you will have to use Sound Classes for that.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Get System Volume (Percentages)", Keywords = "sound audio android current system"))
		static void GetCurrentVolumePercentage(float& Percentage, bool& Success);



	/**
	* Returns the current Android volume, from 0 to 15.
	*
	* This will always only ever work on Android devices, other systems will always return 0. If you want more systems supported later on, use the "Get System Volume (Percentages)" blueprint instead.
	*
	* Note: This blueprint is not used to retrieve or change the sound volume in-game, you will have to use Sound Classes for that.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android Volume", Keywords = "sound audio android current system"))
		static void GetAndroidVolume(int& Volume);

	/**
	* Returns the Android device make, returns an empty string if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return an emptry string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android Device Make", Keywords = "android system name make type"))
		static FString GetAndroidDeviceMake();

	/**
	* Returns the Android device model, returns an empty string if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return an emptry string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android Device Model", Keywords = "android system name model type"))
		static FString GetAndroidDeviceModel();

	/**
	* Returns the Android version, returns an empty string if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return an emptry string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android Version", Keywords = "android system"))
		static FString GetAndroidVersion();

	/**
	* Returns the Android OS language, returns an empty string if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return an emptry string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android OS Language", Keywords = "android system locale language"))
		static FString GetAndroidOsLanguage();

	/**
	* Returns the Android default locale, returns an empty string if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return an emptry string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android Default Locale", Keywords = "android system locale language"))
		static FString GetAndroidDefaultLocale();

	/**
	* Returns the Android GPU family, returns an empty string if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return an emptry string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android GPU Family", Keywords = "android system"))
		static FString GetAndroidGpuFamily();

	/**
	* Returns the Android GL version, returns an empty string if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return an emptry string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android GL Version", Keywords = "android system"))
		static FString GetAndroidGlVersion();

	/**
	* Returns the Android build version, returns -1 if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return -1.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android Build Version", Keywords = "android system"))
		static int32 GetAndroidBuildVersion();

	/**
	* Returns true if this is an Android daydream application, returns false if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return false.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Is Android Daydream Application", Keywords = "android system"))
		static bool IsAndroidDaydreamApplication();

	/**
	* Returns the number of cores, returns -1 if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return -1.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Get Android Number Of Cores", Keywords = "android system cpu"))
		static int32 GetAndroidNumberOfCores();

	/**
	* Returns true if headphones are plugged in, returns false if it failed.
	*
	* This will always only ever work on Android devices, other systems will always return false.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Android", Meta = (DisplayName = "Are Android Headphones Plugged In", Keywords = "android system"))
		static bool AreAndroidHeadphonesPluggedIn();



	/**
	* Returns the current system volume.
	*
	* Doesn't work, use Get Current System Volume (Percentages) instead.
	*
	* Note: This blueprint is not used to retrieve or change the sound volume in-game, you will have to use Sound Classes for that.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DeprecatedFunction, DeprecationMessage = "This function has been replaced by Get Current System Volume (Percentages).", DisplayName = "Get Current System Volume (Old)", Keywords = "sound audio android"))
		static void GetCurrentVolume(int32& Volume, bool& Success);

	/**
	* Returns the maximum system volume.
	*
	* Doesn't work, use Get Current System Volume (Percentages) instead.
	*
	* Note: This blueprint is not used to retrieve or change the sound volume in-game, you will have to use Sound Classes for that.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DeprecatedFunction, DeprecationMessage = "This function has been replaced by Get Current System Volume (Percentages).", DisplayName = "Get Maximum System Volume (Old)", Keywords = "sound audio android"))
		static void GetMaximumVolume(int32& Volume, bool& Success);



	/**
	* Returns an instance from the given Class.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Create Object", Keywords = "make instance", DeterminesOutputType = "Class", DynamicOutputParam = "Object"))
		static void CreateObject(TSubclassOf<UObject> Class, UObject*& Object);



	/**
	* Returns the Team ID of the given Actor.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|AI", Meta = (DisplayName = "Get Generic Team ID"))
		static void GetGenericTeamId(AActor* Target, uint8& TeamID);
	
	/**
	* Sets the Team ID of the given Actor.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|AI", Meta = (DisplayName = "Set Generic Team ID"))
		static void SetGenericTeamId(AActor* Target, const uint8 TeamID);



	/**
	* Sets the volume of a Sound Class.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Sound Class", Meta = (DisplayName = "Set Volume"))
		static void SoundClass_SetVolume(USoundClass* SoundClass, const float Volume);

	/**
	* Returns the volume of a Sound Class.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Sound Class", Meta = (DisplayName = "Get Volume"))
		static float SoundClass_GetVolume(USoundClass* SoundClass);

	/**
	* Sets the pitch of a Sound Class.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Sound Class", Meta = (DisplayName = "Set Pitch"))
		static void SoundClass_SetPitch(USoundClass* SoundClass, const float Pitch);

	/**
	* Returns the pitch of a Sound Class.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Sound Class", Meta = (DisplayName = "Get Pitch"))
		static float SoundClass_GetPitch(USoundClass* SoundClass);



	/**
	* Creates a new latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Boolean", Meta = (DisplayName = "Create Latent Action (Boolean)", Keywords = "make instance"))
		static void LatentAction_Create_Boolean(ULowEntryLatentActionBoolean*& LatentAction);

	/**
	* Creates a new latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Float", Meta = (DisplayName = "Create Latent Action (Float)", Keywords = "make instance"))
		static void LatentAction_Create_Float(ULowEntryLatentActionFloat*& LatentAction);

	/**
	* Creates a new latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Integer", Meta = (DisplayName = "Create Latent Action (Integer)", Keywords = "make instance"))
		static void LatentAction_Create_Integer(ULowEntryLatentActionInteger*& LatentAction);

	/**
	* Creates a new latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|None", Meta = (DisplayName = "Create Latent Action (None)", Keywords = "make instance"))
		static void LatentAction_Create_None(ULowEntryLatentActionNone*& LatentAction);

	/**
	* Creates a new latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|Object", Meta = (DisplayName = "Create Latent Action (Object)", Keywords = "make instance"))
		static void LatentAction_Create_Object(ULowEntryLatentActionObject*& LatentAction);

	/**
	* Creates a new latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Latent Action|String", Meta = (DisplayName = "Create Latent Action (String)", Keywords = "make instance"))
		static void LatentAction_Create_String(ULowEntryLatentActionString*& LatentAction);



	/**
	* Returns true if the two arrays contain the same data.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Bytes", Meta = (DisplayName = "Are Bytes Equal", Keywords = "same compare array ==", AdvancedDisplay = "2"))
		static bool AreBytesEqual(const TArray<uint8>& A, const TArray<uint8>& B, int32 IndexA = 0, int32 LengthA = 0x7FFFFFFF, int32 IndexB = 0, int32 LengthB = 0x7FFFFFFF);



	/**
	* Splits the given Byte Array into two Byte Arrays.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Bytes", Meta = (DisplayName = "Split Bytes", Keywords = "byte array"))
		static void SplitBytes(const TArray<uint8>& ByteArray, const int32 LengthA, TArray<uint8>& A, TArray<uint8>& B);

	/**
	* Merges multiple Byte Arrays into one.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Bytes", Meta = (DeprecatedFunction, DeprecationMessage = "This function is commutative, meaning it sometimes causes bytes to be merged in an incorrect order. Use the new Merge Bytes node instead.", DisplayName = "Merge Bytes (commutative)", Keywords = "byte array", CommutativeAssociativeBinaryOperator = "true"))
		static TArray<uint8> MergeBytes(TArray<uint8> A, TArray<uint8> B);

	/**
	* Returns the values of the given bytes of the given index and length.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Bytes", Meta = (DisplayName = "Get Bytes Sub Array", Keywords = "get byte array"))
		static TArray<uint8> BytesSubArray(const TArray<uint8>& ByteArray, int32 Index, int32 Length = 0x7FFFFFFF);



	/**
	* Returns random bytes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Bytes", Meta = (DisplayName = "Generate Random Bytes", Keywords = "make create"))
		static void GenerateRandomBytes(const int32 Length, TArray<uint8>& ByteArray);

	/**
	* Returns random bytes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Bytes", Meta = (DisplayName = "Generate Random Bytes (Random Length)", Keywords = "make create"))
		static void GenerateRandomBytesRandomLength(int32 MinLength, int32 MaxLength, TArray<uint8>& ByteArray);
	


	/**
	* Converts a String into a Byte Array (using UTF-8 encoding).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "String To Bytes (Utf 8)", Keywords = "byte array string utf-8"))
		static TArray<uint8> StringToBytesUtf8(const FString& String);

	/**
	* Tries to convert a Byte Array into a String (using UTF-8 encoding). Will return an empty String on failure.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To String (Utf 8)", Keywords = "byte array string utf-8", AdvancedDisplay = "1"))
		static FString BytesToStringUtf8(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	/**
	* Tries to convert a Base64 String into a Byte Array. Will return an empty Array on failure.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Base64 To Bytes", Keywords = "byte array base64"))
		static TArray<uint8> Base64ToBytes(const FString& Base64);

	/**
	* Converts a Byte Array into a Base64 String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Base64", Keywords = "byte array base64", AdvancedDisplay = "1"))
		static FString BytesToBase64(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	/**
	* Converts a Base64 string to a Base64Url string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|Strings", Meta = (DisplayName = "Base64 To Base64Url", Keywords = "base64 url web"))
		static FString Base64ToBase64Url(const FString& Base64);

	/**
	* Converts a Base64Url string to a Base64 string.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|Strings", Meta = (DisplayName = "Base64Url To Base64", Keywords = "base64 url web"))
		static FString Base64UrlToBase64(const FString& Base64Url);

	/**
	* Tries to convert a Base64Url String into a Byte Array. Will return an empty Array on failure.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Base64Url To Bytes", Keywords = "byte array base64 url web"))
		static TArray<uint8> Base64UrlToBytes(const FString& Base64Url);

	/**
	* Converts a Byte Array into a Base6 Url String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Base64Url", Keywords = "byte array base64 url web", AdvancedDisplay = "1"))
		static FString BytesToBase64Url(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	/**
	* Tries to convert a Hexadecimal (Base16) String into a Byte Array. Will return an empty Array on failure.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Hex To Bytes", Keywords = "byte array hex hexadecimal base16"))
		static TArray<uint8> HexToBytes(const FString& Hex);

	/**
	* Converts a Byte Array into a Hexadecimal (Base16) String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Hex", Keywords = "byte array hex hexadecimal base16", AdvancedDisplay = "2"))
		static FString BytesToHex(const TArray<uint8>& ByteArray, const bool AddSpaces = false, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	/**
	* Tries to convert a Binary (Base2) String into a Byte Array. Will return an empty Array on failure.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Binary To Bytes", Keywords = "byte array binary base2"))
		static TArray<uint8> BinaryToBytes(const FString& Binary);

	/**
	* Converts a Byte Array into a Binary (Base2) String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Binary", Keywords = "byte array binary base2", AdvancedDisplay = "2"))
		static FString BytesToBinary(const TArray<uint8>& ByteArray, const bool AddSpaces = false, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	/**
	* Tries to convert a Binary (Base2) String (with each byte reversed) into a Byte Array. Will return an empty Array on failure.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Bit String To Bytes", Keywords = "byte array binary base2 bits reversed"))
		static TArray<uint8> BitStringToBytes(const FString& Bits);

	/**
	* Converts a Byte Array into a Bit (Base2) String, with each byte reversed.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Bit String", Keywords = "byte array binary base2 bits reversed", AdvancedDisplay = "2"))
		static FString BytesToBitString(const TArray<uint8>& ByteArray, const bool AddSpaces = false, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	/**
	* Converts a boolean into a Byte Array (1 byte).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Boolean To Bytes", Keywords = "byte array bool boolean"))
		static TArray<uint8> BooleanToBytes(const bool Value);

	/**
	* Converts a Byte Array into a boolean (00000001 will return true, everything else will return false).
	*
	* If there is more than 1 byte given, it will only convert the first byte to a boolean.
	* If there are no bytes given, it will return false.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Boolean", Keywords = "byte array bool boolean", AdvancedDisplay = "1"))
		static bool BytesToBoolean(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	/**
	* Converts a boolean into a Byte.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Boolean To Byte", Keywords = "byte bool boolean"))
		static uint8 BooleanToByte(const bool Value);

	/**
	* Converts a Byte into a boolean (00000001 will return true, everything else will return false).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Byte To Boolean", Keywords = "byte bool boolean", AdvancedDisplay = "1"))
		static bool ByteToBoolean(const uint8 Byte);


	/**
	* Converts a signed integer (int32) into a Byte Array (4 bytes).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Integer To Bytes", Keywords = "byte array int integer"))
		static TArray<uint8> IntegerToBytes(const int32 Value);

	/**
	* Converts a Byte Array into a signed integer (int32).
	* 
	* If there are more than 4 bytes given, it will only convert the first 4 bytes to an integer.
	* If there are less than 4 bytes given, it will prefix the bytes with 0 value bytes (so 01010101 01010101 01010101 turns into 00000000 01010101 01010101 01010101).
	* If there are no bytes given, it will return 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Integer", Keywords = "byte array int integer", AdvancedDisplay = "1"))
		static int32 BytesToInteger(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	static TArray<uint8> LongToBytes(const int64 Value);

	static int64 BytesToLong(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Converts a Byte Array into a signed long (int64) (bytes).
	*
	* If there are more than 8 bytes given, it will only convert the first 8 bytes to a long.
	* If there are less than 8 bytes given, it will prefix the bytes with 0 value bytes (so 01010101 01010101 01010101 turns into 00000000 00000000 00000000 00000000 00000000 01010101 01010101 01010101).
	* If there are no bytes given, it will return 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Long (bytes)", Keywords = "byte array long", AdvancedDisplay = "1"))
		static ULowEntryLong* BytesToLongBytes(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Parses a string into a long.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Parse String Into Long (bytes)"))
		static ULowEntryLong* ParseStringIntoLongBytes(const FString& String);


	/**
	* Converts a float into a Byte Array (4 bytes).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Float To Bytes", Keywords = "byte array float"))
		static TArray<uint8> FloatToBytes(const float Value);

	/**
	* Converts a Byte Array into a float.
	* 
	* If there are more than 4 bytes given, it will only convert the first 4 bytes to a float.
	* If there are less than 4 bytes given, it will prefix the bytes with 0 value bytes (so 01010101 01010101 01010101 turns into 00000000 01010101 01010101 01010101).
	* If there are no bytes given, it will return 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Float", Keywords = "byte array float", AdvancedDisplay = "1"))
		static float BytesToFloat(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	static TArray<uint8> DoubleToBytes(const double Value);

	static double BytesToDouble(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Converts a Byte Array into a double (bytes).
	*
	* If there are more than 8 bytes given, it will only convert the first 8 bytes to a double.
	* If there are less than 8 bytes given, it will prefix the bytes with 0 value bytes (so 01010101 01010101 01010101 turns into 00000000 00000000 00000000 00000000 00000000 01010101 01010101 01010101).
	* If there are no bytes given, it will return 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Double (bytes)", Keywords = "byte array double", AdvancedDisplay = "1"))
		static ULowEntryDouble* BytesToDoubleBytes(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Parses a string into a double.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Parse String Into Double (bytes)"))
		static ULowEntryDouble* ParseStringIntoDoubleBytes(const FString& String);


	/**
	* Converts a byte (uint8) into a Byte Array (1 byte).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Byte To Bytes", Keywords = "byte array"))
		static TArray<uint8> ByteToBytes(const uint8 Value);

	/**
	* Converts a Byte Array into a byte (uint8).
	*
	* If there are more than 1 bytes given, it will return the first byte.
	* If there are less than 1 bytes given, it will return 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Byte", Keywords = "byte array", AdvancedDisplay = "1"))
		static uint8 BytesToByte(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);


	/**
	* Converts bits into a byte.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|Bits", Meta = (DisplayName = "Bits To Byte", Keywords = "bit byte"))
		static void BitsToByte(const bool Bit1, const bool Bit2, const bool Bit3, const bool Bit4, const bool Bit5, const bool Bit6, const bool Bit7, const bool Bit8, uint8& Byte);

	/**
	* Converts a byte into bits.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|Bits", Meta = (DisplayName = "Byte To Bits", Keywords = "bit byte"))
		static void ByteToBits(const uint8 Byte, bool& Bit1, bool& Bit2, bool& Bit3, bool& Bit4, bool& Bit5, bool& Bit6, bool& Bit7, bool& Bit8);


	/**
	* Returns true if the bit is 1, returns false if the bit is 0.
	* 
	* Bytes start with bit 8, ending with bit 1, as such: 87654321
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|Bits", Meta = (DisplayName = "Is Bit Set", Keywords = "bit byte"))
		static bool IsBitSet(const uint8 B, const int32 Bit);

	/**
	* Sets a bit 1 or 0, depending on the given boolean.
	* 
	* Bytes start with bit 8, ending with bit 1, as such: 87654321
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Encoding|Bits", Meta = (DisplayName = "Get Byte With Bit Set", Keywords = "bit byte"))
		static uint8 GetByteWithBitSet(const uint8 Byte, const int32 Bit, const bool Value);
	
		
	/**
	* Converts a Byte Array into an image (Texture2D).
	* 
	* Returns NULL if it fails.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Image (Texture2D)", Keywords = "byte array binary", AdvancedDisplay = "2"))
		static UTexture2D* BytesToImage(const TArray<uint8>& ByteArray, const ELowEntryImageFormat ImageFormat, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Converts a Byte Array into an image (Texture2D).
	*
	* Returns NULL if it fails.
	* 
	* Will re-use the given Texture2D if possible, ReusedGivenTexture2D will be true if it was possible.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Existing Image (Texture2D)", Keywords = "byte array binary", AdvancedDisplay = "4"))
		static UTexture2D* BytesToExistingImage(bool& ReusedGivenTexture2D, UTexture2D* Texture2D, const TArray<uint8>& ByteArray, const ELowEntryImageFormat ImageFormat, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Converts a Texture2D into a Byte Array.
	*
	* Some formats will not work (like BMP, ICO and ICNS).
	* 
	* The Compression Quality has to be 1-100, a value of 0 will use the default value for the given ImageFormat.
	* 
	* Returns an empty Byte Array if it fails.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Image To Bytes (Texture2D)", Keywords = "byte array binary", AdvancedDisplay = "3"))
		static void Texture2DToBytes(UTexture2D* Texture2D, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality = 0);


	/**
	* Converts a Byte Array into a Pixel Array.
	*
	* Returns an empty Pixel Array if it fails, the Width and the Height will also be 0 then.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Pixels", Keywords = "byte binary array width height pixels colors", AdvancedDisplay = "5"))
		static void BytesToPixels(const TArray<uint8>& ByteArray, const ELowEntryImageFormat ImageFormat, int32& Width, int32& Height, TArray<FColor>& Pixels, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Converts a Pixel Array into a Byte Array.
	* 
	* Some formats will not work (like BMP, ICO and ICNS).
	* 
	* The Compression Quality has to be 1-100, a value of 0 will use the default value for the given ImageFormat.
	*
	* Returns an empty Byte Array if it fails.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Pixels To Bytes", Keywords = "byte binary array width height pixels colors", AdvancedDisplay = "5"))
		static void PixelsToBytes(const int32 Width, const int32 Height, const TArray<FColor>& Pixels, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality = 0);
	
	
	/**
	* Converts the pixel to an accurate-looking gray pixel.
	*
	* The formula it uses:  brightness  =  21.25% red  +  71.54% green  +  7.21% blue
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Image|Other", Meta = (DisplayName = "Grayscale Pixel", Keywords = "to convert grey get"))
		static FColor GrayscalePixel(const FColor& Pixel);

	/**
	* Converts the pixels to accurate-looking gray pixels.
	*
	* The formula it uses:  brightness  =  21.25% red  +  71.54% green  +  7.21% blue
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Image|Other", Meta = (DisplayName = "Grayscale Pixels", Keywords = "to convert grey get"))
		static TArray<FColor> GrayscalePixels(const TArray<FColor>& Pixel);


	/**
	* Converts a Texture2D into a Pixel Array.
	*
	* Returns an empty Pixel Array if it fails, the Width and the Height will also be 0 then.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Image|To Pixels", Meta = (DisplayName = "Image To Pixels (Texture2D)", Keywords = "array width height pixels colors"))
		static void Texture2DToPixels(UTexture2D* Texture2D, int32& Width, int32& Height, TArray<FColor>& Pixels);

	/**
	* Converts a Pixel Array into an image (Texture2D).
	*
	* Returns NULL if it fails.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Image|From Pixels", Meta = (DisplayName = "Pixels To Image (Texture2D)", Keywords = "array width height pixels colors"))
		static UTexture2D* PixelsToTexture2D(const int32 Width, const int32 Height, const TArray<FColor>& Pixels);

	/**
	* Converts a Pixel Array into an image (Texture2D).
	*
	* Returns NULL if it fails.
	* 
	* Will re-use the given Texture2D if possible, ReusedGivenTexture2D will be true if it was possible.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Image|From Pixels", Meta = (DisplayName = "Pixels To Existing Image (Texture2D)", Keywords = "array width height pixels colors"))
		static UTexture2D* PixelsToExistingTexture2D(bool& ReusedGivenTexture2D, UTexture2D* Texture2D, const int32 Width, const int32 Height, const TArray<FColor>& Pixels);


	static UTexture2D* DataToTexture2D(int32 Width, int32 Height, const void* Src, SIZE_T Count);
	static UTexture2D* DataToExistingTexture2D(UTexture2D* Texture2D, int32 Width, int32 Height, const void* Src, SIZE_T Count);


	/**
	* Converts a SceneCapture2D into a Byte Array.
	* 
	* Some formats will not work (like BMP, ICO and ICNS).
	* 
	* The Compression Quality has to be 1-100, a value of 0 will use the default value for the given ImageFormat.
	* 
	* To get the best results:
	*  1) In the SceneCapture2D [Texture Target]'s settings, set [Render Target Format] to [RTF RGBA8] and choose a properly high Size X and Y (1000+ seems to be fine)
	*  2) In the SceneCapture2D's settings, change the [Capture Source] to [Final Color (LDR) in RGB], if you don't see this option, try converting your SceneCapture2D Actor to a blueprint Actor first
	*  3) To get a brighter image, in the SceneCapture2D settings, play around with the Color Grading Contrast and Gamma (a Contrast and Gamma of X=1.0 Y=1.0 Z=1.0 W=2.0 looked quite good on my end)
	*
	* Returns an empty Byte Array if it fails.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Image To Bytes (SceneCapture2D)", Keywords = "byte array binary", AdvancedDisplay = "3"))
		static void SceneCapture2DToBytes(ASceneCapture2D* SceneCapture2D, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality = 0);

	/**
	* Converts a SceneCaptureComponent2D into a Byte Array.
	* 
	* Some formats will not work (like BMP, ICO and ICNS).
	* 
	* The Compression Quality has to be 1-100, a value of 0 will use the default value for the given ImageFormat.
	* 
	* To get the best results:
	*  1) In the SceneCaptureComponent2D [Texture Target]'s settings, set [Render Target Format] to [RTF RGBA8] and choose a properly high Size X and Y (1000+ seems to be fine)
	*  2) In the SceneCaptureComponent2D's settings, change the [Capture Source] to [Final Color (LDR) in RGB], if you don't see this option, try converting your SceneCaptureComponent2D's Actor to a blueprint Actor first
	*  3) To get a brighter image, in the SceneCaptureComponent2D settings (not in the CameraActor settings, but in the SceneCaptureComponent2D settings), play around with the Color Grading Contrast and Gamma (a Contrast and Gamma of X=1.0 Y=1.0 Z=1.0 W=2.0 looked quite good on my end)
	*
	* Returns an empty Byte Array if it fails.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Image To Bytes (SceneCaptureComponent2D)", Keywords = "byte array binary", AdvancedDisplay = "3"))
		static void SceneCaptureComponent2DToBytes(USceneCaptureComponent2D* SceneCaptureComponent2D, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality = 0);

	/**
	* Converts a TextureRenderTarget2D into a Byte Array.
	* 
	* Some formats will not work (like BMP, ICO and ICNS).
	* 
	* The Compression Quality has to be 1-100, a value of 0 will use the default value for the given ImageFormat.
	* 
	* To get the best results:
	*  1) In the Texture Target's settings, set [Render Target Format] to [RTF RGBA8] and choose a properly high Size X and Y (1000+ seems to be fine)
	*
	* Returns an empty Byte Array if it fails.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Encoding|To Bytes", Meta = (DisplayName = "Image To Bytes (TextureRenderTarget2D)", Keywords = "byte array binary", AdvancedDisplay = "3"))
		static void TextureRenderTarget2DToBytes(UTextureRenderTarget2D* TextureRenderTarget2D, const ELowEntryImageFormat ImageFormat, TArray<uint8>& ByteArray, const int32 CompressionQuality = 0);


	/**
	* Converts a SceneCapture2D into a Pixel Array.
	*
	* To get the best results:
	*  1) In the SceneCapture2D [Texture Target]'s settings, set [Render Target Format] to [RTF RGBA8] and choose a properly high Size X and Y (1000+ seems to be fine)
	*  2) In the SceneCapture2D's settings, change the [Capture Source] to [Final Color (LDR) in RGB], if you don't see this option, try converting your SceneCapture2D Actor to a blueprint Actor first
	*  3) To get a brighter image, in the SceneCapture2D settings, play around with the Color Grading Contrast and Gamma (a Contrast and Gamma of X=1.0 Y=1.0 Z=1.0 W=2.0 looked quite good on my end)
	*
	* Returns an empty Pixel Array if it fails, the Width and the Height will also be 0 then.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Image|To Pixels", Meta = (DisplayName = "Image To Pixels (SceneCapture2D)", Keywords = "array width height pixels colors"))
		static void SceneCapture2DToPixels(ASceneCapture2D* SceneCapture2D, int32& Width, int32& Height, TArray<FColor>& Pixels);

	/**
	* Converts a SceneCaptureComponent2D into a Pixel Array.
	*
	* To get the best results:
	*  1) In the SceneCaptureComponent2D [Texture Target]'s settings, set [Render Target Format] to [RTF RGBA8] and choose a properly high Size X and Y (1000+ seems to be fine)
	*  2) In the SceneCaptureComponent2D's settings, change the [Capture Source] to [Final Color (LDR) in RGB], if you don't see this option, try converting your SceneCaptureComponent2D's Actor to a blueprint Actor first
	*  3) To get a brighter image, in the SceneCaptureComponent2D settings (not in the CameraActor settings, but in the SceneCaptureComponent2D settings), play around with the Color Grading Contrast and Gamma (a Contrast and Gamma of X=1.0 Y=1.0 Z=1.0 W=2.0 looked quite good on my end)
	*
	* Returns an empty Pixel Array if it fails, the Width and the Height will also be 0 then.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Image|To Pixels", Meta = (DisplayName = "Image To Pixels (SceneCaptureComponent2D)", Keywords = "bytearray width height pixels colors"))
		static void SceneCaptureComponent2DToPixels(USceneCaptureComponent2D* SceneCaptureComponent2D, int32& Width, int32& Height, TArray<FColor>& Pixels);

	/**
	* Converts a TextureRenderTarget2D into a Pixel Array.
	*
	* To get the best results:
	*  1) In the Texture Target's settings, set [Render Target Format] to [RTF RGBA8] and choose a properly high Size X and Y (1000+ seems to be fine)
	*
	* Returns an empty Pixel Array if it fails, the Width and the Height will also be 0 then.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Image|To Pixels", Meta = (DisplayName = "Image To Pixels (TextureRenderTarget2D)", Keywords = "array width height pixels colors"))
		static void TextureRenderTarget2DToPixels(UTextureRenderTarget2D* TextureRenderTarget2D, int32& Width, int32& Height, TArray<FColor>& Pixels);

	
	/**
	* Loads a video.
	* 
	* Requires a:
	*  - MediaSoundComponent (to hear the video), this is created by using the "Add Media Sound Component" blueprint on an object on which you want to hear the sound on, also, don't forget to run the "Start" blueprint on the Media Sound Component, otherwise you won't hear anything
	*  - URL (could be a HTTP/HTTPS URL, or a relative or absolute filepath, more on that below)
	*  - PlayOnOpen (determines whether "Play" should be automatically called on the returned MediaPlayer, if this is false, the video/sound won't start until you call "Play" on the returned MediaPlayer yourself)
	*  - Loop (determines whether the video/sound should keep playing, or whether it should just play one time and then stop)
	* 
	* Returns a:
	*  - MediaPlayer (to play/pause/etc the video)
	*  - MediaTexture (to see the video)
	*
	* This blueprint also returns a boolean called Success.
	*  - true, everything went well, every returned Object is valid
	*  - false, something went wrong, every returned Object is NULL
	*
	* The URL is either:
	*  - a HTTP/HTTPS URL, for example "http://public.lowentry.com/files/test_data/TestVideoMp4.mp4"
	*  - a relative filepath URL of a video located in "YourProject/Content/Movies/" formatted like "./Movies/YourVideo.mp4"
	*  - an absolute filepath URL of a video prefixed by "file://", for example "file://C:/Program Files/Epic Games/4.13/Engine/Binaries/Win64/YourVideo.mp4"
	*
	* Some tips:
	*  - only MP4 (MPEG-4) can be played on every platform, so it's best to only use MP4 (MPEG-4) videos for now
	*
	* Additional tips:
	*  - this blueprint can also be used to load sound assets, just ignore the returned Texture in that case
	*  - if no MediaSoundComponent is given, or if Start wasn't called on the MediaSoundComponent, you won't hear any sound
	* 
	* Screenshots:
	*  - screenshots on how to use this blueprint correctly can be found at: https://public.lowentry.com/#files/LowEntryUE4/ue4/images/tutorials/load_video/
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Video", Meta = (DisplayName = "Load Video", Keywords = "movie download audio sound"))
		static void LoadVideo(UMediaSoundComponent* MediaSoundComponent, const FString& Url, bool& Success, UMediaPlayer*& MediaPlayer, UMediaTexture*& MediaTexture, const bool PlayOnOpen = true, const bool Loop = true);



	/**
	* Calls Texture->UpdateResource() if the given Texture is valid.
	*
	* Updating the resource of a texture might take several frames. During these frames, the texture will be blank.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Texture", Meta = (DisplayName = "Update Resource (Texture)", Keywords = ""))
		static void TextureUpdateResource(UTexture* Texture);



	/**
	* Returns the FOV of the given SceneCapture2D's SceneCaptureComponent2D.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Get FOV (SceneCapture2D)"))
		static void SceneCapture2D_GetFov(ASceneCapture2D* SceneCapture2D, float& Fov);

	/**
	* Sets the FOV of the given SceneCapture2D's SceneCaptureComponent2D.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Set FOV (SceneCapture2D)"))
		static void SceneCapture2D_SetFov(ASceneCapture2D* SceneCapture2D, const float Fov);


	/**
	* Returns the FOV of the given SceneCaptureComponent2D.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Get FOV (SceneCaptureComponent2D)"))
		static void SceneCaptureComponent2D_GetFov(USceneCaptureComponent2D* SceneCaptureComponent2D, float& Fov);

	/**
	* Sets the FOV of the given SceneCaptureComponent2D.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Set FOV (SceneCaptureComponent2D)"))
		static void SceneCaptureComponent2D_SetFov(USceneCaptureComponent2D* SceneCaptureComponent2D, const float Fov);



	/**
	* Generates a Pearson hash, returns the given HashLength number of bytes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Pearson)", AdvancedDisplay = "2"))
		static TArray<uint8> Pearson(const TArray<uint8>& ByteArray, const int32 HashLength, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Generates a MD5 hash, always returns 16 bytes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Md5)", AdvancedDisplay = "1"))
		static TArray<uint8> Md5(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Generates a SHA1 hash, always returns 20 bytes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Sha1)", AdvancedDisplay = "1"))
		static TArray<uint8> Sha1(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Generates a SHA-256 hash, always returns 32 bytes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Sha-256)", AdvancedDisplay = "1"))
		static TArray<uint8> Sha256(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Generates a SHA-512 hash, always returns 64 bytes.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Sha-512)", AdvancedDisplay = "1"))
		static TArray<uint8> Sha512(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Generates a BCrypt hash, always returns 24 bytes.
	* 
	* If the given ByteArray contain more than 72 bytes, only the first 72 bytes will be used.
	* 
	* The given salt needs to be 16 bytes.
	* The given strength needs to be between 4 and 30, a strength between 10 and 12 is recommended.
	* 
	* If these conditions aren't met, this blueprint will return an empty byte array.
	*
	* PS: the Index and Length parameters refer to the Byte Array (see the "Get Bytes Sub Array" blueprint for more information).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Bcrypt)", AdvancedDisplay = "3"))
		static TArray<uint8> BCrypt(const TArray<uint8>& ByteArray, const TArray<uint8>& Salt, int32 Strength = 10, int32 Index = 0, int32 Length = 0x7FFFFFFF);



	/**
	* Generates a HMAC hash.
	*
	* PS: the Index and Length parameters refer to the Byte Array (see the "Get Bytes Sub Array" blueprint for more information).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Hmac)", AdvancedDisplay = "3"))
		static TArray<uint8> HMAC(const TArray<uint8>& ByteArray, const TArray<uint8>& Key, ELowEntryHmacAlgorithm Algorithm = ELowEntryHmacAlgorithm::SHA256, int32 Index = 0, int32 Length = 0x7FFFFFFF);

private:
	static int32 HMAC_GetBlockSize(ELowEntryHmacAlgorithm Algorithm);
	static TArray<uint8> HMAC_Hash(const TArray<uint8>& Array, ELowEntryHmacAlgorithm Algorithm);
public:



	/**
	* Creates Hashcash hashes, each will have a variable amount of characters.
	*
	* The strength (or value) of the Hashcash hashes is determined by the amount of given bits.
	*
	* 20 is an average amount of bits.
	* 22 is a good amount of bits.
	* 24 is a very good amount of bits.
	*
	* The given 'resources' are basically IDs of the service you are 'buying' with this Hashcash, like actions or an email addresses or whatever, something that is unique-ish but not necessarily unique.
	*
	* Hashcash hashes are only valid for a certain amount of time (depending on the receiver of the Hashcash), this blueprint uses the current date and time as the creation date of the Hashcash hashes (which is what you normally want).
	*
	* You can validate Hashcash hashes with the Parse Hashcash blueprints.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Generate", Meta = (DisplayName = "Generate Hashcash (Array)"))
		static TArray<FString> HashcashArray(const TArray<FString>& Resources, const int32 Bits = 22);

	/**
	* Creates Hashcash hashes, each will have a variable amount of characters.
	*
	* The strength (or value) of the Hashcash hashes is determined by the amount of given bits.
	*
	* 20 is an average amount of bits.
	* 22 is a good amount of bits.
	* 24 is a very good amount of bits.
	*
	* The given 'resources' are basically IDs of the service you are 'buying' with this Hashcash, like actions or an email addresses or whatever, something that is unique-ish but not necessarily unique.
	*
	* Hashcash hashes are only valid for a certain amount of time (depending on the receiver of the Hashcash), the given DateTime is used as the creation date of the Hashcash hashes.
	*
	* You can validate Hashcash hashes with the Parse Hashcash blueprints.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Generate", Meta = (DisplayName = "Generate Hashcash (Array) (Custom Creation Date)"))
		static TArray<FString> HashcashArrayCustomCreationDate(const TArray<FString>& Resources, const FDateTime& UtcDate, const int32 Bits = 22);

	/**
	* Creates a Hashcash hash, returns a variable amount of characters.
	*
	* The strength (or value) of the Hashcash hash is determined by the amount of given bits.
	*
	* 20 is an average amount of bits.
	* 22 is a good amount of bits.
	* 24 is a very good amount of bits.
	*
	* The given 'resource' is basically an ID of the service you are 'buying' with this Hashcash, like an action or an email address or whatever, something that is unique-ish but not necessarily unique.
	*
	* Hashcash hashes are only valid for a certain amount of time (depending on the receiver of the Hashcash), this blueprint uses the current date and time as the creation date of the Hashcash hash (which is what you normally want).
	*
	* You can validate Hashcash hashes with the Parse Hashcash blueprints.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Generate", Meta = (DisplayName = "Generate Hashcash"))
		static FString Hashcash(const FString& Resource, const int32 Bits = 22);

	/**
	* Creates Hashcash hashes, returns a variable amount of characters, will never return null.
	*
	* The strength (or value) of the Hashcash hash is determined by the amount of given bits.
	*
	* 20 is an average amount of bits.
	* 22 is a good amount of bits.
	* 24 is a very good amount of bits.
	*
	* The given 'resource' is basically an ID of the service you are 'buying' with this Hashcash, like an action or an email address or whatever, something that is unique-ish but not necessarily unique.
	*
	* Hashcash hashes are only valid for a certain amount of time (depending on the receiver of the Hashcash), the given DateTime is used as the creation date of the Hashcash hash.
	*
	* You can validate Hashcash hashes with the Parse Hashcash blueprints.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Generate", Meta = (DisplayName = "Generate Hashcash (Custom Creation Date)"))
		static FString HashcashCustomCreationDate(const FString& Resource, const FDateTime& UtcDate, const int32 Bits = 22);


	/**
	* Parses and validates a Hashcash hash.
	*
	* To successfully validate a Hashcash hash, do the following:
	* 1) call this method to parse the hashes
	* 2) check if the returned ParsedHashcashes return true for Is Parsed Hashcash Valid
	* 3) check if the amount of bits of the returned ParsedHashcashes are of a desired number
	* 4) check if the resources of the returned ParsedHashcashes matches the expected string
	* 5) check if the dates of the returned ParsedHashcashes are not in the future and are not too long ago
	* 6) check if the hash hasn't been used already (save the used Hashcash hashes in an Array for example)
	*
	* You can change the order of actions if desired.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Hashcash|Parse", Meta = (DisplayName = "Parse Hashcash (Array)"))
		static TArray<ULowEntryParsedHashcash*> HashcashParseArray(const TArray<FString>& Hashes);

	/**
	* Parses and validates a Hashcash hash.
	*
	* To successfully validate a Hashcash hash, do the following:
	* 1) call this method to parse the hash
	* 2) check if the returned ParsedHashcash returns true for Is Parsed Hashcash Valid
	* 3) check if the amount of bits of the returned ParsedHashcash is of a desired number
	* 4) check if the resource of the returned ParsedHashcash matches the expected string
	* 5) check if the date of the returned ParsedHashcash is not in the future and is not too long ago
	* 6) check if the hash hasn't been used already (save the used Hashcash hashes in an Array for example)
	*
	* You can change the order of actions if desired.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Hashcash|Parse", Meta = (DisplayName = "Parse Hashcash"))
		static ULowEntryParsedHashcash* HashcashParse(const FString& Hash);


	/**
	* Returns true if this Parsed Hashcash is valid, returns false if it is not valid.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashcash|Parsed", Meta = (DisplayName = "Is Parsed Hashcash Valid"))
		static bool ParsedHashcashIsValid(ULowEntryParsedHashcash* Target);
	
	
	
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
		static FString MinString(FString A, FString B);

	/**
	* Returns the maximum value of the given values.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Max (String)", CompactNodeTitle = "MAX", CommutativeAssociativeBinaryOperator = "true"))
		static FString MaxString(FString A, FString B);

	/**
	* Returns true if A is less than B (A < B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "String < String", CompactNodeTitle = "<"))
		static bool LessStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than B (A > B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "String > String", CompactNodeTitle = ">"))
		static bool GreaterStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is less than or equal to B (A <= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "String <= String", CompactNodeTitle = "<="))
		static bool LessEqualStringString(const FString& A, const FString& B);

	/**
	* Returns true if A is greater than or equal to B (A >= B)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Compare", Meta = (DisplayName = "String >= String", CompactNodeTitle = ">="))
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
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (DisplayName = "Round (With Decimals)"))
		static float RoundDecimals(float Number, int32 Decimals);

	/**
	* Ceil to the given Decimals.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (DisplayName = "Ceil (With Decimals)"))
		static float CeilDecimals(float Number, int32 Decimals);

	/**
	* Floor to the given Decimals.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (DisplayName = "Floor (With Decimals)"))
		static float FloorDecimals(float Number, int32 Decimals);



	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MaxOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMaxValue, FString& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MinOfStringArray(const TArray<FString>& StringArray, int32& IndexOfMinValue, FString& MinValue);

	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MaxOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMaxValue, FDateTime& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MinOfDateTimeArray(const TArray<FDateTime>& DateTimeArray, int32& IndexOfMinValue, FDateTime& MinValue);

	/**
	* Returns the maximum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MaxOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMaxValue, FTimespan& MaxValue);

	/**
	* Returns the minimum value of all array entries and the index at which it was found. Returns an index of -1 if the given array is empty.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array")
		static void MinOfTimespanArray(const TArray<FTimespan>& TimespanArray, int32& IndexOfMinValue, FTimespan& MinValue);



	/**
	* Returns the ISO-8601 string representation of the FDateTime.
	*
	* The resulting string assumes that the FDateTime is in UTC.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Date Time", Meta = (DisplayName = "To String (Iso 8601)"))
		static void DateTime_ToIso8601(const FDateTime& DateTime, FString& String);

	/**
	* Returns the string representation of the given FDateTime.
	* 
	* The format works as follows:
	* 
	* case TCHAR('a'): Result += IsMorning() ? TEXT("am") : TEXT("pm"); break;
	* case TCHAR('A'): Result += IsMorning() ? TEXT("AM") : TEXT("PM"); break;
	* case TCHAR('d'): Result += FString::Printf(TEXT("%02i"), GetDay()); break;
	* case TCHAR('D'): Result += FString::Printf(TEXT("%03i"), GetDayOfYear()); break;
	* case TCHAR('m'): Result += FString::Printf(TEXT("%02i"), GetMonth()); break;
	* case TCHAR('y'): Result += FString::Printf(TEXT("%02i"), GetYear() % 100); break;
	* case TCHAR('Y'): Result += FString::Printf(TEXT("%04i"), GetYear()); break;
	* case TCHAR('h'): Result += FString::Printf(TEXT("%02i"), GetHour12()); break;
	* case TCHAR('H'): Result += FString::Printf(TEXT("%02i"), GetHour()); break;
	* case TCHAR('M'): Result += FString::Printf(TEXT("%02i"), GetMinute()); break;
	* case TCHAR('S'): Result += FString::Printf(TEXT("%02i"), GetSecond()); break;
	* case TCHAR('s'): Result += FString::Printf(TEXT("%03i"), GetMillisecond()); break;
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Date Time", Meta = (DisplayName = "To String"))
		static void DateTime_ToString(const FDateTime& DateTime, FString& String, const FString& Format = TEXT("%Y.%m.%d-%H.%M.%S"));

	/**
	* Creates a FDateTime with the given time in milliseconds after January 1, 1970 00:00:00 GMT.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Date Time", Meta = (DisplayName = "To Unix Timestamp", Keywords = "byte array long get create convert"))
		static void DateTime_ToUnixTimestamp(const FDateTime& DateTime, ULowEntryLong*& Timestamp);

	/**
	* Returns the number of milliseconds since January 1, 1970, 00:00:00 GMT represented by the given FDateTime.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Date Time", Meta = (DisplayName = "Date Time from Unix Timestamp", Keywords = "byte array long get create convert"))
		static void DateTime_FromUnixTimestamp(ULowEntryLong* Timestamp, FDateTime& DateTime);



	/**
	* Converts the given DateTime from the local time into the UTC time.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Date Time", Meta = (DisplayName = "Convert Local to Utc", Keywords = "get create convert time zone"))
		static void ConvertLocalDateToUtcDate(const FDateTime& Local, FDateTime& Utc);

	/**
	* Converts the given DateTime from the UTC time into the local time.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Date Time", Meta = (DisplayName = "Convert Utc to Local", Keywords = "get create convert time zone"))
		static void ConvertUtcDateToLocalDate(const FDateTime& Utc, FDateTime& Local);



	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (String Array) (Copy)"))
		static TArray<FString> SortStringArray(const TArray<FString>& StringArray, const bool Reversed = false);

	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (String Array)"))
		static void SortStringArrayDirectly(UPARAM(ref) TArray<FString>& StringArray, const bool Reversed = false);


	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Integer Array) (Copy)"))
		static TArray<int32> SortIntegerArray(const TArray<int32>& IntegerArray, const bool Reversed = false);

	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Integer Array)"))
		static void SortIntegerArrayDirectly(UPARAM(ref) TArray<int32>& IntegerArray, const bool Reversed = false);


	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Float Array) (Copy)"))
		static TArray<float> SortFloatArray(const TArray<float>& FloatArray, const bool Reversed = false);

	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Float Array)"))
		static void SortFloatArrayDirectly(UPARAM(ref) TArray<float>& FloatArray, const bool Reversed = false);


	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Byte Array) (Copy)"))
		static TArray<uint8> SortByteArray(const TArray<uint8>& ByteArray, const bool Reversed = false);

	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Byte Array)"))
		static void SortByteArrayDirectly(UPARAM(ref) TArray<uint8>& ByteArray, const bool Reversed = false);


	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (DateTime Array) (Copy)"))
		static TArray<FDateTime> SortDateTimeArray(const TArray<FDateTime>& DateTimeArray, const bool Reversed = false);

	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (DateTime Array)"))
		static void SortDateTimeArrayDirectly(UPARAM(ref) TArray<FDateTime>& DateTimeArray, const bool Reversed = false);


	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Timespan Array) (Copy)"))
		static TArray<FTimespan> SortTimespanArray(const TArray<FTimespan>& TimespanArray, const bool Reversed = false);

	/**
	* Sorts a copy of the given array.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Timespan Array)"))
		static void SortTimespanArrayDirectly(UPARAM(ref) TArray<FTimespan>& TimespanArray, const bool Reversed = false);


	/**
	* Sorts a copy of the given array.
	* 
	* To create the Comparator, do this:
	*  - create a function that has 2 input parameters (Object and Object) and 1 output parameter (Boolean)
	*  - it is important that the parameters have the following names: ObjectA, ObjectB and Return
	*  - in that function, return true if ObjectA is smaller than ObjectB, return false otherwise
	*  - then, when using the Sort Object Array blueprint, use the Create Event blueprint and set its value as the function created earlier
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Object Array) (Copy)"))
		static TArray<UObject*> SortObjectArray(const TArray<UObject*>& ObjectArray, FDelegateULowEntryExtendedStandardLibraryCompareObjects Comparator, const bool Reversed = false);

	/**
	* Sorts the given array.
	*
	* To create the Comparator, do this:
	*  - create a function that has 2 input parameters (Object and Object) and 1 output parameter (Boolean)
	*  - it is important that the parameters have the following names: ObjectA, ObjectB and Return
	*  - in that function, return true if ObjectA is smaller than ObjectB, return false otherwise
	*  - then, when using the Sort Object Array blueprint, use the Create Event blueprint and set its value as the function created earlier
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Object Array)"))
		static void SortObjectArrayDirectly(UPARAM(ref) TArray<UObject*>& ObjectArray, FDelegateULowEntryExtendedStandardLibraryCompareObjects Comparator, const bool Reversed);

	

	/**
	* Perform a latent action with a random delay (specified in seconds).  Calling again while it is counting down will be ignored.
	*
	* @param WorldContext	World context.
	* @param MinDuration 	minimum length of delay (in seconds).
	* @param MaxDuration 	maximum length of delay (in seconds).
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay", meta = (DeprecatedFunction, DeprecationMessage = "Use a [Delay] with a [Random Float In Range] instead.", Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void	RandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, FLatentActionInfo LatentInfo);

	/**
	* Perform a latent action with a retriggerable random delay (specified in seconds).  Calling again while it is counting down will reset the countdown to a new random Duration.
	*
	* @param WorldContext	World context.
	* @param MinDuration 	minimum length of delay (in seconds).
	* @param MaxDuration 	maximum length of delay (in seconds).
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay", meta = (DeprecatedFunction, DeprecationMessage = "Use a [Retriggerable Delay] with a [Random Float In Range] instead.", Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void RetriggerableRandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, FLatentActionInfo LatentInfo);



	/**
	* Perform a latent action with a delay (specified in frames).  Calling again while it is counting down will be ignored.
	*
	* @param WorldContext	World context.
	* @param Frames			frames of delay.
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay (Frames)", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Delay (Frames)"))
		static void	DelayFrames(UObject* WorldContextObject, int32 Frames, FLatentActionInfo LatentInfo);

	/**
	* Perform a latent action with a retriggerable delay (specified in frames).  Calling again while it is counting down will reset the countdown to the given Frames.
	*
	* @param WorldContext	World context.
	* @param Frames			frames of delay.
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay (Frames)", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Retriggerable Delay (Frames)"))
		static void RetriggerableDelayFrames(UObject* WorldContextObject, int32 Frames, FLatentActionInfo LatentInfo);

	/**
	* Perform a latent action with a random delay (specified in frames).  Calling again while it is counting down will be ignored.
	*
	* @param WorldContext	World context.
	* @param MinFrames		minimum frames of delay.
	* @param MaxFrames 		maximum frames of delay.
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay (Frames)", meta = (DeprecatedFunction, DeprecationMessage = "Use a [Delay (Frames)] with a [Random Integer In Range] instead.", Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinFrames = "10", MaxFrames = "30", DisplayName = "Random Delay (Frames)"))
		static void	RandomDelayFrames(UObject* WorldContextObject, int32 MinFrames, int32 MaxFrames, FLatentActionInfo LatentInfo);

	/**
	* Perform a latent action with a retriggerable random delay (specified in frames).  Calling again while it is counting down will reset the countdown to a new random Frames.
	*
	* @param WorldContext	World context.
	* @param MinFrames	 	minimum frames of delay.
	* @param MaxFrames	 	maximum frames of delay.
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay (Frames)", meta = (DeprecatedFunction, DeprecationMessage = "Use a [Retriggerable Delay (Frames)] with a [Random Integer In Range] instead.", Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinFrames = "10", MaxFrames = "30", DisplayName = "Retriggerable Random Delay (Frames)"))
		static void RetriggerableRandomDelayFrames(UObject* WorldContextObject, int32 MinFrames, int32 MaxFrames, FLatentActionInfo LatentInfo);



	/**
	* Queues up executions, will run a pending execution when Next() is called.
	*
	* @param WorldContext	World context.
	* @param Queue 			the queue in which the executions are stored.
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Execution Queue", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Queue"))
		static void	QueueExecutions(UObject* WorldContextObject, ULowEntryExecutionQueue*& Queue, FLatentActionInfo LatentInfo);

	/**
	* Runs a pending execution (if any). 
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Execution Queue", meta = (DisplayName = "Next"))
		static void	NextQueueExecution(ULowEntryExecutionQueue* Queue);



	/**
	* Creates a String of the given length.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Create String"))
		static FString CreateString(const int32 Length, const FString& Filler = TEXT(" "));



	/**
	* Removes all characters except the characters chosen to keep.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Remove Characters"))
		static FString RemoveCharactersExcept(const FString& String, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep);

	/**
	* Replaces all characters with the given replacement character except the characters chosen to keep.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Replace Characters"))
		static FString ReplaceCharactersExcept(const FString& String, const FString& ReplacementCharacter, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep);



	/**
	* Returns true if a regex match was found in the given String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Regex Match"))
		static bool RegexMatch(const FString& String, const FString& Pattern);
	
	/**
	* Returns the number of times the regex matched in the given String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Regex Count"))
		static int32 RegexCount(const FString& String, const FString& Pattern);

	/**
	* Returns the begin index, end index and matched string of each regex match (including each capture group of the regex) found in the given String.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Regex Get Matches"))
		static TArray<FLowEntryRegexMatch> RegexGetMatches(const FString& String, const FString& Pattern);

	/**
	* Replaces every regex match with the given replacement String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Regex Replace"))
		static FString RegexReplace(const FString& String, const FString& Pattern, const FString& Replacement);
	


	/**
	* Causes a crash.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (CompactNodeTitle = "- CRASH -", DisplayName = "Crash"))
		static void Crash();



	/**
	* Hosts a game.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Game", meta = (WorldContext = "WorldContextObject", DisplayName = "Host Game"))
		static void HostGame(UObject* WorldContextObject, const FString& Map, const FString& Args, class APlayerController* SpecificPlayer = NULL);

	/**
	* Joins a game.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Game", meta = (WorldContext = "WorldContextObject", DisplayName = "Join Game"))
		static void JoinGame(UObject* WorldContextObject, const FString& ServerAddress, const FString& Args, class APlayerController* SpecificPlayer = NULL);

	/**
	* Changes the map of the server, and with that, everyone that is playing on the server. 
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Game", meta = (WorldContext = "WorldContextObject", DisplayName = "Change Map (Server)"))
		static void ServerChangeMap(UObject* WorldContextObject, const FString& Map, const FString& Args, class APlayerController* SpecificPlayer = NULL);

	/**
	* Changes the map.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Game", meta = (WorldContext = "WorldContextObject", DisplayName = "Change Map"))
		static void ChangeMap(UObject* WorldContextObject, const FString& Map, const FString& Args, class APlayerController* SpecificPlayer = NULL);



	/**
	* Ticks for x times, with x frames interval between each tick.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Tick (Frames Interval)", Keywords = "loop timer loop delay"))
		static void TickFrames(UObject* WorldContextObject, FLatentActionInfo LatentInfo, const int32 Ticks, const int32 FramesInterval, int32& Tick);

	/**
	* Ticks for x times, with x seconds interval between each tick.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Tick (Seconds Interval)", Keywords = "loop timer loop delay"))
		static void TickSeconds(UObject* WorldContextObject, FLatentActionInfo LatentInfo, const int32 Ticks, const float SecondsInterval, int32& Tick);



	/**
	* Creates a new Byte Data Reader.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Reader", Meta = (DisplayName = "Create Byte Data Reader", AdvancedDisplay = "1"))
		static ULowEntryByteDataReader* ByteDataReader_Create(const TArray<uint8>& Bytes, int32 Index = 0, int32 Length = 0x7FFFFFFF);



	/**
	* Creates a new Byte Data Writer.
	*/
	/*UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Create Byte Data Writer"))*/
	static ULowEntryByteDataWriter* ByteDataWriter_Create();

	/**
	* Creates a new Byte Data Writer.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Create Byte Data Writer (Byte Data Entry Array) (Non-Pure)"))
		static ULowEntryByteDataWriter* ByteDataWriter_CreateFromEntryArray(const TArray<ULowEntryByteDataEntry*>& Array);

	/**
	* Creates a new Byte Data Writer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Create Byte Data Writer (Byte Data Entry Array) (Pure)"))
		static ULowEntryByteDataWriter* ByteDataWriter_CreateFromEntryArrayPure(const TArray<ULowEntryByteDataEntry*>& Array);

	/**
	* Returns the byte data.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Get Bytes"))
		static TArray<uint8> ByteDataWriter_GetBytes(ULowEntryByteDataWriter* ByteDataWriter);



	/**
	* Creates a new Byte Data Entry with the value of a byte.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Byte"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromByte(const uint8 Value);

	/**
	* Creates a new Byte Data Entry with the value of an integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Integer"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromInteger(const int32 Value);

	/**
	* Creates a new Byte Data Entry with the value of a positive integer.
	*
	* Will store values below 128 in 1 byte, higher values will be stored in 4 bytes.
	*
	* The given integer has to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Positive Integer 1"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromPositiveInteger1(const int32 Value);

	/**
	* Creates a new Byte Data Entry with the value of a positive integer.
	*
	* Will store values below 32.768 in 2 bytes, higher values will be stored in 4 bytes.
	*
	* The given integer has to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Positive Integer 2"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromPositiveInteger2(const int32 Value);

	/**
	* Creates a new Byte Data Entry with the value of a positive integer.
	*
	* Will store values below 8.388.608 in 3 bytes, higher values will be stored in 4 bytes.
	*
	* The given integer has to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Positive Integer 3"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromPositiveInteger3(const int32 Value);

	/**
	* Creates a new Byte Data Entry with the value of a long (bytes).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Long (bytes)"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromLongBytes(ULowEntryLong* Value);


	/**
	* Creates a new Byte Data Entry with the value of a float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Float"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromFloat(const float Value);

	/**
	* Creates a new Byte Data Entry with the value of a double (bytes).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Double (bytes)"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromDoubleBytes(ULowEntryDouble* Value);


	/**
	* Creates a new Byte Data Entry with the value of a boolean.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Boolean"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromBoolean(const bool Value);

	/**
	* Creates a new Byte Data Entry with the value of a String (UTF-8).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "String (Utf 8)"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromStringUtf8(const FString& Value);



	/**
	* Creates a new Byte Data Entry with the value of a byte array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Byte Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromByteArray(const TArray<uint8>& Value);

	/**
	* Creates a new Byte Data Entry with the value of an integer array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Integer Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromIntegerArray(const TArray<int32>& Value);

	/**
	* Creates a new Byte Data Entry with the value of a positive integer array.
	*
	* Will store values below 128 in 1 byte, higher values will be stored in 4 bytes.
	*
	* The given integers have to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Positive Integer 1 Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromPositiveInteger1Array(const TArray<int32>& Value);

	/**
	* Creates a new Byte Data Entry with the value of a positive integer array.
	*
	* Will store values below 32.768 in 2 bytes, higher values will be stored in 4 bytes.
	*
	* The given integers have to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Positive Integer 2 Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromPositiveInteger2Array(const TArray<int32>& Value);

	/**
	* Creates a new Byte Data Entry with the value of a positive integer array.
	*
	* Will store values below 8.388.608 in 3 bytes, higher values will be stored in 4 bytes.
	*
	* The given integers have to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Positive Integer 3 Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromPositiveInteger3Array(const TArray<int32>& Value);

	/**
	* Creates a new Byte Data Entry with the value of a long (bytes) array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Long (bytes) Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromLongBytesArray(const TArray<ULowEntryLong*>& Value);


	/**
	* Creates a new Byte Data Entry with the value of a float array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Float Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromFloatArray(const TArray<float>& Value);

	/**
	* Creates a new Byte Data Entry with the value of a double (bytes) array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Double (bytes) Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromDoubleBytesArray(const TArray<ULowEntryDouble*>& Value);


	/**
	* Creates a new Byte Data Entry with the value of a boolean array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "Boolean Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromBooleanArray(const TArray<bool>& Value);

	/**
	* Creates a new Byte Data Entry with the value of a String (UTF-8) array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Byte Data|Entry", Meta = (DisplayName = "String (Utf 8) Array"))
		static ULowEntryByteDataEntry* ByteDataEntry_CreateFromStringUtf8Array(const TArray<FString>& Value);



	/**
	* Creates a new Bit Data Reader.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Reader", Meta = (DisplayName = "Create Bit Data Reader", AdvancedDisplay = "1"))
		static ULowEntryBitDataReader* BitDataReader_Create(const TArray<uint8>& Bytes, int32 Index = 0, int32 Length = 0x7FFFFFFF);



	/**
	* Creates a new Bit Data Writer.
	*
	* This is basically a Byte Data Writer, except that it adds certain methods, like methods to add individual bits, and methods to only add a certain number of bits of a given byte or integer.
	*
	* Booleans are also always stored in 1 bit with a Bit Data Writer, with a Byte Data Writer it will take 1 full byte to store a boolean.
	*
	* This allows you to create smaller results than you can with the Byte Data Writer, but it costs a little bit more processing power to write data with the Bit Data Writer, and it also costs a little bit more processing power to read data with the Bit Data Reader.
	*/
	/*UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Create Bit Data Writer"))*/
	static ULowEntryBitDataWriter* BitDataWriter_Create();

	/**
	* Creates a new Bit Data Writer.
	*
	* This is basically a Byte Data Writer, except that it adds certain methods, like methods to add individual bits, and methods to only add a certain number of bits of a given byte or integer.
	*
	* Booleans are also always stored in 1 bit with a Bit Data Writer, with a Byte Data Writer it will take 1 full byte to store a boolean.
	*
	* This allows you to create smaller results than you can with the Byte Data Writer, but it costs a little bit more processing power to write data with the Bit Data Writer, and it also costs a little bit more processing power to read data with the Bit Data Reader.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Create Bit Data Writer (Bit Data Entry Array) (Non-Pure)"))
		static ULowEntryBitDataWriter* BitDataWriter_CreateFromEntryArray(const TArray<ULowEntryBitDataEntry*>& Array);

	/**
	* Creates a new Bit Data Writer.
	*
	* This is basically a Byte Data Writer, except that it adds certain methods, like methods to add individual bits, and methods to only add a certain number of bits of a given byte or integer.
	*
	* Booleans are also always stored in 1 bit with a Bit Data Writer, with a Byte Data Writer it will take 1 full byte to store a boolean.
	*
	* This allows you to create smaller results than you can with the Byte Data Writer, but it costs a little bit more processing power to write data with the Bit Data Writer, and it also costs a little bit more processing power to read data with the Bit Data Reader.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Create Bit Data Writer (Bit Data Entry Array) (Pure)"))
		static ULowEntryBitDataWriter* BitDataWriter_CreateFromEntryArrayPure(const TArray<ULowEntryBitDataEntry*>& Array);

	/**
	* Returns the byte data.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Writer", Meta = (DisplayName = "Get Bytes"))
		static TArray<uint8> BitDataWriter_GetBytes(ULowEntryBitDataWriter* BitDataWriter);



	/**
	* Creates a new Bit Data Entry with the value of a bit.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Bit"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromBit(const bool Value);

	/**
	* Creates a new Bit Data Entry with the value of a byte, will only add a certain amount of bits from the given byte.
	*
	* For example, take 63 as the value (bitwise this is: 0011 1111).
	* If you use this blueprint with value 63 and bitcount 4, only the lowest 4 bits will be added, meaning only 1111 will be added, which will then have a value of 15 when read again.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Byte (Least Significant Bits Only)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromByteLeastSignificantBits(const uint8 Value, const int32 BitCount);

	/**
	* Creates a new Bit Data Entry with the value of a byte, will only add a certain amount of bits from the given byte.
	*
	* For example, take 63 as the value (bitwise this is: 0011 1111).
	* If you use this blueprint with value 63 and bitcount 4, only the highest 4 bits will be added, meaning only 0011 will be added, which will then have a value of 48 when read again.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Byte (Most Significant Bits Only)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromByteMostSignificantBits(const uint8 Value, const int32 BitCount);

	/**
	* Creates a new Bit Data Entry with the value of an integer, will only add a certain amount of bits from the given integer.
	*
	* For example, take 268435471 as the value (bitwise this is: 00010000 00000000 00000000 00001111).
	* If you use this blueprint with value 268435471 and bitcount 4, only the lowest 4 bits will be added, meaning only 1111 will be added, which will then have a value of 15 when read again.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Integer (Least Significant Bits Only)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromIntegerLeastSignificantBits(const int32 Value, const int32 BitCount);

	/**
	* Creates a new Bit Data Entry with the value of an integer, will only add a certain amount of bits from the given integer.
	*
	* For example, take 268435471 as the value (bitwise this is: 00010000 00000000 00000000 00001111).
	* If you use this blueprint with value 268435471 and bitcount 4, only the highest 4 bits will be added, meaning only 0001 will be added, which will then have a value of 268435456 when read again.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Integer (Most Significant Bits Only)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromIntegerMostSignificantBits(const int32 Value, const int32 BitCount);

	/**
	* Creates a new Bit Data Entry with the value of a byte.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Byte"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromByte(const uint8 Value);

	/**
	* Creates a new Bit Data Entry with the value of an integer.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Integer"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromInteger(const int32 Value);

	/**
	* Creates a new Bit Data Entry with the value of a positive integer.
	*
	* Will store values below 128 in 1 byte, higher values will be stored in 4 bytes.
	*
	* The given integer has to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Positive Integer 1"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromPositiveInteger1(const int32 Value);

	/**
	* Creates a new Bit Data Entry with the value of a positive integer.
	*
	* Will store values below 32.768 in 2 bytes, higher values will be stored in 4 bytes.
	*
	* The given integer has to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Positive Integer 2"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromPositiveInteger2(const int32 Value);

	/**
	* Creates a new Bit Data Entry with the value of a positive integer.
	*
	* Will store values below 8.388.608 in 3 bytes, higher values will be stored in 4 bytes.
	*
	* The given integer has to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Positive Integer 3"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromPositiveInteger3(const int32 Value);

	/**
	* Creates a new Bit Data Entry with the value of a long (bytes).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Long (bytes)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromLongBytes(ULowEntryLong* Value);


	/**
	* Creates a new Bit Data Entry with the value of a float.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Float"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromFloat(const float Value);

	/**
	* Creates a new Bit Data Entry with the value of a double (bytes).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Double (bytes)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromDoubleBytes(ULowEntryDouble* Value);


	/**
	* Creates a new Bit Data Entry with the value of a boolean, this does the same as a Bit Data Entry with the value of a bit.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Boolean"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromBoolean(const bool Value);

	/**
	* Creates a new Bit Data Entry with the value of a String (UTF-8).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "String (Utf 8)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromStringUtf8(const FString& Value);



	/**
	* Creates a new Bit Data Entry with the value of a bit array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Bit Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromBitArray(const TArray<bool>& Value);

	/**
	* Creates a new Bit Data Entry with the value of a byte array, will only add a certain amount of bits from every given byte.
	*
	* For example, take 63 as the value (bitwise this is: 0011 1111).
	* If you use this blueprint with value [63, 63, 63] and bitcount 4, only the lowest 4 bits of each byte will be added, meaning only 1111 1111 1111 will be added, which will then have a value of 15 for each byte when read again.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Add Byte Array (Least Significant Bits Only)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromByteArrayLeastSignificantBits(const TArray<uint8>& Value, const int32 BitCount);

	/**
	* Creates a new Bit Data Entry with the value of a byte array, will only add a certain amount of bits from every given byte.
	*
	* For example, take 63 as the value (bitwise this is: 0011 1111).
	* If you use this blueprint with value [63, 63, 63] and bitcount 4, only the highest 4 bits of each byte will be added, meaning only 0011 0011 0011 will be added, which will then have a value of 48 for each byte when read again.
	*
	* The bitcount can be anything between 0 and 8, values higher or lower will be clamped to 0 to 8.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Add Byte Array (Most Significant Bits Only)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromByteArrayMostSignificantBits(const TArray<uint8>& Value, const int32 BitCount);

	/**
	* Creates a new Bit Data Entry with the value of an integer array, will only add a certain amount of bits from every given integer.
	*
	* For example, take 268435471 as the value (bitwise this is: 00010000 00000000 00000000 00001111).
	* If you use this blueprint with value [268435471, 268435471, 268435471] and bitcount 4, only the lowest 4 bits of each integer will be added, meaning only 1111 1111 1111 will be added, which will then have a value of 15 for each integer when read again.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Add Integer Array (Least Significant Bits Only)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromIntegerArrayLeastSignificantBits(const TArray<int32>& Value, const int32 BitCount);

	/**
	* Creates a new Bit Data Entry with the value of an integer array, will only add a certain amount of bits from every given integer.
	*
	* For example, take 268435471 as the value (bitwise this is: 00010000 00000000 00000000 00001111).
	* If you use this blueprint with value [268435471, 268435471, 268435471] and bitcount 4, only the highest 4 bits of each integer will be added, meaning only 0001 0001 0001 will be added, which will then have a value of 268435456 for each integer when read again.
	*
	* The bitcount can be anything between 0 and 32, values higher or lower will be clamped to 0 to 32.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Add Integer Array (Most Significant Bits Only)"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromIntegerArrayMostSignificantBits(const TArray<int32>& Value, const int32 BitCount);

	/**
	* Creates a new Bit Data Entry with the value of a byte array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Byte Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromByteArray(const TArray<uint8>& Value);

	/**
	* Creates a new Bit Data Entry with the value of an integer array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Integer Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromIntegerArray(const TArray<int32>& Value);

	/**
	* Creates a new Bit Data Entry with the value of a positive integer array.
	*
	* Will store values below 128 in 1 byte, higher values will be stored in 4 bytes.
	*
	* The given integers have to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Positive Integer 1 Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromPositiveInteger1Array(const TArray<int32>& Value);

	/**
	* Creates a new Bit Data Entry with the value of a positive integer array.
	*
	* Will store values below 32.768 in 2 bytes, higher values will be stored in 4 bytes.
	*
	* The given integers have to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Positive Integer 2 Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromPositiveInteger2Array(const TArray<int32>& Value);

	/**
	* Creates a new Bit Data Entry with the value of a positive integer array.
	*
	* Will store values below 8.388.608 in 3 bytes, higher values will be stored in 4 bytes.
	*
	* The given integers have to be 0 or higher, values under 0 will be changed to 0.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Positive Integer 3 Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromPositiveInteger3Array(const TArray<int32>& Value);

	/**
	* Creates a new Bit Data Entry with the value of a long (bytes) array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Long (bytes) Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromLongBytesArray(const TArray<ULowEntryLong*>& Value);


	/**
	* Creates a new Bit Data Entry with the value of a float array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Float Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromFloatArray(const TArray<float>& Value);

	/**
	* Creates a new Bit Data Entry with the value of a double (bytes) array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Double (bytes) Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromDoubleBytesArray(const TArray<ULowEntryDouble*>& Value);


	/**
	* Creates a new Bit Data Entry with the value of a boolean array, this does the same as a Bit Data Entry with the value of a bit array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "Boolean Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromBooleanArray(const TArray<bool>& Value);

	/**
	* Creates a new Bit Data Entry with the value of a String (UTF-8) array.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Bit Data|Entry", Meta = (DisplayName = "String (Utf 8) Array"))
		static ULowEntryBitDataEntry* BitDataEntry_CreateFromStringUtf8Array(const TArray<FString>& Value);



	/**
	* Creates a new long (bytes), a long is always 8 bytes.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Create Long (bytes) (Value of 0)"))
		static ULowEntryLong* Long_CreateZero();

	/**
	* Creates a new long (bytes), a long is always 8 bytes (give less bytes and it will pad with 0, give more bytes and it will only take the first 8).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Long (bytes)", Meta = (DisplayName = "Create Long (bytes)", AdvancedDisplay = "1"))
		static ULowEntryLong* Long_Create(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);

	/**
	* Creates a new double (bytes), a double is always 8 bytes.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Create Double (bytes) (Value of 0)"))
		static ULowEntryDouble* Double_CreateZero();

	/**
	* Creates a new double (bytes), a double is always 8 bytes (give less bytes and it will pad with 0, give more bytes and it will only take the first 8).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Types|Double (bytes)", Meta = (DisplayName = "Create Double (bytes)", AdvancedDisplay = "1"))
		static ULowEntryDouble* Double_Create(const TArray<uint8>& ByteArray, int32 Index = 0, int32 Length = 0x7FFFFFFF);



	/**
	* Sets the mouse position (relative to the viewport).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Mouse", Meta = (DisplayName = "Set Mouse Position"))
		static void SetMousePosition(const int32 X, const int32 Y);

	/**
	* Returns the mouse position (relative to the viewport), from 0 to the viewport width or height.
	* 
	* Returns Success=false, X=0 and Y=0 if the mouse position could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Viewport is null
	*  - the mouse is outside of the viewport
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Mouse", Meta = (DisplayName = "Get Mouse Position"))
		static void GetMousePosition(bool& Success, int32& X, int32& Y);


	/**
	* Sets the mouse position (relative to the viewport) in percentages, from 0.0 to 1.0.
	* 
	* X:  0.0 is left, 1.0 is right
	* Y:  0.0 is top,  1.0 is bottom
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Mouse", Meta = (DisplayName = "Set Mouse Position (Percentages)"))
		static void SetMousePositionInPercentages(const float X, const float Y);

	/**
	* Returns the mouse position (relative to the viewport) in percentages, from 0.0 to 1.0.
	* 
	* X:  0.0 is left, 1.0 is right
	* Y:  0.0 is top,  1.0 is bottom
	*
	* Returns Success=false, X=0.0 and Y=0.0 if the mouse position could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Viewport is null
	*  - the mouse is outside of the viewport
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Mouse", Meta = (DisplayName = "Get Mouse Position (Percentages)"))
		static void GetMousePositionInPercentages(bool& Success, float& X, float& Y);


	/**
	* Sets the mouse locked to the viewport (meaning the mouse cursor won't be able to get out of the viewport).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Mouse", Meta = (DisplayName = "Set Mouse Locked To Viewport", Keywords = "cursor confined min max"))
		static void SetMouseLockedToViewport(const bool Locked);



	/**
	* Returns the primary monitor resolution.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Monitor", Meta = (DisplayName = "Get Primary Monitor Resolution", Keywords = "screen size desktop"))
		static void GetPrimaryMonitorResolution(int32& Width, int32& Height);

	/**
	* Returns the primary monitor work area, this is the area not covered by task bars or other docked widgets.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Monitor", Meta = (DisplayName = "Get Primary Monitor Work Area", Keywords = "screen size desktop"))
		static void GetPrimaryMonitorWorkArea(int32& X, int32& Y, int32& Width, int32& Height);



	/**
	* Returns the windows bounds in screen space.
	*
	* Returns Success=false, X=0, Y=0, Width=0 and Height=0 if the window bounds could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Get Window Bounds", Keywords = "size location position"))
		static void GetWindowBounds(bool& Success, int32& X, int32& Y, int32& Width, int32& Height);

	/**
	* Gets the window position in screen space.
	*
	* Returns Success=false, X=0 and Y=0 if the window bounds could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Get Window Position"))
		static void GetWindowPosition(bool& Success, int32& X, int32& Y);

	/**
	* Gets the window size in screen pixels.
	*
	* Returns Success=false, Width=0 and Height=0 if the window bounds could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Get Window Size"))
		static void GetWindowSize(bool& Success, int32& Width, int32& Height);

	/**
	* Gets the window position in screen space in percentages, relative to the primary monitor work area, from 0.0 to 1.0.
	*
	* This will take the window size in account, meaning that X=0.5 and Y=0.5 will cause the window to be centered in the primary screen work area.
	*
	* Returns Success=false, X=0.0 and Y=0.0 if the window bounds could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Get Window Position (Percentages)"))
		static void GetWindowPositiomInPercentagesCentered(bool& Success, float& X, float& Y);


	/**
	* Sets the window position in screen space.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Set Window Position"))
		static void SetWindowPosition(const int32 X, const int32 Y);

	/**
	* Sets the window size in screen pixels.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Set Window Size"))
		static void SetWindowSize(const int32 Width, const int32 Height);

	/**
	* Sets the window position in screen space in percentages, relative to the primary monitor work area, from 0.0 to 1.0.
	* 
	* This will take the window size in account, meaning that X=0.5 and Y=0.5 will cause the window to be centered in the primary screen work area.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Set Window Position (Percentages)"))
		static void SetWindowPositiomInPercentagesCentered(const float X, const float Y);



	/**
	* Gets the window border size.
	* Useful for when you want to set the window's position while still showing the border as well.
	*
	* Returns Success=false if the window bounds could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Get Window Border Size", Keywords = "margin padding"))
		static void GetWindowBorderSize(bool& Success, FMargin& Margin);



	/**
	* Returns the window mode. 
	* 
	* If Fullscreen is false then IsFullscreenWindowed will also be false.
	* 
	* Returns Success=false, Fullscreen=false and Windowed=false if the window mode could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*  - The mode is pseudo-fullscreen (used for devices like HMDs)
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Get Window Mode", Keywords = "screen fullscreen windowed"))
		static void GetWindowMode(bool& Success, bool& Fullscreen, bool& IsFullscreenWindowed);

	/**
	* Sets the window mode.
	* 
	* If Fullscreen is false, it will be windowed.
	* If Fullscreen is true and IsFullscreenWindowed is false, it will be fullscreen.
	* If Fullscreen is true and IsFullscreenWindowed is true, it will be windowed fullscreen.
	* 
	* IsFullscreenWindowed is only used when Fullscreen is true.
	* 
	* Fullscreen and Windowed can both be true.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Window", Meta = (DisplayName = "Set Window Mode", Keywords = "screen fullscreen windowed"))
		static void SetWindowMode(const bool Fullscreen, const bool IsFullscreenWindowed);



	/**
	* Enables or disables split screen.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Viewport", Meta = (DisplayName = "Set Split Screen Enabled", Keywords = "screen split multiplayer mode"))
		static void SetSplitScreenEnabled(const bool Enabled);

	/**
	* Get the current split screen type, note that this value also depends on the number of players that are currently in the game.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Viewport", Meta = (DisplayName = "Get Split Screen Type", Keywords = "screen split multiplayer mode"))
		static void GetSplitScreenType(ELowEntrySplitScreenType& Type);

	/**
	* Set the split screen type (for 2 players).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Viewport", Meta = (DisplayName = "Set Split Screen Type (2 players)", Keywords = "screen split multiplayer mode"))
		static void SetSplitScreenType_TwoPlayers(const ELowEntrySplitScreenTypeTwoPlayers Type);

	/**
	* Set the split screen type (for 3 players).
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Viewport", Meta = (DisplayName = "Set Split Screen Type (3 players)", Keywords = "screen split multiplayer mode"))
		static void SetSplitScreenType_ThreePlayers(const ELowEntrySplitScreenTypeThreePlayers Type);



	/**
	* Retrieves whether world rendering is enabled.
	* 
	* Returns Success=false and Enabled=false if the world rendering enabled value could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Viewport", Meta = (DisplayName = "Is World Rendering Enabled", Keywords = "disable game 3d view get"))
		static void IsWorldRenderingEnabled(bool& Success, bool& Enabled);

	/**
	* Causes the world rendering to be enabled or disabled.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Viewport", Meta = (DisplayName = "Set World Rendering Enabled", Keywords = "disable game 3d view"))
		static void SetWorldRenderingEnabled(const bool Enabled);



	/**
	* Retrieves and returns the clipboard's content.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Clipboard", Meta = (DisplayName = "Clipboard Get", Keywords = "paste retrieve obtain access"))
		static FString ClipboardGet();

	/**
	* Sets the given string as the clipboard's content.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Clipboard", Meta = (DisplayName = "Clipboard Set", Keywords = "copy put place"))
		static void ClipboardSet(const FString& Value);



	/**
	* Finds a class.
	* 
	* The given ClassName has to be a specific path to your class/object, for example: /Game/Blueprints/GameMode.GameMode_C
	* 
	* Note that you have to append _C to the end of your ClassName, as is done in the example.
	* Note that is also always has to start with /Game/, no matter what the path to your class is.
	* 
	* The easiest way to get the correct ClassName is by right clicking your class/object in the content browser and by then clicking on 'Copy Reference', then you'll just have to remove the 'Blueprint' and the quotes and add the _C at the end of it.
	* So this: Blueprint'/Game/Blueprints/PlayerController.PlayerController'
	* Would turn into this: /Game/Blueprints/PlayerController.PlayerController_C
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Get Class With Name", Keywords = "get retrieve create object path find by value"))
		static void GetClassWithName(const FString& ClassName, UClass*& Class_, bool& Success);



	/**
	* Divides A by B.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Math", Meta = (DisplayName = "vector2d / vector2d", Keywords = "divide vector2d", CompactNodeTitle = "/"))
		static FVector2D Divide_Vector2dVector2d(const FVector2D& A, const FVector2D& B);



	/**
	* Returns the absolute size of the given Geometry.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Widgets", Meta = (DisplayName = "Get Absolute Size"))
		static FVector2D GetAbsoluteSize(const FGeometry& Geometry);

	/**
	* Returns the scale of the given Geometry from Local to Absolute (Absolute Size divided by Local Size).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Widgets", Meta = (DisplayName = "Get Local To Absolute Scale"))
		static FVector2D GetLocalToAbsoluteScale(const FGeometry& Geometry);

	/**
	* Returns the scale of the given Geometry from Absolute to Local (Local Size divided by Absolute Size).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Widgets", Meta = (DisplayName = "Get Absolute To Local Scale"))
		static FVector2D GetAbsoluteToLocalScale(const FGeometry& Geometry);



	/**
	* Clears widget focus.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Widgets", Meta = (DisplayName = "Clear All User Focus", Keywords = "reset"))
		static void ClearAllUserFocus();

	/**
	* Clears widget focus.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Widgets", Meta = (DisplayName = "Clear User Focus", Keywords = "reset"))
		static void ClearUserFocus(const int32 UserIndex);

	/**
	* Clears widget focus.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Widgets", Meta = (DisplayName = "Clear Keyboard Focus", Keywords = "reset"))
		static void ClearKeyboardFocus();

	/**
	* Clears widget focus.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Widgets", Meta = (DisplayName = "Get User Focused Widget Type"))
		static FName GetUserFocusedWidgetType(const int32 UserIndex);

	/**
	* Clears widget focus.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Widgets", Meta = (DisplayName = "Get Keyboard Focused Widget Type"))
		static FName GetKeyboardFocusedWidgetType();



	/**
	* Returns a boolean depending on which exec pin has been executed.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Exec To Boolean", ExpandEnumAsExecs = "Branch"))
		static void ExecToBoolean(const ELowEntryExtendedStandardLibraryTrueOrFalse Branch, bool& Value);

	/**
	* Returns an integer depending on which exec pin has been executed.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Exec To Integer", ExpandEnumAsExecs = "Branch"))
		static void ExecToInteger(const ELowEntryExtendedStandardLibrary0to9 Branch, int32& Value);

	/**
	* Returns a byte depending on which exec pin has been executed.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Exec To Byte", ExpandEnumAsExecs = "Branch"))
		static void ExecToByte(const ELowEntryExtendedStandardLibrary0to9 Branch, uint8& Value);



	/**
	* Executes a the pin of the matching value.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Case Switch Integer", ExpandEnumAsExecs = "Branch"))
		static void CaseSwitchInteger(const int32 OnlyCheckFirstX, const int32 Value, const int32 _1__, const int32 _2__, const int32 _3__, const int32 _4__, const int32 _5__, const int32 _6__, const int32 _7__, const int32 _8__, const int32 _9__, const int32 _10__, ELowEntryExtendedStandardLibrary1to10other& Branch);

	/**
	* Executes a the pin of the matching value.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Case Switch Byte", ExpandEnumAsExecs = "Branch"))
		static void CaseSwitchByte(const int32 OnlyCheckFirstX, const uint8 Value, const uint8 _1__, const uint8 _2__, const uint8 _3__, const uint8 _4__, const uint8 _5__, const uint8 _6__, const uint8 _7__, const uint8 _8__, const uint8 _9__, const uint8 _10__, ELowEntryExtendedStandardLibrary1to10other& Branch);

	/**
	* Executes a the pin of the matching value.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Case Switch Object", ExpandEnumAsExecs = "Branch"))
		static void CaseSwitchObject(const int32 OnlyCheckFirstX, const UObject* Value, const UObject* _1__, const UObject* _2__, const UObject* _3__, const UObject* _4__, const UObject* _5__, const UObject* _6__, const UObject* _7__, const UObject* _8__, const UObject* _9__, const UObject* _10__, ELowEntryExtendedStandardLibrary1to10other& Branch);



	/**
	* Returns the LocalPlayer from the given PlayerController.
	*
	* Fails if the PlayerController isn't owned by a LocalPlayer (but by a networked player instead).
	*
	* Description of a LocalPlayer: Each player that is active on the current client has a LocalPlayer. It stays active across maps There may be several spawned in the case of splitscreen/coop. There may be 0 spawned on servers. See http://api.unrealengine.com/INT/API/Runtime/Engine/Engine/ULocalPlayer/index.html
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Gameplay", Meta = (DisplayName = "Get Local Player"))
		static void PlayerControllerGetLocalPlayer(APlayerController* PlayerController, bool& Success, ULocalPlayer*& LocalPlayer);



	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Internal", Meta = (BlueprintInternalUseOnly = "true", DisplayName = "Kismet Print"))
		static void SimpleKismetSystemLibraryPrintString(const FString& InString);

	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Internal", Meta = (BlueprintInternalUseOnly = "true", DisplayName = "Encapsulate Byte Array"))
		static ULowEntryByteArray* EncapsulateByteArray(const TArray<uint8>& ByteArray);

	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Internal", Meta = (BlueprintInternalUseOnly = "true", DisplayName = "Merge Encapsulated Byte Arrays"))
		static TArray<uint8> MergeEncapsulatedByteArrays(const TArray<ULowEntryByteArray*>& ByteArrays);
};
