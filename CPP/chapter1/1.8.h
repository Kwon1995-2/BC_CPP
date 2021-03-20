// "1.8.h"
/* 
2���� �迭�� main()���� ����
�Է��� ������ ����Ͽ� �Է�
sorting�� �Ŀ� ����ϴ� ���α׷� �ۼ�
*/

void SelectionSort(int *a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i;
		for (int k = i + 1; k < n; k++)
			if (a[k] < a[j])	j = k;
		swap(a[i], a[j]);
	}
}
void swap(int& left, int& right) {
	int temp = left;
	left = right;
	right = temp;
}
