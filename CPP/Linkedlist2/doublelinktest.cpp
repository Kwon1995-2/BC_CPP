#include <iostream>
#include "MyDoubleLinkedList.h"
#include <iomanip>

using namespace std;

int main()
{
	MyDoubleLinkedList mm;

	mm.addNodeBack(0, "Kim", 2000, 1, 1);
	mm.addNodeFront(1, "Lee", 2001, 1, 1);
	mm.addNodeBack(2, "Choi", 2002, 1, 1);
	mm.addNodeBack(3, "Shy", 2003, 1, 1);
	mm.addNodeBack(4, "Shoe", 2004, 1, 1);
	mm.displaybackward();
	cout << endl;
	mm.displayforward();
	cout << endl;

	mm.insertNode(1, 10, "Who", 2010, 1, 1);
	mm.displaybackward();
	cout << endl;
	mm.displayforward();
	cout << endl;

	mm.deleteNode(3);
	mm.displaybackward();
	cout << endl;
	mm.displayforward();
	cout << endl;

	DNODE* t = mm.searchNode(1);
	if (t)
	{
		cout << t->id << setw(6) << t->name << t->year << "." << t->month << "." << t->day << endl;
	}


	return 1;
}