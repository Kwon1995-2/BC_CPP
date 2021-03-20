#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void Keylessencry(char*, int);
void Keylessdecry(char*, int);
int main(void)
{
	int select = 0, key =0;
	string text = {0,};
	char* c_text = NULL;
	int str_size = 0;

	//cout << "1. 암호화 2. 복호화 : ";
	//cin >> select; cout << endl;
	cout << "Input string : ";
	cin >> text; cout << endl;

	c_text = new char[text.size() + 1];
	strcpy_s(c_text, text.size() + 1, text.c_str());
	str_size = text.length();

	Keylessencry(c_text,str_size);
	cout << c_text << endl;
	Keylessdecry(c_text, str_size);
	cout << c_text << endl;
	
	delete[] c_text;
	return 0;
}

void Keylessencry(char* _ct, int s) 
{
	
	char tmp_text[2][20] = {0,}; //변수인 s를 상수처럼 사용 못 함

	for (int i = 0; i < s+1; i++)
	{
		if ((_ct[i] >= 'a') && (_ct[i] <= 'z') || (_ct[i] >= 'A') && (_ct[i] <= 'Z'))
		{
			if (i % 2 == 0) //even
			{
				tmp_text[0][i / 2] = _ct[i];
			}
			else 
			{
				tmp_text[1][i / 2] = _ct[i];
			}
		}
	}

	if (s % 2 == 0)
	{
		for (int i = 0; i < (s / 2) +1 ; i++)
		{
			_ct[i] = tmp_text[0][i];
			_ct[i + (s / 2)] = tmp_text[1][i];
		}
	}
	else
	{
		for (int i = 0; i < (s / 2)+1; i++)
		{
			_ct[i] = tmp_text[0][i];
			_ct[i + (s / 2) + 1] = tmp_text[1][i];
		}
	}
}

void Keylessdecry(char* _ct, int s)
{
	char tmp_text[2][20] = { 0, }; //변수인 s를 상수처럼 사용 못 함

	for (int i = 0; i < (s/2)+1; i++)
	{
		if ((_ct[i] >= 'a') && (_ct[i] <= 'z') || (_ct[i] >= 'A') && (_ct[i] <= 'Z'))
		{
			if (s % 2 == 0)
			{
				tmp_text[0][i] = _ct[i];
				tmp_text[1][i] = _ct[i + s / 2];
			}
			else {
				tmp_text[0][i] = _ct[i];
				tmp_text[1][i] = _ct[i + s / 2 + 1];
			}
		}
	}

	if (s % 2 == 0)
	{
		for (int i = 0; i < s + 1; i += 2)
		{
			_ct[i] = tmp_text[0][i];
			_ct[i + 1] = tmp_text[1][i];
		}
	}
	else
	{
		int j = 0;
		for (int i = 0; i < s + 1; i = i + 2)
		{
			// j를 한칸만 움직이기
			_ct[i] = tmp_text[0][j];
			_ct[i + 1] = tmp_text[1][j];
			j++;
		}
	}
}
