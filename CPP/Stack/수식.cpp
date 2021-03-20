#include <iostream>
#include <string>
#include "arraystack.h"

using namespace std;

int getpriority(char ch)
{
	char prec[5] = { '*', '/', '+', '-', '(' };
	char prio[5] = { 3, 3, 2, 2, 1 };

	for (int i = 0; i < 5; i++)
	{
		if (prec[i] == ch)	return prio[i];
	}
	return -1;
}

string Postfix_Notation(string& str)
{
	ArrayStack<char> opStack;
	string answer = "";
	string ops = "+-*/";

	int size = str.length();
	for (int i = 0; i < size; i++)
	{
		char ch = str.at(i);
		// '('이면 스택에 push
		if (ch == '(')
		{
			opStack.push(ch);
		}
		// ')'이면 '('가 나올 때까지 pop, 출력
		else if (ch == ')')
		{
			while (opStack.top() != '(')
			{
				answer += opStack.top();
				opStack.pop();
			}
			opStack.pop();
		}
		// 연산자면
		else if (ops.find(ch) != -1)
		{
			// 스택이 비어있으면 push
			if (opStack.empty())
				opStack.push(ch);
			// 비어있지 않다면 비교
			else
			{
				while (opStack.size() > 0)
				{
					// 우선 순위 비교 후 밖에 있는 놈이 낮으면 꺼내고 계속 비교
					if (getpriority(opStack.top()) >= getpriority(ch))
					{
						answer += opStack.top();
						opStack.pop();
					}
					// 우선 순위가 밖에 있는 놈이 높으면 반복문 탈출
					else
						break;
				}
				opStack.push(ch);
			}
		}
		// 피연산자인 경우
		else
			answer += ch;
	}
	// 스택이 빌 때 까지 pop
	while (!opStack.empty())
	{
		answer += opStack.top();
		opStack.pop();
	}
	
	return answer;
}

int main()
{
	string instr;
	string ops = "+-*/";

	cout << "수식을 입력하세요(1~9):";  // 코드 수정해야 함
	cin >> instr;

	string ret = Postfix_Notation(instr);

	cout << ret << endl;

	// 계산
	int res = 0;
	ArrayStack<char> calc;
	int size = ret.length();
	for (int i = 0; i < size; i++)
	{
		char ch = ret.at(i);

		// 연산자가 아니면
		if (ops.find(ch) == -1)
			calc.push(ch);
		else
		{
			int val1 = calc.top() - 48; calc.pop();
			int val2 = calc.top() - 48; calc.pop();
			switch (ch)
			{
			case '+': res = val1 + val2;	break;
			case '-': res = val1 - val2;	break;
			case '*': res = val1 * val2;	break;
			case '/': res = val1 / val2;	break;
			}
			calc.push(res + 48);
		}
	}

	cout << "result:" << res << endl;

	return 1;
}