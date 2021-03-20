//4장-4. POINTER_ARRAY2.cpp    4.3 pointer 변수와 reference 변수
#include <iostream>
using namespace std;
#define ROWS 2
#define COLS 3
int sum(int (&)[ROWS][COLS], int row);
int sum2(int (*t)[COLS], int row);
void main(void){
	int num[2][3] ={{1, 2, 3}, {4, 5, 6}};
	int total = 0;
	total = sum(num, ROWS);
	cout<<"sum()::totoal = "<<total<<endl;
	total = sum2(num, ROWS);
	cout<<"sum2()::totoal = "<<total<<endl;
	system("pause");
}
int sum(int (&t)[ROWS][COLS], int row)//how to pass 2D array as reference
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			//total += (*t)[j];//t를 pointer로 사용
			total += t[i][j];
		}
	}
	return total;
}
int sum2(int (*t)[COLS], int row)//how to pass 2D array as pointer
{
	int total = 0;
	for (int i = 0; i < row; i++)
	{
			for (int j = 0; j < COLS; j++)
			total += t[i][j];//t는 배열로 사용 가능
	}
	return total;
}