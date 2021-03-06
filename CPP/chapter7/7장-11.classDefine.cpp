 //7장-11 classDefine.cpp
#include <iostream>
using namespace std;

class A{
private:
    int a1;
protected:
    int a2;
public:
    int a3;
	A(int i = 0, int j = 0, int k = 0):a1(i), a2(j), a3(k) {}
	//void virtual show() {
	void show() {
		cout<<"A::show() -> a1 ="<<a1<<", a2 = "<<a2<<", a3 = "<<a3<<endl;
	}
};
//class B : protected A{
class B : public A {
private:
    int b1;
protected:
    int b2;
public:
    int b3;
	B(int i = 0, int j = 0, int k = 0): A(i,j,k) {b1 = i; b2 = j; b3 = k;}
	void show() {
		A::show();//code reuse 사용예
		cout<<"B::show()->b1 ="<<b1<<", b2 = "<<b2<<", b3 = "<<b3<<endl;
	}
};
class C: protected B{
private:
    int c1;
protected:
    int c2;
public:
    int c3;
	C(int i = 0, int j = 0, int k = 0):B(i,j,k) {c1 = i; c2 = j; c3 = k;}
	void show() {
		B::show();//code reuse 사용예
		cout<<"C::show()-> c1 ="<<c1<<", c2 = "<<c2<<", c3 = "<<c3<<endl;
	}
};

//void main(){
//    A ax(1,2,3);
//	cout<<"ax ::"<<endl;
//	ax.show();
//    B bx(4,5,6);
//	cout <<"bx = ::"<<endl;
//	bx.show();
//    C cx(7,8,9);
//	cout<<"cx = ::"<<endl;
//	cx.show();
//	ax = bx;//protected로 상속시에 변수 치환이 안됨
//	ax = (A)bx;
//	system("pause");
//}
void main() {
	A ax(1,2,3);
	cout<<"ax ::"<<endl;
	ax.show();
	B bx(4,5,6);
	cout <<"bx = ::"<<endl;
	bx.show();
	C cx(7,8,9);
	cout<<"cx = ::"<<endl;
	cx.show();
	ax = bx;//protected로 상속시에 변수 치환이 안됨
	ax.show();
	ax = (A)bx;
	ax.show();
	system("pause");
}