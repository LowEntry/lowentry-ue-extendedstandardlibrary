#pragma once


#include "Engine.h"


class ULowEntryHashingBCryptLibrary
{
private:
	int32 P[18];
	int32 S[1024];

	int32					nk = 0;
	int32					nr = 0;
	TArray<TArray<uint8>>	w;


private:
	void encipher(int32 lr[], int off);
	static int32 streamtoword(TArray<uint8> data, int32 offp[]);
	void init_key();
	void key(TArray<uint8> key);
	void ekskey(TArray<uint8> data, TArray<uint8> key);
	TArray<uint8> crypt_raw(TArray<uint8> password, TArray<uint8> salt, int32 log_rounds, int32 cdata[]);
	TArray<uint8> crypt_raw(TArray<uint8> password, TArray<uint8> salt, int32 log_rounds);


public:
	static TArray<uint8> Hash(TArray<uint8> Bytes, TArray<uint8> Salt, int32 Strength);
};
