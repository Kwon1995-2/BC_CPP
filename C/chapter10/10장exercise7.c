#include<stdio.h>
#include<stdlib.h>

#define ROWS 3
#define COLS 4
#define SIZE 5

int copy_arr(double tgt[], double src[], int n); //copy_arr prototype
int copy_2D_arr(double junk2[][COLS], double junk[][COLS], int n);

int main(void)
{
	int i, j;
	double source[SIZE] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[SIZE];
	double junk[ROWS][COLS] = { {2.1, 4.1, 6.1, 8.1},{3.2, 5.2, 7.2, 9.2} , 
		{12.3, 10.3, 8.3, 6.3}};
	double junk2[ROWS][COLS];


	copy_arr(target1, source, SIZE);
	printf("Target Array: ");
	for (i = 0; i < SIZE; i++)
	{
		printf("%.1f ", target1[i]);
	}
	printf("\n");

	//copy_2D_arr
	copy_2D_arr(junk2, junk, COLS);
	printf("Target Array: \n");
	for (i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%4.1f ", junk2[i][j]);
		}
		printf("\n");
	}
	

	return 0;

}

int copy_arr(double tgt[], double src[], int n)
{
	for (int i = 0; i < n; i++)
	{
		tgt[i] = src[i];
	}
	return 0;
}

int copy_2D_arr(double junk2[][COLS], double junk[][COLS], int n)
{
	for (int i = 0; i < ROWS; i++)
		copy_arr(junk2[i], junk[i], COLS);

	return 0;
}