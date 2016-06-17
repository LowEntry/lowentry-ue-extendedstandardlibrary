#pragma once


#include "Engine.h"
#include "Core.h"
#include "CoreUObject.h"
#include "Base64.h"
#include "DelayAction.h"
#include "Engine/LatentActionManager.h"
#include "Regex.h"

#include "FLowEntryRegexMatch.h"

#include "Interfaces/IImageWrapper.h"
#include "Interfaces/IImageWrapperModule.h"

#include "ELowEntryBatteryState.h"

#include "ELowEntryImageFormat.h"
#include "ELowEntryRGBFormat.h"

#include "IMediaModule.h"
#include "IMediaPlayer.h"
#include "MediaPlayer.h"
#include "MediaTexture.h"
#include "MediaSoundWave.h"

#include "LowEntryExtendedStandardLibrary.generated.h"


class ULowEntryLatentActionBoolean;
class ULowEntryLatentActionFloat;
class ULowEntryLatentActionInteger;
class ULowEntryLatentActionNone;
class ULowEntryLatentActionObject;
class ULowEntryLatentActionString;

class ULowEntryByteArray;

class ULowEntryByteDataEntry;
class ULowEntryByteDataReader;
class ULowEntryByteDataWriter;

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
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Debug Build", Keywords = "compile export mode version type"))
		static bool DebugBuild();

	/**
	* Returns true if this is a debug build (UE_BUILD_DEVELOPMENT), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Development Build", Keywords = "compile export mode version type"))
		static bool DevelopmentBuild();

	/**
	* Returns true if this is a debug build (UE_BUILD_TEST), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Test Build", Keywords = "compile export mode version type"))
		static bool TestBuild();

	/**
	* Returns true if this is a debug build (UE_BUILD_SHIPPING), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Build", Meta = (DisplayName = "Is Shipping Build", Keywords = "compile export mode version type"))
		static bool ShippingBuild();



	/**
	* Returns true if this is the Html5 platform (PLATFORM_HTML5), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Html5 Platform", Keywords = "compile export mode version type"))
		static bool Html5Platform();

	/**
	* Returns true if this is the Windows platform (PLATFORM_WINDOWS), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Windows Platform", Keywords = "compile export mode version type"))
		static bool WindowsPlatform();

	/**
	* Returns true if this is the Windows RT platform (PLATFORM_WINRT), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Windows Rt Platform", Keywords = "compile export mode version type"))
		static bool WindowsRtPlatform();

	/**
	* Returns true if this is the Windows RT ARM platform (PLATFORM_WINRT_ARM), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Windows Rt Arm Platform", Keywords = "compile export mode version type"))
		static bool WindowsRtArmPlatform();

	/**
	* Returns true if this is the Linux platform (PLATFORM_LINUX), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Linux Platform", Keywords = "compile export mode version type"))
		static bool LinuxPlatform();

	/**
	* Returns true if this is the Mac platform (PLATFORM_MAC), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Mac Platform", Keywords = "compile export mode version type"))
		static bool MacPlatform();

	/**
	* Returns true if this is the PS4 platform (PLATFORM_PS4), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Ps4 Platform", Keywords = "compile export mode version type"))
		static bool Ps4Platform();

	/**
	* Returns true if this is the Xbox One platform (PLATFORM_XBOXONE), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Xbox One Platform", Keywords = "compile export mode version type"))
		static bool XboxOnePlatform();

	/**
	* Returns true if this is the Android platform (PLATFORM_ANDROID), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Android Platform", Keywords = "compile export mode version type"))
		static bool AndroidPlatform();

	/**
	* Returns true if this is the IOS platform (PLATFORM_IOS), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Ios Platform", Keywords = "compile export mode version type"))
		static bool IosPlatform();

	/**
	* Returns true if this is a desktop (PLATFORM_DESKTOP), returns false otherwise.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Platform", Meta = (DisplayName = "Is Desktop", Keywords = "compile export mode version type"))
		static bool DesktopPlatform();



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
	* Returns the system volume.
	*
	* Currently only works on Android devices (only on 4.10+).
	* 
	* Note: This blueprint is not used to retrieve or change the sound volume in-game, you will have to use Sound Classes for that.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Get System Volume", Keywords = "current sound audio android"))
		static void GetCurrentVolume(int32& Volume, bool& Success);



	/**
	* Returns an instance from the given Class.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Other", Meta = (DisplayName = "Create Object", Keywords = "make instance"))
		static void CreateObject(UClass* Class, UObject*& Object);



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
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Encoding|From Bytes", Meta = (DisplayName = "Bytes To Image", Keywords = "byte array binary", AdvancedDisplay = "2"))
		static UTexture2D* BytesToImage(const TArray<uint8>& ByteArray, const ELowEntryImageFormat ImageFormat, int32 Index = 0, int32 Length = 0x7FFFFFFF);



	/**
	* Loads a video, returns a:
	*  - MediaPlayer (to play/pause/etc the video)
	*  - MediaTexture (to see the video)
	*  - MediaSoundWave (to hear the video)
	* 
	* This blueprint also returns a boolean called Success.
	*  - true: every returned Object is valid
	*  - false: every returned Object is NULL
	* 
	* The URL is either:
	* - a http/https URL, for example "http://public.lowentry.com/files/test_data/TestVideoMp4.mp4"
	* - a filepath URL of a video located in "YourProject/Content/Movies/" formatted like "./Movies/YourVideo.mp4"
	* 
	* Some tips:
	* - only MP4 can be played on every platform, so it's best to only use MP4 videos for now
	* - don't forget to call Play on the MediaPlayer, otherwise nothing will happen
	* - don't forget to call Play Sound with the MediaSoundWave, otherwise you won't hear any sound
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|External", Meta = (DisplayName = "Load Video", Keywords = "movie"))
		static void LoadVideo(const FString& Url, bool& Success, UMediaPlayer*& Player, UMediaTexture*& Texture, UMediaSoundWave*& Sound);



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
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Hashes|Generate", Meta = (DisplayName = "Generate Hash (Bcrypt)", AdvancedDisplay = "3"))
		static TArray<uint8> BCrypt(const TArray<uint8>& ByteArray, const TArray<uint8>& Salt, int32 Strength = 10, int32 Index = 0, int32 Length = 0x7FFFFFFF);
	
	
	
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
	*  - in that function, return true if the first Object is smaller than the second Object, return false otherwise
	*  - then, when using the Sort Object Array blueprint, use the Create Event blueprint and set its value as the function created earlier
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|Array", Meta = (DisplayName = "Sort (Object Array) (Copy)"))
		static TArray<UObject*> SortObjectArray(const TArray<UObject*>& ObjectArray, FDelegateULowEntryExtendedStandardLibraryCompareObjects Comparator, const bool Reversed = false);

	/**
	* Sorts the given array.
	*
	* To create the Comparator, do this:
	*  - create a function that has 2 input parameters (Object and Object) and 1 output parameter (Boolean)
	*  - in that function, return true if the first Object is smaller than the second Object, return false otherwise
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
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void	RandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, struct FLatentActionInfo LatentInfo);

	/**
	* Perform a latent action with a retriggerable random delay (specified in seconds).  Calling again while it is counting down will reset the countdown to a new random Duration.
	*
	* @param WorldContext	World context.
	* @param MinDuration 	minimum length of delay (in seconds).
	* @param MaxDuration 	maximum length of delay (in seconds).
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinDuration = "0.2", MaxDuration = "0.5"))
		static void RetriggerableRandomDelay(UObject* WorldContextObject, float MinDuration, float MaxDuration, FLatentActionInfo LatentInfo);



	/**
	* Perform a latent action with a delay (specified in frames).  Calling again while it is counting down will be ignored.
	*
	* @param WorldContext	World context.
	* @param Frames			frames of delay.
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay (Frames)", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Delay (Frames)"))
		static void	DelayFrames(UObject* WorldContextObject, int32 Frames, struct FLatentActionInfo LatentInfo);

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
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay (Frames)", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinFrames = "10", MaxFrames = "30", DisplayName = "Random Delay (Frames)"))
		static void	RandomDelayFrames(UObject* WorldContextObject, int32 MinFrames, int32 MaxFrames, struct FLatentActionInfo LatentInfo);

	/**
	* Perform a latent action with a retriggerable random delay (specified in frames).  Calling again while it is counting down will reset the countdown to a new random Frames.
	*
	* @param WorldContext	World context.
	* @param MinFrames	 	minimum frames of delay.
	* @param MaxFrames	 	maximum frames of delay.
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Delay (Frames)", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", MinFrames = "10", MaxFrames = "30", DisplayName = "Retriggerable Random Delay (Frames)"))
		static void RetriggerableRandomDelayFrames(UObject* WorldContextObject, int32 MinFrames, int32 MaxFrames, FLatentActionInfo LatentInfo);



	/**
	* Queues up executions, will run a pending execution when Next() is called.
	*
	* @param WorldContext	World context.
	* @param Queue 			the queue in which the executions are stored.
	* @param LatentInfo 	The latent action.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Execution Queue", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", DisplayName = "Queue"))
		static void	QueueExecutions(UObject* WorldContextObject, ULowEntryExecutionQueue*& Queue, struct FLatentActionInfo LatentInfo);

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
	* Returns true if the regex was found in the given String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Regex Match"))
		static bool RegexMatch(const FString& String, const FString& Pattern);
	
	/**
	* Returns the number of times the regex was found in the given String.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|Extended Standard Library|Utilities|String", Meta = (DisplayName = "Regex Count"))
		static int32 RegexCount(const FString& String, const FString& Pattern);

	/**
	* Returns the begin index, end index and matched string of each regex found in the given String.
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
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Byte Data|Writer", Meta = (DisplayName = "Create Byte Data Writer (Byte Data Entry Array) (Callable)"))
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
	* Sets the mouse position.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Mouse", Meta = (DisplayName = "Set Mouse Position"))
		static void SetMousePosition(const int32 X, const int32 Y);

	/**
	* Returns the mouse position.
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
	* Sets the mouse position in percentages, from 0.0 to 1.0.
	* 
	* X:  0.0 is left, 1.0 is right
	* Y:  0.0 is top,  1.0 is bottom
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Mouse", Meta = (DisplayName = "Set Mouse Position (Percentages)"))
		static void SetMousePositionInPercentages(const float X, const float Y);

	/**
	* Returns the mouse position in percentages, from 0.0 to 1.0.
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



	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Internal", Meta = (BlueprintInternalUseOnly = "true", DisplayName = "Kismet Print"))
		static void SimpleKismetSystemLibraryPrintString(const FString& InString);

	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Internal", Meta = (BlueprintInternalUseOnly = "true", DisplayName = "Encapsulate Byte Array"))
		static ULowEntryByteArray* EncapsulateByteArray(const TArray<uint8>& ByteArray);

	UFUNCTION(BlueprintCallable, Category = "Low Entry|Extended Standard Library|Utilities|Internal", Meta = (BlueprintInternalUseOnly = "true", DisplayName = "Merge Encapsulated Byte Arrays"))
		static TArray<uint8> MergeEncapsulatedByteArrays(const TArray<ULowEntryByteArray*>& ByteArrays);
};
