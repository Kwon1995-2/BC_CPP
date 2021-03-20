#pragma once
//Program 1.34: square matrix multi C = A x B
// called by multiple_test.cpp
void Multiply(int **a, int **b, int **c, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
}
