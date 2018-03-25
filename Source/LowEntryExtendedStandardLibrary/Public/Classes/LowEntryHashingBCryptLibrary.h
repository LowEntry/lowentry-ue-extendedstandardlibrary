// Copyright Low Entry. Apache License, Version 2.0.

#pragma once


#include "CoreMinimal.h"


class ULowEntryHashingBCryptLibrary
{
private:
	const static int32 BCRYPT_SALT_LEN = 16;

	const static int32 BLOWFISH_NUM_ROUNDS = 16;

	const static int32 P_len = 18;
	const static int32 S_len = 1024;
	const static int32 bf_crypt_ciphertext_len = 6;

	const static int32 P_orig[18];
	const static int32 S_orig[1024];
	const static int32 bf_crypt_ciphertext[6];


private:
	int32 P[18];
	int32 S[1024];

	int32					nk = 0;
	int32					nr = 0;
	TArray<TArray<uint8>>	w;


private:
	void encipher(int32 lr[], const int32 off);
	static int32 streamtoword(const TArray<uint8>& data, int32 offp[]);
	void init_key();
	void key(const TArray<uint8>& key);
	void ekskey(const TArray<uint8>& data, const TArray<uint8>& key);
	TArray<uint8> crypt_raw(const TArray<uint8>& password, const TArray<uint8>& salt, const int32 log_rounds, int32 cdata[]);
	TArray<uint8> crypt_raw(const TArray<uint8>& password, const TArray<uint8>& salt, const int32 log_rounds);


public:
	static TArray<uint8> Hash(const TArray<uint8>& Bytes, const TArray<uint8>& Salt, const int32 Strength);
};
