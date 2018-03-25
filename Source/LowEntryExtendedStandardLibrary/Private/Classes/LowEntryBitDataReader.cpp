// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryBitDataReader.h"
#include "LowEntryExtendedStandardLibrary.h"


const uint8 ULowEntryBitDataReader::mask[9] = {((uint8) 0x00), ((uint8) 0x01), ((uint8) 0x03), ((uint8) 0x07), ((uint8) 0x0F), ((uint8) 0x1F), ((uint8) 0x3F), ((uint8) 0x7F), ((uint8) 0xFF)};


// init >>
	ULowEntryBitDataReader::ULowEntryBitDataReader(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryBitDataReader* ULowEntryBitDataReader::Create(const TArray<uint8>& Bytes, int32 Index, int32 Length)
	{
		ULowEntryBitDataReader* Item = NewObject<ULowEntryBitDataReader>();
		Item->Bytes = ULowEntryExtendedStandardLibrary::BytesSubArray(Bytes, Index, Length);
		return Item;
	}

	ULowEntryBitDataReader* ULowEntryBitDataReader::CreateClone(const TArray<uint8>& Bytes, const int32 Position, const uint8 CurrentByte, const int32 CurrentBytePosition)
	{
		ULowEntryBitDataReader* Item = NewObject<ULowEntryBitDataReader>();
		Item->Bytes = Bytes;
		Item->Position = Position;
		Item->CurrentByte = CurrentByte;
		Item->CurrentBytePosition = CurrentBytePosition;
		return Item;
	}
// init <<


int32 ULowEntryBitDataReader::GetAndIncreasePosition(const int32 Increasement)
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

int32 ULowEntryBitDataReader::MaxElementsRemaining(const int32 MinimumSizePerElement)
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


ULowEntryBitDataReader* ULowEntryBitDataReader::GetClone()
{
	return ULowEntryBitDataReader::CreateClone(Bytes, Position, CurrentByte, CurrentBytePosition);
}

int32 ULowEntryBitDataReader::ULowEntryBitDataReader::GetPosition()
{
	return (Position * 8) + CurrentBytePosition;
}

void ULowEntryBitDataReader::SetPosition(const int32 Position_)
{
	if(Position_ < 0)
	{
		Reset();
	}
	else
	{
		Position = Position_ / 8;
		CurrentBytePosition = Position_ % 8;
		CurrentByte = 0;
		if(Position > Bytes.Num())
		{
			Position = Bytes.Num();
			CurrentBytePosition = 0;
		}
		else if(CurrentBytePosition > 0)
		{
			if(Position == 0)
			{
				CurrentBytePosition = 0;
			}
			else
			{
				CurrentByte = Bytes[Position - 1];
			}
		}
	}
}

void ULowEntryBitDataReader::Reset()
{
	Position = 0;
	CurrentBytePosition = 0;
	CurrentByte = 0;
}

void ULowEntryBitDataReader::Empty()
{
	Position = Bytes.Num();
	CurrentBytePosition = 0;
	CurrentByte = 0;
}

int32 ULowEntryBitDataReader::Remaining()
{
	if(CurrentBytePosition != 0)
	{
		return (Bytes.Num() - Position) + 1;
	}
	return Bytes.Num() - Position;
}


bool ULowEntryBitDataReader::GetRawBit()
{
	if(CurrentBytePosition == 0)
	{
		int32 pos = GetAndIncreasePosition(1);
		if(Bytes.Num() <= pos)
		{
			return false;
		}
		CurrentByte = Bytes[pos];
	}

	bool bit = (((CurrentByte >> CurrentBytePosition) & 1) != 0);

	if(CurrentBytePosition == 7)
	{
		CurrentBytePosition = 0;
	}
	else
	{
		CurrentBytePosition++;
	}

	return bit;
}

uint8 ULowEntryBitDataReader::GetRawByte()
{
	if(CurrentBytePosition == 0)
	{
		int32 pos = GetAndIncreasePosition(1);
		if(Bytes.Num() <= pos)
		{
			return 0;
		}
		return Bytes[pos];
	}
	else
	{
		uint8 b = ((CurrentByte >> CurrentBytePosition) & mask[8 - CurrentBytePosition]);

		int32 pos = GetAndIncreasePosition(1);
		if(Bytes.Num() <= pos)
		{
			CurrentBytePosition = 0;
			return b;
		}
		CurrentByte = Bytes[pos];

		return (b | (CurrentByte << (8 - CurrentBytePosition)));
	}
}

uint8 ULowEntryBitDataReader::GetPartialRawByte(int32 Bits)
{
	if(Bits == 0)
	{
		return 0;
	}
	if((Bits >= 8) || (Bits <= -8))
	{
		return GetRawByte();
	}

	if(CurrentBytePosition == 0)
	{
		int32 pos = GetAndIncreasePosition(1);
		if(Bytes.Num() <= pos)
		{
			return 0;
		}
		CurrentByte = Bytes[pos];
	}

	bool mostSignificantBits = false;
	if(Bits < 0)
	{
		Bits = -Bits;
		mostSignificantBits = true;
	}

	uint8 b = ((CurrentByte >> CurrentBytePosition) & mask[8 - CurrentBytePosition]);
	CurrentBytePosition += Bits;

	if(CurrentBytePosition >= 8)
	{
		int32 pos = GetAndIncreasePosition(1);
		if(Bytes.Num() <= pos)
		{
			CurrentBytePosition = 0;
			b = (b & mask[Bits]);
			if(mostSignificantBits)
			{
				return (b << (8 - Bits));
			}
			return b;
		}
		CurrentByte = Bytes[pos];
		CurrentBytePosition -= 8;

		if(CurrentBytePosition != 0)
		{
			b = ((b | (CurrentByte << (Bits - CurrentBytePosition))) & mask[Bits]);
			if(mostSignificantBits)
			{
				return (b << (8 - Bits));
			}
			return b;
		}
	}
	b = (b & mask[Bits]);
	if(mostSignificantBits)
	{
		return (b << (8 - Bits));
	}
	return b;
}


bool ULowEntryBitDataReader::GetBit()
{
	return GetRawBit();
}

uint8 ULowEntryBitDataReader::GetByteLeastSignificantBits(const int32 BitCount)
{
	if(BitCount <= 0)
	{
		return 0;
	}
	return GetPartialRawByte(BitCount);
}

uint8 ULowEntryBitDataReader::GetByteMostSignificantBits(const int32 BitCount)
{
	if(BitCount <= 0)
	{
		return 0;
	}
	return GetPartialRawByte(-BitCount);
}

int32 ULowEntryBitDataReader::GetIntegerLeastSignificantBits(const int32 BitCount)
{
	if(BitCount <= 0)
	{
		return 0;
	}
	if(BitCount >= 32)
	{
		uint8 b1 = GetRawByte();
		uint8 b2 = GetRawByte();
		uint8 b3 = GetRawByte();
		uint8 b4 = GetRawByte();
		return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
	}
	else if(BitCount > 24)
	{
		uint8 b1 = GetRawByte();
		uint8 b2 = GetRawByte();
		uint8 b3 = GetRawByte();
		uint8 b4 = GetPartialRawByte(BitCount - 24);
		return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
	}
	else if(BitCount > 16)
	{
		uint8 b1 = GetRawByte();
		uint8 b2 = GetRawByte();
		uint8 b3 = GetPartialRawByte(BitCount - 16);
		return (b3 << 16) | (b2 << 8) | b1;
	}
	else if(BitCount > 8)
	{
		uint8 b1 = GetRawByte();
		uint8 b2 = GetPartialRawByte(BitCount - 8);
		return (b2 << 8) | b1;
	}
	else
	{
		uint8 b1 = GetPartialRawByte(BitCount);
		return b1;
	}
}

int32 ULowEntryBitDataReader::GetIntegerMostSignificantBits(int32 BitCount)
{
	if(BitCount <= 0)
	{
		return 0;
	}
	BitCount = -BitCount;
	if(BitCount <= -32)
	{
		uint8 b1 = GetRawByte();
		uint8 b2 = GetRawByte();
		uint8 b3 = GetRawByte();
		uint8 b4 = GetRawByte();
		return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
	}
	else if(BitCount < -24)
	{
		uint8 b1 = GetPartialRawByte(BitCount + 24);
		uint8 b2 = GetRawByte();
		uint8 b3 = GetRawByte();
		uint8 b4 = GetRawByte();
		return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
	}
	else if(BitCount < -16)
	{
		uint8 b1 = GetPartialRawByte(BitCount + 16);
		uint8 b2 = GetRawByte();
		uint8 b3 = GetRawByte();
		return (b3 << 24) | (b2 << 16) | (b1 << 8);
	}
	else if(BitCount < -8)
	{
		uint8 b1 = GetPartialRawByte(BitCount + 8);
		uint8 b2 = GetRawByte();
		return (b2 << 24) | (b1 << 16);
	}
	else
	{
		uint8 b1 = GetPartialRawByte(BitCount);
		return (b1 << 24);
	}
}

uint8 ULowEntryBitDataReader::GetByte()
{
	return GetRawByte();
}

int32 ULowEntryBitDataReader::GetInteger()
{
	int32 RemainingCount = Remaining();
	if(RemainingCount >= 4)
	{
		uint8 b1 = GetRawByte();
		uint8 b2 = GetRawByte();
		uint8 b3 = GetRawByte();
		uint8 b4 = GetRawByte();
		return (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
	}
	if(RemainingCount == 3)
	{
		uint8 b1 = GetRawByte();
		uint8 b2 = GetRawByte();
		uint8 b3 = GetRawByte();
		return (b1 << 16) | (b2 << 8) | b3;
	}
	if(RemainingCount == 2)
	{
		uint8 b1 = GetRawByte();
		uint8 b2 = GetRawByte();
		return (b1 << 8) | b2;
	}
	if(RemainingCount == 1)
	{
		return GetRawByte();
	}
	return 0;
}

int32 ULowEntryBitDataReader::GetUinteger()
{
	if(Remaining() < 1)
	{
		return 0;
	}

	uint8 b1 = GetRawByte();
	if(((b1 >> 7) & 1) == 0)
	{
		return b1;
	}

	if(Remaining() < 3)
	{
		Empty();
		return 0;
	}

	uint8 b2 = GetRawByte();
	uint8 b3 = GetRawByte();
	uint8 b4 = GetRawByte();

	int32 Value = ((b1 & ~(1 << 7)) << 24) | (b2 << 16) | (b3 << 8) | b4;
	if(Value < 128)
	{
		return 0;
	}
	return Value;
}

int32 ULowEntryBitDataReader::GetPositiveInteger1()
{
	if(Remaining() < 1)
	{
		return 0;
	}

	uint8 b1 = GetRawByte();
	if(((b1 >> 7) & 1) == 0)
	{
		return b1;
	}

	if(Remaining() < 3)
	{
		Empty();
		return 0;
	}

	uint8 b2 = GetRawByte();
	uint8 b3 = GetRawByte();
	uint8 b4 = GetRawByte();

	int32 Value = ((b1 & ~(1 << 7)) << 24) | (b2 << 16) | (b3 << 8) | b4;
	if(Value < 128)
	{
		return 0;
	}
	return Value;
}

int32 ULowEntryBitDataReader::GetPositiveInteger2()
{
	if(Remaining() < 2)
	{
		Empty();
		return 0;
	}

	uint8 b1 = GetRawByte();
	uint8 b2 = GetRawByte();
	if(((b1 >> 7) & 1) == 0)
	{
		return (b1 << 8) | b2;
	}

	if(Remaining() < 2)
	{
		Empty();
		return 0;
	}

	uint8 b3 = GetRawByte();
	uint8 b4 = GetRawByte();

	int32 Value = ((b1 & ~(1 << 7)) << 24) | (b2 << 16) | (b3 << 8) | b4;
	if(Value < 32768)
	{
		return 0;
	}
	return Value;
}

int32 ULowEntryBitDataReader::GetPositiveInteger3()
{
	if(Remaining() < 3)
	{
		Empty();
		return 0;
	}

	uint8 b1 = GetRawByte();
	uint8 b2 = GetRawByte();
	uint8 b3 = GetRawByte();
	if(((b1 >> 7) & 1) == 0)
	{
		return (b1 << 16) | (b2 << 8) | b3;
	}

	if(Remaining() < 1)
	{
		Empty();
		return 0;
	}

	uint8 b4 = GetRawByte();

	int32 Value = ((b1 & ~(1 << 7)) << 24) | (b2 << 16) | (b3 << 8) | b4;
	if(Value < 8388608)
	{
		return 0;
	}
	return Value;
}

ULowEntryLong* ULowEntryBitDataReader::GetLongBytes()
{
	TArray<uint8> Data;
	int32 RemainingCount = Remaining();
	if(RemainingCount >= 8)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 7)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 6)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 5)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 4)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 3)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 2)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 1)
	{
		Data.Add(GetRawByte());
	}
	return ULowEntryLong::Create(Data);
}

float ULowEntryBitDataReader::GetFloat()
{
	int32 IntValue = GetInteger();
	return *((float*) (&IntValue));
}

ULowEntryDouble* ULowEntryBitDataReader::GetDoubleBytes()
{
	TArray<uint8> Data;
	int32 RemainingCount = Remaining();
	if(RemainingCount >= 8)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 7)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 6)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 5)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 4)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 3)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 2)
	{
		Data.Add(GetRawByte());
		Data.Add(GetRawByte());
	}
	else if(RemainingCount == 1)
	{
		Data.Add(GetRawByte());
	}
	return ULowEntryDouble::Create(Data);
}

bool ULowEntryBitDataReader::GetBoolean()
{
	return GetRawBit();
}

FString ULowEntryBitDataReader::GetStringUtf8()
{
	int32 length = GetUinteger();
	length = FMath::Min(length, MaxElementsRemaining(1));
	if(length <= 0)
	{
		return "";
	}
	if(CurrentBytePosition == 0)
	{
		int32 pos = GetAndIncreasePosition(length);
		return ULowEntryExtendedStandardLibrary::BytesToStringUtf8(Bytes, pos, length);
	}
	TArray<uint8> Data;
	Data.SetNum(length);
	for(int i = 0; i < length; i++)
	{
		Data[i] = GetRawByte();
	}
	return ULowEntryExtendedStandardLibrary::BytesToStringUtf8(Data);
}


TArray<bool> ULowEntryBitDataReader::GetBitArray()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, SafeMultiply(MaxElementsRemaining(1), 8));
	if(Length <= 0)
	{
		return TArray<bool>();
	}
	TArray<bool> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetBoolean();
	}
	return Array;
}

TArray<uint8> ULowEntryBitDataReader::GetByteArrayLeastSignificantBits(const int32 BitCount)
{
	int32 Length = GetUinteger();
	if(BitCount <= 0)
	{
		return TArray<uint8>();
	}
	Length = (int) FMath::Min((double) Length, FMath::CeilToDouble(MaxElementsRemaining(1) * (8.0 / BitCount)));
	if(Length <= 0)
	{
		return TArray<uint8>();
	}
	TArray<uint8> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetByteLeastSignificantBits(BitCount);
	}
	return Array;
}

TArray<uint8> ULowEntryBitDataReader::GetByteArrayMostSignificantBits(const int32 BitCount)
{
	int32 Length = GetUinteger();
	if(BitCount <= 0)
	{
		return TArray<uint8>();
	}
	Length = (int) FMath::Min((double) Length, FMath::CeilToDouble(MaxElementsRemaining(1) * (8.0 / BitCount)));
	if(Length <= 0)
	{
		return TArray<uint8>();
	}
	TArray<uint8> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetByteMostSignificantBits(BitCount);
	}
	return Array;
}

TArray<int32> ULowEntryBitDataReader::GetIntegerArrayLeastSignificantBits(const int32 BitCount)
{
	int32 Length = GetUinteger();
	if(BitCount <= 0)
	{
		return TArray<int32>();
	}
	Length = (int) FMath::Min((double) Length, FMath::CeilToDouble(MaxElementsRemaining(1) * (8.0 / BitCount)));
	if(Length <= 0)
	{
		return TArray<int32>();
	}
	TArray<int32> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetIntegerLeastSignificantBits(BitCount);
	}
	return Array;
}

TArray<int32> ULowEntryBitDataReader::GetIntegerArrayMostSignificantBits(const int32 BitCount)
{
	int32 Length = GetUinteger();
	if(BitCount <= 0)
	{
		return TArray<int32>();
	}
	Length = (int) FMath::Min((double) Length, FMath::CeilToDouble(MaxElementsRemaining(1) * (8.0 / BitCount)));
	if(Length <= 0)
	{
		return TArray<int32>();
	}
	TArray<int32> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetIntegerMostSignificantBits(BitCount);
	}
	return Array;
}

TArray<uint8> ULowEntryBitDataReader::GetByteArray()
{
	int32 length = GetUinteger();
	length = FMath::Min(length, MaxElementsRemaining(1));
	if(length <= 0)
	{
		return TArray<uint8>();
	}
	if(CurrentBytePosition == 0)
	{
		int32 pos = GetAndIncreasePosition(length);
		return ULowEntryExtendedStandardLibrary::BytesSubArray(Bytes, pos, length);
	}
	TArray<uint8> Data;
	Data.SetNum(length);
	for(int i = 0; i < length; i++)
	{
		Data[i] = GetRawByte();
	}
	return Data;
}

TArray<int32> ULowEntryBitDataReader::GetIntegerArray()
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

TArray<int32> ULowEntryBitDataReader::GetPositiveInteger1Array()
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

TArray<int32> ULowEntryBitDataReader::GetPositiveInteger2Array()
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

TArray<int32> ULowEntryBitDataReader::GetPositiveInteger3Array()
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

TArray<ULowEntryLong*> ULowEntryBitDataReader::GetLongBytesArray()
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

TArray<float> ULowEntryBitDataReader::GetFloatArray()
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

TArray<ULowEntryDouble*> ULowEntryBitDataReader::GetDoubleBytesArray()
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

TArray<bool> ULowEntryBitDataReader::GetBooleanArray()
{
	int32 Length = GetUinteger();
	Length = FMath::Min(Length, SafeMultiply(MaxElementsRemaining(1), 8));
	if(Length <= 0)
	{
		return TArray<bool>();
	}
	TArray<bool> Array;
	Array.SetNum(Length);
	for(int32 i = 0; i < Length; i++)
	{
		Array[i] = GetBoolean();
	}
	return Array;
}

TArray<FString> ULowEntryBitDataReader::GetStringUtf8Array()
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


int32 ULowEntryBitDataReader::SafeMultiply(const int32 A, const int32 B)
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
