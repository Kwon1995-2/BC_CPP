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
	//�� �Է¹ޱ�
	//cout << "1. ��ȣȭ  2. ��ȣȭ : ";
	//cin >> k; cout << endl;
	cout << "Write the plain text : ";
	cin >> p_text;
	int str_size = strlen(p_text);
	
	//��� ���� ����
	if ((str_size % BLOCK_SIZE) != 0) {
		block_num = str_size / BLOCK_SIZE + 1;
		for (int i = str_size; i < block_num * BLOCK_SIZE; i++)
		{
			p_text[i] = '*';  //���� ĭ���ٰ� * ����ֱ�
		}   // *�� ��Ÿ���� ���� �ʴٸ�??
	}
	else {
		block_num = str_size / BLOCK_SIZE;
	}
		// Transpencry(p_text, c_text, block_num)
		//���� ��ȣ������ �ٲٱ�
		for (int i = 0; i < block_num; i++) {
			for (int j = 0; j < BLOCK_SIZE; j++) {
				c_text[i * BLOCK_SIZE + j] = p_text[(key[j] - 1) + i * BLOCK_SIZE];
			}
		}
		//string c = c_text;
		//cout << c<<endl;
		cout <<"��ȣ�� : "<< c_text << endl;
	
		//��ȣȭ�ϱ�
		for (int i = 0; i < block_num; i++) {
			for (int j = 0; j < BLOCK_SIZE; j++) {
				m_text[(key[j] - 1) + i * BLOCK_SIZE] = c_text[i * BLOCK_SIZE + j];
			}
		}
		cout <<"��ȣ�� : "<< m_text << endl;


  return 0;
}
