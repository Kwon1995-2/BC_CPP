#include <iostream>
using namespace std;

class PointerClass {
	int number;
	int* pointer;
public:
	PointerClass() : number(NULL), pointer(NULL) {};
	~PointerClass() {};
	friend istream& operator >>(istream& s, PointerClass& pc);
	friend ostream& operator <<(ostream& s, PointerClass& pc);

	PointerClass(const PointerClass& src);
};

int main() {
	PointerClass p;
	cout << "input an object..." << endl;
	cin >> p;
	cout << "You have input an object -> " << p <<endl;


	PointerClass p1 = p;  // 복사생성자 호출
	cout << p1;

	p1 = p;  // 단순 대입연산 -> 대입연산자 오버로딩 
	cout << p1;
	return 0;
}

istream& operator >>(istream& s, PointerClass& pc)
{
	s >> pc.number;
	pc.pointer = &(pc.number);
	return s;
}
ostream& operator <<(ostream& s, PointerClass& pc)
{
	cout << "print PointerClass : ";
	s << pc.number << ", " << pc.pointer << ", " << *(pc.pointer) << endl;
	return s;
}

PointerClass::PointerClass(const PointerClass& src) //p가 인자로 넘어옴
{											  //p1이 receiver object
	number = src.number; //p1.number = src.number;
	pointer = &(number); //p1.pointer = &(p1.number);
}