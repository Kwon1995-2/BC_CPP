#include <iostream>
#include "DES.h"
//#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int i;
	int msg_len = 0, block_count = 0;

	BYTE p_text[128] = { 0, };
	BYTE c_text[128] = { 0, };
	BYTE d_text[128] = { 0, };
	//BYTE e_text[128] = { 0, };
	BYTE key1[9] = { 0, };
	BYTE key2[9] = { 0, };

	cout << "평문입력 : ";
	gets_s((char*)p_text, sizeof(p_text));

	cout << "비밀키1 입력 : ";
	//scanf("%s", key1);
	gets_s((char*)key1, sizeof(key1));
	cout <<"비밀키2 입력 : ";
	gets_s((char*)key2, sizeof(key2));

	msg_len = (rsize_t)strlen((char*)p_text);
	block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);

	for (i = 0; i < block_count; i++)
	{
		DES_Encryption(&p_text[i * BLOCK_SIZE], &c_text[i * BLOCK_SIZE], key1);
	}
	for (i = 0; i < block_count; i++)
	{
		DES_Decryption(&c_text[i * BLOCK_SIZE], &d_text[i * BLOCK_SIZE], key2);
	}
	for (i = 0; i < block_count; i++)
	{
		DES_Encryption(&d_text[i * BLOCK_SIZE], &c_text[i * BLOCK_SIZE], key1);
	}
	//strcpy((char*)d_text, "");

	printf("암호문 : ");

	for (i = 0; i < msg_len; i++)
	{
		printf("%c", c_text[i]);
	}
	printf("\n");

	for (i = 0; i < block_count; i++)
	{
		DES_Decryption(&c_text[i * BLOCK_SIZE], &d_text[i * BLOCK_SIZE], key1);
	}
	for (i = 0; i < block_count; i++)
	{
		DES_Encryption(&d_text[i * BLOCK_SIZE], &c_text[i * BLOCK_SIZE], key2);
	}
	//strcpy((char*)d_text, "");
	for (i = 0; i < block_count; i++)
	{
		DES_Decryption(&c_text[i * BLOCK_SIZE], &p_text[i * BLOCK_SIZE], key1);
	}

	printf("복호문 : ");

	for (i = 0; i < msg_len; i++)
	{
		printf("%c", p_text[i]);
	}
	printf("\n");

	return 0;
}

