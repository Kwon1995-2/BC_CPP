#include <iostream>
#include "MyLinkedList.h"
#include <iomanip>
using namespace std;



void MyLinkedList::addNode(int a, string b, int c, int d, int e) {
	TNODE* t = new TNODE;  //객체를 선언해야 쓸 수 있다.
	t->id = a;
	t->name = b;
	t->year = c;
	t->month = d;
	t->day = e;
	t->next = NULL;
	addNode(t);
}
void MyLinkedList::addNode(TNODE* _node) {
	if (head == NULL)
	{
		head = _node;
		return;
	}

	TNODE* tnode = head;
	while (1)
	{
		if (tnode->next == NULL)
		{
			tnode->next = _node;
			break;
		}
		tnode = tnode->next;
	}
	//_node->next = head;
	//head = _node;
	/*_node = _node->next;
	while (!_node) { _node = _node->next; }*/
}
void MyLinkedList::display() {
	TNODE* n;
	n->next = head;
	while (!n->next) { 
		cout << n->id << setw(6) << n->name << n->year << ". " << n->month << ". " << n->day << endl; 
	}
}
void MyLinkedList::insertNode(TNODE* node1, TNODE* node2) {

}
void MyLinkedList::deleteNode(TNODE* node) {

}
void MyLinkedList::search(int) {

}