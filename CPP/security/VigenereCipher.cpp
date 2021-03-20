#include <iostream>
#include <cstring>
using namespace std;

void encry(char*, char*, int, int);
void decry(char*, char*, int, int);

int main(void)
{
	//평문 입력 받음
	char key[20] = { 0, };
	char p[20] = { 0, };
	int x = 0;
	cout << "1.암호화  2.복호화 : ";
	cin >> x;
	cout << "Enter the key number" << endl;
	cin >> key;
	cout << "Enter the string" << endl;
	cin >> p;

	int key_size = strlen(key);
	int str_size = strlen(p);

	if (x == 1)
	{
		encry(p, key, key_size, str_size);
		cout << p << endl;
	}
	else if (x == 2)
	{
		//key -= (key + key);
		decry(p, key, key_size, str_size);
		cout << p << endl;
	}
	else { cout << "can't action" << endl; }

	return 0;
}

void encry(char* p, char* k, int key, int _str)
{
	for (int i = 0; i < _str; i=i++)
	{
		int j = i % key; 
			if ((p[i] >= 'A') && (p[i] <= 'Z'))
			{
				p[i] = p[i] - 'A'; k[j] = k[j] - 'A';
				if ((p[i] + k[j]) < 0)
				{
					p[i] = p[i] + 26;
				}

				p[i] = (p[i] + k[j]) % 26;
				p[i] = p[i] + 'A'; k[j] = k[j] + 'A';
			}
			else if ((p[i] >= 'a') && (p[j] <= 'z'))
			{
				p[i] = p[i] - 'a'; k[j] = k[j] - 'a';
				if ((p[i] + k[j]) < 0)
				{
					p[i] = p[i] + 26;
				}
				p[i] = (p[i] + k[j]) % 26;
				p[i] = p[i] + 'a'; k[j] = k[j] + 'a';
			
			}
	}
}

void decry(char* p, char* k, int key, int _str)
{
	for (int i = 0; i < _str; i = i++)
	{
		int j = i % key; //for loop 두 개 쓰면 논리가 안 맞음
		if ((p[i] >= 'A') && (p[i] <= 'Z'))
		{
			p[i] = p[i] - 'A'; k[j] = k[j] - 'A';
			if ((p[i] + k[j]) < 0)
			{
				p[i] = p[i] + 26;
			}

			p[i] = (p[i] - k[j]) % 26;
			p[i] = p[i] + 'A'; k[j] = k[j] + 'A';
		}
		else if ((p[i] >= 'a') && (p[j] <= 'z'))
		{
			p[i] = p[i] - 'a'; k[j] = k[j] - 'a';

			if ((p[i] + k[j]) < 0)
			{
				p[i] = p[i] + 26;
			}
			p[i] = (p[i] - k[j]) % 26;
			p[i] = p[i] + 'a'; k[j] = k[j] + 'a';

		}
	}
}


