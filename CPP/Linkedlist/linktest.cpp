#include <iostream>
#include "MyLinkedLIst.h"

using namespace std;

int main()
{
	{
		MyLinkedList mm;

		mm.addNode(0, "Kim", 2000, 1, 1);
		mm.addNode(1, "Lee", 2001, 1, 1);
		mm.addNode(2, "Choi", 2002, 1, 1);

		mm.display();
		cout << endl;
	}

	return 1;
}