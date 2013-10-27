/*
Driver code for testing the sha256 algorithm with a defined 32 byte array.
*/

#include "sha256.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char charToHex(char val)
{
	if(val < 10)
	{
		return val + '0';
	}

	return (val - 10) + 'a';
}

void byteToHex(char bytes[2], uint8 byte)
{
	bytes[0] = charToHex((byte & 0xF0) >> 4);
	bytes[1] = charToHex(byte & 0x0F);
}

void byte_array_to_str(uint8* bytes, char* str, int len)
{
	for(int i = 0; i < len; i++)
	{
		byteToHex(str + (i*2), bytes[i]);
	}
}

int main()
{
	int loopCount = 1;
	uint8 output[32];
	char str[65]; 
	for(int i = 0; i < loopCount; i++)
	{
		memset(str, '\0', 65);
		sha256_32byte((uint8*)"d57c28c041e2551865ec8ed205414d82c3857819ea0c5bd2ceefa85a8207a5ca", output);
		byte_array_to_str(output, str, 32);
		if(strcmp(str, "50e3c98a8f90f56174d8eb406e542139d8e9f670a206a7182b9adce8e3a491f9") != 0)
		{
			printf("invalid match! %s", str);
			break;
		}

		memset(str, '\0', 65);
		sha256_32byte((uint8*)"50e3c98a8f90f56174d8eb406e542139d8e9f670a206a7182b9adce8e3a491f9", output);
		byte_array_to_str(output, str, 32);
		if(strcmp(str, "05569cf48297f296ca65d2e05ea4e60133d4717759fe9c436e057ba575562cd2") != 0)
		{
			printf("invalid match 2! %s", str);
			break;
		}
	}
	
	printf("done!");
	getchar();
	return 0;
}
