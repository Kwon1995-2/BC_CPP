#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<char> brace;

	//파일 읽어오기
	FILE* fp = fopen("예제5.3stl.cpp", "rt"); //  이 파일을 text 모드로 읽어오겠다.
	if (!fp)
	{
		cout << "error! - 읽을 수 없는 파일" << endl;
		return 1;
	}

	char c;
	while (c = fgetc(fp))
	{
		if (c == '{' || c == '(') 
			brace.push(c); // (, { 만나면 stack에 넣기

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
				cout << "Can't pop" << endl; //2. 비어있는데 pop하는 경우
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
				cout << "Can't pop" << endl; //2. 비어있는데 pop하는 경우
				break;
			}
		}

		if (c == EOF)
			break;	
	}
	//오류 출력 문구 1. 남아있는 경우  
		if (!brace.empty()) //오류
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