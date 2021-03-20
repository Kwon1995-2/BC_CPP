#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BLOCK_SIZE 8;

typedef unsigned char BYTE;

void get_DT(BYTE* DT)
{
	int i;
	time_t cur_time;

	time(&cur_time);

	for (i = 0; i < BLOCK_SIZE; i+= 4)
	{   //64bit
		DT[i] = (BYTE)((cur_time & 0xFF000000) >> 24);
		DT[i+1] = (BYTE)((cur_time & 0x00FF0000) >> 16);
		DT[i+2] = (BYTE)((cur_time & 0x0000FF00) >> 8);
		DT[i] = (BYTE)((cur_time & 0xFF0000FF));
	}
}

void set_V(BYTE* V)
{
	int i;

	srand(time(NULL));

	for (i = 0; i < BLOCK_SIZE; i++)
	{
		V[i] = (BYTE)(rand() % 256);
	}
}

void Triple_DES_Enc(BYTE* p_text, BYTE* result, BYTE* key1, BYTE* key2)
{
	BYTE middle_text1[BLOCK_SIZE] = { 0, };
	BYTE middle_text2[BLOCK_SIZE] = { 0, };

	DES_Enc(p_text, middle_text1, key1);
	DES_Dec(middle_text1, middle_text2, key2);
	DES_Enc(middle_text2, result, key1);
}

void X9_17_Rng(BYTE* Rnum, BYTE* key1, BYTE* key2, int Rnum_size)
{
	int i, j;
	BYTE V[8] = { 0, };
	BYTE DT[8] = { 0, };
	BYTE input[8] = { 0, };
	BYTE _3DES_result[8] = { 0, };

	set_V(V);

	for (i = 0; i < Rnum_size; i += BLOCK_SIZE)
	{
		get_DT(DT);
		// 3 DES           //°ª ÀúÀå   
		Triple_DES_Enc(DT, _3DES_Result, key1, key2);

		for (j = 0; j < BLOCK_SIZE; j++)
		{
			input[j] = V[j] ^ _3DES_result[j];
		}

		Triple_DES_Enc(input, &Rnum[i], key1, key2);

		for (j = 0; j < BLOCK_SIZE; j++)
		{
			input[j] = Rnum[i+j] ^ _3DES_result[j];
		}
		Triple_DES_Enc(input, V, key1, key2);
	}
}

void main()
{
	int i, j;
	BYTE Rnum[16] = { 0, };
	BYTE key[BLOCK_SIZE + 1] = "infosec1";
	BYTE key[BLOCK_SIZE + 1] = "security";

	for (j = 0; j < 10; j++)
	{
		X9_17_Rng(Rnum, key1, key2, 16);

		printf("*Random number = ");
		for (i = 0; i < 16; i++) {
			printf("%X ", Rnum[i]);
		}
		printf("\n");

		memset(Rnum, 0, 16);
	}
}