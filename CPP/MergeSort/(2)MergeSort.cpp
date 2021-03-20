#include <iostream>
using namespace std;

#define vsize 10
int src[] = { 1,9,8,5,4,2,3,7,6,0 };
int tmp[vsize];

//int type ���� start:�迭�� ���۵Ǵ� �迭�� �������� �־��ش�.
//int type ���� end:�迭�� ������ �迭�� �������� �־��ش�.
void MergeSort(int start, int end) 
{
	if (start < end)									  //start �������� end ������ ���� �������� �Լ������� ����, ����Լ� ����� 
	{
		int mid = (start + end) / 2;					  //start ������ end ������ ���� �߰����� int type ���� mid�� �����Ѵ�.
		MergeSort(start, mid);							  //���ȣ��, start ������ start���� end ������ mid���� ���� ���ȣ��
		MergeSort(mid+1, end);							  //���ȣ��, start ������ mid+1���� end ������ end���� ���� ���ȣ��
														  //��͸� Ȱ���Ͽ� �迭�� Split �Ѵ�.
		int p = start;									  //int type ���� p�� �����ϰ� start �������� �����Ͽ� ����
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