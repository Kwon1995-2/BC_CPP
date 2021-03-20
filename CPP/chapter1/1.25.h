#pragma once
//program 1.25: Fibonacci numbers
#include <iostream>
using namespace std;

void Fibonacci(int n)
{
	if (n <= 1) cout << n << endl;
	else
	{
		int fn;
		int fnm2 = 0;
		int fnm1 = 1;
		for (int i = 2; i <= n; i++)
		{
			fn = fnm1 + fnm2;
			fnm2 = fnm1;
			fnm1 = fn;
		}
		cout << fn << endl;
	}
}
