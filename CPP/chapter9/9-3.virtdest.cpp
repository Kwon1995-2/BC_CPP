// 9-3.VIRTDEST.CPP   9.6 virtual �Ҹ���

#include <iostream>
using namespace std;
class BaseClass{
public:
    BaseClass(){
        cout<< "Base class ������ ȣ��"<< endl;
    }
	/*
    virtual ~BaseClass(){ 
        cout<< "Base class �Ҹ��� ȣ��"<< endl;
    }
	*/
	~BaseClass() {
		cout << "Base class �Ҹ��� ȣ��" << endl;
	}
};

class Derived : public BaseClass{
public:
    Derived(){
        cout<< "Derived class ������ ȣ��"<< endl;
    }
    ~Derived(){
        cout<< "Derived class �Ҹ��� ȣ��"<< endl;
    }
};

void main(){
    cout<<"----BaseClass�� Derived class�� ���"<<endl;
    BaseClass* pbase;
        
    pbase = new BaseClass;
 
    delete pbase;                
    cout << endl;

    pbase = new Derived;  
    
    delete pbase; //virual�� ���� �� destructor�� ȣ��Ǵ����� Ȯ���ϴ� �ǽ�               
    cout << endl;
    Derived* d = new Derived;
    delete d;
    system("pause");
}