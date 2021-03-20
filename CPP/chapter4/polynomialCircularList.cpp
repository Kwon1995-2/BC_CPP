//program 4.25: Adding two polynomials, page 209
// circular list를 사용한 version

#include <iostream>

using namespace std;
// Tested p + q; 0 + p; p + 0; p + p; 0 + 0; p + (-p)
enum Bool { FALSE, TRUE };

template <class Type> class CircList;
template <class Type> class CircListIterator;
template <class Type> class List;

struct Term
{
	int coef;
	int exp;
	void EnterTerm() { cout << endl << "coef: "; cin >> coef; cout << endl << "exp: "; cin>> exp; };
};

ostream& operator<<(ostream& os, Term e)
{
	os << e.coef << "X**" << e.exp;
	return os;
}

template <class Type>
class ListNode {
	friend class CircList<Type>;
	friend class CircListIterator<Type>;
private:
	Type data;
	ListNode* link;
	ListNode(Type);
	ListNode() {};
};

template <class Type>
ListNode<Type>::ListNode(Type Default)
{
	data = Default;
	link = 0;
}

template <class Type>
class CircList {
	friend class CircListIterator<Type>;
public:
	CircList() { first = new ListNode<Type>; first->link = first; last = first; };
	CircList(const CircList&);
	~CircList();
	void Attach(Type);
private:
	ListNode<Type>* first;
	ListNode<Type>* last;
	static ListNode<Type>* av;
};

ListNode<Term>* CircList<Term>::av = 0;//static 사용시 초기화 방법
//ListNode<Term> CircList<Term>::av = 0;//오류 발생

template <class Type>
class CircListIterator {
public:
	CircListIterator(const CircList<Type>& l) : list(l) { current = l.first->link; }
	Type* Next();
	Type* First();
	Bool NotNull();
	Bool NextNotNull();
private:
	const CircList<Type>& list;
	ListNode<Type>* current;
};

template <class Type>
Type* CircListIterator<Type>::First() {
	if (current != list.first) return &current->data;
	else return 0;
}

template <class Type>
Type* CircListIterator<Type>::Next() {
	current = current->link;
	if (current != list.first) return &current->data;
	else return 0;
}

template <class Type>
Bool CircListIterator<Type>::NotNull()
{
	if (current != list.first) return TRUE;
	else return FALSE;
}

template <class Type>
Bool CircListIterator<Type>::NextNotNull()
{
	if (current->link != list.first) return TRUE;
	else return FALSE;
}


template <class Type>
CircList<Type>::CircList(const CircList<Type>& l)
{
	if (l.first == 0) { first = 0; return; }
	first = new ListNode<Type>(l.first->data);
	ListNode<Type>* newnode = first;
	for (ListNode<Type>* current = l.first->link; current != l.first; current = current->link)
	{
		newnode->link = new ListNode<Type>(current->data);
		newnode = newnode->link;
	}
	newnode->link = first;
}


template <class Type>
CircList<Type>::~CircList()
{
	if (first)
	{
		ListNode<Type>* second = first->link;
		first->link = av;
		av = second;
		first = 0;
	}
}


ostream& operator<<(ostream& os, CircList<Term>& l)
{
	CircListIterator<Term> li(l);
	if (!li.NotNull()) return os;
	os << *li.First();
	while (li.NextNotNull())
		os << " + " << *li.Next();
	os << endl;
	return os;
}


template <class Type>
void CircList<Type>::Attach(Type k)
{
	ListNode<Type>* newnode = new ListNode<Type>(k);
	if (first == 0) first = last = newnode;
	else {
		newnode->link = last->link;
		last->link = newnode;
		last = newnode;
	}
}


//////////////Polynomial////////////////
template <class Type>
class Polynomial
{
private:
	CircList<Term> poly;
public:
	template <class Type>
	friend ostream& operator<<(ostream&, Polynomial&);//polynomial 출력
	/*
	template <class Type>
	friend istream& operator>>(istream&, Polynomial&);//polynomial 출력
	*/
	friend Polynomial operator+(const Polynomial&, const Polynomial&);//polynomial ADD()
	Polynomial();//생성자 정의 필요-head node를 갖는 경우
	void Add(Term e);
	int GetData();
	/*
	T Evaluate(T&) const;//f(x)에 대하여 x에 대한 값을 구한다
	Polynomial<T> Multiply(Polynomial<T>&); //f(x) * g(x)
	Polynomial(const Polynomial<T>& p); //copy constructor
	friend istream& operator>>(istream&, Polynomial<T>&);//polynomial 입력
	friend ostream& operator<<(ostream&, Polynomial<T>&);//polynomial 출력
	const Polynomial<T>& operator=(const Polynomial<T>&) const;
	~Polynomial();
	Polynomial<T> operator-(const Polynomial<T>&)const;
	*/
};
template <class Type>
Polynomial<Type>::Polynomial()
{
	poly = 0;
}
template <class Type>
int Polynomial<Type>::GetData() {
	int i, degree;
	float coef;
	int expo;
	cout << "Enter Degree Of Polynomial:";
	cin >> degree;
	start = free;
	for (i = degree; i > 0; i--) {
		cout << "Enter coefficient of x^" << i << ":";
		cin >> coef;
		cout << "Enter exponent of x^" << i << ":";
		cin >> expo;
		NewTerm(coef, expo);
	}
	finish = free - 1;
	terms = finish - start + 1;
	return 0;
}
template <class Type>
void Polynomial<Type>::Add(Term e)
{
	poly.Attach(e);
}
template <class Type>
ostream& operator<<(ostream& os, Polynomial<Type>& p)
{
	os << p.poly;
	return os;
}

char compare(int a, int b)
{
	if (a == b) return '=';
	if (a < b) return '<';
	return '>';
}
template <class Type>
Polynomial<Type>& operator+(const Polynomial<Type>& a, const Polynomial<Type>& b)
{
	Term* p, * q, temp;
	CircListIterator<Term> Aiter(a.poly);
	CircListIterator<Term> Biter(b.poly);
	Polynomial<Type> c;

	p = Aiter.First();
	q = Biter.First();

	int x = 0;
	while (Aiter.NotNull() && Biter.NotNull()) {
		switch (compare(p->exp, q->exp)) {
		case '=':
			x = p->coef + q->coef;
			temp.Init(x, q->exp);
			if (x) c.poly.Attach(temp);
			p = Aiter.Next();
			q = Biter.Next();
			break;
		case '<':
			temp.Init(q->coef, q->exp);
			c.poly.Attach(temp);
			q = Biter.Next();
			break;
		case '>':
			temp.Init(p->coef, p->exp);
			c.poly.Attach(temp);
			p = Aiter.Next();
		}
	}
	while (Aiter.NotNull()) {
		temp.Init(p->coef, q->exp);
		c.poly.Attach(temp);
		p = Aiter.Next();
	}
	while (Biter.NotNull()) {
		temp.Init(q->coef, q->exp);
		c.poly.Attach(temp);
		q = Biter.Next();
	}
	return c;
}
//page 209, Program 4.25: adding two polynomials as circular lists with head nodes=> 수정하는 것을 실습

int main()
{
	Polynomial<int> p, q, r;
	char select;
	Term e;
	cout << endl << "Select command: a: Add_a, b: Add_b, p: a + b, d: DisplayAll, q: exit" << endl;
	cin >> select;
	while (select != 'q')
	{
		switch (select)
		{
		case 'a':
			cout << "Add a new term to p: " << endl;
			e.EnterTerm(); p.Add(e);
			break;
		case 'b':
			cout << "Add a new term to q: " << endl;
			e.EnterTerm(); q.Add(e);
			break;
		case 'p': //a+b
			r = p + q;
			Polynomial<int> r = p + q;
			cout << "do: r = p + q" << endl << "output: \n" << r << endl;

			Polynomial<int> s;
			cout << "output s" << endl << s << endl;

			Polynomial<int> t = s + s;
			cout << "do: t = s + s" << endl << "output: \n" << t << endl;

			Polynomial<int> u = p + p;
			cout << "do: u = p + p" << endl << "output: \n" << u << endl;
			delete q;
			break;
		case 'd':
			cout << "display all: " << endl;
			cout << p;
			cout << q;
			cout << r;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}
		cout << endl << "Select command: a: Add_a, b: Add_b, p: Plus, d: DisplayAll, q: exit" << endl;
		cin >> select;
	}
	system("pause");
	return 0;
}