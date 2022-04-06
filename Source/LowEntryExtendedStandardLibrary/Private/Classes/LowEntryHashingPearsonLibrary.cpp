// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryHashingPearsonLibrary.h"


constexpr uint8 ULowEntryHashingPearsonLibrary::pearson[256] = {static_cast<uint8>(0x62), static_cast<uint8>(0x06), static_cast<uint8>(0x55), static_cast<uint8>(0x96), static_cast<uint8>(0x24), static_cast<uint8>(0x17), static_cast<uint8>(0x70), static_cast<uint8>(0xA4), static_cast<uint8>(0x87), static_cast<uint8>(0xCF), static_cast<uint8>(0xA9), static_cast<uint8>(0x05), static_cast<uint8>(0x1A), static_cast<uint8>(0x40), static_cast<uint8>(0xA5), static_cast<uint8>(0xDB), static_cast<uint8>(0x3D), static_cast<uint8>(0x14), static_cast<uint8>(0x44), static_cast<uint8>(0x59), static_cast<uint8>(0x82), static_cast<uint8>(0x3F), static_cast<uint8>(0x34), static_cast<uint8>(0x66), static_cast<uint8>(0x18), static_cast<uint8>(0xE5), static_cast<uint8>(0x84), static_cast<uint8>(0xF5), static_cast<uint8>(0x50), static_cast<uint8>(0xD8), static_cast<uint8>(0xC3), static_cast<uint8>(0x73), static_cast<uint8>(0x5A), static_cast<uint8>(0xA8), static_cast<uint8>(0x9C), static_cast<uint8>(0xCB), static_cast<uint8>(0xB1), static_cast<uint8>(0x78), static_cast<uint8>(0x02), static_cast<uint8>(0xBE), static_cast<uint8>(0xBC), static_cast<uint8>(0x07), static_cast<uint8>(0x64), static_cast<uint8>(0xB9), static_cast<uint8>(0xAE), static_cast<uint8>(0xF3), static_cast<uint8>(0xA2), static_cast<uint8>(0x0A), static_cast<uint8>(0xED), static_cast<uint8>(0x12), static_cast<uint8>(0xFD), static_cast<uint8>(0xE1), static_cast<uint8>(0x08), static_cast<uint8>(0xD0), static_cast<uint8>(0xAC), static_cast<uint8>(0xF4), static_cast<uint8>(0xFF), static_cast<uint8>(0x7E), static_cast<uint8>(0x65), static_cast<uint8>(0x4F), static_cast<uint8>(0x91), static_cast<uint8>(0xEB), static_cast<uint8>(0xE4), static_cast<uint8>(0x79), static_cast<uint8>(0x7B), static_cast<uint8>(0xFB), static_cast<uint8>(0x43), static_cast<uint8>(0xFA), static_cast<uint8>(0xA1), static_cast<uint8>(0x00), static_cast<uint8>(0x6B), static_cast<uint8>(0x61), static_cast<uint8>(0xF1), static_cast<uint8>(0x6F), static_cast<uint8>(0xB5), static_cast<uint8>(0x52), static_cast<uint8>(0xF9), static_cast<uint8>(0x21), static_cast<uint8>(0x45), static_cast<uint8>(0x37), static_cast<uint8>(0x3B), static_cast<uint8>(0x99), static_cast<uint8>(0x1D), static_cast<uint8>(0x09), static_cast<uint8>(0xD5), static_cast<uint8>(0xA7), static_cast<uint8>(0x54), static_cast<uint8>(0x5D), static_cast<uint8>(0x1E), static_cast<uint8>(0x2E), static_cast<uint8>(0x5E), static_cast<uint8>(0x4B), static_cast<uint8>(0x97), static_cast<uint8>(0x72), static_cast<uint8>(0x49), static_cast<uint8>(0xDE), static_cast<uint8>(0xC5), static_cast<uint8>(0x60), static_cast<uint8>(0xD2), static_cast<uint8>(0x2D), static_cast<uint8>(0x10), static_cast<uint8>(0xE3), static_cast<uint8>(0xF8), static_cast<uint8>(0xCA), static_cast<uint8>(0x33), static_cast<uint8>(0x98), static_cast<uint8>(0xFC), static_cast<uint8>(0x7D), static_cast<uint8>(0x51), static_cast<uint8>(0xCE), static_cast<uint8>(0xD7), static_cast<uint8>(0xBA), static_cast<uint8>(0x27), static_cast<uint8>(0x9E), static_cast<uint8>(0xB2), static_cast<uint8>(0xBB), static_cast<uint8>(0x83), static_cast<uint8>(0x88), static_cast<uint8>(0x01), static_cast<uint8>(0x31), static_cast<uint8>(0x32), static_cast<uint8>(0x11), static_cast<uint8>(0x8D), static_cast<uint8>(0x5B), static_cast<uint8>(0x2F), static_cast<uint8>(0x81), static_cast<uint8>(0x3C), static_cast<uint8>(0x63), static_cast<uint8>(0x9A), static_cast<uint8>(0x23), static_cast<uint8>(0x56), static_cast<uint8>(0xAB), static_cast<uint8>(0x69), static_cast<uint8>(0x22), static_cast<uint8>(0x26), static_cast<uint8>(0xC8), static_cast<uint8>(0x93), static_cast<uint8>(0x3A), static_cast<uint8>(0x4D), static_cast<uint8>(0x76), static_cast<uint8>(0xAD), static_cast<uint8>(0xF6), static_cast<uint8>(0x4C), static_cast<uint8>(0xFE), static_cast<uint8>(0x85), static_cast<uint8>(0xE8), static_cast<uint8>(0xC4), static_cast<uint8>(0x90), static_cast<uint8>(0xC6), static_cast<uint8>(0x7C), static_cast<uint8>(0x35), static_cast<uint8>(0x04), static_cast<uint8>(0x6C), static_cast<uint8>(0x4A), static_cast<uint8>(0xDF), static_cast<uint8>(0xEA), static_cast<uint8>(0x86), static_cast<uint8>(0xE6), static_cast<uint8>(0x9D), static_cast<uint8>(0x8B), static_cast<uint8>(0xBD), static_cast<uint8>(0xCD), static_cast<uint8>(0xC7), static_cast<uint8>(0x80), static_cast<uint8>(0xB0), static_cast<uint8>(0x13), static_cast<uint8>(0xD3), static_cast<uint8>(0xEC), static_cast<uint8>(0x7F), static_cast<uint8>(0xC0), static_cast<uint8>(0xE7), static_cast<uint8>(0x46), static_cast<uint8>(0xE9), static_cast<uint8>(0x58), static_cast<uint8>(0x92), static_cast<uint8>(0x2C), static_cast<uint8>(0xB7), static_cast<uint8>(0xC9), static_cast<uint8>(0x16), static_cast<uint8>(0x53), static_cast<uint8>(0x0D), static_cast<uint8>(0xD6), static_cast<uint8>(0x74), static_cast<uint8>(0x6D), static_cast<uint8>(0x9F), static_cast<uint8>(0x20), static_cast<uint8>(0x5F), static_cast<uint8>(0xE2), static_cast<uint8>(0x8C), static_cast<uint8>(0xDC), static_cast<uint8>(0x39), static_cast<uint8>(0x0C), static_cast<uint8>(0xDD), static_cast<uint8>(0x1F), static_cast<uint8>(0xD1), static_cast<uint8>(0xB6), static_cast<uint8>(0x8F), static_cast<uint8>(0x5C), static_cast<uint8>(0x95), static_cast<uint8>(0xB8), static_cast<uint8>(0x94), static_cast<uint8>(0x3E), static_cast<uint8>(0x71), static_cast<uint8>(0x41), static_cast<uint8>(0x25), static_cast<uint8>(0x1B), static_cast<uint8>(0x6A), static_cast<uint8>(0xA6), static_cast<uint8>(0x03), static_cast<uint8>(0x0E), static_cast<uint8>(0xCC), static_cast<uint8>(0x48), static_cast<uint8>(0x15), static_cast<uint8>(0x29), static_cast<uint8>(0x38), static_cast<uint8>(0x42), static_cast<uint8>(0x1C), static_cast<uint8>(0xC1), static_cast<uint8>(0x28), static_cast<uint8>(0xD9), static_cast<uint8>(0x19), static_cast<uint8>(0x36), static_cast<uint8>(0xB3), static_cast<uint8>(0x75), static_cast<uint8>(0xEE), static_cast<uint8>(0x57), static_cast<uint8>(0xF0), static_cast<uint8>(0x9B), static_cast<uint8>(0xB4), static_cast<uint8>(0xAA), static_cast<uint8>(0xF2), static_cast<uint8>(0xD4), static_cast<uint8>(0xBF), static_cast<uint8>(0xA3), static_cast<uint8>(0x4E), static_cast<uint8>(0xDA), static_cast<uint8>(0x89), static_cast<uint8>(0xC2), static_cast<uint8>(0xAF), static_cast<uint8>(0x6E), static_cast<uint8>(0x2B), static_cast<uint8>(0x77), static_cast<uint8>(0xE0), static_cast<uint8>(0x47), static_cast<uint8>(0x7A), static_cast<uint8>(0x8E), static_cast<uint8>(0x2A), static_cast<uint8>(0xA0), static_cast<uint8>(0x68), static_cast<uint8>(0x30), static_cast<uint8>(0xF7), static_cast<uint8>(0x67), static_cast<uint8>(0x0F), static_cast<uint8>(0x0B), static_cast<uint8>(0x8A), static_cast<uint8>(0xEF)};


TArray<uint8> ULowEntryHashingPearsonLibrary::Hash(const TArray<uint8>& Bytes, int32 Index, int32 Length, const int32 HashLength)
{
	if (HashLength <= 0)
	{
		return TArray<uint8>();
	}

	TArray<uint8> hh;
	hh.SetNum(HashLength);

	if (Bytes.Num() <= 0)
	{
		return hh;
	}

	if (Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if (Length > (Bytes.Num() - Index))
	{
		Length = Bytes.Num() - Index;
	}
	if (Length <= 0)
	{
		return hh;
	}

	for (int32 j = 0; j < HashLength; j++)
	{
		uint8 h = pearson[(Bytes[Index] + j) & 0xff];
		for (int32 i = 1; i < Length; i++)
		{
			h = pearson[(h ^ Bytes[(Index + i) & 0xff]) & 0xff];
		}
		hh[j] = h;
	}
	return hh;
}
