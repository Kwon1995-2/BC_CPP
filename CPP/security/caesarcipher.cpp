#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	//�� �Է� ����
	int key = 0;
	char p[100] = {0,};
	//string p1;
	cout << "Enter the key number" << endl;
	cin >> key;
	cout << "Enter the string" << endl;
	cin >> p;
	//strcpy(ch, )
	//�� -> ��ȣ��
	int str_size = strlen(p);
	//cout << str_size;
	for (int i = 0; i < str_size; i++)
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
	cout << p << endl;
	cout << endl;
	//��ȣ��->��
	cout << "��ȣȭ : ";

	key -= (key + key);
	for (int i = 0; i < str_size; i++)
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
	cout << p << endl;
	return 0;
}
	

