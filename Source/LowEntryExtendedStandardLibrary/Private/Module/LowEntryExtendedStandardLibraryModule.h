// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "ILowEntryExtendedStandardLibraryModule.h"


class FLowEntryExtendedStandardLibraryModule : public ILowEntryExtendedStandardLibraryModule
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
