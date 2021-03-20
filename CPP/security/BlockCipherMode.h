#pragma once
#include "DES.h"

void BtoUINT64(BYTE* text, UINT64* int64, int j) {
	int i;
	for (i = 0; i < 8; i++) {
		*int64 |= (UINT64)text[j * BLOCK_SIZE + i] << (56 - (i * 8));
	}
}

void UINT64toB(UINT64 int64, BYTE* text,  int j) {
	int i;
	for (i = 0; i < 8; i++) {
		text[j * BLOCK_SIZE + i] |= (int64 >> (56 - (i * 8)));
	}
}
/*-------------------------------------------------------------
---------------------- 암호화-----------------------------------
----------------------------------------------------------------*/
void DES_CBC_Enc(BYTE* p_text, BYTE* c_text, BYTE* IV, BYTE* key, int msg_len) {
	BYTE temp[BLOCK_SIZE] = { 0, };
	UINT64 iv_64 = 0;
	UINT64 iv_64_2 = 0;
	cout << endl << "Cipher Block Codebook 암호화 실행" << p_text << " " << c_text << " " << IV << " " << key << " " << msg_len << endl;

	int block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);

	for (int i = 0; i < block_count; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			temp[j] = 0;
		}
		iv_64 = 0;
		iv_64_2 = 0;

		for (int j = 0; j < BLOCK_SIZE; j++) {
			if (p_text[i * BLOCK_SIZE + j] == 0) {
				p_text[i * BLOCK_SIZE + j] = 'Z';
			}
		}

		if (i == 0) {
			BtoUINT64(IV, &iv_64, 0);
		}
		else {
			BtoUINT64(c_text, &iv_64, i-1);
		}

		BtoUINT64(p_text, &iv_64_2, i);  //비트로

		iv_64 = iv_64_2 ^ iv_64;
		UINT64toB(iv_64, temp, 0); //글자로

		DES_Encryption(&temp[0], &c_text[i * BLOCK_SIZE], key);

	}
}

void DES_CFB_Enc(BYTE* p_text, BYTE* c_text, BYTE* IV, BYTE* key, int msg_len) {
	BYTE temp[BLOCK_SIZE] = { 0, };
	UINT64 iv_64 = 0;
	UINT64 iv_64_2 = 0;
	cout << endl << "CFB 암호화 실행" << p_text << " " << c_text << " " << IV << " " << key << " " << msg_len << endl;

	int block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);

	for (int i = 0; i < block_count; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			temp[j] = 0;
		}
		iv_64 = 0;
		iv_64_2 = 0;

		for (int j = 0; j < BLOCK_SIZE; j++) {
			if (p_text[i * BLOCK_SIZE + j] == 0) {
				p_text[i * BLOCK_SIZE + j] = 'Z';
			}
		}
		if (i == 0) {
			cout << "IV사용" << endl;
			DES_Encryption(IV, &temp[0], key);
		}
		else {
			cout << "이전 블럭 사용" << endl;
			DES_Encryption(&c_text[(i-1)*BLOCK_SIZE],&temp[0],key);
		}
		
			BtoUINT64(temp, &iv_64, 0);
			BtoUINT64(p_text, &iv_64, i);
			iv_64 = iv_64_2 ^ iv_64;
		UINT64toB(iv_64, c_text, i); //글자로
	}
}

void DES_OFB_Enc(BYTE* p_text, BYTE* c_text, BYTE* IV, BYTE* key, int msg_len) {
	BYTE output[BLOCK_SIZE] = { 0, };
	BYTE output_pre[BLOCK_SIZE] = { 0, };
	UINT64 iv_64 = 0;
	UINT64 iv_64_2 = 0;
	cout << endl << "OFB 암호화 실행" << p_text << " " << c_text << " " << IV << " " << key << " " << msg_len << endl;

	int block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);

	for (int i = 0; i < block_count; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			output[j] = 0;
		}
		iv_64 = 0;
		iv_64_2 = 0;

		for (int j = 0; j < BLOCK_SIZE; j++) {
			if (p_text[i * BLOCK_SIZE + j] == 0) {
				p_text[i * BLOCK_SIZE + j] = 'Z';
			}
		}
		if (i == 0) {
			cout << "IV사용" << endl;
			DES_Encryption(IV, &output[0], key);
		}
		else {
			cout << "이전 블럭 사용" << endl;
			DES_Encryption(&output_pre[0], &output[0], key);
		}

		BtoUINT64(output, &iv_64, 0);
		BtoUINT64(p_text, &iv_64, i);
		iv_64 = iv_64_2 ^ iv_64;
		UINT64toB(iv_64, c_text, i); //글자로

		for (int k = 0; k < BLOCK_SIZE; k++) {
			output_pre[k] = output[k];
		}
	}
}

void DES_CTR_Enc(BYTE* p_text, BYTE* c_text, BYTE* key, UINT64 ctr, int msg_len) {
	BYTE output[BLOCK_SIZE] = { 0, };
	BYTE temp[BLOCK_SIZE] = { 0, };
	UINT64 iv_64 = 0;
	UINT64 iv_64_2 = 0;
	cout << endl << "Counter 암호화 실행" << p_text << " " << c_text << " " << ctr<< " " << key << " " << msg_len << endl;

	int block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);

	for (int i = 0; i < block_count; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			temp[j] = 0;
			output[j] = 0;
		}
		iv_64 = 0;
		iv_64_2 = 0;

		for (int j = 0; j < BLOCK_SIZE; j++) {
			if (p_text[i * BLOCK_SIZE + j] == 0) {
				p_text[i * BLOCK_SIZE + j] = 'Z';
			}
		}

		UINT64toB(ctr + i, temp, 0);
		DES_Encryption(&temp[0], &output[0], key);
		BtoUINT64(output, &iv_64, 0);
		BtoUINT64(p_text, &iv_64, i);
		iv_64 = iv_64_2 ^ iv_64;
		UINT64toB(iv_64, c_text, i);
	}
}


/*-------------------------------------------------------------
---------------------- 복호화-----------------------------------
----------------------------------------------------------------*/
void DES_CBC_Dec(BYTE* c_text, BYTE* d_text, BYTE* IV, BYTE* key, int msg_len) {
	BYTE temp[BLOCK_SIZE] = { 0, };
	UINT64 iv_64 = 0;
	UINT64 iv_64_2 = 0;
	cout << endl << "Cipher Block Codebook 복호화 실행" << c_text << " " << d_text << " " << IV << " " << key << " " << msg_len << endl;

	int block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);
	// 0 : 거짓, 0이외 : 참
	for (int i = 0; i < block_count; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			temp[j] = 0;
			d_text[i * BLOCK_SIZE + j] = 0;
		}
		iv_64 = 0;
		iv_64_2 = 0;

		DES_Decryption(&c_text[i * BLOCK_SIZE], &temp[0], key);

		if (i == 0) {
			BtoUINT64(IV, &iv_64, 0);
		}
		else {
			BtoUINT64(c_text, &iv_64, i - 1);
		}
		BtoUINT64(temp, &iv_64_2, 0);
		iv_64 = iv_64_2 ^ iv_64;

		UINT64toB(iv_64, d_text, i); //iv_64 => d_text에 넣어줌

	}
}

void DES_CFB_Dec(BYTE* c_text, BYTE* d_text, BYTE* IV, BYTE* key, int msg_len) {
	BYTE temp[BLOCK_SIZE] = { 0, };
	UINT64 iv_64 = 0;
	UINT64 iv_64_2 = 0;
	cout << endl << "Cipher Block Codebook 복호화 실행" << endl;

	int block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);
	// 0 : 거짓, 0이외 : 참
	for (int i = 0; i < block_count; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			temp[j] = 0;
			d_text[i * BLOCK_SIZE + j] = 0;
		}
		iv_64 = 0;
		iv_64_2 = 0;


		if (i == 0) {
			cout << "IV사용" << endl;
			DES_Encryption(IV, &temp[0], key);
		}
		else {
			cout << "이전 블럭 사용" << endl;
			DES_Decryption(&c_text[(i - 1) * BLOCK_SIZE], &temp[0], key);
		}

		BtoUINT64(temp, &iv_64, 0);
		BtoUINT64(c_text, &iv_64_2, i);
		iv_64 = iv_64_2 ^ iv_64;
		UINT64toB(iv_64, d_text, i); 
	}
}

void DES_OFB_Dec(BYTE* c_text, BYTE* d_text, BYTE* IV, BYTE* key, int msg_len) {
	BYTE output[BLOCK_SIZE] = { 0, };
	BYTE output_pre[BLOCK_SIZE] = { 0, };
	UINT64 iv_64 = 0;
	UINT64 iv_64_2 = 0;
	cout << endl << "OFB 복호화 실행" << endl;

	int block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);

	for (int i = 0; i < block_count; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			output[j] = 0;
		}
		iv_64 = 0;
		iv_64_2 = 0;

		if (i == 0) {
			cout << "IV사용" << endl;
			DES_Encryption(IV, &output[0], key);
		}
		else {
			cout << "이전 블럭 사용" << endl;
			DES_Encryption(&output_pre[0], &output[0], key);
		}

		BtoUINT64(output, &iv_64, 0);
		BtoUINT64(c_text, &iv_64, i);
		iv_64 = iv_64_2 ^ iv_64;
		UINT64toB(iv_64, d_text, i); //글자로

		for (int k = 0; k < BLOCK_SIZE; k++) {
			output_pre[k] = output[k];
		}
	}
}

void DES_CTR_Dec(BYTE* c_text, BYTE* d_text, BYTE* key, UINT64 ctr, int msg_len){

	BYTE output[BLOCK_SIZE] = { 0, };
	BYTE temp[BLOCK_SIZE] = { 0, };
	UINT64 iv_64 = 0;
	UINT64 iv_64_2 = 0;
	cout << endl << "Counter 암호화 실행" << endl;

	int block_count = (msg_len % BLOCK_SIZE) ? (msg_len / BLOCK_SIZE + 1) : (msg_len / BLOCK_SIZE);

	for (int i = 0; i < block_count; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			temp[j] = 0;
			output[j] = 0;
		}
		iv_64 = 0;
		iv_64_2 = 0;

	
		UINT64toB(ctr + i, temp, 0);
		DES_Encryption(&temp[0], &output[0], key);

		BtoUINT64(output, &iv_64, 0);
		BtoUINT64(c_text, &iv_64, i);
		iv_64 = iv_64_2 ^ iv_64;
		UINT64toB(iv_64, d_text, i);
	}
}


