//exercise: list iterator
#include <iostream>
using namespace std;

class List;

class Node {
	friend ostream& operator<<(ostream&, List&);
	friend class List;  // List는 내(Node) access가능
private:
	int num;// 난수를 생성하여 입력한다
	Node* link;
};

class List {
private:
	Node* first;
public:
	List();
	//List(int);
	//List(const List&);//list를 복사
	void addNode(int);
	List& addList(List&);//a = a+ b(a1 a2 a3 b1 b2 b3 b4)
	void showList();
	List& mergeList(List&);//a = a1, b1, a2, b2 등으로 값을 비교하면서 merge
	
	friend istream& operator>>(istream&, List&);//List 입력
	friend ostream& operator<<(ostream&, List&);//List 출력
	
	List& operator=(const List& l);//list의 first만 복사하는 것으로 구현
};

void MakeList(List&, int);

ostream& operator<<(ostream& os, List& l)
{
	Node* t = l.first;
	os << "first";
	while (t != NULL) {
		os << "->" << t->num;
		t = t->link;
	}
	return os;
}
istream& operator>>(istream& is, List& l)
{
	return is;
}

List :: List() : first(NULL){}
List::List(const List& n) {  //n 을 통해서 수정하지 못한다.
	//Node* p = new Node;
	//p = n.first;
	//while (p->link != NULL) {
	//	p->num = n.first->num;
	//	p->link = n.first->link;
	//	//n.first = n.first->link;
	//}
	Node* p = n.first;
	Node* t, *q;
	int mode = 0;
	while (p != NULL)
	{
		t = new Node;
		t->num = p->num;;
		if (!mode) {
			first = t;
			mode++;
		}
		q->link = t;
		q = t;
		p = p->link;
	}
	q->link = p;
}

List& List ::operator=(const List& l) {
	Node* p = l.first;
	Node* t, * q;
	int mode = 0;
	while (p != NULL)
	{
		t = new Node;
		t->num = p->num;;
		if (!mode) {
			first = t;
			mode++;
		}
		q->link = t;
		q = t;
		p = p->link;
	}
	q->link = p;
}

void MakeList(List& x, int y) {
	/*int temp = 0;
	int num = 0;
	while (temp++ < y) {
		num = rand() % 8;
		x.addNode(num); //인자로 받은 객체의 멤버함수 호출
	}*/
	int temp = 0;
	while (temp < y) {
		x.addNode(y);
		y -= 2;
	}
}
void List::addNode(int n) {
	Node* t = new Node; 
	t->num = n;
	t->link = first;
	first = t;
}
void List::showList() {
	Node* p;
	p = first;
	cout << "first";
	while (p != NULL) {  //while(!p) -> p가 null일 때 작동
		cout << "->" << p->num;
		p = p->link;
	}
	cout << endl;
}
List& List::addList(List& x) {
	Node* p;
	p = first;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = x.first;

	return *this;
}

List& List::mergeList(List& a) {
	Node* p; p = first;
	Node* q; q = a.first;
	Node* t;
	while (1) {
		if (p->num < q->num)
		{
			t = p;
			p = p->link;
			t->link = q;
		}
		else if (p->num > q->num)
		{
			t = q;
			q = q->link;
			t->link = p;
		}

		if (p->link == NULL || q->link == NULL)
			break;
	}
	return *this;
}

int main(void)
{
	List a1, a2;  //class 안에 함수가 있으면 객체.MakeList해야 함
	MakeList(a1, 21);  //난수를 생성하여 노드를 생성, 10은 노드 갯수
	MakeList(a2, 18);  //a2가 empty list이거나 임의 list일 때도 동작 가능할 것
	a1.showList();  //원형(circular) 리스트이므로 2번 출력하게 구현
	//cout <<a1;
	//cout << a2
	a2.showList();
	//List a3 = a1.addList(a2);//복사 생성자를 사용하는 실습
	//a3.showList();
	List a4 = a1.mergeList(a2);
	a4.showList();
	List a5;
	a5 = a4; //assign operator의 overloading
	//cout << a4;
	return 1;

}
