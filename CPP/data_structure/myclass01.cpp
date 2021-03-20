#include<iostream>
#include"myclass01.h"
#include<time.h>
#include<iomanip>
using namespace std;

myclass01 :: myclass01() {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			table[i][j] = rand() % 51+50;
		}
	}
	pMatrix = NULL;
}

myclass01::~myclass01() {
	for (int i = 0; i < rows; i++)
	{
		free(pMatrix[i]);
	}
	free(pMatrix);
}

myclass01::myclass01(int row, int col) {
	rows = row; cols = col;
	pMatrix = new int*[row];
	for (int i = 0; i < row; i++)
	{
		pMatrix[i] = new int[col];  //제대로 할당된 것이지만 쓰레기값 들어있었음
		for (int j = 0; j < col; j++)
		{
			pMatrix[i][j] = rand() % 51;
		}
	}
}

void myclass01::free_Matrix() {
	for (int j = 0; j < cols; j++)
	{
		delete(pMatrix[j]);
	}
	delete(pMatrix);
}

void myclass01 :: setMatrix(int row, int col)
{
	rows = row; cols = col;
	pMatrix = (int**)malloc(sizeof(int*) * rows);
	for (int i = 0; i < row; i++)
	{
		pMatrix[i] = (int*)malloc(sizeof(int) * col);
		for (int j = 0; j < col; j++)
		{
			pMatrix[i][j] = rand() % 51;
		}
	}
	
	/*for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			pMatrix[i][j] = rand() % 51;
		}
	}*/
}
void myclass01::displayTable()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout <<setw(3) <<table[i][j];
		}
		cout << endl;
	}
}
void myclass01::diplayMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout <<setw(3)<< pMatrix[i][j];
		}
		cout << endl;
	}
}

