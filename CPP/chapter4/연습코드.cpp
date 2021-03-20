//reference�� ���� �Լ� return ��
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
		cout << "\nSelect command 1: ��� �ʱ�ȭ, 2: Add, 3. Display, 4: Quit => ";
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
// ���� b�� ����Ͽ� ��� ���Ҹ� 0���� �ʱ�ȭ�ϴ� �Լ��� �ۼ�.
// �Ѱܹ��� �迭 a��, �Ʒ��� ���õ� �ڵ�� ���� *b�� �����Ͽ� ����ؾ� ��.
void InputComplexNumber(struct Matrix& m)
{
	//�迭 ���� �ʱ�ȭ: 0<= m[][] < N*N
	 //srand()����Ͽ� random number ���� ������ �ʱ�ȭ
	
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
	//��� a�� return
	
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