// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryByteDataReader.h"
#include "LowEntryExtendedStandardLibrary.h"


// init >>
	ULowEntryByteDataReader::ULowEntryByteDataReader(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryByteDataReader* ULowEntryByteDataReader::Create(const TArray<uint8>& Bytes, int32 Index, int32 Length)
	{
		ULowEntryByteDataReader* Item = NewObject<ULowEntryByteDataReader>();
		Item->Bytes = ULowEntryExtendedStandardLibrary::BytesSubArray(Bytes, Index, Length);
		return Item;
	}

	ULowEntryByteDataReader* ULowEntryByteDataReader::CreateClone(const TArray<uint8>& Bytes, const int32 Position)
	{
		ULowEntryByteDataReader* Item = NewObject<ULowEntryByteDataReader>();
		Item->Bytes = Bytes;
		Item->Position = Position;
		return Item;
	}
// init <<


int32 ULowEntryByteDataReader::GetAndIncreasePosition(const int32 Increasement)
{
	int32 Pos = Position;
	if((Bytes.Num() - Increasement) <= Position)
	{
		Position = Bytes.Num();
	}
	else
	{
		Position += Increasement;
	}
	return Pos;
}

int32 ULowEntryByteDataReader::MaxElementsRemaining(const int32 MinimumSizePerElement)
{
	int32 RemainingCount = Remaining();
	if(RemainingCount <= 0)
	{
		return 0;
	}
	if(MinimumSizePerElement <= 1)
	{
		return RemainingCount;
	}
	return (RemainingCount / MinimumSizePerElement) + 1;
}


ULowEntryByteDataReader* ULowEntryByteDataReader::GetClone()
{
	return ULowEntryByteDataReader::CreateClone(Bytes, Position);
}

int32 ULowEntryByteDataReader::ULowEntryByteDataReader::GetPosition()
{
	return Position;
}

void ULowEntryByteDataReader::SetPosition(const int32 Position_)
{
	Position = Position_;
}

void ULowEntryByteDataReader::Reset()
{
	Position = 0;
}

void ULowEntryByteDataReader::Empty()
{
	Position = Bytes.Num();
}

int32 ULowEntryByteDataReader::Remaining()
{
	return Bytes.Num() - Position;
}


uint8 ULowEntryByteDataReader::GetByte()
{
	int32 Pos = GetAndIncreasePosition(1);
	if(Bytes.Num() <= Pos)
	{
		return 0;
	}
	return Bytes[Pos];
}

int32 ULowEntryByteDataReader::GetInteger()
{
	int32 Pos = GetAndIncreasePosition(4);
	if(Bytes.Num() <= Pos)
	{
		return 0;
	}
	return ULowEntryExtendedStandardLibrary::BytesToInteger(Bytes, Pos, 4);
}

int32 ULowEntryByteDataReader::GetUinteger()
{
	int32 Pos = GetAndIncreasePosition(1);
	if(Bytes.Num() <= Pos)
	{
		return 0;
	}
	uint8 B = Bytes[Pos];
	if(((B >> 7) & 1) == 0)
	{
		return B;
	}

	Pos = GetAndIncreasePosition(3);
	if(Bytes.Num() <= (Pos + 2))
	{
		return 0;
	}
	int32 Value = ((B & ~(1 << 7)) << 24) | (Bytes[Pos + 0] << 16) | (Bytes[Pos + 1] << 8) | Bytes[Pos + 2];
	if(Value < 128)
	{
		return 0;
	}
	return Value;
}

int32 ULowEntryByteDataReader::GetPositiveInteger1()
{
	int32 Pos = GetAndIncreasePosition(1);
	if(Bytes.Num() <= Pos)
	{
		return 0;
	}
	uint8 B = Bytes[Pos];
	if(((B >> 7) & 1) == 0)
	{
		return B;
	}

	Pos = GetAndIncreasePosition(3);
	if(Bytes.Num() <= (Pos + 2))
	{
		return 0;
	}
	int32 Value = ((B & ~(1 << 7)) << 24) | (Bytes[Pos + 0] << 16) | (Bytes[Pos + 1] << 8) | Bytes[Pos + 2];
	if(Value < 128)
	{
		return 0;
	}
	return Value;
}

int32 ULowEntryByteDataReader::GetPositiveInteger2()
{
	int32 Pos = GetAndIncreasePosition(2);
	if(Bytes.Num() <= (Pos + 1))
	{
		return 0;
	}
	uint8 B1 = Bytes[Pos + 0];
	uint8 B2 = Bytes[Pos + 1];
	if(((B1 >> 7) & 1) == 0)
	{
		return (B1 << 8) | B2;
	}

	Pos = GetAndIncreasePosition(2);
	if(Bytes.Num() <= (Pos + 1))
	{
		return 0;
	}
	int32 Value = ((B1 & ~(1 << 7)) << 24) | (B2 << 16) | (Bytes[Pos + 0] << 8) | Bytes[Pos + 1];
	if(Value < 32768)
	{
		return 0;
	}
	return Value;
}

int32 ULowEntryByteDataReader::GetPositiveInteger3()
{
	int32 Pos = GetAndIncreasePosition(3);
	if(Bytes.Num() <= (Pos + 2))
	{
		return 0;
	}
	uint8 B1 = Bytes[Pos + 0];
	uint8 B2 = Bytes[Pos + 1];
	uint8 B3 = Bytes[Pos + 2];
	if(((B1 >> 7) & 1) == 0)
	{
		return (B1 << 16) | (B2 << 8) | B3;
	}

	Pos = GetAndIncreasePosition(1);
	if(Bytes.Num() <= Pos)
	{
		return 0;
	}
	int32 Value = ((B1 & ~(1 << 7)) << 24) | (B2 << 16) | (B3 << 8) | Bytes[Pos];
	if(Value < 8388608)
	{
		return 0;
	}
	return Value;
}

ULowEntryLong* ULowEntryByteDataReader::GetLongBytes()
{
	int32 Pos = GetAndIncreasePosition(8);
	if(Bytes.Num() <= Pos)
	{
		return ULowEntryLong::Create();
	}
	return ULowEntryLong::Create(Bytes, Pos, 8);
}

float ULowEntryByteDataReader::GetFloat()
{
	int32 Pos = GetAndIncreasePosition(4);
	if(Bytes.Num() <= Pos)
	{
		return 0;
	}
	return ULowEntryExtendedStandardLibrary::BytesToFloat(Bytes, Pos, 4);
}

ULowEntryDouble* ULowEntryByteDataReader::GetDoubleBytes()
{
	int32 Pos = GetAndIncreasePosition(8);
	if(Bytes.Num() <= Pos)
	{
		return ULowEntryDouble::Create();
	}
	return ULowEntryDouble::Create(Bytes, Pos, 8);
}

bool ULowEntryByteDataReader::GetBoolean()
{
	int32 Pos = GetAndIncreasePosition(1);
	if(Bytes.Num() <= Pos)
	{
		return false;
	}
	return ULowEntryExtendedStandardLibrary::BytesToBoolean(Bytes, Pos, 1);
}

FString ULowEntryByteDataReader::GetStringUtf8()
{
	int32 Length = GetUinteger();
	if(Length <= 0)
	{
		return TEXT("");
	}
	int32 Pos = GetAndIncreasePosition(Length);
	if(Bytes.Num() <= Pos)
	{
		return TEXT("");
	}
	return ULowEntryExtendedStandardLibrary::BytesToStringUtf8(Bytes, Pos, Length);
}


TArray<uint8> ULowEntryByteDataReader::GetByteArray()
{
	int32 Length = GetUinteger();
	if(Length <= 0)
	{
		return TArray<uint8>();
	}
	int32 Pos = GetAndIncreasePosition(Length);
	if(Bytes.Num() <= Pos)
	{
		return TArray<uint8>();
	}
	return ULowEntryExtendedStandardLibrary::BytesSubArray(Bytes, Pos, Length);
}

TArray<int32> ULowEntryByteDataReader::GetIntegerArray()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, MaxElementsRemaining(4));
	if(Length <= 0)
	{
		return TArray<int32>();
	}
	TArray<int32> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetInteger();
	}
	return Array;
}

TArray<int32> ULowEntryByteDataReader::GetPositiveInteger1Array()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, MaxElementsRemaining(1));
	if(Length <= 0)
	{
		return TArray<int32>();
	}
	TArray<int32> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetPositiveInteger1();
	}
	return Array;
}

TArray<int32> ULowEntryByteDataReader::GetPositiveInteger2Array()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, MaxElementsRemaining(2));
	if(Length <= 0)
	{
		return TArray<int32>();
	}
	TArray<int32> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetPositiveInteger2();
	}
	return Array;
}

TArray<int32> ULowEntryByteDataReader::GetPositiveInteger3Array()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, MaxElementsRemaining(3));
	if(Length <= 0)
	{
		return TArray<int32>();
	}
	TArray<int32> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetPositiveInteger3();
	}
	return Array;
}

TArray<ULowEntryLong*> ULowEntryByteDataReader::GetLongBytesArray()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, MaxElementsRemaining(8));
	if(Length <= 0)
	{
		return TArray<ULowEntryLong*>();
	}
	TArray<ULowEntryLong*> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetLongBytes();
	}
	return Array;
}

TArray<float> ULowEntryByteDataReader::GetFloatArray()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, MaxElementsRemaining(4));
	if(Length <= 0)
	{
		return TArray<float>();
	}
	TArray<float> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetFloat();
	}
	return Array;
}

TArray<ULowEntryDouble*> ULowEntryByteDataReader::GetDoubleBytesArray()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, MaxElementsRemaining(8));
	if(Length <= 0)
	{
		return TArray<ULowEntryDouble*>();
	}
	TArray<ULowEntryDouble*> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetDoubleBytes();
	}
	return Array;
}

TArray<bool> ULowEntryByteDataReader::GetBooleanArray()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, SafeMultiply(MaxElementsRemaining(1), 8));
	if(Length <= 0)
	{
		return TArray<bool>();
	}
	TArray<bool> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i += 8)
	{
		uint8 B = GetByte();
		for(int32 BIndex = 0; BIndex < 8; BIndex++)
		{
			int32 Index = i + BIndex;
			if(Index >= Length)
			{
				return Array;
			}
			Array[Index] = (((B >> (7 - BIndex)) & 1) != 0);
		}
	}
	return Array;
}

TArray<FString> ULowEntryByteDataReader::GetStringUtf8Array()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, MaxElementsRemaining(1));
	if(Length <= 0)
	{
		return TArray<FString>();
	}
	TArray<FString> Array;
	Array.SetNumZeroed(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetStringUtf8();
	}
	return Array;
}


int32 ULowEntryByteDataReader::SafeMultiply(const int32 A, const int32 B)
{
	int64 Result = (int64) A * (int64) B;
	int32 Max = 2147483647;
	int32 Min = (-2147483647 - 1);
	if(Result >= Max)
	{
		return Max;
	}
	if(Result <= Min)
	{
		return Min;
	}
	return (int32) Result;
}
