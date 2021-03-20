#include <iostream>
#include <string>
#define BLOCK_SIZE 6;
#define ROUND_NUM 2
using namespace std;

int F1(char input);
int F2(char input);
char Feistel_Enc(char);
char Feistel_Dec(char);
int main(void)
{
	char p_text = 0x2B;
	char c_bit, d_bit;
	int temp = 0, i = 0;

	cout << "평문 : ";
	for (i = 5 ; i >= 0;i--) {
		temp = (p_text >> i) & 0x01;
		cout << temp;
	}
	cout << endl;
	
	c_bit = Feistel_Enc(p_text);

	cout << "암호문 : ";
	for (i = 5; i >= 0; i--) {
		temp = (c_bit >> i) & 0x01;
		cout << temp;
	}
	cout << endl;
	
	d_bit = Feistel_Dec(c_bit);

	cout << "복호문 : ";
	for (i = 5; i >= 0; i--) {
		temp = (d_bit >> i) & 0x01;
		cout << temp;
	}
	cout << endl;

}

int F1(char input) {
	if (input == 0x00) return 0x05;
	else if (input == 0x01) return 0x02;
	else if (input == 0x02) return 0x03;
	else if (input == 0x03) return 0x06;
	else if (input == 0x04) return 0x04;
	else if (input == 0x05) return 0x01;
	else if (input == 0x06) return 0x07;
	else if (input == 0x07) return 0x00;
	else;
}
int F2(char input) {
	if (input == 0x00) return 0x04;
	else if (input == 0x01) return 0x00;
	else if (input == 0x02) return 0x03;
	else if (input == 0x03) return 0x07;
	else if (input == 0x04) return 0x06;
	else if (input == 0x05) return 0x05;
	else if (input == 0x06) return 0x01;
	else if (input == 0x07) return 0x02;
	else;
}
char Feistel_Enc(char input) {
	//swaping 해서 구현해보기
	char left = input&0x07;
	char right = (input>>3)&0x07^F1(left);
	//char total = (left << 3) + right;
	left = (left >> 3) & 0x07 ^ F2(right>>3);
	char total = (left << 3) + right;
	return total;
}

char Feistel_Dec(char input) {
	char left = input & 0x07;
	char right = (input >> 3) & 0x07 ^ F2(left);
	//char total = (left << 3) + right;
	left = (left >> 3) & 0x07 ^ F1(right >> 3);
	char total = (left << 3) + right;
	return total;
}