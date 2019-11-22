// Copyright Low Entry. Apache License, Version 2.0.

#include "K2Node_LowEntry_CreateByteDataWriter.h"
#include "LowEntryExtendedStandardLibrary.h"
#include "LowEntryByteDataEntry.h"
#include "LowEntryByteDataWriter.h"


UK2Node_LowEntry_CreateByteDataWriter::UK2Node_LowEntry_CreateByteDataWriter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	LowEntry_Name = TEXT("Create Byte Data Writer (Non-Pure)");
	LowEntry_Category = TEXT("Low Entry|Extended Standard Library|Byte Data|Writer");
	LowEntry_Tooltip = TEXT("Creates a new Byte Data Writer.");
	LowEntry_ResultPinName = TEXT("ByteDataWriter");
	LowEntry_IsNodePure = false;
	LowEntry_InputClass = ULowEntryByteDataEntry::StaticClass();
	LowEntry_OutputClass = ULowEntryByteDataWriter::StaticClass();
	LowEntry_ConverterClass = ULowEntryExtendedStandardLibrary::StaticClass();
	LowEntry_ConverterFunctionName = TEXT("ByteDataWriter_CreateFromEntryArray");
}
