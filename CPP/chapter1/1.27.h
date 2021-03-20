#pragma once
#include <iostream>
using namespace std;

int SequentialSearch(int *a, const int n, const int x)
{
	int i;
	for (i = 0; i < n && a[i] != x; i++);
	if (i == n) return -1;
	else return i;
}
