// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "IImageWrapper.h"

#include "ELowEntryImageFormat.generated.h"


UENUM(BlueprintType)
enum class ELowEntryImageFormat : uint8
{
	/** Invalid or unrecognized format */
	Invalid,

	/** Portable Network Graphics */
	PNG,

	/** Joint Photographic Experts Group */
	JPEG,

	/** Single channel jpeg */
	GrayscaleJPEG,

	/** Windows Bitmap */
	BMP,

	/** Windows Icon resource */
	ICO,

	/** OpenEXR (HDR) image file format */
	EXR,

	/** Mac icon */
	ICNS
};


static EImageFormat ELowEntryImageFormatToUE4(ELowEntryImageFormat Value)
{
	if(Value == ELowEntryImageFormat::Invalid)
	{
		return EImageFormat::Invalid;
	}
	if(Value == ELowEntryImageFormat::PNG)
	{
		return EImageFormat::PNG;
	}
	if(Value == ELowEntryImageFormat::JPEG)
	{
		return EImageFormat::JPEG;
	}
	if(Value == ELowEntryImageFormat::GrayscaleJPEG)
	{
		return EImageFormat::GrayscaleJPEG;
	}
	if(Value == ELowEntryImageFormat::BMP)
	{
		return EImageFormat::BMP;
	}
	if(Value == ELowEntryImageFormat::ICO)
	{
		return EImageFormat::ICO;
	}
	if(Value == ELowEntryImageFormat::EXR)
	{
		return EImageFormat::EXR;
	}
	if(Value == ELowEntryImageFormat::ICNS)
	{
		return EImageFormat::ICNS;
	}
	return EImageFormat::Invalid;
}

static ELowEntryImageFormat ELowEntryImageFormatFromUE4(EImageFormat Value)
{
	if(Value == EImageFormat::Invalid)
	{
		return ELowEntryImageFormat::Invalid;
	}
	if(Value == EImageFormat::PNG)
	{
		return ELowEntryImageFormat::PNG;
	}
	if(Value == EImageFormat::JPEG)
	{
		return ELowEntryImageFormat::JPEG;
	}
	if(Value == EImageFormat::GrayscaleJPEG)
	{
		return ELowEntryImageFormat::GrayscaleJPEG;
	}
	if(Value == EImageFormat::BMP)
	{
		return ELowEntryImageFormat::BMP;
	}
	if(Value == EImageFormat::ICO)
	{
		return ELowEntryImageFormat::ICO;
	}
	if(Value == EImageFormat::EXR)
	{
		return ELowEntryImageFormat::EXR;
	}
	if(Value == EImageFormat::ICNS)
	{
		return ELowEntryImageFormat::ICNS;
	}
	return ELowEntryImageFormat::Invalid;
}
