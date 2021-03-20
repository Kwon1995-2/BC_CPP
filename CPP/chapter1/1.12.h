#pragma once

//실습4
//program 1.12, recursive permutation generator
// 배열 원소를 3, 4, 5개 등으로 증가시켜서 실행 실습
#include <iostream>
#include "swap.h"
using namespace std;

void Permutations(char *a, const int k, const int m)
{
	if (k == m - 1)
	{
		for (int i = 0; i <= m; i++) cout << a[i] << "";
		cout << endl;
	}
	else
		for (int i = k; i < m; i++)
		{
			swap(a[k], a[i]);
			Permutations(a, k + 1, m);
			swap(a[k], a[i]);
		}

}
