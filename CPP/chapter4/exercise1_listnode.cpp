//exercise: list iterator
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

class List;

class Node {
	friend class List;
private:
	//float coef;
	int exp;
	Node* link;
};

class List {
private:
	Node* first;
public:
	List();
	//List& addList(List&);
	//void addNode(float, int);
	void addNode(int);
	void showList();
	void addList(List&);
	//friend istream& operator>>(istream&, List&);//List �Է�
	//friend ostream& operator<<(ostream&, List&);//List ���
};

//ostream& operator<<(ostream& os, List& l)
//{
//		return os;
//}

List::List() : first(NULL) {}


void MakeList(List& I) {
	int num = 0;
	int n = 0;
	while (n++ < 5) {
		num = rand() % 5;
		I.addNode(num);
	}
}
void List :: addNode(int n) {
	//Node t;
	Node* t = new Node;
	t->exp = n;
	t->link = first;
	first = t;
}
void List::showList() {
	//pointer�� ���󰡸鼭 null�� ���� ������ ���
	Node* p;
	p = first;
	cout << "first";
	while ( p!= NULL) {  //while(!p)
		cout << setw(3) <<"->"<< p->exp;
		p = p->link;
	}
	cout << endl;
}
void List::addList(List& x) {
	Node* p; //Node q;
	p = first;
	while (p->link) {p = p->link;}
	p->link = x.first;
}

int main(void)
{
	srand((unsigned int) time(NULL));
	List a1, a2;
	MakeList(a1);//������ ����� �Է��Ͽ� ó��
	MakeList(a2);//a2�� empty list�̰ų� ���� list�� ���� ���� ������ ��
	a1.showList();//����(circular) ����Ʈ�̹Ƿ� 2�� ����ϰ� ����
	//cout <<a1;
	//cout << a2
	a2.showList();
	a1.addList(a2);
	a1.showList();
	//List a3 = a1.addList(a2);
	//a3.showList();
	//cout << a3;
	return 1;
	
}
