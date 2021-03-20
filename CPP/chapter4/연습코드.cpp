//reference에 의한 함수 return 값
#include <iostream>
#include <time.h>
#include<stdlib.h>
#include <windows.h>

using namespace std;
#define N 10
struct Matrix
{
	int A[N][N];
};

void InputComplexNumber(struct Matrix&); //Matrix&
void DisplayComplexNumber(struct Matrix&);
struct Matrix& AddMatrix(struct Matrix&, struct Matrix&);

int main() 
{
	Matrix a, b, c, d;
	while (1)
	{
		int select;
		//testing plan: A) run 1. and 3, B) run 2 and 3
		cout << "\nSelect command 1: 행렬 초기화, 2: Add, 3. Display, 4: Quit => ";
		cin >> select;
		switch (select) {
		case 1:
			InputComplexNumber(a);
			Sleep(1000);
			InputComplexNumber(b);
			Sleep(1000);
			InputComplexNumber(c);
			Sleep(1000);
			InputComplexNumber(d);
			break;
		case 2:
			AddMatrix(AddMatrix(a, c), AddMatrix(b, d));
			break;
		case 3:
			DisplayComplexNumber(a);
			cout << '\n';
			DisplayComplexNumber(b);
			cout << '\n';
			DisplayComplexNumber(c);
			cout << '\n';
			DisplayComplexNumber(d);
			break;

		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}
// 변수 b를 사용하여 모든 원소를 0으로 초기화하는 함수를 작성.
// 넘겨받은 배열 a는, 아래에 제시된 코드와 같이 *b에 연결하여 사용해야 함.
void InputComplexNumber(struct Matrix& m)
{
	//배열 값의 초기화: 0<= m[][] < N*N
	 //srand()사용하여 random number 정수 값으로 초기화
	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			m.A[i][j] = rand() % 8 ;  //  0<= rand() % 8 < 7
		}
	}
	
}
void DisplayComplexNumber(struct Matrix& m)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << m.A[i][j] << '\t';
		}
		cout << '\n';
	}

}
struct Matrix& AddMatrix(struct Matrix& a, struct Matrix& b)
{
	// a = a + b
	//
	//행렬 a를 return
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a.A[i][j] = a.A[i][j] + b.A[i][j];
			//b.A[i][j] += a.A[i][j];
		}
		cout << '\n';
	}

	return a;
}