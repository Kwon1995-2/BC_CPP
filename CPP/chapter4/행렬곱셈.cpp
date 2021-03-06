#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <iomanip>
using namespace std;
// implement the functions : add, sub, mult, transpose
#define ROWS 2//1
#define COLS 3//2
#define COLX 4//3
#define N 5
class Matrix {
public:
    Matrix() {}; //default constructor
   // Matrix(int n, int m) { rows = n; cols = m;}
    //Matrix(int row, int col);
    int GetData();
   // Matrix Transpose();
    int Display();
    Matrix& Add(Matrix& b); // ?Լ?????
  /*  Matrix& Sub(Matrix& b);
    Matrix Multiply(Matrix b);
    int CompareRowCol(Matrix b);
    int CompareRowRow(Matrix b);
    int CompareColCol(Matrix b);*/
private:
   int rows, cols;
    //Do not use "int Term[rows][cols];"
    //int* Term;
    int Term[N][N];
};
//Matrix::Matrix(int row, int col) : rows(row), cols(col)
//{
//    Term = new int[rows * cols];
//}
int Matrix::GetData() {
    //int input_value;
   // cout << "rows = " << rows << "  cols = " << cols << endl;
   
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Term[i][j] = rand() % 8;
        }
    }
   


   /* for (int j = 0; j < rows * cols; j++)
    {
        cout << "term value = ";
        cin >> input_value;
        cout << " " << endl;
        Term[j] = input_value;
    }*/
    return 0;
}
//Matrix Matrix::Transpose() {
//    Matrix b(cols, rows);
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            b.Term[j * rows + i] = Term[i * cols + j];
//        }
//    }
//    //...
//    // to be implemented
//    return b;
//}
//Matrix Matrix::Multiply(Matrix b) {
//    Matrix d(rows, b.cols);
//    if (cols != b.rows)
//    {
//        cout << "Incompatible matrices" << endl;
//        for (int i = 0; i < rows * b.cols; i++)
//            d.Term[i] = 0;
//        return d;
//    }
//    else {
//        for (int i = 0; i < rows; i++)
//        {
//            for (int j = 0; j < b.cols; j++)
//            {
//                d.Term[i * b.cols + j] = 0;
//                for (int k = 0; k < b.rows; k++)
//                {
//                    d.Term[i * b.cols + j] += Term[i * rows + k] * b.Term[k * b.cols + j];
//                }
//            }
//        }
//        return d;
//    }
//}
Matrix& Matrix::Add(Matrix& b) {

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Term[i][j] += b.Term[i][j];
        }
        cout << endl;
    }
    return (*this);
    //return b;
    /*if (cols != b.cols || rows != b.rows)
    {
        cout << "Incompatible matrices" << endl;
        for (int i = 0; i < rows * b.cols; i++)
            b.Term[i] = 0;
        return b;
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                b.Term[i * cols + j] = Term[i * cols + j] + b.Term[i * cols + j];
            }
        }
        return b;
    }*/
}
//Matrix& Matrix::Sub(Matrix& b) {
//    if (cols != b.cols || rows != b.rows)
//    {
//        cout << "Incompatible matrices" << endl;
//        for (int i = 0; i < rows * b.cols; i++)
//            b.Term[i] = 0;
//        return b;
//    }
//    else
//    {
//        for (int i = 0; i < rows; i++)
//        {
//            for (int j = 0; j < cols; j++)
//            {
//                b.Term[i * cols + j] = Term[i * cols + j] - b.Term[i * cols + j];
//            }
//        }
//        return b;
//    }
//}
//int Matrix::CompareRowCol(Matrix b) {
//    if (cols != b.rows) return 1;
//    else return 0;
//}
//int Matrix::CompareColCol(Matrix b) {
//    if (cols != b.cols) return 1;
//    else return 0;
//}
//int Matrix::CompareRowRow(Matrix b) {
//    if (rows != b.rows) return 1;
//    else return 0;
//}
int Matrix::Display() {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout <<setw(2)<<Term[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
   /* int n;
    n = rows * cols;
    for (int i = 0; i < rows; i++)
    {
        cout << endl;
        for (int j = 0; j < cols; j++)
            cout << Term[i * cols + j] << " ";
    }
    cout << endl;
    return 0;*/
}
int main()
{
   /* Matrix a(ROWS, COLS);
    Matrix b(COLS, COLX);
    Matrix c(ROWS, COLX);
    Matrix s(ROWS, COLS);
    Matrix t(ROWS, COLS);
    Matrix w(ROWS, COLS);*/
    
    Matrix a;
    Matrix b;
    Matrix c;
    Matrix s;
    Matrix t;
    Matrix w;
    srand((unsigned int)time(NULL));
    cout << "Enter first matrix: " << endl;
    a.GetData();
    a.Display();
    cout << "Enter S matrix: " << endl;
    s.GetData();
    s.Display();
    cout << "Enter T matrix: " << endl;
    t.GetData();
    t.Display();
    w = a.Add(s.Add(t));
    w.Display();
    //if (s.CompareRowRow(t) || s.CompareColCol(t))
    //{
    //    cout << "Error! columns and rows of first matrix is not equal to the columns and rows of the second.";
    //    cout << "Enter rows and columns for first matrix: ";
    //}
    //else
    //{
    //    w = a.Add(s.Add(t));
    //    w.Display();
    //}
    //if (a.CompareRowRow(s) || a.CompareColCol(s))
    //{
    //    cout << "Error! columns and rows of first matrix is not equal to the columns and rows of the second.";
    //    cout << "Enter rows and columns for first matrix: ";
    //}
    //else
    //{
    //    a = a.Add(s);
    //    cout << "Display first matrix: " << endl;
    //    a.Display();
    //}
    //cout << "Enter second matrix: " << endl;
    //b.GetData();
    //cout << "Display second matrix: " << endl;
    //b.Display();
    //Matrix d(COLS, ROWS);
    //d = b.Transpose();
    //cout << "Transpose() of Matrix b" << endl;
    //d.Display();
    //if (a.CompareRowCol(b))
    //{
    //    cout << "Error! column of first matrix not equal to row of second.";
    //    cout << "Enter rows and columns for first matrix: ";
    //}
    //else {
    //    c = a.Multiply(b);//not using transpose()
    //    //c = a.Add(b);
    //    cout << "Multiply of Matrix a,b" << endl;
    //    c.Display();
    //}
    //d = b.Transpose();
    //if (a.CompareRowCol(d))
    //{
    //    cout << "Error! column of first matrix not equal to row of second.";
    //    cout << "Enter rows and columns for first matrix: ";
    //}
    //else
    //{
    //    cout << "using transpose()" << endl;
    //    Matrix e(ROWS, COLS);
    //    e = a.Multiply(d);//using transpose()
    //    e.Display();
    //}
    system("pause");
    return 0;
}