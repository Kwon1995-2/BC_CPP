#include<stdio.h>
#include<time.h>

#define N 5

int get_data(int element[][N], int a);  //�Լ� ������Ÿ��
int show_data(int element[][N], int a); //�Լ� ������Ÿ��
void SelectionSort(int element[][N], int n);
void SelectionSort2(int element[][N], int n);
//void swap(int& left, int& right);
int BinarySearch(int element[][N], const int x, const int n);
int BinarySearch2(int element[][N], const int x, const int n);

int main(void)
{
	int element[N][N];
	int k = 0;
	srand((unsigned int)time(NULL));
	get_data(element, N);
	show_data(element, N);
	
	printf("Sorting data : \n");

	/*SelectionSort(element, N);
	show_data(element, N);*/
	SelectionSort(element, N);
	show_data(element, N);
	printf("Enter the key number: ");
	scanf("%d", &k);
	while (1)
	{
		int num;
		num = BinarySearch(element, k, N);
		switch (num)
		{
		case -1:
			scanf("%d", &k);
			break;
		}
		if(num == k)
		{
				printf("find key!");
				break;
		}
		
	}
	return 0;

}

int get_data(int element[][N], int a)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
			element[i][j] = rand() % 30;
	}
	return 0;
}
int show_data(int element[][N], int a)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
			printf("%4d", element[i][j]);
		printf("\n");
	}
	

	return 0;
}
void SelectionSort(int element[][N], int n)
{
	int Temp[N * N];  //2������ 1�������� �ٲ� �ٸ� ��� �˾ƺ���

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Temp[i * n + j] = element[i][j];
		}
	}

	for (int i = 0; i < n * n; i++)
	{
		int j = i;
		for (int k = i + 1; k < n * n; k++)
			if (Temp[k] < Temp[j]) {
				j = k;
			}
		int temp = Temp[i];
		Temp[i] = Temp[j];
		Temp[j] = temp;
	}
	/*for (int i = 0; i < n * n; i++)
		printf("%d ", Temp[i]);*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			element[i][j] = Temp[i * n + j];
	}
}

//void SelectionSort2(int element[][N], int n)
//{
//	
//	//int temp = 0;
//	for (int c = 0; c < n; c++)
//	{
//		for (int r = 0; r < n; r++)
//		{
//			for (int i = 0/*r*/; i < n; i++)
//			{
//				for (int j = 0 /*c+1*/; j < n; j++)
//				{
//					if (element[c][r] < element[i][j])
//					{
//						int temp = element[i][j];
//						element[i][j] = element[c][r];
//						element[c][r] = temp;
//					}
//				}
//				
//			}
//		}
//	}
//
//}

int BinarySearch(int element[][N], const int x, const int n)
{

	int Temp[N * N] = {0};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Temp[i * n + j] = element[i][j];
		}
	}
	int left = 0, right = n*n - 1;
	while (left <= right)  //���ʰ� �������� ������ �� while loop ��������
	{
		int middle = (left + right) / 2;
		if (x < Temp[middle]) right = middle - 1;
		else if (x > Temp[middle]) left = middle + 1;
		else return Temp[middle]; //middle�� ��ȯ�� Temp[middle]�� ��ȯ
	}
	return -1;
}

int BinarySearch2(int element[][N], const int x, const int n) 
{ // 2���� �״�� ó���ϴ� ��� �˾ƺ���


	int left = 0, right = n*n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < element[middle]) right = middle - 1;
		else if (x > element[middle]) left = middle + 1;
		else return middle;
	}
	return -1;
}