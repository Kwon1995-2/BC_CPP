#ifndef _MYLINKEDLIST_H_
#define _MYLINKEDLIST_H_
#include <string>

using namespace std;

typedef struct _tnode {
    int id;
    string name;
    int year, month, day;
    struct _tnode* next;
} TNODE;
class MyLinkedList
{
    TNODE* head;			                // 연결 리스트의 시작점(초기는 NULL)
public:
    MyLinkedList();                         // 생성자
    ~MyLinkedList();                        // 소멸자

    void addNode(int _id, string name, int y, int m, int d);
    void insertNode(int iid, int _id, string name, int y, int m, int d);

    TNODE* searchNode(int _id);		        // id를 이용해서 Node를 찾는 함수
    void display();			                // 현재 저장된 LinkedList Node들의 name, year, month, day를 출력
    void deleteNode(int _id);		        // id가 _id인 Node를 삭제하는 함수

private:
    void addNode(TNODE* node);	            // Node를 제일 뒤에 추가하는 함수
    void insertNode(int _id, TNODE* node);	// id가 _id인 노드를 찾아서 뒤에 node 를 삽입하는 함수
};

#endif