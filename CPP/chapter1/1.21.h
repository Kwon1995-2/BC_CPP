#pragma once
//½Ç½À5
//program 1.21: program 1.18 with count statements added


int count0 = 0;

float Rsum(float *a, const int n)
{
	count0++;
	if (n <= 0)
	{
		count0++;
		return 0;
	}
	else
	{
		count0++;
		return (Rsum(a, n - 1) + a[n - 1]);
	}
}