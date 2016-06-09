#pragma once


#include "Engine.h"
#include "Core.h"

#include "Interfaces/IImageWrapper.h"

#include "ELowEntryERGBFormat.generated.h"


UENUM()
enum class ELowEntryERGBFormat
{
	Invalid,
	RGBA,
	BGRA,
	Gray,
};


static ERGBFormat::Type ELowEntryERGBFormatToUE4(ELowEntryERGBFormat Value)
{
	if(Value == ELowEntryERGBFormat::Invalid)
	{
		return ERGBFormat::Type::Invalid;
	}
	if(Value == ELowEntryERGBFormat::RGBA)
	{
		return ERGBFormat::Type::RGBA;
	}
	if(Value == ELowEntryERGBFormat::BGRA)
	{
		return ERGBFormat::Type::BGRA;
	}
	if(Value == ELowEntryERGBFormat::Gray)
	{
		return ERGBFormat::Type::Gray;
	}
	return ERGBFormat::Type::Invalid;
}

static ELowEntryERGBFormat ELowEntryERGBFormatFromUE4(ERGBFormat::Type Value)
{
	if(Value == ERGBFormat::Type::Invalid)
	{
		return ELowEntryERGBFormat::Invalid;
	}
	if(Value == ERGBFormat::Type::RGBA)
	{
		return ELowEntryERGBFormat::RGBA;
	}
	if(Value == ERGBFormat::Type::BGRA)
	{
		return ELowEntryERGBFormat::BGRA;
	}
	if(Value == ERGBFormat::Type::Gray)
	{
		return ELowEntryERGBFormat::Gray;
	}
	return ELowEntryERGBFormat::Invalid;
}
