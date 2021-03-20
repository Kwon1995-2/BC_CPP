#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	// 파일 argument가 없으면 사용법을 보여주고 종료
	if (argc != 2)
	{
		cout << "usage : stack.exe filename" << endl;
		return 1;
	}

	// 스택 변수 선언
	stack<char> S;

	// 파일을 연다. 파일명은 argv[1]에 지정되어 있다.
	FILE* fp = fopen(argv[1], "rt");
	if (!fp)
	{
		// 파일 열기에 실패하면
		cout << "failt to open File:" << argv[1] << endl;
		return 1;
	}

	char ch;
	try
	{
		// 파일에서 글자 하나를 읽어 들인다. 파일 마지막(EOF)이면 루프를 종료
		while ((ch = fgetc(fp)) != EOF)
		{
			// 괄호가 열리면 스택에 추가 ('{' 또는 '(')
			if (ch == '{' || ch == '(')	S.push(ch);

			// 괄호가 닫히면 스택과 비교 ('}' 또는 ')')
			if (ch == '}' || ch == ')')
			{
				if (S.empty())
				{
					// 스택이 비었다면 열리기도 전에 닫는 괄호가 나왔으므로 예외를 발생
					char msg[64];
					sprintf(msg, "Extra right paren - [%c]", ch);
					throw(exception (msg));
				}
				else
				{
					// 스택에 데이터는 있지만 괄호의 짝이 맞지 않으면 예외를 발생
					if ((ch == '}' && S.top() != '{') || (ch == ')' && S.top() != '('))
					{
						char msg[64];
						sprintf(msg, "Mismatch paren - [%c]", ch);
						throw(exception(msg));
					}
					// 스택에 데이터가 있고 제대로 짝이 맞으면 pop
					else
						S.pop();
				}
			}
		}

		// 최종적으로 스택이 비어 있으면
		if (S.empty())
			cout << "Match!!!" << endl;
		// 최종적으로 스택에 데이터가 있으면
		else
			cout << "Mismatch!!!" << endl;
	}
	catch (const exception& e)
	{
		// 예외가 발생되었을 때
		cout << e.what() << endl;
	}

	// 파일 닫기
	fclose(fp);

	return 1;
}