#pragma once


#include "Engine.h"


class ULowEntryHashingSha512Library
{
private:
	const static int64 k[80];
	const static int32 BLOCK_SIZE = 128;


private:
	UPROPERTY()
	TArray<int64>	w;

	UPROPERTY()
	int64			h0 = 0x6a09e667f3bcc908L;
	UPROPERTY()
	int64			h1 = 0xbb67ae8584caa73bL;
	UPROPERTY()
	int64			h2 = 0x3c6ef372fe94f82bL;
	UPROPERTY()
	int64			h3 = 0xa54ff53a5f1d36f1L;
	UPROPERTY()
	int64			h4 = 0x510e527fade682d1L;
	UPROPERTY()
	int64			h5 = 0x9b05688c2b3e6c1fL;
	UPROPERTY()
	int64			h6 = 0x1f83d9abfb41bd6bL;
	UPROPERTY()
	int64			h7 = 0x5be0cd19137e2179L;

	UPROPERTY()
	int32			count = 0;
	UPROPERTY()
	TArray<uint8>	buffer;


private:
	void initialize();
	void update(const TArray<uint8>& b, const int32 offset, const int32 len);
	TArray<uint8> digest();
	TArray<uint8> padBuffer();
	TArray<uint8> getResult();
	void sha(const TArray<uint8>& in, int32 offset);
	FORCEINLINE static int64 s(const int64 a, const int32 b);


public:
	static TArray<uint8> Hash(const TArray<uint8>& Bytes);
	static TArray<uint8> Hash(const TArray<uint8>& Bytes, int32 Index, int32 Length);
};
