// 6-1.SIDE.CPP
#include <iostream>
using namespace std;

int multiply (int &x, int &y){
    x *= y;
	cout<<"multiply(): x = "<<x<<", y = "<<y<<endl;
    return x;
}

void main (){ 
	
    // 값 치환에 의한 초기화
    int a = 5, b = 3, c = 0;
	// 다음 표현식은 side effect 때문에 잘못된 결과를 준다.
    c = a + multiply (a, b);
	cout<<"after multiply(): a = "<<a<<", b = "<<b<<endl;
    cout << "5 + 3 * 5 = "<< c << endl << endl;
	system("pause");
}