// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryByteDataEntry.h"


// init >>
	ULowEntryByteDataEntry::ULowEntryByteDataEntry(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromByte(const uint8 Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetByte(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromInteger(const int32 Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetInteger(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromPositiveInteger1(const int32 Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetPositiveInteger1(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromPositiveInteger2(const int32 Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetPositiveInteger2(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromPositiveInteger3(const int32 Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetPositiveInteger3(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromLongBytes(ULowEntryLong* Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetLongBytes(Value);
		return Instance;
	}

	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromFloat(const float Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetFloat(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromDoubleBytes(ULowEntryDouble* Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetDoubleBytes(Value);
		return Instance;
	}

	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromBoolean(const bool Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetBoolean(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromStringUtf8(const FString& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetStringUtf8(Value);
		return Instance;
	}


	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromByteArray(const TArray<uint8>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetByteArray(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromIntegerArray(const TArray<int32>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetIntegerArray(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromPositiveInteger1Array(const TArray<int32>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetPositiveInteger1Array(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromPositiveInteger2Array(const TArray<int32>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetPositiveInteger2Array(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromPositiveInteger3Array(const TArray<int32>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetPositiveInteger3Array(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromLongBytesArray(const TArray<ULowEntryLong*>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetLongBytesArray(Value);
		return Instance;
	}

	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromFloatArray(const TArray<float>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetFloatArray(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromDoubleBytesArray(const TArray<ULowEntryDouble*>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetDoubleBytesArray(Value);
		return Instance;
	}

	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromBooleanArray(const TArray<bool>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetBooleanArray(Value);
		return Instance;
	}
	ULowEntryByteDataEntry* ULowEntryByteDataEntry::CreateFromStringUtf8Array(const TArray<FString>& Value)
	{
		ULowEntryByteDataEntry* Instance = NewObject<ULowEntryByteDataEntry>();
		Instance->SetStringUtf8Array(Value);
		return Instance;
	}
// init <<


bool ULowEntryByteDataEntry::IsByte()
{
	return (Type == 1);
};
void ULowEntryByteDataEntry::SetByte(const uint8 Value)
{
	Type = 1;
	ByteValue = Value;
};
uint8 ULowEntryByteDataEntry::GetByte()
{
	return ByteValue;
}

bool ULowEntryByteDataEntry::IsInteger()
{
	return (Type == 2);
};
void ULowEntryByteDataEntry::SetInteger(const int32 Value)
{
	Type = 2;
	IntegerValue = Value;
};
int32 ULowEntryByteDataEntry::GetInteger()
{
	return IntegerValue;
}

bool ULowEntryByteDataEntry::IsPositiveInteger1()
{
	return (Type == 8);
};
void ULowEntryByteDataEntry::SetPositiveInteger1(const int32 Value)
{
	Type = 8;
	IntegerValue = Value;
};
int32 ULowEntryByteDataEntry::GetPositiveInteger1()
{
	return IntegerValue;
}

bool ULowEntryByteDataEntry::IsPositiveInteger2()
{
	return (Type == 9);
};
void ULowEntryByteDataEntry::SetPositiveInteger2(const int32 Value)
{
	Type = 9;
	IntegerValue = Value;
};
int32 ULowEntryByteDataEntry::GetPositiveInteger2()
{
	return IntegerValue;
}

bool ULowEntryByteDataEntry::IsPositiveInteger3()
{
	return (Type == 10);
};
void ULowEntryByteDataEntry::SetPositiveInteger3(const int32 Value)
{
	Type = 10;
	IntegerValue = Value;
};
int32 ULowEntryByteDataEntry::GetPositiveInteger3()
{
	return IntegerValue;
}

bool ULowEntryByteDataEntry::IsLongBytes()
{
	return (Type == 3);
};
void ULowEntryByteDataEntry::SetLongBytes(ULowEntryLong* Value)
{
	Type = 3;
	LongBytesValue = Value;
};
ULowEntryLong* ULowEntryByteDataEntry::GetLongBytes()
{
	return LongBytesValue;
}


bool ULowEntryByteDataEntry::IsFloat()
{
	return (Type == 4);
};
void ULowEntryByteDataEntry::SetFloat(const float Value)
{
	Type = 4;
	FloatValue = Value;
};
float ULowEntryByteDataEntry::GetFloat()
{
	return FloatValue;
}

bool ULowEntryByteDataEntry::IsDoubleBytes()
{
	return (Type == 5);
};
void ULowEntryByteDataEntry::SetDoubleBytes(ULowEntryDouble* Value)
{
	Type = 5;
	DoubleBytesValue = Value;
};
ULowEntryDouble* ULowEntryByteDataEntry::GetDoubleBytes()
{
	return DoubleBytesValue;
}


bool ULowEntryByteDataEntry::IsBoolean()
{
	return (Type == 6);
};
void ULowEntryByteDataEntry::SetBoolean(const bool Value)
{
	Type = 6;
	BooleanValue = Value;
};
bool ULowEntryByteDataEntry::GetBoolean()
{
	return BooleanValue;
}

bool ULowEntryByteDataEntry::IsStringUtf8()
{
	return (Type == 7);
};
void ULowEntryByteDataEntry::SetStringUtf8(const FString& Value)
{
	Type = 7;
	StringUtf8Value = Value;
};
FString ULowEntryByteDataEntry::GetStringUtf8()
{
	return StringUtf8Value;
}



bool ULowEntryByteDataEntry::IsByteArray()
{
	return (Type == 101);
};
void ULowEntryByteDataEntry::SetByteArray(const TArray<uint8>& Value)
{
	Type = 101;
	ByteArrayValue = Value;
};
TArray<uint8> ULowEntryByteDataEntry::GetByteArray()
{
	return ByteArrayValue;
}

bool ULowEntryByteDataEntry::IsIntegerArray()
{
	return (Type == 102);
};
void ULowEntryByteDataEntry::SetIntegerArray(const TArray<int32>& Value)
{
	Type = 102;
	IntegerArrayValue = Value;
};
TArray<int32> ULowEntryByteDataEntry::GetIntegerArray()
{
	return IntegerArrayValue;
}

bool ULowEntryByteDataEntry::IsPositiveInteger1Array()
{
	return (Type == 108);
};
void ULowEntryByteDataEntry::SetPositiveInteger1Array(const TArray<int32>& Value)
{
	Type = 108;
	IntegerArrayValue = Value;
};
TArray<int32> ULowEntryByteDataEntry::GetPositiveInteger1Array()
{
	return IntegerArrayValue;
}

bool ULowEntryByteDataEntry::IsPositiveInteger2Array()
{
	return (Type == 109);
};
void ULowEntryByteDataEntry::SetPositiveInteger2Array(const TArray<int32>& Value)
{
	Type = 109;
	IntegerArrayValue = Value;
};
TArray<int32> ULowEntryByteDataEntry::GetPositiveInteger2Array()
{
	return IntegerArrayValue;
}

bool ULowEntryByteDataEntry::IsPositiveInteger3Array()
{
	return (Type == 110);
};
void ULowEntryByteDataEntry::SetPositiveInteger3Array(const TArray<int32>& Value)
{
	Type = 110;
	IntegerArrayValue = Value;
};
TArray<int32> ULowEntryByteDataEntry::GetPositiveInteger3Array()
{
	return IntegerArrayValue;
}

bool ULowEntryByteDataEntry::IsLongBytesArray()
{
	return (Type == 103);
};
void ULowEntryByteDataEntry::SetLongBytesArray(const TArray<ULowEntryLong*>& Value)
{
	Type = 103;
	LongBytesArrayValue = Value;
};
TArray<ULowEntryLong*> ULowEntryByteDataEntry::GetLongBytesArray()
{
	return LongBytesArrayValue;
}


bool ULowEntryByteDataEntry::IsFloatArray()
{
	return (Type == 104);
};
void ULowEntryByteDataEntry::SetFloatArray(const TArray<float>& Value)
{
	Type = 104;
	FloatArrayValue = Value;
};
TArray<float> ULowEntryByteDataEntry::GetFloatArray()
{
	return FloatArrayValue;
}

bool ULowEntryByteDataEntry::IsDoubleBytesArray()
{
	return (Type == 105);
};
void ULowEntryByteDataEntry::SetDoubleBytesArray(const TArray<ULowEntryDouble*>& Value)
{
	Type = 105;
	DoubleBytesArrayValue = Value;
};
TArray<ULowEntryDouble*> ULowEntryByteDataEntry::GetDoubleBytesArray()
{
	return DoubleBytesArrayValue;
}


bool ULowEntryByteDataEntry::IsBooleanArray()
{
	return (Type == 106);
};
void ULowEntryByteDataEntry::SetBooleanArray(const TArray<bool>& Value)
{
	Type = 106;
	BooleanArrayValue = Value;
};
TArray<bool> ULowEntryByteDataEntry::GetBooleanArray()
{
	return BooleanArrayValue;
}

bool ULowEntryByteDataEntry::IsStringUtf8Array()
{
	return (Type == 107);
};
void ULowEntryByteDataEntry::SetStringUtf8Array(const TArray<FString>& Value)
{
	Type = 107;
	StringUtf8ArrayValue = Value;
};
TArray<FString> ULowEntryByteDataEntry::GetStringUtf8Array()
{
	return StringUtf8ArrayValue;
}
