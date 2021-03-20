#include <iostream>
#include "MyLinkedLIst.h"
#include <iomanip>

using namespace std;

int main()
{
	
		MyLinkedList mm;

		mm.addNode(0, "Kim", 2000, 1, 1);
		mm.addNode(1, "Lee", 2001, 1, 1);
		mm.addNode(2, "Choi", 2002, 1, 1);
		mm.addNode(3, "Shy", 2003, 1, 1);
		mm.addNode(4, "Shoe", 2004, 1, 1);
		mm.display();
		cout << endl;

		mm.insertNode(1, 10, "Who", 2010, 1, 1);
		mm.display();
		cout << endl;

		mm.deleteNode(3);
		mm.display();
		cout << endl;

		TNODE* t = mm.search(1);
		if (t)
		{
			cout << t->id << setw(6) << t->name << t->year << "." << t->month << "." << t->day << endl;
		}
	

	return 1;
}