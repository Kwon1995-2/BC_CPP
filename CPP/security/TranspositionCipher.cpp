#include <iostream>
#define BLOCK_SIZE 6
using namespace std;

int main()
{
	char p_text[20] = {NULL,};
	char m_text[20] = {NULL, };
	char c_text[20] = {NULL,};
	int key[BLOCK_SIZE] = {3, 5, 1, 6, 4, 2};
	int k = 0;
	//int key = 0;
	int block_num = 0;
	//평문 입력받기
	//cout << "1. 암호화  2. 복호화 : ";
	//cin >> k; cout << endl;
	cout << "Write the plain text : ";
	cin >> p_text;
	int str_size = strlen(p_text);
	
	//블록 갯수 결정
	if ((str_size % BLOCK_SIZE) != 0) {
		block_num = str_size / BLOCK_SIZE + 1;
		for (int i = str_size; i < block_num * BLOCK_SIZE; i++)
		{
			p_text[i] = '*';  //남은 칸에다가 * 집어넣기
		}   // *를 나타내고 싶지 않다면??
	}
	else {
		block_num = str_size / BLOCK_SIZE;
	}
		// Transpencry(p_text, c_text, block_num)
		//평문을 암호문으로 바꾸기
		for (int i = 0; i < block_num; i++) {
			for (int j = 0; j < BLOCK_SIZE; j++) {
				c_text[i * BLOCK_SIZE + j] = p_text[(key[j] - 1) + i * BLOCK_SIZE];
			}
		}
		//string c = c_text;
		//cout << c<<endl;
		cout <<"암호문 : "<< c_text << endl;
	
		//복호화하기
		for (int i = 0; i < block_num; i++) {
			for (int j = 0; j < BLOCK_SIZE; j++) {
				m_text[(key[j] - 1) + i * BLOCK_SIZE] = c_text[i * BLOCK_SIZE + j];
			}
		}
		cout <<"복호문 : "<< m_text << endl;


  return 0;
}
