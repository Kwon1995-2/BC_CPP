#include <time.h>
#include<iomanip>
#include<iostream>
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5

using namespace std;

class Matrix {
private:
	int rows, cols;
	static int* data;
	static int free;
	int start, finish;
	int terms;
public:
	Matrix(int , int );
	int get_data();
	int show_data();
	int sort_data();
	Matrix& addMatrix(Matrix&);
	Matrix& MultiplyMatrix(Matrix&, Matrix&);
};


int Matrix::free = 0;
int* Matrix::data = new int[100];

Matrix::Matrix(int a, int b) {
	rows = a; 
	cols = b;
	start = free; 
	finish = start + a * b;
	free += a * b; //start가 늘어나야 함
}

int Matrix::get_data()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[start+i * cols + j] = rand() % 2;
		}
	}

	return 0;
}
int Matrix::show_data()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << data[start+i * cols + j];
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

int Matrix::sort_data() {
	for (int i = 0; i < rows * cols; i++)
	{
		for (int j = 0; j < rows * cols; j++)
		{
			if (data[start+i] < data[start+j])
			{
				int temp = data[start + j];
				data[start + j] = data[start + i];
				data[start + i] = temp;
			}
		}
	}
	return 0;
}

Matrix& Matrix::addMatrix(Matrix& b)
{
	if (rows != b.rows || cols != b.cols)
		cout << "Can't Add";
	else if (rows == b.rows && cols == b.cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[start+i * cols + j] += b.data[b.start+i * cols + j];
			}
			//cout << endl;
		}
	}
	else
		cout << "Can't Add";

	return (*this);
}

Matrix& Matrix::MultiplyMatrix(Matrix& b, Matrix& c)
{

	if (cols != b.rows)
		cout << "Can't Multiply";
	else if (cols == b.rows)
	{
		for (int k = 0; k < rows; k++)
		{
			for (int i = 0; i < b.cols; i++)
			{
				c.data[c.start+k * b.cols + i] = 0;
				for (int j = 0; j < cols; j++)
				{
					c.data[c.start+k * b.cols + i] += data[start+k * cols + j] * b.data[b.start+j * b.cols + i];
				}
				//cout << endl; -> 곱하기 연산에는 필요없는 문장
			}
		}
	}
	else
		cout << "Can't Multiply";

	return c;
}
int main(void)
{
	Matrix matrixA(AROWS, ACOLS);  //3,4
	Matrix matrixA1(AROWS, ACOLS); //3,4
	Matrix matrixB(BROWS, BCOLS);  //4,5
	Matrix matrixC(CROWS, CCOLS);  //3,5
	//Matrix matrixC1(10, 5);
	srand((unsigned int)time(NULL));
	matrixA.get_data();
	matrixA.show_data();
	//matrixA.sort_data();
	//matrixA.show_data();
	matrixA1.get_data();
	matrixA1.show_data();
	//matrixA.addMatrix(matrixA1);
	//matrixA.show_data();
	matrixB.get_data();
	matrixB.show_data();
	matrixC.get_data();
	matrixC.show_data();
	//matrixC1.get_data();
	//matrixC1.show_data();
	//matrixB.show_data();
	//matrixB.sort_data();
	//matrixB.show_data();
	//matrixA.MultiplyMatrix(matrixB, matrixC);
	//matrixC.show_data();
	//system("pause");
	return 0;
}

