#include<iostream>
#include <time.h>
#include<iomanip>
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
	//int terms;
public:
	Matrix(int, int);
	~Matrix() {
		cout << "destructor" << endl;
	};
	int get_data();
	int show_data();
	int sort_data();
	int addMatrix(Matrix&);
	int MultiplyMatrix(Matrix&, Matrix&);
};

int Matrix::free = 0;
int* Matrix::data = new int[100];

Matrix::Matrix(int a, int b) {
	rows = a; cols = b;
	start = free;
	finish = start + a * b;  //왜 1을 빼야 할까?
	free += a * b;
}

int Matrix::get_data() {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			data[start+i*cols + j] = rand() % 5;
		}
	}
	return 0;

	/*for (int i = start; i < finish; i++)
		data[i] = rand() % 10;*/
}
int Matrix:: show_data() {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3)<<data[start + i * cols + j];
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
int Matrix::sort_data() {
	for (int i = 0; i < rows*cols; i++)
	{
		for (int j = 0; j < rows * cols; j++) {
			if (data[start + i] < data[start + j])
			{
				int temp = data[start + j];
				data[start + j] = data[start + i];
				data[start + i] = temp;
			}
		}
	}
	return 0;
}
int Matrix:: addMatrix(Matrix& b) {
	
	if (rows != b.rows || cols != b.cols)
	{
		cout << "can't add" << endl;
	}
	else if (rows == b.rows && cols == b.cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[start + i * cols + j] += b.data[b.start + i * cols + j];
			}
		}
	}
	else
		cout << "can't add" << endl;

	/*for (int i = start; i < finish; i++)
		data[start + i] += b.data[b.start + i];*/
	return 0;
}
int Matrix::MultiplyMatrix(Matrix& b, Matrix& c) {

	if (cols != b.rows)
	{
		cout << "can't multiply" << endl;
	}
	else if (cols == b.rows)
	{
		for (int i = 0; i < rows * b.cols; i++)
		{
			c.data[c.start + i] = 0;
			for (int j = 0; j < cols; j++)
			{
				c.data[c.start + i] += data[start + j + i / b.cols] * b.data[b.start + j * b.cols + i % b.cols];
			}
		}
	}
	else
		cout << "can't multiply" << endl;
	
	return 0;
}
int main(void)
{
	Matrix matrixA(AROWS, ACOLS);
	Matrix matrixA1(AROWS, ACOLS);
	Matrix matrixB(BROWS, BCOLS);
	Matrix matrixC(CROWS, CCOLS);

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
	//matrixC.get_data();
	//matrixC.show_data();
	matrixA.MultiplyMatrix(matrixB, matrixC);
	matrixC.show_data();
	//system("pause");
	return 0;
}

