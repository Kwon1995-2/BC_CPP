#include <iostream>
#include "MyLinkedList.h"
#include <iomanip>
using namespace std;


MyLinkedList::~MyLinkedList() {
	
	while (1) {
		TNODE* del = head;
		head = head->next;
		//if (del != NULL) {
			//delete del;
			//cout << "delete" << endl;
		//}
		cout << "delete : " << del->id << endl;
		delete del;

		if (head == NULL) break;	
	}
}
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
	TNODE* d = head;
	//d->next = head;
	while (d != NULL) { 
		cout << d->id << setw(6) << d->name << d->year << "." << d->month << "." << d->day << endl; 
		d = d->next;
	}
}
void MyLinkedList::insertNode(int z, int a, string b, int c, int d, int e) {
	TNODE* x;
	x = head;
	while (1)
	{
		if (x->id == z) break;
		x = x->next;
	}
	TNODE* y = new TNODE;  
	y->id = a;
	y->name = b;
	y->year = c;
	y->month = d;
	y->day = e;
	y->next = NULL;
	insertNode(x, y);
	
}
void MyLinkedList::insertNode(TNODE* node1, TNODE* node2) {
	node2->next = node1->next;
	node1->next = node2;
}

void MyLinkedList::deleteNode(int _id)
{
	TNODE* d = head;
	TNODE* e = head->next;
	while (1) {   // 개선 필요
		if (e->id == _id) {
			//deleteNode(d);
			d->next = e->next;
			delete e;
			break;
		}
		e = e->next;
		d = d->next;
	}
}

//void MyLinkedList::deleteNode(TNODE* node) 
//{
//	node = node->next; //그 이전의 노드는 다음다음 노드 가리킬 것
//	node->next = NULL; //해당 노드 next NULL로 초기화
//}

TNODE* MyLinkedList::search(int n) {
	TNODE* s=head;
	while (1) {
		if (s->id == n) return s;
		if (s->next == NULL) break;
		s = s->next;
	}
	return NULL;
}

//TNODE* MyLinkedList::search(int n) {
//	TNODE* s = head;
//	while (s->id != n) {
//		s = s->next;
//		}
//	return s;
//}