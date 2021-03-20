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
	int* data;
public:
	//Matrix() {};
	Matrix(int r, int c) : rows(r), cols(c) {
		data = new int[rows * cols];
	}
	~Matrix() { cout << "out" << endl;  delete(data); };
	int get_data();
	int show_data();
	int sort_data();
	Matrix& addMatrix(Matrix&);
	Matrix& MultiplyMatrix(Matrix&, Matrix&);
	
};

int Matrix::get_data()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[i * cols + j] = rand() % 8;
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
			cout << setw(4) << data[i * cols + j];
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
			if (data[i] < data[j])
			{
				int temp = data[j];
				data[j] = data[i];
				data[i] = temp;
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
				data[i * cols + j] += b.data[i * cols + j];
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
				c.data[k * b.cols + i] = 0;
				for (int j = 0; j < cols; j++)
				{
					c.data[k * b.cols + i] += data[k * cols + j] * b.data[j * b.cols + i];
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
	srand((unsigned int)time(NULL));
	matrixA.get_data();
	matrixA.show_data();
	//matrixA.sort_data();
	//matrixA.show_data();
	//matrixA1.get_data();
	//matrixA1.show_data();
	//matrixA.addMatrix(matrixA1);
	//matrixA.show_data();
	matrixB.get_data();
	matrixB.show_data();
	matrixA.MultiplyMatrix(matrixB, matrixC);
	matrixC.show_data();
	//system("pause");
	/*matrixA.data_delete();
	matrixB.data_delete();
	matrixC.data_delete();*/
	return 0;
}