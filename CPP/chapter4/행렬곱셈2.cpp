#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<iostream>

#define N 2

using namespace std;

class Matrix {
public :
	Matrix() {};
	
	int get_Date();
	int display();
	Matrix& Multiply(Matrix b);
	Matrix& Multiply(Matrix &, Matrix&);
private:
	int Term[N][N];
};

int Matrix :: get_Date()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Term[i][j] = rand() % 4;
		}
	}
	return 0;
}

int Matrix::display()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(2) << Term[i][j] ;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

Matrix& Matrix::Multiply(Matrix b)
{
	Matrix t;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			int sum = 0;
			for (int j = 0; j < N; j++)
			{
				/*Term[i][j] *= b.Term[j][i];
				Term[k][i] += Term[i][j];*/
				sum += Term[k][j] * b.Term[j][i];
				t.Term[k][i] = sum;
			}
		}
	}
	return t; //임시 변수, 좋지 못 한 것
}

Matrix& Matrix :: Multiply(Matrix&b, Matrix&c)
{
	for (int r=0; r < N; r++)
	{ //Matrix sum; (X)
		for (int j=0; j < N; j++)
		{
			int sum = 0;
			for (int i = 0; i < N; i++)
			{
				sum += Term[r][i] * b.Term[i][j];
				c.Term[r][j] = sum;
			}
		}
	}
	return c;
}

int main(void)
{
	Matrix a;
	Matrix b;
	Matrix c;
	Matrix d;
	srand((unsigned int)time(NULL));
	a.get_Date();
	b.get_Date();
	a.display();
	b.display();
	
	//c = a.Multiply(b);
	//c.display();

	d = a.Multiply(b, c);
	d.display();
}