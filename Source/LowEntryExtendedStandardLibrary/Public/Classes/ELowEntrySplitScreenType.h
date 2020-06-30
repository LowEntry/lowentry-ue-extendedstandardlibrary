// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"

#include "Engine/ViewportSplitScreen.h"

#include "ELowEntrySplitScreenType.generated.h"


UENUM(BlueprintType)
enum class ELowEntrySplitScreenType : uint8
{
	None,
	TwoPlayer_Horizontal,
	TwoPlayer_Vertical,
	ThreePlayer_FavorTop,
	ThreePlayer_FavorBottom,
	ThreePlayer_Vertical,
	FourPlayer_Grid,
	FourPlayer_Vertical
};


static ESplitScreenType::Type ELowEntrySplitScreenTypeToUE4(ELowEntrySplitScreenType Value)
{
	if(Value == ELowEntrySplitScreenType::None)
	{
		return ESplitScreenType::Type::None;
	}
	if(Value == ELowEntrySplitScreenType::TwoPlayer_Horizontal)
	{
		return ESplitScreenType::Type::TwoPlayer_Horizontal;
	}
	if(Value == ELowEntrySplitScreenType::TwoPlayer_Vertical)
	{
		return ESplitScreenType::Type::TwoPlayer_Vertical;
	}
	if(Value == ELowEntrySplitScreenType::ThreePlayer_FavorTop)
	{
		return ESplitScreenType::Type::ThreePlayer_FavorTop;
	}
	if(Value == ELowEntrySplitScreenType::ThreePlayer_FavorBottom)
	{
		return ESplitScreenType::Type::ThreePlayer_FavorBottom;
	}
	if(Value == ELowEntrySplitScreenType::ThreePlayer_Vertical)
	{
		return ESplitScreenType::Type::ThreePlayer_Vertical;
	}
	if(Value == ELowEntrySplitScreenType::FourPlayer_Grid)
	{
		return ESplitScreenType::Type::FourPlayer_Grid;
	}
	if(Value == ELowEntrySplitScreenType::FourPlayer_Vertical)
	{
		return ESplitScreenType::Type::FourPlayer_Vertical;
	}
	return ESplitScreenType::Type::None;
}

static ELowEntrySplitScreenType ELowEntrySplitScreenTypeFromUE4(ESplitScreenType::Type Value)
{
	if(Value == ESplitScreenType::Type::None)
	{
		return ELowEntrySplitScreenType::None;
	}
	if(Value == ESplitScreenType::Type::TwoPlayer_Horizontal)
	{
		return ELowEntrySplitScreenType::TwoPlayer_Horizontal;
	}
	if(Value == ESplitScreenType::Type::TwoPlayer_Vertical)
	{
		return ELowEntrySplitScreenType::TwoPlayer_Vertical;
	}
	if(Value == ESplitScreenType::Type::ThreePlayer_FavorTop)
	{
		return ELowEntrySplitScreenType::ThreePlayer_FavorTop;
	}
	if(Value == ESplitScreenType::Type::ThreePlayer_FavorBottom)
	{
		return ELowEntrySplitScreenType::ThreePlayer_FavorBottom;
	}
	if(Value == ESplitScreenType::Type::ThreePlayer_Vertical)
	{
		return ELowEntrySplitScreenType::ThreePlayer_Vertical;
	}
	if(Value == ESplitScreenType::Type::FourPlayer_Grid)
	{
		return ELowEntrySplitScreenType::FourPlayer_Grid;
	}
	if(Value == ESplitScreenType::Type::FourPlayer_Vertical)
	{
		return ELowEntrySplitScreenType::FourPlayer_Vertical;
	}
	return ELowEntrySplitScreenType::None;
}
