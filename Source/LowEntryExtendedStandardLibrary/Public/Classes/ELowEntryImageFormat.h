#pragma once


#include "Engine.h"
#include "Core.h"

#include "Interfaces/IImageWrapper.h"

#include "ELowEntryImageFormat.generated.h"


UENUM()
enum class ELowEntryImageFormat
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


static EImageFormat::Type ELowEntryImageFormatToUE4(ELowEntryImageFormat Value)
{
	if(Value == ELowEntryImageFormat::Invalid)
	{
		return EImageFormat::Type::Invalid;
	}
	if(Value == ELowEntryImageFormat::PNG)
	{
		return EImageFormat::Type::PNG;
	}
	if(Value == ELowEntryImageFormat::JPEG)
	{
		return EImageFormat::Type::JPEG;
	}
	if(Value == ELowEntryImageFormat::GrayscaleJPEG)
	{
		return EImageFormat::Type::GrayscaleJPEG;
	}
	if(Value == ELowEntryImageFormat::BMP)
	{
		return EImageFormat::Type::BMP;
	}
	if(Value == ELowEntryImageFormat::ICO)
	{
		return EImageFormat::Type::ICO;
	}
	if(Value == ELowEntryImageFormat::EXR)
	{
		return EImageFormat::Type::EXR;
	}
	if(Value == ELowEntryImageFormat::ICNS)
	{
		return EImageFormat::Type::ICNS;
	}
	return EImageFormat::Type::Invalid;
}

static ELowEntryImageFormat ELowEntryImageFormatFromUE4(EImageFormat::Type Value)
{
	if(Value == EImageFormat::Type::Invalid)
	{
		return ELowEntryImageFormat::Invalid;
	}
	if(Value == EImageFormat::Type::PNG)
	{
		return ELowEntryImageFormat::PNG;
	}
	if(Value == EImageFormat::Type::JPEG)
	{
		return ELowEntryImageFormat::JPEG;
	}
	if(Value == EImageFormat::Type::GrayscaleJPEG)
	{
		return ELowEntryImageFormat::GrayscaleJPEG;
	}
	if(Value == EImageFormat::Type::BMP)
	{
		return ELowEntryImageFormat::BMP;
	}
	if(Value == EImageFormat::Type::ICO)
	{
		return ELowEntryImageFormat::ICO;
	}
	if(Value == EImageFormat::Type::EXR)
	{
		return ELowEntryImageFormat::EXR;
	}
	if(Value == EImageFormat::Type::ICNS)
	{
		return ELowEntryImageFormat::ICNS;
	}
	return ELowEntryImageFormat::Invalid;
}
