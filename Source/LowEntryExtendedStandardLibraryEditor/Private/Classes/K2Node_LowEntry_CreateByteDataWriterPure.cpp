// Copyright Low Entry. Apache License, Version 2.0.

#include "K2Node_LowEntry_CreateByteDataWriterPure.h"
#include "LowEntryExtendedStandardLibrary.h"
#include "LowEntryByteDataEntry.h"
#include "LowEntryByteDataWriter.h"


UK2Node_LowEntry_CreateByteDataWriterPure::UK2Node_LowEntry_CreateByteDataWriterPure(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	LowEntry_Name = TEXT("Create Byte Data Writer (Pure)");
	LowEntry_Category = TEXT("Low Entry|Extended Standard Library|Byte Data|Writer");
	LowEntry_Tooltip = TEXT("Creates a new Byte Data Writer.");
	LowEntry_ResultPinName = TEXT("ByteDataWriter");
	LowEntry_IsNodePure = true;
	LowEntry_InputClass = ULowEntryByteDataEntry::StaticClass();
	LowEntry_OutputClass = ULowEntryByteDataWriter::StaticClass();
	LowEntry_ConverterClass = ULowEntryExtendedStandardLibrary::StaticClass();
	LowEntry_ConverterFunctionName = TEXT("ByteDataWriter_CreateFromEntryArray");
}
