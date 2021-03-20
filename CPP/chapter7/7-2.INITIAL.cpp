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

class B : virtual public A{//virtual �߰��غ���
public:
    B(){  //default constructor
        cout<<"Constructor of class B, derived from A"<<endl;
        data = 100;
    }
    ~B(){  //destructor
        cout<<"Destructor of class B"<<endl;
    }
};

class C : virtual public A{//virtual �߰��غ���
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
    // �ּ�1
	
    cout<<"Defining an object of class A"<<endl;
    A aa;
    cout<<endl;
    
    // �ּ� 2
	
    cout<<"Defining an object of class B"<<endl;
    B bb;//A�� constructor �� ���� ȣ��Ǵ� ����: ��ӵǴ� A�� ������ ����� A�� constructor �� ����
    cout<<endl;
    
    // �ּ� 3
	
    cout<<"Defining an object of class C"<<endl;
    C cc;
    cout<<endl;
    
    // �ּ� 4
	
    cout<<"Defining an object of class D"<<endl;
    D dd;
    //class B,class C�� virtual�� ������ ����, ������ ��� class�� 
    //data���� ��ȣ�ϱ� ������ error�� �߻��Ѵ�.
//    cout << dd.data;  //200
    //B�� C�� A�� virtual�� ��ӹް� D�� �ݺ�����ϸ� ��� ���� �� ����     //����� class�� �����͸� ���ٰ����ϴ�.
    cout << dd.B::data << endl; //200??
    cout << dd.C::data;  //200
    cout << endl;
    
    //system("pause");
} //�Ҹ��ڴ� ������ ���� ������ �ݴ��ΰ�??