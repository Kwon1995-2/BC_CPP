#include <iostream>
#include "MyLinkedList.h"

MyLinkedList::MyLinkedList() : head(nullptr)// 생성자
{}

MyLinkedList::~MyLinkedList()// 소멸자
{
	TNODE* tnode = head;		// 리스트를 순회하기 위한 임시변수
	while (1)
	{
		head = tnode->next;
		cout << "delete :" << tnode->id << endl;
		delete tnode;
		if (head == NULL) break;
		tnode = head;
	}
}

void MyLinkedList::addNode(int _id, string name, int y, int m, int d)
{
	TNODE* tnode = new TNODE;

	tnode->id = _id;
	tnode->name = name;
	tnode->year = y;
	tnode->month = m;
	tnode->day = d;
	tnode->next = NULL;

	addNode(tnode);
}

void MyLinkedList::addNode(TNODE* node)// Node를 제일 뒤에 추가하는 함수
{
	if (!head)	// head가 없다면 node를 head로 설정
	{
		head = node;
		return;
	}

	TNODE* tnode = head;		// 리스트를 순회하기 위한 임시변수
	while (tnode->next != NULL)	tnode = tnode->next;
	tnode->next = node;
}

void MyLinkedList::insertNode(int iid, int _id, string name, int y, int m, int d)
{
	TNODE* tnode = new TNODE;

	tnode->id = _id;
	tnode->name = name;
	tnode->year = y;
	tnode->month = m;
	tnode->day = d;
	tnode->next = NULL;

	insertNode(iid, tnode);
}

void MyLinkedList::insertNode(int _id, TNODE* node)// id가 _id인 노드를 찾아서 뒤에 node 를 삽입하는 함수
{
	if (!head)	// head가 없다면 node를 head로 설정
	{
		head = node;
		return;
	}

	TNODE* tnode = head;		// 리스트를 순회하기 위한 임시변수
	while (1)
	{
		if (tnode->id == _id)
		{
			node->next = tnode->next;
			tnode->next = node;
			return;
		}
		if (tnode->next == NULL)	break;
		tnode = tnode->next;
	}
	addNode(node);
}

void MyLinkedList::deleteNode(int _id)// id가 _id인 Node를 삭제하는 함수
{
	if (!head)	return;

	TNODE* pre = NULL;
	TNODE* tnode = head;		// 리스트를 순회하기 위한 임시변수
	while (1)
	{
		if (tnode->id == _id)
		{
			if (tnode == head)
				head = tnode->next;
			else
				pre->next = tnode->next;
			delete tnode;
			return;
		}
		pre = tnode;
		tnode = tnode->next;

		if (tnode == NULL)
			break;
	}
}

TNODE* MyLinkedList::searchNode(int _id)// id를 이용해서 Node를 찾는 함수
{
	TNODE* tnode = head;		// 리스트를 순회하기 위한 임시변수
	while (1)
	{
		if (tnode->id == _id)
			return tnode;
		tnode = tnode->next;
		if (tnode == NULL)	break;
	}
	return nullptr;
}

void MyLinkedList::display()// 현재 저장된 LinkedList Node들의 name, year, month, day를 출력
{
	TNODE* tnode = head;		// 리스트를 순회하기 위한 임시변수
	while (1)
	{
		cout << tnode->id << "," << tnode->name << "," << tnode->year << "-" << tnode->month << "-" << tnode->day << endl;

		tnode = tnode->next;
		if (tnode == NULL)	break;
	}
}
