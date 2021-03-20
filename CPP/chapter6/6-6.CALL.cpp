// 6-6.CALL.CPP
#include <iostream>
using namespace std;

class Number{
public:
    //default 생성자
    Number();
    //복사 생성자
    Number(const Number&);
    //생성자 overloading
    Number(int );

    //치환 연산자
    Number & operator = (const Number &); 
    //소멸자
    ~Number(); 
    int *n;
};
Number::Number(){
    cout<<"[default 생성자 호출]"<<endl;
    n=0;
}
Number::~Number(){
    //cout<<"[소멸자 호출]"<<endl;
}
Number::Number(const Number& num){
    cout<<"[복사 생성자 호출]"<<endl;
    n = new int(sizeof(n)+1);
    n = num.n;
}
Number::Number(int _num){
    cout<<"[parameter가 있는 생성자 호출]"<<endl;
    n = new int(sizeof(n)+1);
    *n = _num;
}
//주석 1 - class 정의에서 치환 연산자 선언에 대한 주석 해제 필요
//*
Number & Number:: operator = (const Number & num){
    //code for assignment operator
    cout<<"[재정의한 assign 함수 호출]"<<endl;
    n = new int(sizeof(num)+1);
    *n = *num.n;
    return *this;
}
//*/
void main(){
    cout<<"Number n1(1)"<<endl;
    Number n1(1);
    cout<<"n1의값은: "<<*n1.n<<endl<<endl;
    cout<<"Number n2(2)"<<endl;
    Number n2(2);
    cout<<"n2의값은: "<<*n2.n<<endl<<endl;
    cout<<"Number n3(n1)"<<endl;
    Number n3(n1);
    cout<<"n3의값은: "<<*n3.n<<endl<<endl;
    cout<<"Number n4 = 3"<<endl;
    Number n4 = 3;
    cout<<"n4의값은: "<<*n4.n<<endl<<endl;
    cout<<"*n4.n = *n2.n"<<endl;
    *n4.n = *n2.n;
    cout<<"n4의값은: "<<*n4.n<<endl<<endl;
    cout<<"*n4.n = 4"<<endl;
    *n4.n = 4;
    cout<<"n4의값은: "<<*n4.n<<endl<<endl;
    cout<<"Number n5 = n3"<<endl;
    Number n5 = n3;
    cout<<"n5의값은: "<<*n5.n<<endl<<endl;
    cout<<"Number n6(3)"<<endl;
    Number n6(3);
    cout<<"n6의값은: "<<*n6.n<<endl<<endl;
    cout<<"n6 = n3"<<endl;
    n6 = n3;
    cout<<"n6의값은: "<<*n6.n<<endl<<endl;
    cout<<"n6 = 4"<<endl;
    //compiler가 자체적으로 4를 가지는 Number객체를 임의로 생성하여 치환이 가능하도록 지원
    n6 = 4; 
    cout<<"n6의값은: "<<*n6.n<<endl<<endl;
	system("pause");
}