#include <iostream>
#include <cstring>
using namespace std;

void affineencry(char*, int, int, int);
void affinedecry(char*, int, int, int);
int modinverse(int a);

int main(void)
{
	//평문 입력 받음
	int key1 = 0, key2 =0;
	char p[100] = { 0, };
	int x = 0;
	cout << "1.암호화  2.복호화 : ";
	cin >> x;
	cout << "Enter the key number" << endl;
	cin >> key1 >> key2;
	cout << "Enter the string" << endl;
	cin >> p;

	int str_size = strlen(p);

	if (x == 1)
	{
		affineencry(p, key1, key2, str_size);
		cout << p << endl;
	}
	else if (x == 2)
	{
		key1 = modinverse(key1);
		affinedecry(p, key1, key2, str_size);
		cout << p << endl;
	}
	else { cout << "can't action" << endl; }

	return 0;
}

void affineencry(char* p, int key1,int key2, int _str)
{
	for (int i = 0; i < _str; i++)
	{
		if ((p[i] >= 'A') && (p[i] <= 'Z'))
		{
			p[i] = p[i] - 'A';
			if ((key1*p[i] + key2) < 0)
			{
				p[i] = p[i] + 26;
			}

			p[i] = (key1*p[i] + key2) % 26;
			p[i] = p[i] + 'A';
		}
		else if ((p[i] >= 'a') && (p[i] <= 'z'))
		{
			p[i] = p[i] - 'a';

			if ((key1*p[i] + key2) < 0)
			{
				p[i] = p[i] + 26;
			}
			p[i] = (key1 * p[i] + key2) % 26;
			p[i] = p[i] + 'a';
		}
	}
}

int modinverse(int a) 
{
	a = a % 26;
	for (int x = 1; x < 26; x++)
	{
		if ((a * x) % 26 == 1) {
			return x;
		}
	}
}

void affinedecry(char* p, int key1_, int key2, int _str)
{
	for (int i = 0; i < _str; i++)
	{
		if ((p[i] >= 'A') && (p[i] <= 'Z'))
		{
			p[i] = p[i] - 'A';
			if ((key1_ * p[i] + key2) < 0)
			{
				p[i] = p[i] + 26;
			}

			p[i] = ((p[i] - key2) * key1_) % 26;
			p[i] = p[i] + 'A';
		}
		else if ((p[i] >= 'a') && (p[i] <= 'z'))
		{
			p[i] = p[i] - 'a';

			if ((key1_ * p[i] + key2) < 0)
			{
				p[i] = p[i] + 26;
			}
			p[i] = ((p[i] - key2) * key1_) % 26;
			p[i] = p[i] + 'a';
		}
	}
}

