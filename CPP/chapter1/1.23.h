#pragma once

//program 1.23: matrix addition with counting statements
//실습6
//화면에서 행렬 a[], b[]의 row, col을 화면에서 입력받는다. 
//행렬 값은 자동으로 초기화, 출력으로 row, col, count 값을 출력한다.
#include <iostream>
using namespace std;

int count0 = 0;
void Add(int **a, int **b, int **c, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		count0++;
		for (int j = 0; j < n; j++)
		{
			count0++;
			c[i][j] = a[i][j] + b[i][j];
			count0++;
		}
		count0++;
	}
	count0++;
}
