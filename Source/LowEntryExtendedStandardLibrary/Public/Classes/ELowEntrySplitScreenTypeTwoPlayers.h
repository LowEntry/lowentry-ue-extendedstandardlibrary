// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "GameMapsSettings.h"

#include "ELowEntrySplitScreenTypeTwoPlayers.generated.h"


UENUM(BlueprintType)
enum class ELowEntrySplitScreenTypeTwoPlayers : uint8
{
	Horizontal,
	Vertical
};


static ETwoPlayerSplitScreenType::Type ELowEntrySplitScreenTypeTwoPlayersToUE4(ELowEntrySplitScreenTypeTwoPlayers Value)
{
	if(Value == ELowEntrySplitScreenTypeTwoPlayers::Horizontal)
	{
		return ETwoPlayerSplitScreenType::Type::Horizontal;
	}
	if(Value == ELowEntrySplitScreenTypeTwoPlayers::Vertical)
	{
		return ETwoPlayerSplitScreenType::Type::Vertical;
	}
	return ETwoPlayerSplitScreenType::Type::Horizontal;
}

static ELowEntrySplitScreenTypeTwoPlayers ELowEntrySplitScreenTypeTwoPlayersFromUE4(ETwoPlayerSplitScreenType::Type Value)
{
	if(Value == ETwoPlayerSplitScreenType::Type::Horizontal)
	{
		return ELowEntrySplitScreenTypeTwoPlayers::Horizontal;
	}
	if(Value == ETwoPlayerSplitScreenType::Type::Vertical)
	{
		return ELowEntrySplitScreenTypeTwoPlayers::Vertical;
	}
	return ELowEntrySplitScreenTypeTwoPlayers::Horizontal;
}
