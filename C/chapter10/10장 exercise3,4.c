#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
//int sum(int ar[], int n);

int largest(int ar[], int n);
int largest_idx(int* start, int* end);

int main(void)
{
	int marbles[SIZE] = { 20,10,5,39,4,16,19,26,31,20 };
	long answer;
	int answer2;
	answer = largest(marbles, SIZE);
	answer2 = largest_idx(marbles, marbles + 9);
	printf("The largest number of marbles is %d.\n", answer);
	printf("The largest number_idx of marbles is %d.\n", answer2);
	////answer = sum(marbles, SIZE);
	//printf("The total number of marbles is %ld.\n", answer);
	//printf("The size of marbles is %zd bytes.\n", sizeof marbles);

	return 0;
}

int largest(int ar[], int n)
{
	int max=0;
		for (int i = 0; i < n; i++)
		{
			if (ar[i] > max)
			{
				//ar[i] = ar[i-1];
				max = ar[i];
			}

		}
	
	return max;
}

int largest_idx(int* start, int* end)
{
	int max = 0;
	//int max_idx = SIZE - 1;
	int max_idx = 0;
	int i = 0;
	while (start < end)
	{
		if (*start > max)
		{
			max = *start;
			max_idx = i;
		}
		start++;
		i++;
		
	}
	return max_idx;
	
	/*while (*start != max)
	{
		max_idx--;
		start--;

	}

	return max_idx;*/
}

//int sum(int ar[], int n)
//{
//	int i;
//	int total = 0;
//
//	for (i = 0; i < n; i++)
//		total += ar[i];
//	printf("The size of ar is %zd bytes.\n", sizeof ar);
//
//	return total;
//}