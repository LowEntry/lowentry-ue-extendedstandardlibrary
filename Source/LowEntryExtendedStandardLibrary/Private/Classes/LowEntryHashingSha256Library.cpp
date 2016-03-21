#include "LowEntryExtendedStandardLibraryPrivatePCH.h"
#include "LowEntryHashingSha256Library.h"


const int32 ULowEntryHashingSha256Library::k[64] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};


void ULowEntryHashingSha256Library::initialize()
{
	w.SetNum(64);
	buffer.SetNum(64);
}

void ULowEntryHashingSha256Library::update(const TArray<uint8>& b, const int32 offset, const int32 len)
{
	int32 n = count % BLOCK_SIZE;
	count += len;
	int32 partLen = BLOCK_SIZE - n;
	int32 i = 0;

	if(len >= partLen)
	{
		for(int32 index = 0; index < partLen; index++)
		{
			buffer[n + index] = b[offset + index];
		}
		sha(buffer, 0);
		for(i = partLen; ((i + BLOCK_SIZE) - 1) < len; i += BLOCK_SIZE)
		{
			sha(b, offset + i);
		}
		n = 0;
	}

	if(i < len)
	{
		for(int32 index = 0; index < len - i; index++)
		{
			buffer[n + index] = b[offset + i + index];
		}
	}
}

TArray<uint8> ULowEntryHashingSha256Library::digest()
{
	TArray<uint8> tail = padBuffer();
	update(tail, 0, tail.Num());
	return getResult();
}

TArray<uint8> ULowEntryHashingSha256Library::padBuffer()
{
	int32 n = count % BLOCK_SIZE;
	int32 padding = (n < 56) ? (56 - n) : (120 - n);
	TArray<uint8> result;
	result.SetNum(padding + 8);
	result[0] = (uint8) 0x80;
	int64 bits = count << 3;
	result[padding + 0] = (uint8) (bits >> 56);
	result[padding + 1] = (uint8) (bits >> 48);
	result[padding + 2] = (uint8) (bits >> 40);
	result[padding + 3] = (uint8) (bits >> 32);
	result[padding + 4] = (uint8) (bits >> 24);
	result[padding + 5] = (uint8) (bits >> 16);
	result[padding + 6] = (uint8) (bits >> 8);
	result[padding + 7] = (uint8) bits;
	padding += 8;
	return result;
}

TArray<uint8> ULowEntryHashingSha256Library::getResult()
{
	TArray<uint8> result;
	result.SetNumUninitialized(32);

	result[0] = (uint8) (h0 >> 24);
	result[1] = (uint8) (h0 >> 16);
	result[2] = (uint8) (h0 >> 8);
	result[3] = (uint8) (h0);

	result[4] = (uint8) (h1 >> 24);
	result[5] = (uint8) (h1 >> 16);
	result[6] = (uint8) (h1 >> 8);
	result[7] = (uint8) (h1);

	result[8] = (uint8) (h2 >> 24);
	result[9] = (uint8) (h2 >> 16);
	result[10] = (uint8) (h2 >> 8);
	result[11] = (uint8) (h2);

	result[12] = (uint8) (h3 >> 24);
	result[13] = (uint8) (h3 >> 16);
	result[14] = (uint8) (h3 >> 8);
	result[15] = (uint8) (h3);

	result[16] = (uint8) (h4 >> 24);
	result[17] = (uint8) (h4 >> 16);
	result[18] = (uint8) (h4 >> 8);
	result[19] = (uint8) (h4);

	result[20] = (uint8) (h5 >> 24);
	result[21] = (uint8) (h5 >> 16);
	result[22] = (uint8) (h5 >> 8);
	result[23] = (uint8) (h5);

	result[24] = (uint8) (h6 >> 24);
	result[25] = (uint8) (h6 >> 16);
	result[26] = (uint8) (h6 >> 8);
	result[27] = (uint8) (h6);

	result[28] = (uint8) (h7 >> 24);
	result[29] = (uint8) (h7 >> 16);
	result[30] = (uint8) (h7 >> 8);
	result[31] = (uint8) (h7);

	return result;
}

void ULowEntryHashingSha256Library::sha(const TArray<uint8>& in, int32 offset)
{
	int32 A = h0;
	int32 B = h1;
	int32 C = h2;
	int32 D = h3;
	int32 E = h4;
	int32 F = h5;
	int32 G = h6;
	int32 H = h7;
	int32 T;
	int32 T2;
	int32 r;
	for(r = 0; r < 16; r++)
	{
		w[r] = ((in[offset] << 24) | ((in[offset + 1] & 0xFF) << 16) | ((in[offset + 2] & 0xFF) << 8) | (in[offset + 3] & 0xFF));
		offset += 4;
	}
	for(r = 16; r < 64; r++)
	{
		T = w[r - 2];
		T2 = w[r - 15];
		w[r] = (((s(T, 17) | (T << 15)) ^ (s(T, 19) | (T << 13)) ^ s(T, 10)) + w[r - 7] + ((s(T2, 7) | (T2 << 25)) ^ (s(T2, 18) | (T2 << 14)) ^ s(T2, 3)) + w[r - 16]);
	}
	for(r = 0; r < 64; r++)
	{
		T = (H + ((s(E, 6) | (E << 26)) ^ (s(E, 11) | (E << 21)) ^ (s(E, 25) | (E << 7))) + ((E & F) ^ (~E & G)) + k[r] + w[r]);
		T2 = (((s(A, 2) | (A << 30)) ^ (s(A, 13) | (A << 19)) ^ (s(A, 22) | (A << 10))) + ((A & B) ^ (A & C) ^ (B & C)));
		H = G;
		G = F;
		F = E;
		E = D + T;
		D = C;
		C = B;
		B = A;
		A = T + T2;
	}
	h0 += A;
	h1 += B;
	h2 += C;
	h3 += D;
	h4 += E;
	h5 += F;
	h6 += G;
	h7 += H;
}

int32 ULowEntryHashingSha256Library::s(const int32 a, const int32 b)
{
	const uint32 A = a;
	const uint32 B = b;
	return (A >> B);
}


TArray<uint8> ULowEntryHashingSha256Library::Hash(const TArray<uint8>& Bytes)
{
	ULowEntryHashingSha256Library instance = ULowEntryHashingSha256Library();
	instance.initialize();
	instance.update(Bytes, 0, Bytes.Num());
	return instance.digest();
}

TArray<uint8> ULowEntryHashingSha256Library::Hash(const TArray<uint8>& Bytes, int32 Index, int32 Length)
{
	if(Bytes.Num() <= 0)
	{
		ULowEntryHashingSha256Library instance = ULowEntryHashingSha256Library();
		instance.initialize();
		return instance.digest();
	}

	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length > (Bytes.Num() - Index))
	{
		Length = Bytes.Num() - Index;
	}

	if(Length <= 0)
	{
		ULowEntryHashingSha256Library instance = ULowEntryHashingSha256Library();
		instance.initialize();
		return instance.digest();
	}

	ULowEntryHashingSha256Library instance = ULowEntryHashingSha256Library();
	instance.initialize();
	instance.update(Bytes, Index, Length);
	return instance.digest();
}
