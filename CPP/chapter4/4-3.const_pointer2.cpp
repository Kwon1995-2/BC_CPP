//4-3. const_pointer2.cpp   4.2.2 상수 pointer 선언
//function argument에 const 사용되는 예제를 실습 - const의 주요 용도가 함수에 전달되는 parameter에 대한 상수 규정하는 것임
#include <iostream>
using namespace std;

void square(const int *const width);
void square1(int *const j);
void square1(int* j);

void main(){
    //주석 1번
    //*
    int i=10;
    int *const j = &i;
    square1(&i);
    square(j);
	cout <<"i = "<<i<<", j = "<<*j<<endl;
	//*/
    //주석 2번
    /*
    int k=10;
    const int *const width = &k;
    square(width);
    //square1(width);  //const int * 형식의 인수가 int * 형식의 매개변수와 호환되지 않는다
    */
    //주석 3번
    
    int a[]={12, 46, 58, 27}; 
    const int *p = a;
    //*p = 10;//식이 수정할 수 있는 lvalue여야 한다
	//p[1] = 55;
	a[1] = 44;
	p++;
	int *q = a;
	//q = p; //const int * 형식의 값을 int * 형식에 assign할 수 없다
	//*
	int m = 10;
	const int n = 20;
	int *pm = &m;
	int *const pn = &m;
	const int *const e = &m;
	m = n;m = *pn; m = *e;
	//n = m; n = *pm; n = *e;//n은 수정할 수 있는 lvalue 여야 한다
	pm = &m; pm = &n; pm = pn; pm = e;
	pn = &m; pn = &n; pn = pm; pn = e;
	e = &m; e = &n; e = pm;e = pn;
	//*/
	system("pause");
}
void square(const int *const width){
	int value;
	value = (*width) * (*width);
	//*width = 10;
}
void square1(int *const j) {
	int v;
	*j *= *j;
}