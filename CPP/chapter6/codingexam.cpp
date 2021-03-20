
#include <iostream>

using namespace std;

#include <stdlib.h>

// implement the functions : add, sub, mult, transpose

class Matrix {

public:

	Matrix(int row, int col);

	int GetData();

	Matrix Transpose();

	int Display();

	Matrix & operator + (const Matrix &);//add matrix to matrix
	Matrix & operator * (const Matrix &);//multiply matrix y matrix
	friend istream& operator >> (istream& s, Matrix &);
	friend ostream& operator << (ostream& s, Matrix &);
	int CompareRowCol(Matrix b);

private:
	int rows, cols;
	//Do not use "int Term[rows][cols];"

	int *Term;
};
Matrix::Matrix(int row, int col) : rows(row), cols(col)

{

	Term = new int[rows * cols];

}

istream& operator >> (istream& s, Matrix & m) {

	int input_value;

	cout << "rows = " << rows << "  cols = " << cols << endl;

	for (int j = 0; j < rows * cols; j++)

	{

		cout << "term value = ";

		cin >> input_value;

		cout << " " << endl;

		Term[j] = input_value;

	}

}


/*
Matrix Matrix::Transpose() {

	Matrix b(cols, rows);

	//...

	// to be implemented

	return b;

}
*/
Matrix & Matrix::operator + (const Matrix &n) {//add matrix to matrix
	//
}

Matrix & Matrix::operator *(const Matrix &b) {

	if (cols != b.rows) cout << "Incompatible matrices" << endl;

	Matrix d(rows, b.cols);

	//  to be implemented

	return d;

}
/*
Matrix Matrix::Multiply2(Matrix b) {

	if (cols != b.rows) cout << "Incompatible matrices" << endl;

	Matrix bXpose = b.Transpose();

	Matrix d(rows, b.cols);

	//  to be implemented

	return d;

}
*/
int Matrix::CompareRowCol(Matrix b) {

	if (cols != b.rows) return 1;

	else return 0;

}
ostream& operator << (ostream& s, Matrix &b){}

	int n;

	n = rows * cols;

//

	cout << endl;

	return 0;

}





int main()

{
	Matrix a(3, 4);
	Matrix b(4, 5);
	Matrix c(3, 5);

	cin >> a >> b;//2차원 행렬 형태/바둑판 배열로 출력, rows=**, cols=**을 출력하여 행렬을 구분

	if (!a.CompareRowCol(b))

	{
		Matrix d = a * b;//copy constructor 호출
		cout << a << b << d;
	} // destructor 호출
	c = a * b;//assignment 호출
	cout << c;
	system("pause");
	return 0;

}

