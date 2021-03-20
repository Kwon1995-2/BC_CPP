#pragma once
//Program 1.32: example program
void D(int *x, int n)
{
	int i = 1;
	do {
		x[i] += 2;
		i += 2;
	} while (i <= n);
	i = 1;
	while (i <= (n / 2))
	{
		x[i] += x[i + 1];
		i++;
	}
}
