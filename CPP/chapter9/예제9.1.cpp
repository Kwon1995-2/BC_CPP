#include <iostream>
using namespace std;
class BaseClass {
public:
	BaseClass() {
		cout << "Base class ������ ȣ��" << endl;
	}
	 virtual ~BaseClass() {
		cout << "Base class �Ҹ��� ȣ��" << endl;
	}
};

class Derived : public BaseClass {
public :
	Derived() {
		cout << "Derived class ������ ȣ��" << endl;
	}
	~Derived() {
		cout << "Derived class �Ҹ��� ȣ��" << endl;
	}
};

class ReDerived : public Derived {
public : 
	ReDerived() {
		cout << "ReDerived class ������ ȣ��" << endl;
	}
	~ReDerived() {
		cout << "ReDerived �Ҹ��� ȣ��" << endl;
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
	//delete b; -> ������ ���� �߻�
}