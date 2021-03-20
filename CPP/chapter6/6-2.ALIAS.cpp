// 6-2.ALIAS.CPP
#include <iostream>
using namespace std;

void main (){
    int a = 2;
    int b = 10;
	// c는 b의 alias이다.
    int &c = b;
	cout<<"&b = "<<&b<<", &c = "<<&c<<endl;
    cout << endl << "b equals to " << b << endl;
	// 다음 문장은 b의 값을 변경하게 된다.
    c = a * b;
	cout <<"After c = a *b: a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
	// b는 변경되지 않아야 한다(b는 lvalue로 사용된 것이 아니다, 그러나 변경되었다)
    cout << endl << "now b equals to " << b << endl;
	system("pause");
}