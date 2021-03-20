#include <iostream>
#include <string>

#include "BlockCipherMode.h"

using namespace std;

#define N 25
#define BLOCK_MODE 2 //4, 3, 2, 1

int main()
{
	int i;
	BYTE p_text[N] = { 0, };
	BYTE key[9] = { 0, };
	BYTE IV[9] = { 0, };
	BYTE c_text[N] = { 0, };
	BYTE d_text[N] = { 0, };
	int msg_len;
	UINT64 ctr = 0;

	printf("평문입력 : ");
	cin.getline((char*)p_text, N, '\n');

	printf("비밀키 입력 : ");
	cin >> key;

	if (BLOCK_MODE != 4) {
		printf("초기화 벡터 입력 : ");
		cin >> IV;
	}
	else {
		printf("ctr입력 : ");
		cin >> ctr;
	}

	msg_len = strlen((const char*)p_text);

	if (BLOCK_MODE == 1) {
		DES_CBC_Enc(p_text, c_text, IV, key, msg_len);
	}
	else if (BLOCK_MODE == 2) {
		DES_CFB_Enc(p_text, c_text, IV, key, msg_len);
	}
	else if (BLOCK_MODE == 3) {
		DES_OFB_Enc(p_text, c_text, IV, key, msg_len);
	}
	else if (BLOCK_MODE == 4) {
		DES_CTR_Enc(p_text, c_text, key, ctr, msg_len);
	}

	printf("\n암호문 : ");
	for (i = 0; i < msg_len; i++) {
		printf("%x", c_text[i]);
	}
	printf("\n\n");


	if (BLOCK_MODE == 1) {
		DES_CBC_Dec(c_text, d_text, IV, key, msg_len);
	}
	else if (BLOCK_MODE == 2) {
		DES_CFB_Dec(c_text, d_text, IV, key, msg_len);
	}
	else if (BLOCK_MODE == 3) {
		DES_OFB_Dec(c_text, d_text, IV, key, msg_len);
	}
	else if (BLOCK_MODE == 4) {
		DES_CTR_Dec(c_text, d_text, IV, ctr, msg_len);
	}

	printf("\n복호문 : ");
	for (i = 0; i < msg_len; i++) {
		printf("%x", d_text[i]);
	}
	printf("\n\n");

	printf("\n복호문 : ");
	for (i = 0; i < msg_len; i++) {
		printf("%c", d_text[i]);
	}
	printf("\n\n");

	return 0;
}