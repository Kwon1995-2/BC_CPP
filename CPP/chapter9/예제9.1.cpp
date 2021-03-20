#include <iostream>
using namespace std;
class BaseClass {
public:
	BaseClass() {
		cout << "Base class 생성자 호출" << endl;
	}
	 virtual ~BaseClass() {
		cout << "Base class 소멸자 호출" << endl;
	}
};

class Derived : public BaseClass {
public :
	Derived() {
		cout << "Derived class 생성자 호출" << endl;
	}
	~Derived() {
		cout << "Derived class 소멸자 호출" << endl;
	}
};

class ReDerived : public Derived {
public : 
	ReDerived() {
		cout << "ReDerived class 생성자 호출" << endl;
	}
	~ReDerived() {
		cout << "ReDerived 소멸자 호출" << endl;
	}
};

void main() {
	BaseClass* b;
	b = new Derived;
	//delete b;

	Derived* pder;
	pder = new ReDerived;
	b = pder;
	delete pder;
	//delete b; -> 엑세스 위반 발생
}