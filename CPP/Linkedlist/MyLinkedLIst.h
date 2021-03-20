#include <iostream>
using namespace std;
typedef struct _tnode {
	int id;
	string name; //char name[32];
	int year, month, day;
	struct _tnode* next;
}TNODE;

class MyLinkedList {
private:
	TNODE* head;
public:
	MyLinkedList() :head(NULL) {};
	~MyLinkedList() {};
	void addNode(TNODE*);
	void addNode(int, string, int, int, int);
	void display();
	void insertNode(TNODE*, TNODE*);
	void deleteNode(TNODE*);
	void search(int);
};
