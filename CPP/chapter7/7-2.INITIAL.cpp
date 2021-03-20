//7-2.INITIAL.CPP

#include <iostream>
using namespace std;

class A{
public:
    int data;
    A(){  //default constructor
        cout<<"Constructor of class A"<<endl;
        data = 0;
    }
    ~A(){  //destructor
        cout<<"Destructor of class A"<<endl;
    }
};

class B : virtual public A{//virtual 추가해보기
public:
    B(){  //default constructor
        cout<<"Constructor of class B, derived from A"<<endl;
        data = 100;
    }
    ~B(){  //destructor
        cout<<"Destructor of class B"<<endl;
    }
};

class C : virtual public A{//virtual 추가해보기
public:
    C(){  //default constructor
        cout<<"Constructor of class C, derived from A"<<endl;
        data = 200;
    }
    ~C(){  //destructor
        cout<<"Destructor of class C"<<endl;
    }
};

class D : public B, public C {
public:
    D(){   //default constructor
        cout<<"Constructor of class D, derived from B and C"<<endl;
    }
    ~D(){  //destructor
        cout<<"Destructor of class D"<<endl;
    }
};

void main()
{
    // 주석1
	
    cout<<"Defining an object of class A"<<endl;
    A aa;
    cout<<endl;
    
    // 주석 2
	
    cout<<"Defining an object of class B"<<endl;
    B bb;//A의 constructor 가 먼저 호출되는 이유: 상속되는 A의 데이터 멤버는 A의 constructor 로 생성
    cout<<endl;
    
    // 주석 3
	
    cout<<"Defining an object of class C"<<endl;
    C cc;
    cout<<endl;
    
    // 주석 4
	
    cout<<"Defining an object of class D"<<endl;
    D dd;
    //class B,class C에 virtual이 있으면 정상, 없으면 어느 class의 
    //data인지 모호하기 때문에 error가 발생한다.
//    cout << dd.data;  //200
    //B와 C가 A를 virtual로 상속받고 D를 반복상속하면 상속 선언 시 먼저     //선언된 class의 데이터만 접근가능하다.
    cout << dd.B::data << endl; //200??
    cout << dd.C::data;  //200
    cout << endl;
    
    //system("pause");
} //소멸자는 생성자 생성 순서의 반대인가??