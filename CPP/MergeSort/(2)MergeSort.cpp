#include <iostream>
using namespace std;

#define vsize 10
int src[] = { 1,9,8,5,4,2,3,7,6,0 };
int tmp[vsize];

//int type 변수 start:배열의 시작되는 배열의 순서값을 넣어준다.
//int type 변수 end:배열의 끝나는 배열의 순서값을 넣어준다.
void MergeSort(int start, int end) 
{
	if (start < end)									  //start 변수값이 end 변수값 보다 작을때만 함수진입이 가능, 재귀함수 제어역할 
	{
		int mid = (start + end) / 2;					  //start 변수와 end 변수를 더한 중간값을 int type 변수 mid에 대입한다.
		MergeSort(start, mid);							  //재귀호출, start 변수에 start값을 end 변수에 mid값을 대입 재귀호출
		MergeSort(mid+1, end);							  //재귀호출, start 변수에 mid+1값을 end 변수에 end값을 대입 재귀호출
														  //재귀를 활용하여 배열을 Split 한다.
		int p = start;									  //int type 변수 p를 선언하고 start 변수값을 대입하여 정의
		int q = mid + 1;
		int idx = p;

		while (p <= mid || q <= end) 
		{
			if (q > end || (p <= mid && src[p] < src[q]))
			{
				tmp[idx++] = src[p++];
			}
			else
			{
				tmp[idx++] = src[q++];
			}
		}

		for (int i = start; i <= end; i++)
		{
			src[i] = tmp[i];
		}
	}
}


void main() 
{
	cout << "num :";
	for (int i = 0; i < vsize; i++)	cout << src[i] << " ";
	cout << endl;
	MergeSort(0, vsize - 1);
	cout << "num :";
	for (int i = 0; i < vsize; i++)	cout << src[i] << " ";
}