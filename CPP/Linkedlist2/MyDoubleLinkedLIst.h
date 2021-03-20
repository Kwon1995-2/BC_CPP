#include <iostream>
using namespace std;
typedef struct _dnode {
	int id;
	string name; //char name[32];
	int year, month, day;
	struct _dnode* prev;
	struct _dnode* next;
}DNODE;

class MyDoubleLinkedList {
private:
	DNODE* head;
public:
	MyDoubleLinkedList() : head(NULL) {};
	~MyDoubleLinkedList();
	//void addNode(int, string, int, int, int);
	//void addNodeFront(DNODE*);
	void addNodeFront(int, string, int, int, int);
	//void addNodeBack(DNODE*);
	void addNodeBack(int, string, int, int, int);
	void insertNode(int, int, string, int, int, int);
	//void insertNode(DNODE*, DNODE*);
	void deleteNode(int);
	DNODE* searchNode(int);
	void displayforward();
	void displaybackward();
};
