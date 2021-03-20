#include<stdio.h>
#include<stdlib.h>

#define ROWS 3
#define COLS 4
#define SIZE 5

int copy_arr(double tgt[],double src[],int n); //copy_arr prototype

int main(void)
{
	int i, j;
	double source[SIZE] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[SIZE];



	copy_arr(target1, source, SIZE);
	printf("Target Array: ");
	for (i = 0; i < SIZE; i++)
	{
		printf("%.1f ", target1[i]);
	}
	printf("\n");
	return 0;
	
}

int copy_arr(double tgt[], double src[], int n)
{
	for (int i = 0; i < n; i++)
	{
		tgt[i] = src[i];
	}
	return tgt;
}