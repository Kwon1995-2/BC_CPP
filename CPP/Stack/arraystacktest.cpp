#include <iostream>
#include "arraystack.h"
using namespace std;
int main()
{
	try
	{
		ArrayStack<int> A;
		A.push(7);
		A.push(13);
		cout << A.top() << endl; A.pop();
		A.push(9);
		cout << A.top() << endl;
		cout << A.top() << endl; A.pop();
		A.pop();
		A.pop();
	}
	catch (const RuntimeException e)
	{
		cout << e.getMessage() << endl;
	}

	try
	{
		ArrayStack<string> B(10);
		B.push("Bob");
		B.push("Alice");
		cout << B.top() << endl; B.pop();
		B.push("Eve");
	}
	catch (const RuntimeException e)
	{
		cout << e.getMessage() << endl;
	}
	return 1;
}