#include <iostream>
#define BLOCK_SIZE 4
using namespace std;

void encry(char* p, char* c, int* k, int str_size);
void decry(char* c, int* k, int str_size);

int main()
{
	char p_text[20] = { NULL, }; //�ٶ������� ����
	char c_text[20] = { NULL, }; //�ٶ������� ����
	int key[BLOCK_SIZE] = {1, 2, 3, 4};
	int str_size = 0;
	int block_num = 0;
	cout << "Write plaing text : ";
	cin >> p_text;
	
	str_size = strlen(p_text);

	//������� �ɰ��� -> �� ���� �ʿ䰡 ����.
	//if ((str_size % BLOCK_SIZE) != 0) {
	//	block_num = str_size / BLOCK_SIZE + 1;
	//	for (int i = str_size; i < block_num * BLOCK_SIZE; i++)
	//	{
	//		p_text[i] = '1';  //���� ĭ���ٰ� * ����ֱ�
	//	}   // *�� ��Ÿ���� ���� �ʴٸ�??
	//}
	//else {
	//	block_num = str_size / BLOCK_SIZE;
	//}

	//��� �ȿ��� ������ + key����ŭ �̵�
	//������ circle

	encry(p_text, c_text, key, str_size); // ���� ������ �޾Ƶ� ��
	cout << c_text<<endl;
	//cout << p_text << endl;
	decry(c_text, key, str_size);
	cout << c_text;
}


void encry(char* p, char* c, int* k, int str_size)
{
	for (int i = 0; i < str_size; i = i++)
	{
		int j = i % BLOCK_SIZE;
		if ((p[i] >= 'A') && (p[i] <= 'Z'))
		{
			c[i] = p[i] - 'A'; //k[j] = k[j] - 'A';
			if ((c[i] + k[j]) < 0)
			{
				c[i] = c[i] + 26;
			}

			c[i] = (c[i] + k[j]) % 26;
			c[i] = c[i] +'A'; //k[j] = k[j] + 'A';
		}
		else if ((p[i] >= 'a') && (p[j] <= 'z'))
		{
			c[i] = p[i] - 'a'; //k[j] = k[j] - 'a';
			if ((p[i] + k[j]) < 0)
			{
				c[i] = c[i] + 26;
			}
			c[i] = (c[i] + k[j]) % 26;
			c[i] = c[i] +'a'; //k[j] = k[j] + 'a';

		}
	}
}

void decry(char* c, int* k, int str_size)
{
	for (int i = 0; i < str_size; i = i++)
	{
		int j = i % BLOCK_SIZE;
		if ((c[i] >= 'A') && (c[i] <= 'Z'))
		{
			c[i] = c[i] - 'A'; //k[j] = k[j] - 'A';
			if ((c[i] + k[j]) < 0)
			{
				c[i] = c[i] + 26;
			}

			c[i] = (c[i] - k[j]) % 26;
			c[i] = c[i] + 'A'; //k[j] = k[j] + 'A';
		}
		else if ((c[i] >= 'a') && (c[j] <= 'z'))
		{
			c[i] = c[i] - 'a'; //k[j] = k[j] - 'a';
			if ((c[i] + k[j]) < 0)
			{
				c[i] = c[i] + 26;
			}
			c[i] = (c[i] - k[j]) % 26;
			c[i] = c[i] + 'a'; //k[j] = k[j] + 'a';

		}
	}
}