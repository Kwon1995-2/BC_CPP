#include "MyLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
	{
		MyLinkedList ll;

		ll.addNode(0, "John", 2000, 1, 1);
		ll.addNode(1, "Mike", 2010, 10, 10);
		ll.addNode(2, "Tom",  2011, 10, 11);
		ll.addNode(3, "Jake", 2012, 10, 12);
		ll.addNode(4, "Lee",  2013, 10, 13);

		ll.display();
		cout << endl;

		ll.insertNode(1, 10, "Kim", 2010, 9, 1);

		ll.display();
		cout << endl;

		ll.deleteNode(3);

		ll.display();
		cout << endl;
	}
	return 1;
}