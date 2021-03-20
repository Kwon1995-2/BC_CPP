#include <iostream>
#include "DES.h"
using namespace std;

int main(void)
{
	int i;
	int msg_len = 0, block_count = 0;

	BYTE p_text[128] = { 0, };
	BYTE c_text[128] = { 0, };
	BYTE d_text[128] = { 0, };
	BYTE key[9] = { 0, };

	cout << "평문입력 : ";
	gets_s((char*)p_text,sizeof(p_text));

	cout << "비밀키 입력 : ";
	scanf("%s", key);

	msg_len = (rsize_t)strlen((char*)p_text);
	block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);

	for (i = 0; i < block_count; i++)
	{
		DES_Encryption(&p_text[i * BLOCK_SIZE], &c_text[i * BLOCK_SIZE], key);
	}

	printf("암호문 : ");

	for (i = 0; i < (block_count * BLOCK_SIZE); i++)
	{
		printf("%c", c_text[i]) ;
	}
	printf("\n");

	for (i = 0; i < block_count; i++)
	{
		DES_Decryption(&c_text[i * BLOCK_SIZE], &d_text[i * BLOCK_SIZE], key);
	}

	printf("복호문 : ");

	for (i = 0; i < msg_len; i++)
	{
		printf("%c", d_text[i]);
	}
	printf("\n");

	return 0;
}

