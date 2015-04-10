#pragma once


#include "ILowEntryExtendedStandardLibraryModule.h"


class LowEntryExtendedStandardLibraryModule : public ILowEntryExtendedStandardLibraryModule
{
public:
	void StartupModule();
	void ShutdownModule();
};
