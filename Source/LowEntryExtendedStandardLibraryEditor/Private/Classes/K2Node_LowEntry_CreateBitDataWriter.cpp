// Copyright Low Entry. Apache License, Version 2.0.

#include "K2Node_LowEntry_CreateBitDataWriter.h"
#include "LowEntryExtendedStandardLibrary.h"
#include "LowEntryBitDataEntry.h"
#include "LowEntryBitDataWriter.h"


UK2Node_LowEntry_CreateBitDataWriter::UK2Node_LowEntry_CreateBitDataWriter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	LowEntry_Name = TEXT("Create Bit Data Writer (Non-Pure)");
	LowEntry_Category = TEXT("Low Entry|Extended Standard Library|Bit Data|Writer");
	LowEntry_Tooltip = TEXT("Creates a new Bit Data Writer.");
	LowEntry_ResultPinName = TEXT("BitDataWriter");
	LowEntry_IsNodePure = false;
	LowEntry_InputClass = ULowEntryBitDataEntry::StaticClass();
	LowEntry_OutputClass = ULowEntryBitDataWriter::StaticClass();
	LowEntry_ConverterClass = ULowEntryExtendedStandardLibrary::StaticClass();
	LowEntry_ConverterFunctionName = TEXT("BitDataWriter_CreateFromEntryArray");
}
