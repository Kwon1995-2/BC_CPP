// 9-3.VIRTDEST.CPP   9.6 virtual 소멸자

#include <iostream>
using namespace std;
class BaseClass{
public:
    BaseClass(){
        cout<< "Base class 생성자 호출"<< endl;
    }
	/*
    virtual ~BaseClass(){ 
        cout<< "Base class 소멸자 호출"<< endl;
    }
	*/
	~BaseClass() {
		cout << "Base class 소멸자 호출" << endl;
	}
};

class Derived : public BaseClass{
public:
    Derived(){
        cout<< "Derived class 생성자 호출"<< endl;
    }
    ~Derived(){
        cout<< "Derived class 소멸자 호출"<< endl;
    }
};

void main(){
    cout<<"----BaseClass와 Derived class의 경우"<<endl;
    BaseClass* pbase;
        
    pbase = new BaseClass;
 
    delete pbase;                
    cout << endl;

    pbase = new Derived;  
    
    delete pbase; //virual이 없을 때 destructor가 호출되는지를 확인하는 실습               
    cout << endl;
    Derived* d = new Derived;
    delete d;
    system("pause");
}