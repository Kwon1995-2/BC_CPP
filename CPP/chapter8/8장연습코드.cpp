#define DefaultSize 10
#include <iostream>
//2018년 실습 코드
using namespace std;
class Person;
class Bag {
public:
	Bag(int MaxSize = DefaultSize); //생성자
	~Bag(); // 소멸자
	virtual void Add(Person&); // 정수 하나를 bag에 삽입
	virtual Person& Delete(Person&); //bag에서 정수 하나를 삭제
	bool IsFull();
	// bag이 포화상태이면 true, 그렇지 않으면 false를 반환
	bool IsEmpty();
	// bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
	int Top();
	friend ostream& operator<< (ostream& stream, Bag b);
protected:
	void Full(); // bag이 포화상태일 때의 조치
	void Empty(); // bag이 공백 상태일 때의 조치
	Person *arr;
	int MaxSize; // 배열의 크기
	int top; // 배열에서 원소가 들어 있는 가장 높은 위치
};

class Set : public Bag {
public:
	Set(int MaxSize = DefaultSize);      //생성자
	~Set();      // 소멸자
				 //Set 자료구조에 맞게 Add(), Delete() 함수 재정의
	void Add(int);
	int *Delete(int&);
	friend ostream& operator<< (ostream& stream, Set s);
};
class Person {
protected:
	String name;
public:
	Person(char* n) : name(n)
	{ }
	// virtual void Print (){
	void Print() {
		cout << "Person::내 이름은 " << name << endl;
	}
};

class Foreigner : public Person {
public:
	Foreigner(char* n) : Person(n)
	{ }

	void Print() {
		Person::Print();
		cout << "fid is " << fid << endl;
	}
private:
	int fid;
};

class Student : public Person {
public:
	Student(char * n) : Person(n)
	{ }

	void Print() {
		Person::Print();
		cout << "sid is " << sid << endl;
	}
private:
	int sid;
};

Bag::Bag(int MaxBagSize) : MaxSize(MaxBagSize) {
	arr = new int[MaxSize];
	top = 0;
}

Bag::~Bag() {
}

bool Bag::IsFull() {
	if (top == MaxSize - 1)
		return true;
	else
		return false;
}

bool Bag::IsEmpty() {
	if (top == 0)
		return true;
	else
		return false;
}

void Bag::Full() {
	cout << "Data structure is full" << endl;
}

void Bag::Empty() {
	cout << "Data structure is empty" << endl;
}

void Bag::Add(Person& x) {
	if (IsFull())
		Full();
	else {
		arr[top] = x;
		cout << "BAG에 " << arr[top] << "이 추가되었습니다" << endl;
		top++;
	}
}

Person& Bag::Delete(Person& x) {
	if (IsEmpty()) {
		Empty();
		return x;
	}
	int deletePos = top / 2;
	x = arr[deletePos];
	for (int index = deletePos; index<top; index++)
		arr[index] = arr[index + 1];
	top--;
	return x;
}

int Bag::Top() {
	return top;
}
//주석 1
//
ostream& operator<<(ostream& stream, Bag b) {
	cout << "ostream& operator<<(ostream& stream, Bag b) " << endl;
	for (int i = 0; i<b.Top(); i++) {
		stream << b.arr[i] << endl;
	}
	return stream;
}
//

Set::Set(int MaxBagSize) : Bag(MaxBagSize) {}

Set::~Set() {
}

void Set::Add(Person x) {
	if (IsFull())
		Full();
	else {
		for (int i = 0; i<MaxSize; i++) {
			if (arr[i] != x) {
				arr[top] = x;
				cout << "SET에 " << arr[top] << "이 추가되었습니다" << endl;
				top++;
				return;
			}
			else {
				cout << "중복된 값 입니다" << endl;
				return;
			}
		}
	}
}

Person& Set::Delete(Person& x) {
	if (IsEmpty()) {
		Empty();
		return 0;
	}
	int deletePos = top / 2;
	x = arr[deletePos];
	for (int index = deletePos; index<top; index++)
		arr[index] = arr[index + 1];
	top--;
	return x;
}
//주석 1

ostream& operator<<(ostream& stream, Set s) {
	cout << "ostream& operator<<(ostream& stream, Set s) " << endl;
	for (int i = 0; i<s.Top(); i++) {
		stream << s.arr[i] << endl;
	}
	return stream;
}

void main() {
	Person* p[10];
	Set s;
	p[0] = new Foreigner("Tom");
	p[1] = new Student("Thomas");
	p[2] = new Student("Ashley");
	p[3] = new Student("Ryan");
	p[4] = new Student("Daniel");
	p[5] = new Foreigner("Matthew");
	p[6] = new Foreigner("Samuel");
	p[7] = new Foreigner("William");
	p[8] = new Person("Sophie");
	p[9] = new Student("Jessica");

	for (int i = 0; i < 10; i++)
		s.Add(p[i]);
	cout << s;
	for (int i = 0; i < 10; i++)
	{
		p[i]->Print();
		s.Delete(p[i]);
	}
	system("pause");
}