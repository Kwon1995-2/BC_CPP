#pragma once

#include <iostream>
using namespace std;


void Add(int **a, int **b, int **c, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = a[i][j] + b[i][j];
}
