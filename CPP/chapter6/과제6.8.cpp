#include <iostream>

using namespace std;

class ListNode {
	friend class List;
private:
	int data;
	ListNode* link;
public:
	friend istream& operator >>(istream& s, ListNode* n);
	friend ostream& operator <<(ostream& s, ListNode* n);
};

class List {
public:
	List() :first(NULL) {};
	~List();
	void InsertNode(int);
	friend istream& operator >>(istream& s, List& n);
	friend ostream& operator <<(ostream& s, List& n);
private:
	ListNode* first;
};

istream& operator >>(istream& s, List& n) {
	s >> n.first;
	return s;
}
ostream& operator <<(ostream& s, List& n) {
	s << n.first;
	return s;
}
istream& operator >>(istream& s, ListNode* n) {
	s >> n->data;
	ListNode* t = new ListNode;
	t->data = n->data;
	t->link = NULL;  //??

	if (n == NULL) {
		n = t;
		return s;
	}

	ListNode* p = n;
	while (1) {
		if (p->link == NULL)
		{
			p->link = t;
			break;
		}
		p = p->link;
	}
	return s;
}
ostream& operator <<(ostream& s, ListNode* n) {
	//s << n->data; cout << "->";
	while (n != NULL) {
		s << n->data; cout << "->";
		n = n->link;
	}
	cout << "end" << endl;
	return s;
}
List::~List() {
	ListNode* t = first;
	while (t != NULL) {
		ListNode* u = t;
		t = t->link;
		cout << "¼Ò¸êÀÚ È£Ãâ" << endl;
		delete u;
	}
}
void List::InsertNode(int _data) {
	ListNode* t = new ListNode;
	t->data = _data;
	t->link = NULL;  //??

	if (first == NULL) {
		first = t;
		return;
	}
	
	ListNode* p = first;
	while (1) {
		if (p->link == NULL)
		{
			p->link = t;
			break;
		}
		p = p->link;
	}
}
int main(void)
{
	List list;
	int num = 0;
	cout << "number of for loop : ";
	cin >> num; 

	for (int i = 0; i < num; i++) {
		cin >> list;
	}

	//list.InsertNode(0);//cin >> 0;
	//list.InsertNode(1);
	//list.InsertNode(2);
	cout << list;

}
