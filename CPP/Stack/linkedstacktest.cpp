#include <iostream>
#include "linkedstack.h"
using namespace std;
int main()
{
	try
	{
		LinkedStack A;
		A.push("Bob");
		A.push("Alice");
		cout << A.top() << endl; A.pop();
		A.push("Eve");
		cout << A.top() << endl;
		cout << A.top() << endl; A.pop();
	}
	catch (const RuntimeException e)
	{
		cout << e.getMessage() << endl;
	}

	return 1;
}