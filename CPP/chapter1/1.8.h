// "1.8.h"
/* 
2차원 배열을 main()에서 정의
입력은 난수를 사용하여 입력
sorting한 후에 출력하는 프로그램 작성
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
