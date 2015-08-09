#pragma once


#include "ILowEntryExtendedStandardLibraryEditorModule.h"


class FLowEntryExtendedStandardLibraryEditorModule : public ILowEntryExtendedStandardLibraryEditorModule
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
