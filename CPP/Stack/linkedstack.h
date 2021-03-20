#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#pragma warning(disable:4290)
#include "RuntimeException.h"

//////////////////////////////////////////////////////////////////////////////////////////
template <typename E> class SLinkedList;

template <typename E>
class SNode {						// 단일 링크드 리스트 노드
private:
	E elem;							// 링크드 리스트 원소 값
	SNode<E>* next;					// 리스트의 다음 항목
	friend class SLinkedList<E>;	// SLinkedList에게 접근을 제공
};

template <typename E>
class SLinkedList {					// 단일 링크드 리스트
public:
	SLinkedList();					// 빈 리스트 생성자
	~SLinkedList();					// 소멸자
	bool empty() const;				// 리스트가 비었나?
	const E& front() const;			// 앞의 원소 반환
	void addFront(const E& e);		// 리스트의 앞에서 추가
	void removeFront();				// 리스트의 앞에서 제거
private:
	SNode<E>* head;					// 리스트의 head
};

template <typename E> SLinkedList<E>::SLinkedList()
	: head(NULL) {}						// 생성자
template <typename E> bool SLinkedList<E>::empty() const
{	return head == NULL;	}			// 리스트가 비었나?
template <typename E> const E& SLinkedList<E>::front() const
{	return head->elem;		}			// 앞의 원소 반환
template <typename E> SLinkedList<E>::~SLinkedList()
{	while (!empty()) removeFront();	}	// 소멸자
template <typename E> void SLinkedList<E>::addFront(const E& e)
{										// 리스트 앞에 추가
	SNode<E>* v = new SNode<E>;			// 새로운 노드 만들기
	v->elem = e;						// 데이터 저장
	v->next = head;						// 이제 head는 v를 따른다.
	head = v;							// v는 이제 새로운 head가 된다.
}
template <typename E> void SLinkedList<E>::removeFront()
{										// 앞의 엔트리 삭제
	SNode<E>* old = head;				// 현재 head 저장
	head = old->next;					// 이전 head를 건너뛴다.
	delete old;							// 이전 head 삭제
}

//////////////////////////////////////////////////////////////////////////////////////////
typedef string Elem;						// 스택 원소 타입
class LinkedStack
{
public:
	LinkedStack() :S(), n(0) {}
	int size() const { return n; }
	bool empty() const { return n == 0; }
	const Elem& top() const throw(StackEmpty)
	{
		if (empty()) throw StackEmpty("top of empty stack");
		return S.front();
	}
	void push(const Elem& e)
	{
		n++;
		S.addFront(e);
	}
	void pop() throw(StackEmpty)
	{
		if (empty()) throw StackEmpty("Pop from empty stack");
		n--;
		S.removeFront();

	}
private:
	SLinkedList<Elem> S;
	int n;
};
#endif