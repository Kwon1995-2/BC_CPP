#include<iostream>
#include "linkedstack.h"
using namespace std;
int main()
{
	LinkedStack A;
	A.push("Bob");
	A.push("Alice");
	cout << A.top() << endl; A.pop();
	A.push("Eve");
	cout << A.top() << endl;
	cout << A.top() << endl; A.pop();

	return 1;
}