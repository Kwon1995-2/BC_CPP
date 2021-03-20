// #include <iostream>

// using namespace std;

// void square(const int* const width);
// void square1(int* const j);
// int main(void)
// {
//   int i=10;
//   int*const j=&i;
//   square1(&i);
//   //square(j);
//   cout<<"i= "<<i<<", j = "<<*j<<endl;

//   int k=10;
//   const int* const width=&k;
//   square(width);
//  // square1(width);

//  int a[]={12, 46, 58, 27};
//   const int* p=a;
//   //const int* p=a; p가 가리키는 곳 값 못 바꿈
//   //int* const p=a; p의 주소값 못 바꿈
//  //*p = 10;
//  //p[1] = 55;
//  a[1] = 44;
//  p++;
//  int *q = a;
//  //q=p;

//  int m=10;
//  const int n =20;
//  int *pm=&m;
//  int *const pn=&m;
//  const int* pp = &m;
//  const int* const e =&m;
//  m = n;
//  m = *pn;
//  m = *e;
//  n = m;//값을 못 바꿈
//  n = *pn;
//  n=*e;
//  pp = &n; //pp=*n;
// pm = &m;
// pm = &n;//const int
// pm = pn;
// pm = e; //const int* const e
// pn = &m;//주소값 못 바꿈
// pn = &n;
// pn = pm;
// pn = e;
// e = &m;//아예 못 바꿈
// e = &n;
// e = pm;
// e = pn;
// e = pn;
// }
// void square(const int* const width){
//   int value;
//   value =(*width)*(*width);
// }
// void square1(int* const j){
//   *j *= *j;
// }