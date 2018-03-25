// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"


class ULowEntryHashingSha256Library
{
private:
	const static int32 k[64];
	const static int32 BLOCK_SIZE = 64;


private:
	TArray<int32>	w;

	int32			h0 = 0x6a09e667;
	int32			h1 = 0xbb67ae85;
	int32			h2 = 0x3c6ef372;
	int32			h3 = 0xa54ff53a;
	int32			h4 = 0x510e527f;
	int32			h5 = 0x9b05688c;
	int32			h6 = 0x1f83d9ab;
	int32			h7 = 0x5be0cd19;

	int32			count = 0;
	TArray<uint8>	buffer;


private:
	void initialize();
	void update(const TArray<uint8>& b, const int32 offset, const int32 len);
	TArray<uint8> digest();
	TArray<uint8> padBuffer();
	TArray<uint8> getResult();
	void sha(const TArray<uint8>& in, int32 offset);
	FORCEINLINE static int32 s(const int32 a, const int32 b);


public:
	static TArray<uint8> Hash(const TArray<uint8>& Bytes);
	static TArray<uint8> Hash(const TArray<uint8>& Bytes, int32 Index, int32 Length);
};
