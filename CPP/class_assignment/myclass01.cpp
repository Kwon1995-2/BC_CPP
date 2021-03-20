#include <iostream>
#include <time.h>
#include "myclass01.h"

using namespace std;

// (2, 3)
//
// (0,0) (0,1) (0,2)
// (1,0) (1,1) (1,2)
//
myclass01::myclass01()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			table[i][j] = rand() % 51 + 50;
		}
	}

	pMatrix = NULL;
	row = col = 0;
}
myclass01::~myclass01()
{
	deleteMatrix();
}

void myclass01::deleteMatrix()
{
	if (!pMatrix)	return;

	for (int i = 0; i < row; i++)
	{
		free(pMatrix[i]);
	}
	free(pMatrix);
}

void myclass01::setMatrix(int _row, int _col)
{
	deleteMatrix();
	row = _row;
	col = _col;

	pMatrix = (int**)malloc(sizeof(int*) * row);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < row; i++)
	{
		pMatrix[i] = (int*)malloc(sizeof(int) * col);

		for (int j = 0; j < col; j++)
		{
			pMatrix[i][j] = rand() % 51;
		}
	}
}
void myclass01::displayTable()
{
	cout << "displayTable()" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout.width(4);
			cout << table[i][j];
		}
		cout << endl;
	}
}
void myclass01::displayMatrix()
{
	cout << "displayMatrix()" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout.width(4);
			cout << pMatrix[i][j];
		}
		cout << endl;
	}
}
