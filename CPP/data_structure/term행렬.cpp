#include <iostream>
#include <time.h>
#include<iomanip>
#include<windows.h>

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
using namespace std;

class Matrix;
class Term
{
	friend Matrix;
private:
	float coef;
	int exp;
public:
	Term() {};
	~Term() {};
};
class Matrix {
private:
	int rows, cols;
	static Term* TermElement;
	static int free;
	int start, finish;
	int terms;
public:
	Matrix(int, int);
	int get_data();
	int show_data();
	int sort_data();
	int addMatrix(Matrix&);
	//int MultiplyMatrix(Matrix&, Matrix&);//난이도 높다 - 알고리즘 문제임
};

int Matrix::free = 0;
Term* Matrix::TermElement = new Term[100];

//Term::Term() {
//	coef = rand() % 10; 
//	Sleep(1000);
//	exp = rand()  % 10;
//}
Matrix::Matrix(int a, int b) {
	rows = a; cols = b;
	start = free;
	finish = start + a * b; 
	free += a * b;
	//Term();
}
int Matrix::get_data() {
	
	for (int i = start; i < finish; i++)
	{
		TermElement[i].coef = rand() % 10;
		//Sleep(1000);
		TermElement[i].exp = rand() % 10;
	}
	return 0;
}
int Matrix::show_data() {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(2) << TermElement[start + i * cols + j].coef << "x^" << TermElement[start + i * cols + j].exp;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
//int Matrix::sort_data() {
//	for (int i = 0; i < rows * cols; i++)
//	{
//		for (int j = 0; j < rows * cols; j++) {
//			if (data[start + i] < data[start + j])
//			{
//				int temp = data[start + j];
//				data[start + j] = data[start + i];
//				data[start + i] = temp;
//			}
//		}
//	}
//	return 0;
//}
int Matrix::addMatrix(Matrix& b) {

	for(int i=start;i<finish;i++)
	if(TermElement[start + i].exp == b.TermElement[b.start+i+1].exp)
	
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
	
	/*for (int i = start; i < finish; i++)
		data[start + i] += b.data[b.start + i];*/
	return 0;
}
//int Matrix::MultiplyMatrix(Matrix& b, Matrix& c) {
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			c.data[c.start + ] = data[start + j] + b.data[b.start + j * b.cols + ]
//		}
//	}
//}
int main(void)
{
	srand((unsigned int)time(NULL));
	Matrix matrixA(AROWS, ACOLS);
	Matrix matrixA1(AROWS, ACOLS);
	Matrix matrixB(BROWS, BCOLS);
	Matrix matrixC(CROWS, CCOLS);

	matrixA.get_data();//계수와 지수를 난수를 생성하여 입력, 지수는 같은 것이 없어야 한다.
	matrixA.show_data();
	matrixA1.get_data();
	matrixA1.show_data();
	matrixA.addMatrix(matrixA1);
	matrixA.show_data();
	//system("pause");
	return 0;
}

