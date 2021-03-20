#include <iostream>
#include "MyDoubleLinkedList.h"
#include <iomanip>
using namespace std;

MyDoubleLinkedList ::~MyDoubleLinkedList() {
	while (1) {
		DNODE* del = head;
		head = head->next;
		
		cout << "delete : " << del->id << endl;
		delete del;

		if (head == NULL) break;
	}
}

//void MyDoubleLinkedList::addNode(int a, string b, int c, int d, int e) 
//{
//	DNODE* t = new DNODE; 
//	t->id = a;
//	t->name = b;
//	t->year = c;
//	t->month = d;
//	t->day = e;
//	t->prev = NULL;
//	t->next = NULL;
//
//	int x;
//	cout << "0 : front, 1 : back = ";
//	cin >> x; 
//	cout << endl;
//
//	if (x == 0) { addNodeFront(t); }
//	else if (x == 1) { addNodeBack(t); }
//	else { delete t; 
//	return;
//	}//메모리 해제
//}
//void MyDoubleLinkedList::addNodeFront(DNODE* _node) {
//	head->prev = _node;
//	_node->next = head; //_node->next = head->next;
//	//_node->prev = head;
//	head = _node;
//}
void MyDoubleLinkedList::addNodeFront(int a, string b, int c, int d, int e) {
	DNODE* t = new DNODE;
	t->id = a;
	t->name = b;
	t->year = c;
	t->month = d;
	t->day = e;
	t->prev = NULL;
	t->next = NULL;

	head->prev = t;
	t->next = head; //_node->next = head->next;
	//_node->prev = head;
	head = t;
}
//void MyDoubleLinkedList::addNodeBack(DNODE* _node)
//{
//	if (head == NULL)
//	{
//		head = _node;
//		return;
//	}
//
//	DNODE* dnode = head;
//	while (1)
//	{
//		if (dnode->next == NULL)
//		{
//			_node->prev = dnode;
//			dnode->next = _node;
//			break;
//		}
//		dnode = dnode->next;
//	}
//}
void MyDoubleLinkedList::addNodeBack(int a, string b, int c, int d, int e)
{
	DNODE* t = new DNODE;
	t->id = a;
	t->name = b;
	t->year = c;
	t->month = d;
	t->day = e;
	t->prev = NULL;
	t->next = NULL;

	if (head == NULL)
	{
		head = t;
		return;
	}

	DNODE* dnode = head;
	while (1)
	{
		if (dnode->next == NULL)
		{
			t->prev = dnode;
			dnode->next = t;
			break;
		}
		dnode = dnode->next;
	}
}
void MyDoubleLinkedList::insertNode(int z, int a, string b, int c, int d, int e) {
	DNODE* x1;
	DNODE* x2;
	x1 = head;
	x2 = head->next;
	while (1)
	{
		if (x1->id == z) break;
		x1 = x1->next;
		x2 = x2->next;
	}
	DNODE* y = new DNODE;
	y->id = a;
	y->name = b;
	y->year = c;
	y->month = d;
	y->day = e;
	y->next = NULL;

	y->next = x2;
	y->prev = x1;
	x1->next = y;
	x2->prev = y;
}
//void MyDoubleLinkedList::insertNode(DNODE* node1, DNODE* node2) {
//	node2->next = node1->next;
//	node2->prev = node1;
//	node1->next = node2;
//}
void MyDoubleLinkedList::deleteNode(int _id) {
	DNODE* d = head;
	DNODE* e = head->next;
	DNODE* f = e->next;
	while (1) {   // 개선 필요
		if (e->id == _id) {
			//deleteNode(d);
			d->next = e->next;
			f->prev = d;
			delete e;
			break;
		}
		e = e->next;
		d = d->next;
		f = f->next;
	}
}
DNODE* MyDoubleLinkedList::searchNode(int n) {
	DNODE* s = head;
	while (1) {
		if (s->id == n) return s;
		if (s->next == NULL) break;
		s = s->next;
	}
	return NULL;
}
void MyDoubleLinkedList::displayforward() {
	DNODE* d1 = head;
	DNODE* d2 = head->next;
	while (d2 != NULL) {
		d1 = d1->next;
		d2 = d2->next;
	}
	while (d1 != NULL) {
		cout << d1->id << setw(6) << d1->name << d1->year << "." << d1->month << "." << d1->day << endl;
		d1 = d1->prev;
	}
}
void MyDoubleLinkedList::displaybackward() {
	DNODE* d = head;
	//d->next = head;
	while (d != NULL) {
		cout << d->id << setw(6) << d->name << d->year << "." << d->month << "." << d->day << endl;
		d = d->next;
	}
}
