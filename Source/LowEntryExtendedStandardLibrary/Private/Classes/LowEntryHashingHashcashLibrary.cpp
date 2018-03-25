// Copyright Low Entry. Apache License, Version 2.0.

#include "LowEntryHashingHashcashLibrary.h"
#include "LowEntryExtendedStandardLibrary.h"


const FString ULowEntryHashingHashcashLibrary::DATE_FORMAT_STRING = TEXT("%y%m%d%H%M%S");

const TArray<TArray<uint8>> ULowEntryHashingHashcashLibrary::BASE_64_CACHE = ULowEntryHashingHashcashLibrary::GenerateBase64Cache();


const TArray<TArray<uint8>> ULowEntryHashingHashcashLibrary::GenerateBase64Cache()
{
	TArray<TArray<uint8>> Array;
	Array.SetNum(ULowEntryHashingHashcashLibrary::MAX_COUNTER);
	for(int32 i = 0; i < Array.Num(); i++)
	{
		Array[i] = ULowEntryHashingHashcashLibrary::base64WithoutLeadingZeroBytes(i);
	}
	return Array;
}


TArray<FString> ULowEntryHashingHashcashLibrary::hashArray(const TArray<FString>& resource, const int32 bits)
{
	return hashArrayCustomCreationDate(resource, FDateTime::UtcNow(), bits);
}
TArray<FString> ULowEntryHashingHashcashLibrary::hashArrayCustomCreationDate(const TArray<FString>& resources, const FDateTime& date, const int32 bits)
{
	TArray<FString> result;
	result.SetNum(resources.Num());
	for(int32 i = 0; i < resources.Num(); i++)
	{
		result[i] = hashCustomCreationDate(resources[i], date, bits);
	}
	return result;
}

FString ULowEntryHashingHashcashLibrary::hash(const FString& resource, const int32 bits)
{
	return hashCustomCreationDate(resource, FDateTime::UtcNow(), bits);
}
FString ULowEntryHashingHashcashLibrary::hashCustomCreationDate(const FString& resource, const FDateTime& date, const int32 bits)
{
	FSHA1 hasher;
	TArray<uint8> hashBuffer;
	hashBuffer.SetNum(FSHA1::DigestSize);
	
	FString dataPrefix = FString::FromInt(VERSION) + TEXT(":") + FString::FromInt(bits) + TEXT(":") + getDateString(date) + TEXT(":") + resource + TEXT("::");
	TArray<uint8> dataPrefixBytes = ULowEntryExtendedStandardLibrary::StringToBytesUtf8(dataPrefix);

	TArray<uint8> buffer;
	buffer.Reserve(dataPrefixBytes.Num() + 17 + 8);
	buffer.Append(dataPrefixBytes);

	int32 prefixpos = buffer.Num();

	while(true)
	{
		buffer.SetNum(prefixpos, false);
		
		TArray<uint8> randomBytes;
		ULowEntryExtendedStandardLibrary::GenerateRandomBytes(12, randomBytes);
		buffer.Append(ULowEntryExtendedStandardLibrary::StringToBytesUtf8(ULowEntryExtendedStandardLibrary::BytesToBase64(randomBytes) + TEXT(":")));

		for(TArray<uint8> base64counter : BASE_64_CACHE)
		{
			hasher.Reset();
			hasher.Update(buffer.GetData(), buffer.Num());
			hasher.Update(base64counter.GetData(), base64counter.Num());
			hasher.Final();
			hasher.GetHash(hashBuffer.GetData());

			int32 leadingZeroBits = countLeadingZeroBits(hashBuffer);
			if(leadingZeroBits >= bits)
			{
				buffer.Append(base64counter);
				return ULowEntryExtendedStandardLibrary::BytesToStringUtf8(buffer);
			}
		}
	}
}


TArray<ULowEntryParsedHashcash*> ULowEntryHashingHashcashLibrary::parseArray(const TArray<FString>& Hashcashes)
{
	TArray<ULowEntryParsedHashcash*> result;
	result.SetNum(Hashcashes.Num());
	for(int32 i = 0; i < Hashcashes.Num(); i++)
	{
		result[i] = parse(Hashcashes[i]);
	}
	return result;
}

ULowEntryParsedHashcash* ULowEntryHashingHashcashLibrary::parse(const FString& Hashcash)
{
	TArray<FString> parts;
	Hashcash.ParseIntoArray(parts, TEXT(":"), false);
	if(parts.Num() >= 6)
	{
		FString version = parts[0];
		if(version.Equals(TEXT("0")))
		{
			FDateTime date = parseDateString(parts[1]);
			if(date.GetYear() > 1)
			{
				int32 bits = countLeadingZeroBits(ULowEntryExtendedStandardLibrary::Sha1(ULowEntryExtendedStandardLibrary::StringToBytesUtf8(Hashcash)));
				FString resource = parts[2];
				for(int32 i = 3; i < (parts.Num() - 3); i++)
				{
					resource += TEXT(":") + parts[i];
				}
				return ULowEntryParsedHashcash::Create(true, resource, date, bits);
			}
		}
		else if(version.Equals(TEXT("1")))
		{
			if(parts.Num() >= 7)
			{
				FDateTime date = parseDateString(parts[2]);
				if(date.GetYear() > 1)
				{
					int32 bits = FCString::Atoi(*parts[1]);
					if(countLeadingZeroBits(ULowEntryExtendedStandardLibrary::Sha1(ULowEntryExtendedStandardLibrary::StringToBytesUtf8(Hashcash))) >= bits)
					{
						FString resource = parts[3];
						for(int32 i = 4; i < (parts.Num() - 3); i++)
						{
							resource += TEXT(":") + parts[i];
						}
						return ULowEntryParsedHashcash::Create(true, resource, date, bits);
					}
				}
			}
		}
	}
	return ULowEntryParsedHashcash::Create(false, TEXT(""), FDateTime(0), 0);
}


TArray<uint8> ULowEntryHashingHashcashLibrary::base64WithoutLeadingZeroBytes(const int32 value)
{
	TArray<uint8> bytes;
	if(value < 0)
	{
		bytes.SetNum(4);
		bytes[0] = (uint8) (value >> 24);
		bytes[1] = (uint8) (value >> 16);
		bytes[2] = (uint8) (value >> 8);
		bytes[3] = (uint8) (value);
	}
	else if(value < 256)
	{
		bytes.SetNum(1);
		bytes[0] = (uint8) (value);
	}
	else if(value < 65536)
	{
		bytes.SetNum(2);
		bytes[0] = (uint8) (value >> 8);
		bytes[1] = (uint8) (value);
	}
	else if(value < 16777216)
	{
		bytes.SetNum(3);
		bytes[0] = (uint8) (value >> 16);
		bytes[1] = (uint8) (value >> 8);
		bytes[2] = (uint8) (value);
	}
	else
	{
		bytes.SetNum(4);
		bytes[0] = (uint8) (value >> 24);
		bytes[1] = (uint8) (value >> 16);
		bytes[2] = (uint8) (value >> 8);
		bytes[3] = (uint8) (value);
	}
	return ULowEntryExtendedStandardLibrary::StringToBytesUtf8(ULowEntryExtendedStandardLibrary::BytesToBase64(bytes));
}


FString ULowEntryHashingHashcashLibrary::getDateString(const FDateTime& date)
{
	return date.ToString(*ULowEntryHashingHashcashLibrary::DATE_FORMAT_STRING);
}

FDateTime ULowEntryHashingHashcashLibrary::parseDateString(const FString& date)
{
	if(date.Len() < 6)
	{
		return FDateTime(0);
	}

	int32 year = FCString::Atoi(*date.Mid(0, 2));
	int32 month = FCString::Atoi(*date.Mid(2, 2));
	int32 day = FCString::Atoi(*date.Mid(4, 2));
	if((year < 0) || (month < 1) || (month > 12))
	{
		return FDateTime(0);
	}
	year += ((FDateTime::Now().GetYear() / 100) * 100);
	if((day < 1) || (day > FDateTime::DaysInMonth(year, month)))
	{
		return FDateTime(0);
	}

	if(date.Len() < 10)
	{
		return FDateTime(year, month, day);
	}

	int32 hour = FCString::Atoi(*date.Mid(6, 2));
	int32 minutes = FCString::Atoi(*date.Mid(8, 2));
	if((hour < 0) || (hour > 23) || (minutes < 0) || (minutes > 59))
	{
		return FDateTime(0);
	}

	if(date.Len() < 12)
	{
		return FDateTime(year, month, day, hour, minutes);
	}

	int32 seconds = FCString::Atoi(*date.Mid(10, 2));
	if((seconds < 0) || (seconds > 59))
	{
		return FDateTime(0);
	}

	return FDateTime(year, month, day, hour, minutes, seconds);
}


int32 ULowEntryHashingHashcashLibrary::countLeadingZeroBits(const TArray<uint8>& values)
{
	int32 total = 0;
	for(uint8 value : values)
	{
		uint8 ofbyte = countLeadingZeroBits(value);
		total += ofbyte;
		if(ofbyte != 8)
		{
			break;
		}
	}
	return total;
}

uint8 ULowEntryHashingHashcashLibrary::countLeadingZeroBits(const uint8 v)
{
	if(v < 0)
	{
		return 0;
	}
	if(v < 1)
	{
		return 8;
	}
	if(v < 2)
	{
		return 7;
	}
	if(v < 4)
	{
		return 6;
	}
	if(v < 8)
	{
		return 5;
	}
	if(v < 16)
	{
		return 4;
	}
	if(v < 32)
	{
		return 3;
	}
	if(v < 64)
	{
		return 2;
	}
	if(v < 128)
	{
		return 1;
	}
	return 0;
}
