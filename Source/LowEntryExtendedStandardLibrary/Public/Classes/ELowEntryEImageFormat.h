#pragma once


#include "Engine.h"
#include "Core.h"

#include "Interfaces/IImageWrapper.h"

#include "ELowEntryEImageFormat.generated.h"


UENUM()
enum class ELowEntryEImageFormat
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


static EImageFormat::Type ELowEntryEImageFormatToUE4(ELowEntryEImageFormat Value)
{
	if(Value == ELowEntryEImageFormat::Invalid)
	{
		return EImageFormat::Type::Invalid;
	}
	if(Value == ELowEntryEImageFormat::PNG)
	{
		return EImageFormat::Type::PNG;
	}
	if(Value == ELowEntryEImageFormat::JPEG)
	{
		return EImageFormat::Type::JPEG;
	}
	if(Value == ELowEntryEImageFormat::GrayscaleJPEG)
	{
		return EImageFormat::Type::GrayscaleJPEG;
	}
	if(Value == ELowEntryEImageFormat::BMP)
	{
		return EImageFormat::Type::BMP;
	}
	if(Value == ELowEntryEImageFormat::ICO)
	{
		return EImageFormat::Type::ICO;
	}
	if(Value == ELowEntryEImageFormat::EXR)
	{
		return EImageFormat::Type::EXR;
	}
	if(Value == ELowEntryEImageFormat::ICNS)
	{
		return EImageFormat::Type::ICNS;
	}
	return EImageFormat::Type::Invalid;
}

static ELowEntryEImageFormat ELowEntryEImageFormatFromUE4(EImageFormat::Type Value)
{
	if(Value == EImageFormat::Type::Invalid)
	{
		return ELowEntryEImageFormat::Invalid;
	}
	if(Value == EImageFormat::Type::PNG)
	{
		return ELowEntryEImageFormat::PNG;
	}
	if(Value == EImageFormat::Type::JPEG)
	{
		return ELowEntryEImageFormat::JPEG;
	}
	if(Value == EImageFormat::Type::GrayscaleJPEG)
	{
		return ELowEntryEImageFormat::GrayscaleJPEG;
	}
	if(Value == EImageFormat::Type::BMP)
	{
		return ELowEntryEImageFormat::BMP;
	}
	if(Value == EImageFormat::Type::ICO)
	{
		return ELowEntryEImageFormat::ICO;
	}
	if(Value == EImageFormat::Type::EXR)
	{
		return ELowEntryEImageFormat::EXR;
	}
	if(Value == EImageFormat::Type::ICNS)
	{
		return ELowEntryEImageFormat::ICNS;
	}
	return ELowEntryEImageFormat::Invalid;
}
