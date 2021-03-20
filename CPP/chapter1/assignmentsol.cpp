#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>

#define N 4

using namespace std;

int get_data(int(*p)[N], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p[i][j] = rand() % (N * N);
    return 1;
}

void show_data(int(*p)[N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3d ", p[i][j]);
        printf("\n");
    }
}
void SelectionSort(int* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int k = i + 1; k < n; k++)
            if (a[k] < a[j]) j = k;
        swap(a[i], a[j]);
    }
}
void swap(int& left, int& right) {
    int temp = left;
    left = right;
    right = temp;
}

int sort(int(*p)[N], int n)
{
    int one[N * N];
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            one[r * N + c] = p[r][c];
    SelectionSort(one, n * n);
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            p[r][c] = one[r * N + c];

    return 1;
}
/*
int sort(int(*p)[N], int n)
{
 int mode = 0;
 int k;
 for (int r = 0; r < n; r++)
  for (int c = 0; c < n; c++)
  {
   for (int i = r; i < n; i++)
   {
    if (!mode)
     k = c + 1;
    else k = 0;
    //cout << "START::k = " << k << "   mode = " << mode << endl;
    if (k == n) {
     k = 0; mode = 1;
     //cout << "*********************i = " << i << "   k = " << k << endl;
     continue;
    }
    for (int j = k; j < n; j++)
    {
     //cout << "r = " << r << "c == " << c << "i = " << i << "j = " << j << endl;
     if (p[r][c] > p[i][j])
     {
      int temp = p[r][c];
      p[r][c] = p[i][j];
      p[i][j] = temp;
     }
    }
    mode = 1;
   }
   mode = 0;
  }

 return 1;
}
*/

int sequentialSearch(int element[][N], int key)
{
    int Temp[N * N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Temp[i * N + j] = element[i][j];
        }
    }

    for (int i=0; i < N * N; i++)
    {
        if (Temp[i] == key)
            return Temp[i];
    }
    return -1;
}

int main(void)
{
    int element[N][N];
    get_data(element, N);
    show_data(element, N);
    printf("\n\n");
    sort(element, N);
    show_data(element, N);

    int key = 0;
    printf("Enter the key :");
    scanf("%d", &key); // "&" 잊지말자
    while (1)
    {
        int num = sequentialSearch(element, key);
        if (num == -1)
        {
            scanf("%d", &key);
        }
        else if (num == key) // ";" 여기엔 쓰지말자
        {
            printf("find the key!");
            break;
        } 
    }

    //system("pause");
    return 0;
}