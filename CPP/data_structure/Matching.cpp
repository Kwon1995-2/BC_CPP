#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<char> brace;

	//���� �о����
	FILE* fp = fopen("����5.3stl.cpp", "rt"); //  �� ������ text ���� �о���ڴ�.
	if (!fp)
	{
		cout << "error! - ���� �� ���� ����" << endl;
		return 1;
	}

	char c;
	while (c = fgetc(fp))
	{
		if (c == '{' || c == '(') 
			brace.push(c); // (, { ������ stack�� �ֱ�

		if (c == '}')
		{
			switch (brace.top()) {
			case '{':
				brace.pop();
				break;
			case '(':
				cout << "not matched type of brace" << endl;
				break;
			case NULL:
				cout << "Can't pop" << endl; //2. ����ִµ� pop�ϴ� ���
				break;
			}
		}

		if (c == ')')
		{
			switch (brace.top()) {
			case '(':
				brace.pop();
				break;
			case '{':
				cout << "not matched type of brace" << endl;
				break;
			case NULL:
				cout << "Can't pop" << endl; //2. ����ִµ� pop�ϴ� ���
				break;
			}
		}

		if (c == EOF)
			break;	
	}
	//���� ��� ���� 1. �����ִ� ���  
		if (!brace.empty()) //����
		{
			cout << "error!-brace remain" << endl;
		}
		else if (brace.empty())
		{
			cout << "brace match complete" << endl;
		}


	fclose(fp);

	return 1;
}