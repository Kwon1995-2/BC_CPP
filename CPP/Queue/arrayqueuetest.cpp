#include <iostream>
#include "arrayqueue.h"
using namespace std;
int main()
{
	ArrayQueue<int> A;

	try
	{
		A.enqueue(7);
		A.enqueue(13);
		cout << A.front() << endl; A.dequeue();
		A.enqueue(9);
		cout << A.front() << endl;
		cout << A.front() << endl; A.dequeue();
	}
	catch (const RuntimeException e)
	{
		cout << e.getMessage() << endl;
	}

	try
	{
		ArrayQueue<string> B(10);
		B.enqueue("Bob");
		B.enqueue("Alice");
		cout << B.front() << endl; B.dequeue();
		B.enqueue("Eve");

	}
	catch (const RuntimeException e)
	{
		cout << e.getMessage() << endl;
	}
	return 1;
}