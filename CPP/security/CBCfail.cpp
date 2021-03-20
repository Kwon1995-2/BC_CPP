#include <iostream>
#include "DES.h"
using namespace std;
void BtoW_2(BYTE* Plain64, UINT* Left32, UINT* Right32);
int main(void)
{
	int i;
	int msg_len = 0, block_count = 0;

	BYTE p_text[128] = { 0, };
	BYTE p2_text[128] = { 0, };
	BYTE p3_text[128] = { 0, };
	BYTE c_text[128] = { 0, };
	//BYTE c2_text[128] = { 0, };
	BYTE d_text[128] = { 0, };
	BYTE d2_text[128] = { 0, };
	BYTE d3_text[128] = { 0, };
	BYTE d4_text[128] = { 0, };
	BYTE key[9] = { 0, };
	BYTE IV[9] = { 0, };
	//BYTE v_text[128] = { 0, };

	cout << "입력" << endl;
	cout << "평문 : "; gets_s((char*)p_text, sizeof(p_text));
	cout << "키 값 : "; gets_s((char*)key, sizeof(key));
	cout << "IV값 : "; gets_s((char*)IV, sizeof(IV));

	msg_len = (rsize_t)strlen((char*)p_text);
	
	block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);

	//64비트로 바꾸기

	/*UINT mask = 0xff000000;
	for (i = 0; i < 8; i++) {
		
		p2_text[i] |= (p_text[i] & (mask >> (i * 8))) >> (56 - (i * 8));
		v_text[i] |= (IV[i] & (mask >> (i * 8))) >> (56 - (i * 8));
	}*/

	//BtoW
	for (i = 0; i < msg_len; i++)
	{
		p2_text[i] |= (UINT64)p_text[i] << (56 - (i * 8));
		//v_text[i] |= (UNIT64)IV[i] << (56 - (i * 8));
	}
	for (i = 0; i < 8; i++)
	{
		p3_text[i] = p2_text[i] ^ IV[i];
	}

	for (i = 0; i < block_count; i++)
	{
		DES_Encryption(&p3_text[i * BLOCK_SIZE], &c_text[i * BLOCK_SIZE], key);
	}

	printf("암호문 : ");

	for (i = 0; i < msg_len; i++)
	{
		printf("%c", c_text[i]);
	}
	printf("\n");



	//복호화
	for (i = 0; i < block_count; i++)
	{
		DES_Decryption(&c_text[i * BLOCK_SIZE], &d_text[i * BLOCK_SIZE], key);
	}

	/*for (i = 0; i < 8; i++)
	{
		d2_text[i] |= (UNIT64)d_text[msg_len * BLOCK_SIZE + i] << (56 - (i * 8));
	}*/

	for (i = 0; i < 8; i++)
	{
		d2_text[i] = d_text[i] ^ IV[i]; 
	}

	/*for (i = 0; i < 8; i++) {
		d4_text[msg_len * BLOCK_SIZE + i] |= d3_text[i] >> (56 - (i * 8));
	}*/

	printf("복호문 : ");

	for (i = 0; i < msg_len; i++)
	{
		printf("%c", d2_text[i]);
	}
	printf("\n");

	return 0;
}
