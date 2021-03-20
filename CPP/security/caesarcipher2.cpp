#include <iostream>
#include <cstring>
using namespace std;

void encry(char*, int, int);

int main(void)
{
	//평문 입력 받음
	int key = 0;
	char p[100] = { 0, };
	int x=0;
	cout << "1.암호화  2.복호화 : ";
	cin >> x;
	cout << "Enter the key number" << endl;
	cin >> key;
	cout << "Enter the string" << endl;
	cin >> p;
	
	int str_size = strlen(p);

	if (x == 1) 
	{
		encry(p, key, str_size);
		cout << p << endl;
	}
	else if (x == 2)
	{
		key -= (key + key);
		encry(p, key, str_size);
		cout << p << endl;
	}
	else { cout << "can't action"<<endl; }
	
	return 0;
}

void encry(char* p, int key, int _str)
{
	for (int i = 0; i < _str; i++)
	{
		if ((p[i] >= 'A') && (p[i] <= 'Z'))
		{
			p[i] = p[i] - 'A';
			if ((p[i] + key) < 0)
			{
				p[i] = p[i] + 26;
			}

			p[i] = (p[i] + key) % 26;
			p[i] = p[i] + 'A';
		}
		else if ((p[i] >= 'a') && (p[i] <= 'z'))
		{
			p[i] = p[i] - 'a';

			if ((p[i] + key) < 0)
			{
				p[i] = p[i] + 26;
			}
			p[i] = (p[i] + key) % 26;
			p[i] = p[i] + 'a';
		}
	}
}


