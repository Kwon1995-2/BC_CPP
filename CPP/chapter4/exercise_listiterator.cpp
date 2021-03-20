//exercise: circular lined list
#include <iostream>
using namespace std;

class List;
class ListIterator;
class Node {
	friend class List;
	friend class ListIterator;
private:
	float coef;
	int exp;
	Node* link;
};

class List {
	friend class ListIterator;
private:
	Node* first;
public:
	List();//생성자가 head node 를 생성
	List& addList(List&);
	void addNode(float, int);
	void showList();
};

class ListIterator {
public:
	ListIterator(const List& l) :list(l), current(l.first) {};
	//dereferencing operators
	float& operator *() const { return current->coef; }
	int * operator->()const { return &current->exp; }
	//increment
	ListIterator& operator ++(); //preincrement
	ListIterator operator ++(int); //post increment
	bool NotNull(); //check the current element in list is non-null
	bool NextNotNull();//check the next element in list is non-null

	Node* First();     //return a pointer to the first element of list
	Node* Next();  //return a pointer to the next element of list
private:
	const List& list; //refers to an existing list
	Node* current; //points to a node in list
};

int main(void)
{
	List a1, a2;
	MakeList(a1);//지수와 계수를 입력하여 처리
	MakeList(a2);
	a1.showList();
	//cout <<a1;
	//cout << a2
	a2.showList();
	List a3 = a1.addList(a2);
	a3.showList();
	//cout << a3;
	return 1;

}
