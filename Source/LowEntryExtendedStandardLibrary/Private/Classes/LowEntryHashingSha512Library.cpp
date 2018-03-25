// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryHashingSha512Library.h"


const int64 ULowEntryHashingSha512Library::k[80] = {((int64) 0x428a2f98d728ae22), ((int64) 0x7137449123ef65cd), ((int64) 0xb5c0fbcfec4d3b2f), ((int64) 0xe9b5dba58189dbbc), ((int64) 0x3956c25bf348b538), ((int64) 0x59f111f1b605d019), ((int64) 0x923f82a4af194f9b), ((int64) 0xab1c5ed5da6d8118), ((int64) 0xd807aa98a3030242), ((int64) 0x12835b0145706fbe), ((int64) 0x243185be4ee4b28c), ((int64) 0x550c7dc3d5ffb4e2), ((int64) 0x72be5d74f27b896f), ((int64) 0x80deb1fe3b1696b1), ((int64) 0x9bdc06a725c71235), ((int64) 0xc19bf174cf692694), ((int64) 0xe49b69c19ef14ad2), ((int64) 0xefbe4786384f25e3), ((int64) 0x0fc19dc68b8cd5b5), ((int64) 0x240ca1cc77ac9c65), ((int64) 0x2de92c6f592b0275), ((int64) 0x4a7484aa6ea6e483), ((int64) 0x5cb0a9dcbd41fbd4), ((int64) 0x76f988da831153b5), ((int64) 0x983e5152ee66dfab), ((int64) 0xa831c66d2db43210), ((int64) 0xb00327c898fb213f), ((int64) 0xbf597fc7beef0ee4), ((int64) 0xc6e00bf33da88fc2), ((int64) 0xd5a79147930aa725), ((int64) 0x06ca6351e003826f), ((int64) 0x142929670a0e6e70), ((int64) 0x27b70a8546d22ffc), ((int64) 0x2e1b21385c26c926), ((int64) 0x4d2c6dfc5ac42aed), ((int64) 0x53380d139d95b3df), ((int64) 0x650a73548baf63de), ((int64) 0x766a0abb3c77b2a8), ((int64) 0x81c2c92e47edaee6), ((int64) 0x92722c851482353b), ((int64) 0xa2bfe8a14cf10364), ((int64) 0xa81a664bbc423001), ((int64) 0xc24b8b70d0f89791), ((int64) 0xc76c51a30654be30), ((int64) 0xd192e819d6ef5218), ((int64) 0xd69906245565a910), ((int64) 0xf40e35855771202a), ((int64) 0x106aa07032bbd1b8), ((int64) 0x19a4c116b8d2d0c8), ((int64) 0x1e376c085141ab53), ((int64) 0x2748774cdf8eeb99), ((int64) 0x34b0bcb5e19b48a8), ((int64) 0x391c0cb3c5c95a63), ((int64) 0x4ed8aa4ae3418acb), ((int64) 0x5b9cca4f7763e373), ((int64) 0x682e6ff3d6b2b8a3), ((int64) 0x748f82ee5defb2fc), ((int64) 0x78a5636f43172f60), ((int64) 0x84c87814a1f0ab72), ((int64) 0x8cc702081a6439ec), ((int64) 0x90befffa23631e28), ((int64) 0xa4506cebde82bde9), ((int64) 0xbef9a3f7b2c67915), ((int64) 0xc67178f2e372532b), ((int64) 0xca273eceea26619c), ((int64) 0xd186b8c721c0c207), ((int64) 0xeada7dd6cde0eb1e), ((int64) 0xf57d4f7fee6ed178), ((int64) 0x06f067aa72176fba), ((int64) 0x0a637dc5a2c898a6), ((int64) 0x113f9804bef90dae), ((int64) 0x1b710b35131c471b), ((int64) 0x28db77f523047d84), ((int64) 0x32caab7b40c72493), ((int64) 0x3c9ebe0a15c9bebc), ((int64) 0x431d67c49c100d4c), ((int64) 0x4cc5d4becb3e42b6), ((int64) 0x597f299cfc657e2a), ((int64) 0x5fcb6fab3ad6faec), ((int64) 0x6c44198c4a475817)};


void ULowEntryHashingSha512Library::initialize()
{
	w.SetNum(80);
	buffer.SetNum(128);
}

void ULowEntryHashingSha512Library::update(const TArray<uint8>& b, const int32 offset, const int32 len)
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

TArray<uint8> ULowEntryHashingSha512Library::digest()
{
	TArray<uint8> tail = padBuffer();
	update(tail, 0, tail.Num());
	return getResult();
}

TArray<uint8> ULowEntryHashingSha512Library::padBuffer()
{
	int32 n = count % BLOCK_SIZE;
	int32 padding = (n < 112) ? (112 - n) : (240 - n);
	TArray<uint8> result;
	result.SetNum(padding + 16);
	result[0] = (uint8) 0x80;
	uint64 bits = count << 3;
	padding += 8;
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

TArray<uint8> ULowEntryHashingSha512Library::getResult()
{
	TArray<uint8> result;
	result.SetNum(64);

	result[0] = (uint8) (h0 >> 56);
	result[1] = (uint8) (h0 >> 48);
	result[2] = (uint8) (h0 >> 40);
	result[3] = (uint8) (h0 >> 32);
	result[4] = (uint8) (h0 >> 24);
	result[5] = (uint8) (h0 >> 16);
	result[6] = (uint8) (h0 >> 8);
	result[7] = (uint8) (h0);

	result[8] = (uint8) (h1 >> 56);
	result[9] = (uint8) (h1 >> 48);
	result[10] = (uint8) (h1 >> 40);
	result[11] = (uint8) (h1 >> 32);
	result[12] = (uint8) (h1 >> 24);
	result[13] = (uint8) (h1 >> 16);
	result[14] = (uint8) (h1 >> 8);
	result[15] = (uint8) (h1);

	result[16] = (uint8) (h2 >> 56);
	result[17] = (uint8) (h2 >> 48);
	result[18] = (uint8) (h2 >> 40);
	result[19] = (uint8) (h2 >> 32);
	result[20] = (uint8) (h2 >> 24);
	result[21] = (uint8) (h2 >> 16);
	result[22] = (uint8) (h2 >> 8);
	result[23] = (uint8) (h2);

	result[24] = (uint8) (h3 >> 56);
	result[25] = (uint8) (h3 >> 48);
	result[26] = (uint8) (h3 >> 40);
	result[27] = (uint8) (h3 >> 32);
	result[28] = (uint8) (h3 >> 24);
	result[29] = (uint8) (h3 >> 16);
	result[30] = (uint8) (h3 >> 8);
	result[31] = (uint8) (h3);

	result[32] = (uint8) (h4 >> 56);
	result[33] = (uint8) (h4 >> 48);
	result[34] = (uint8) (h4 >> 40);
	result[35] = (uint8) (h4 >> 32);
	result[36] = (uint8) (h4 >> 24);
	result[37] = (uint8) (h4 >> 16);
	result[38] = (uint8) (h4 >> 8);
	result[39] = (uint8) (h4);

	result[40] = (uint8) (h5 >> 56);
	result[41] = (uint8) (h5 >> 48);
	result[42] = (uint8) (h5 >> 40);
	result[43] = (uint8) (h5 >> 32);
	result[44] = (uint8) (h5 >> 24);
	result[45] = (uint8) (h5 >> 16);
	result[46] = (uint8) (h5 >> 8);
	result[47] = (uint8) (h5);

	result[48] = (uint8) (h6 >> 56);
	result[49] = (uint8) (h6 >> 48);
	result[50] = (uint8) (h6 >> 40);
	result[51] = (uint8) (h6 >> 32);
	result[52] = (uint8) (h6 >> 24);
	result[53] = (uint8) (h6 >> 16);
	result[54] = (uint8) (h6 >> 8);
	result[55] = (uint8) (h6);

	result[56] = (uint8) (h7 >> 56);
	result[57] = (uint8) (h7 >> 48);
	result[58] = (uint8) (h7 >> 40);
	result[59] = (uint8) (h7 >> 32);
	result[60] = (uint8) (h7 >> 24);
	result[61] = (uint8) (h7 >> 16);
	result[62] = (uint8) (h7 >> 8);
	result[63] = (uint8) (h7);

	return result;
}

void ULowEntryHashingSha512Library::sha(const TArray<uint8>& in, int32 offset)
{
	int64 A = h0;
	int64 B = h1;
	int64 C = h2;
	int64 D = h3;
	int64 E = h4;
	int64 F = h5;
	int64 G = h6;
	int64 H = h7;
	uint64 T;
	uint64 T2;
	int32 r;
	for(r = 0; r < 16; r++)
	{
		w[r] = ((int64) in[offset] << 56) | (((int64) in[offset + 1] & 0xFF) << 48) | (((int64) in[offset + 2] & 0xFF) << 40) | (((int64) in[offset + 3] & 0xFF) << 32) | (((int64) in[offset + 4] & 0xFF) << 24) | (((int64) in[offset + 5] & 0xFF) << 16) | (((int64) in[offset + 6] & 0xFF) << 8) | ((int64) in[offset + 7] & 0xFF);
		offset += 8;
	}
	for(r = 16; r < 80; r++)
	{
		T = w[r - 2];
		T2 = w[r - 15];
		w[r] = ((s(T, 19) | (T << 45)) ^ (s(T, 61) | (T << 3)) ^ s(T, 6)) + w[r - 7] + ((s(T2, 1) | (T2 << 63)) ^ (s(T2, 8) | (T2 << 56)) ^ s(T2, 7)) + w[r - 16];
	}
	for(r = 0; r < 80; r++)
	{
		T = H + ((s(E, 14) | (E << 50)) ^ (s(E, 18) | (E << 46)) ^ (s(E, 41) | (E << 23))) + ((E & F) ^ ((~E) & G)) + k[r] + w[r];
		T2 = ((s(A, 28) | (A << 36)) ^ (s(A, 34) | (A << 30)) ^ (s(A, 39) | (A << 25))) + ((A & B) ^ (A & C) ^ (B & C));
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

int64 ULowEntryHashingSha512Library::s(const int64 a, const int32 b)
{
	const uint64 A = a;
	const uint32 B = b;
	return (A >> B);
}


TArray<uint8> ULowEntryHashingSha512Library::Hash(const TArray<uint8>& Bytes)
{
	ULowEntryHashingSha512Library instance = ULowEntryHashingSha512Library();
	instance.initialize();
	instance.update(Bytes, 0, Bytes.Num());
	return instance.digest();
}

TArray<uint8> ULowEntryHashingSha512Library::Hash(const TArray<uint8>& Bytes, int32 Index, int32 Length)
{
	if(Bytes.Num() <= 0)
	{
		ULowEntryHashingSha512Library instance = ULowEntryHashingSha512Library();
		instance.initialize();
		return instance.digest();
	}

	if(Index < 0)
	{
		Length += Index;
		Index = 0;
	}
	if(Length >(Bytes.Num() - Index))
	{
		Length = Bytes.Num() - Index;
	}

	if(Length <= 0)
	{
		ULowEntryHashingSha512Library instance = ULowEntryHashingSha512Library();
		instance.initialize();
		return instance.digest();
	}

	ULowEntryHashingSha512Library instance = ULowEntryHashingSha512Library();
	instance.initialize();
	instance.update(Bytes, Index, Length);
	return instance.digest();
}
