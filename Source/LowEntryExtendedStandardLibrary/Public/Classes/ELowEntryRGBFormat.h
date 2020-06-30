// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "IImageWrapper.h"

#include "ELowEntryRGBFormat.generated.h"


UENUM(BlueprintType)
enum class ELowEntryRGBFormat : uint8
{
	Invalid,
	RGBA,
	BGRA,
	Gray,
};


static ERGBFormat ELowEntryRGBFormatToUE4(ELowEntryRGBFormat Value)
{
	if(Value == ELowEntryRGBFormat::Invalid)
	{
		return ERGBFormat::Invalid;
	}
	if(Value == ELowEntryRGBFormat::RGBA)
	{
		return ERGBFormat::RGBA;
	}
	if(Value == ELowEntryRGBFormat::BGRA)
	{
		return ERGBFormat::BGRA;
	}
	if(Value == ELowEntryRGBFormat::Gray)
	{
		return ERGBFormat::Gray;
	}
	return ERGBFormat::Invalid;
}

static ELowEntryRGBFormat ELowEntryRGBFormatFromUE4(ERGBFormat Value)
{
	if(Value == ERGBFormat::Invalid)
	{
		return ELowEntryRGBFormat::Invalid;
	}
	if(Value == ERGBFormat::RGBA)
	{
		return ELowEntryRGBFormat::RGBA;
	}
	if(Value == ERGBFormat::BGRA)
	{
		return ELowEntryRGBFormat::BGRA;
	}
	if(Value == ERGBFormat::Gray)
	{
		return ELowEntryRGBFormat::Gray;
	}
	return ELowEntryRGBFormat::Invalid;
}
