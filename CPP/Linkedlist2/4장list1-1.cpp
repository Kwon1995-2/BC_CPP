//exercise: list iterator
#include <iostream>
using namespace std;

class List;

class Node {
	friend ostream& operator<<(ostream&, List&);
	friend class List;  // List�� ��(Node) access����
private:
	int num;// ������ �����Ͽ� �Է��Ѵ�
	Node* link;
};

class List {
private:
	Node* first;
public:
	List();
	//List(int);
	//List(const List&);//list�� ����
	void addNode(int);
	List& addList(List&);//a = a+ b(a1 a2 a3 b1 b2 b3 b4)
	void showList();
	List& mergeList(List&);//a = a1, b1, a2, b2 ������ ���� ���ϸ鼭 merge
	
	friend istream& operator>>(istream&, List&);//List �Է�
	friend ostream& operator<<(ostream&, List&);//List ���
	
	List& operator=(const List& l);//list�� first�� �����ϴ� ������ ����
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
List::List(const List& n) {  //n �� ���ؼ� �������� ���Ѵ�.
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
		x.addNode(num); //���ڷ� ���� ��ü�� ����Լ� ȣ��
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
	while (p != NULL) {  //while(!p) -> p�� null�� �� �۵�
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
	List a1, a2;  //class �ȿ� �Լ��� ������ ��ü.MakeList�ؾ� ��
	MakeList(a1, 21);  //������ �����Ͽ� ��带 ����, 10�� ��� ����
	MakeList(a2, 18);  //a2�� empty list�̰ų� ���� list�� ���� ���� ������ ��
	a1.showList();  //����(circular) ����Ʈ�̹Ƿ� 2�� ����ϰ� ����
	//cout <<a1;
	//cout << a2
	a2.showList();
	//List a3 = a1.addList(a2);//���� �����ڸ� ����ϴ� �ǽ�
	//a3.showList();
	List a4 = a1.mergeList(a2);
	a4.showList();
	List a5;
	a5 = a4; //assign operator�� overloading
	//cout << a4;
	return 1;

}
