#pragma once


#include "ILowEntryExtendedStandardLibraryModule.h"


class FLowEntryExtendedStandardLibraryModule : public ILowEntryExtendedStandardLibraryModule
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
