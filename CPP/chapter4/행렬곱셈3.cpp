#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<iostream>
#include<windows.h>


using namespace std;

class Matrix {
public:
	Matrix() { };  //초기화 어떻게 하지??
	Matrix(int row, int col);
	int get_Date();
	int display();
	Matrix& Multiply(Matrix b);
	Matrix& Multiply(Matrix&, Matrix&);
	Matrix& Add(Matrix&);
private:
	int rows, cols;
	int *Term;
};

int Matrix::get_Date()
{
	
	for (int i = 0; i < rows; i++)
		    {
		        for (int j = 0; j < cols; j++)
		        {
		            Term[i * cols + j] = rand() % 8;
		        }
		    }

	return 0;
}

Matrix::Matrix(int row, int col) : rows(row), cols(col)
{
	Term = new int[rows * cols]; //오버플로??
}

int Matrix::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << Term[i * cols + j];
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

Matrix& Matrix :: Add(Matrix&b)
{
	if (rows != b.rows || cols != b.cols)
		cout << "Can't Add";
	else if(rows == b.rows && cols == b.cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				Term[i * cols + j] += b.Term[i*cols+j];
			}
			cout << endl;
		}
	}
	else
		cout << "Can't Add";

	return (*this);
}
Matrix& Matrix::Multiply(Matrix b)
{
	Matrix t(rows, b.cols);
	if (cols != b.rows)
		cout << "Can't Multiply";
	else if (cols == b.rows)
	{
		for (int k = 0; k < rows; k++)
		{
			for (int i = 0; i < b.cols; i++)
			{
				t.Term[k * b.cols + i] = 0;
				for (int j = 0; j < cols; j++)
				{
					t.Term[k * b.cols + i] += Term[k * cols + j] * b.Term[j * b.cols + i];
				}
				cout << endl;
			}
		}
	}
	else
		cout << "Can't Multiply";

	return t;
}

Matrix& Matrix::Multiply(Matrix& b, Matrix& c)
{
	
	if (cols != b.rows)
		cout << "Can't Multiply";
	else if (cols == b.rows)
	{
		for (int k = 0; k < rows; k++)
		{
			for (int i = 0; i < b.cols; i++)
			{
				c.Term[k * b.cols + i] = 0;
				for (int j = 0; j < cols; j++)
				{
					c.Term[k * b.cols + i] += Term[k*cols+j] * b.Term[j*b.cols+i];	
				}
				cout << endl;
			}
		}
	}
	else
		cout << "Can't Multiply";

	return c;
}

int main(void)
{
	Matrix a(2,3);
	Matrix b(3,4);
	Matrix c(2,4);
	Matrix d;
	srand((unsigned int)time(NULL));

	a.get_Date();
	b.get_Date();
	//c.get_Date();
	a.display();
	b.display();
	//c.display();
	//d = a.Add(c);
	/*d = a.Multiply(b);
	d.display();*/

	d = a.Multiply(b,c);
	d.display();
}