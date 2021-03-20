#include <iostream>
#include <stack>
#include "RuntimeException.h"

using namespace std;

int main()
{
	stack<int> mystack;

	mystack.push(5);
	mystack.push(3);
	mystack.pop();
	mystack.push(7);
	mystack.pop();
	cout << "top : " << mystack.top() << endl;

	return 1;
}