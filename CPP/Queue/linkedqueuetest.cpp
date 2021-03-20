#include <iostream>
#include "linkedqueue.h"
using namespace std;
int main()
{
	try
	{
		LinkedQueue A;
		A.enqueue("Bob");
		A.enqueue("Alice");
		cout << A.front() << endl; A.dequeue();
		A.enqueue("Eve");
		cout << A.front() << endl;
		cout << A.front() << endl; A.dequeue();
	}
	catch (RuntimeException e)
	{
		cout << e.getMessage() << endl;
	}

	return 1;
}