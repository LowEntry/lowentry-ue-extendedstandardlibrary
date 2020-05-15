// Copyright Low Entry. Apache License, Version 2.0.

#include "K2Node_LowEntry_MergeBytesPure.h"
#include "LowEntryExtendedStandardLibrary.h"
#include "LowEntryByteArray.h"

#include "EdGraph/EdGraphPin.h"
#include "Engine/Blueprint.h"
#include "Framework/Commands/UIAction.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ToolMenus.h"
#include "EdGraphSchema_K2.h"
#include "EdGraph/EdGraphNodeUtils.h"
#include "Kismet2/BlueprintEditorUtils.h"

#include "ScopedTransaction.h"
#include "EdGraphUtilities.h"
#include "KismetCompiledFunctionContext.h"
#include "KismetCompilerMisc.h"
#include "BlueprintNodeSpawner.h"
#include "EditorCategoryUtils.h"
#include "BlueprintActionDatabaseRegistrar.h"

#define LOCTEXT_NAMESPACE "MakeArrayNode"


UK2Node_LowEntry_MergeBytesPure::UK2Node_LowEntry_MergeBytesPure(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	LowEntry_Name = TEXT("Merge Bytes");
	LowEntry_Category = TEXT("Low Entry|Extended Standard Library|Utilities|Bytes");
	LowEntry_Tooltip = TEXT("Merges multiple Byte Arrays into one.");
	LowEntry_ResultPinName = TEXT("Bytes");
	LowEntry_IsNodePure = true;
}


class FKCHandler_LowEntry_MergeBytesPure : public FNodeHandlingFunctor
{
public:
	FKCHandler_LowEntry_MergeBytesPure(FKismetCompilerContext& InCompilerContext) : FNodeHandlingFunctor(InCompilerContext)
	{
	}

	virtual void RegisterNets(FKismetFunctionContext& Context, UEdGraphNode* Node) override
	{
		UK2Node_LowEntry_MergeBytesPure* ArrayNode = CastChecked<UK2Node_LowEntry_MergeBytesPure>(Node);
		FNodeHandlingFunctor::RegisterNets(Context, Node);

		// Create a local term to drop the array into
		UEdGraphPin* ArrayOutputPin = ArrayNode->GetArrayOutputPin();
		FBPTerminal* ArrayTerm = Context.CreateLocalTerminalFromPinAutoChooseScope(ArrayOutputPin, Context.NetNameMap->MakeValidName(ArrayOutputPin) + TEXT("_Array"));
		ArrayTerm->bPassedByReference = false;
		ArrayTerm->Source = Node;
		Context.NetMap.Add(ArrayOutputPin, ArrayTerm);

		// Create a local term to drop the object into
		UEdGraphPin* ObjectOutputPin = ArrayNode->GetObjectOutputPin();
		FBPTerminal* ObjectTerm = Context.CreateLocalTerminalFromPinAutoChooseScope(ObjectOutputPin, Context.NetNameMap->MakeValidName(ObjectOutputPin) + TEXT("_Object"));
		ObjectTerm->bPassedByReference = false;
		ObjectTerm->Source = Node;
		Context.NetMap.Add(ObjectOutputPin, ObjectTerm);

		for(auto PinIt = Node->Pins.CreateIterator(); PinIt; ++PinIt)
		{
			UEdGraphPin* Pin = *PinIt;
			if(Pin && (Pin->Direction == EGPD_Input) && (Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec))
			{
				UEdGraphPin* Pin2 = ArrayNode->GetPin(Pin->PinName.ToString() + TEXT("2"));
				if(Pin2)
				{
					FBPTerminal* Pin2Term = Context.CreateLocalTerminalFromPinAutoChooseScope(Pin2, Context.NetNameMap->MakeValidName(Pin2) + TEXT("_Object"));
					Pin2Term->bPassedByReference = false;
					Pin2Term->Source = Node;
					Context.NetMap.Add(Pin2, Pin2Term);
				}
			}
		}
	}

	virtual void Compile(FKismetFunctionContext& Context, UEdGraphNode* Node) override
	{
		UK2Node_LowEntry_MergeBytesPure* ArrayNode = CastChecked<UK2Node_LowEntry_MergeBytesPure>(Node);
		UEdGraphPin* ArrayOutputPin = ArrayNode->GetArrayOutputPin();
		UEdGraphPin* ObjectOutputPin = ArrayNode->GetObjectOutputPin();

		FBPTerminal** ArrayOutputVariable = Context.NetMap.Find(ArrayOutputPin);
		FBPTerminal** ObjectOutputVariable = Context.NetMap.Find(ObjectOutputPin);
		check(ArrayOutputVariable);
		check(ObjectOutputVariable);


		UClass* ConvertFunctionClass2 = Cast<UClass>(ULowEntryExtendedStandardLibrary::StaticClass());
		UFunction* ConvertFunctionPointer2 = FindUField<UFunction>(ConvertFunctionClass2, TEXT("EncapsulateByteArray"));
		check(ConvertFunctionPointer2);

		for(auto PinIt = Node->Pins.CreateIterator(); PinIt; ++PinIt)
		{
			UEdGraphPin* Pin = *PinIt;
			if(Pin && (Pin->Direction == EGPD_Input) && (Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec))
			{
				FBPTerminal** InputTerm = Context.NetMap.Find(FEdGraphUtilities::GetNetFromPin(Pin));
				if(InputTerm)
				{
					UEdGraphPin* Pin2 = ArrayNode->GetPin(Pin->PinName.ToString() + TEXT("2"));
					if(Pin2)
					{
						FBPTerminal** Input2Term = Context.NetMap.Find(FEdGraphUtilities::GetNetFromPin(Pin2));
						if(Input2Term)
						{
							FBlueprintCompiledStatement& CreateConvertStatement = Context.AppendStatementForNode(Node);
							CreateConvertStatement.Type = KCST_CallFunction;
							CreateConvertStatement.FunctionToCall = ConvertFunctionPointer2;
							CreateConvertStatement.LHS = *Input2Term;
							CreateConvertStatement.RHS.Add(*InputTerm);
						}
					}
				}
			}
		}


		FBlueprintCompiledStatement& CreateArrayStatement = Context.AppendStatementForNode(Node);
		CreateArrayStatement.Type = KCST_CreateArray;
		CreateArrayStatement.LHS = *ArrayOutputVariable;

		for(auto PinIt = Node->Pins.CreateIterator(); PinIt; ++PinIt)
		{
			UEdGraphPin* Pin = *PinIt;
			if(Pin && (Pin->Direction == EGPD_Input) && (Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec))
			{
				FBPTerminal** InputTerm = Context.NetMap.Find(FEdGraphUtilities::GetNetFromPin(Pin));
				if(InputTerm)
				{
					UEdGraphPin* Pin2 = ArrayNode->GetPin(Pin->PinName.ToString() + TEXT("2"));
					if(Pin2)
					{
						FBPTerminal** Input2Term = Context.NetMap.Find(FEdGraphUtilities::GetNetFromPin(Pin2));
						if(Input2Term)
						{
							CreateArrayStatement.RHS.Add(*Input2Term);
						}
					}
				}
			}
		}


		UClass* ConvertFunctionClass = Cast<UClass>(ULowEntryExtendedStandardLibrary::StaticClass());
		UFunction* ConvertFunctionPointer = FindUField<UFunction>(ConvertFunctionClass, TEXT("MergeEncapsulatedByteArrays"));
		check(ConvertFunctionPointer);

		FBlueprintCompiledStatement& CreateConvertStatement = Context.AppendStatementForNode(Node);
		CreateConvertStatement.Type = KCST_CallFunction;
		CreateConvertStatement.FunctionToCall = ConvertFunctionPointer;
		CreateConvertStatement.LHS = *ObjectOutputVariable;
		CreateConvertStatement.RHS.Add(*ArrayOutputVariable);


		if(!ArrayNode->LowEntry_IsNodePure)
		{
			GenerateSimpleThenGoto(Context, *Node);
		}
	}
};


FNodeHandlingFunctor* UK2Node_LowEntry_MergeBytesPure::CreateNodeHandler(FKismetCompilerContext& CompilerContext) const
{
	return new FKCHandler_LowEntry_MergeBytesPure(CompilerContext);
}

UEdGraphPin* UK2Node_LowEntry_MergeBytesPure::GetPin(const FString& PinName) const
{
	return FindPin(*PinName);
}

void UK2Node_LowEntry_MergeBytesPure::AllocateDefaultPins()
{
	if(!true)
	{
		CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, TEXT(""), NULL, UEdGraphSchema_K2::PN_Execute);
		CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, TEXT(""), NULL, UEdGraphSchema_K2::PN_Then);
	}

	// Create the output pins
	FCreatePinParams ArrayOutputPinParams = FCreatePinParams();
	ArrayOutputPinParams.ContainerType = EPinContainerType::Array;
	
	UEdGraphPin* ObjectOutputPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Byte, TEXT(""), NULL, LowEntry_ResultPinName, ArrayOutputPinParams);
	UEdGraphPin* ArrayOutputPin = CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Object, TEXT(""), ULowEntryByteArray::StaticClass(), GetOutputPinName(), ArrayOutputPinParams);

	ArrayOutputPin->bHidden = true;

	// Create the input pins to create the arrays from
	for(int32 i = 0; i < NumInputs; ++i)
	{
		CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Byte, TEXT(""), NULL, *FString::Printf(TEXT("[%d]"), i), ArrayOutputPinParams);
		CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Object, TEXT(""), ULowEntryByteArray::StaticClass(), *FString::Printf(TEXT("[%d]2"), i))->bHidden = true;
	}
}

void UK2Node_LowEntry_MergeBytesPure::AddInputPin()
{
	Modify();

	++NumInputs;
	FEdGraphPinType OutputPinType = GetArrayOutputPin()->PinType;
	FCreatePinParams ArrayOutputPinParams = FCreatePinParams();
	ArrayOutputPinParams.ContainerType = EPinContainerType::Array;
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Byte, TEXT(""), NULL, *FString::Printf(TEXT("[%d]"), (NumInputs - 1)), ArrayOutputPinParams);
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Object, TEXT(""), ULowEntryByteArray::StaticClass(), *FString::Printf(TEXT("[%d]2"), (NumInputs - 1)))->bHidden = true;

	const bool bIsCompiling = GetBlueprint()->bBeingCompiled;
	if(!bIsCompiling)
	{
		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(GetBlueprint());
	}
}

void UK2Node_LowEntry_MergeBytesPure::RemoveInputPin(UEdGraphPin* Pin)
{
	check(Pin->Direction == EGPD_Input);
	check(Pin->ParentPin == nullptr);
	checkSlow(Pins.Contains(Pin));
	check(Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec);

	FScopedTransaction Transaction(LOCTEXT("RemovePinTx", "RemovePin"));
	Modify();

	int32 PinRemovalIndex = INDEX_NONE;
	if(Pins.Find(Pin, /*out*/ PinRemovalIndex))
	{
		for(int32 PinIndex = PinRemovalIndex + 2; PinIndex < Pins.Num(); ++PinIndex)
		{
			Pins[PinIndex]->Modify();
			Pins[PinIndex]->PinName = FName(*FString::Printf(TEXT("[%d]"), (PinIndex / 2) - 2)); // -1 to shift back one, -1 to account for the output pin at the 0th position

			++PinIndex;

			Pins[PinIndex]->Modify();
			Pins[PinIndex]->PinName = FName(*FString::Printf(TEXT("[%d]2"), (PinIndex / 2) - 2)); // -1 to shift back one, -1 to account for the output pin at the 0th position
		}

		UEdGraphPin* Pin2 = GetPin(Pin->PinName.ToString() + TEXT("2"));
		Pin2->Modify();
		Pin2->BreakAllPinLinks();

		Pin->Modify();
		Pin->BreakAllPinLinks();

		Pins.RemoveAt(PinRemovalIndex + 1);
		Pins.RemoveAt(PinRemovalIndex);

		--NumInputs;

		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(GetBlueprint());
	}
}

#undef LOCTEXT_NAMESPACE
