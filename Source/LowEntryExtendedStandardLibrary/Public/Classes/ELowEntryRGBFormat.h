#pragma once


#include "Engine.h"
#include "Core.h"

#include "Interfaces/IImageWrapper.h"

#include "ELowEntryRGBFormat.generated.h"


UENUM()
enum class ELowEntryRGBFormat
{
	Invalid,
	RGBA,
	BGRA,
	Gray,
};


static ERGBFormat::Type ELowEntryRGBFormatToUE4(ELowEntryRGBFormat Value)
{
	if(Value == ELowEntryRGBFormat::Invalid)
	{
		return ERGBFormat::Type::Invalid;
	}
	if(Value == ELowEntryRGBFormat::RGBA)
	{
		return ERGBFormat::Type::RGBA;
	}
	if(Value == ELowEntryRGBFormat::BGRA)
	{
		return ERGBFormat::Type::BGRA;
	}
	if(Value == ELowEntryRGBFormat::Gray)
	{
		return ERGBFormat::Type::Gray;
	}
	return ERGBFormat::Type::Invalid;
}

static ELowEntryRGBFormat ELowEntryRGBFormatFromUE4(ERGBFormat::Type Value)
{
	if(Value == ERGBFormat::Type::Invalid)
	{
		return ELowEntryRGBFormat::Invalid;
	}
	if(Value == ERGBFormat::Type::RGBA)
	{
		return ELowEntryRGBFormat::RGBA;
	}
	if(Value == ERGBFormat::Type::BGRA)
	{
		return ELowEntryRGBFormat::BGRA;
	}
	if(Value == ERGBFormat::Type::Gray)
	{
		return ELowEntryRGBFormat::Gray;
	}
	return ELowEntryRGBFormat::Invalid;
}
