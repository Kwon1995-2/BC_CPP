// MergeSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void merge_sort(int a[], int n);

void merge_sort(int a[], int n)
{
    int i, j, k, first, second, size;
    int* b;                                     //배열 a와 같은 사이즈의 메모리 공간을 할당받고 그 공간을 가리키는 변수 포인터 b
    b = (int*)malloc(sizeof(int) * n);          //배열을 담을 공간을 melloc function으로 할당
    for (size = 1; size < n; size *= 2)         //for 문을 돌면서 배열의 비교숫자를 단계적으로 확장 1st:size=1, 2st:size=2, 3st:size=4...
    {
        first = -2 * size;                      //비교 rouf를 돌기위한 시작점 사이즈 계산
        second = first + size;                

        while (second + size * 2 < n)           //비교 rouf를 돌기위한 while 조건문 조건: 배열의 전체크기 n을 벗어나지 않는 범위내에서 rouf
        {
            first = second + size;              // int type 변수 first 정의, 이전 (-2*size=)first+size+size=0가 되어 결론적으로 항상 first 변수는 0으로 시작
            second = first + size;              // int type 변수 second 정의, 0+size=second가 되므로 second 변수는 size 만큼 배열 앞으로 이동한다.
            i = first;                          // int type 변수 i 정의, 분할된 배열의 왼쪽(Left)을 제어하기 위한 변수
            j = second;                         // int type 변수 j 정의, 분할된 배열의 오른쪽(Right)을 제어하기 위한 변수
            k = first;                          // int type 변수 k 정의, 메모리 영역을 할당해준 동일 사이즈의 메모리의 배열b의 k번째에 Sort된 값을 가리킬때 사용
            while (i < first + size || (j < second + size && j < n)) //while문 조건 1.왼쪽 i값이 size 값을 넘어나지 않거나 or 2.오른쪽 j값이 2*size 값을 벗어나지 않으면서 and 배열의 전체크기 n값을 넘어나지 않는다.
            {
                if (a[i] <= a[j])                                    //if문 조건 배열 a의 j번째 값(a[j])이 배열 a의 i번째 값(a[i]) 보다 크다면 
                {
                    if (i < first + size)    b[k++] = a[i++];        //if문 i값이 0+size값보다 작으면 배열 b의 k번째 값(b[k])에 배열 a의 i번째 값(a[i])에 대입
                    else                                             //else문 아니면 배열 b의 k번째 값(b[k])에 배열 a의 j번째 값(a[j])에 대입
                    {
                        b[k++] = a[j++];
                    }
                }
                else                                                 //else문 조건 배열 a의 j번째 값(a[j])이 배열 a의 i번째 값(a[i]) 보다 크지 않으면
                {
                    if (j < second + size && j < n)  b[k++] = a[j++];//if문 j값이 2*size값보다 작으면 배열 b의 k번째 값(b[k])에 배열 a의 j번째 값(a[j])에 대입
                    else
                    {
                        b[k++] = a[i++];                             //eles문 아니면 배열 b의 k번째 값(b[k])에 배열 a의 j번째 값(a[j])에 대입
                    }
                }
            }
        }
        for (i = 0; i < n; i++)    a[i] = b[i];                      //b배열에 있던 값들을 a배열에 복사
    }
    free(b);                                                         //int point type 변수 b에 malloc함수로 할당했던 메모리 해제
}
int main()
{
    //배열 num       Left<-->Right
    int num[] = { 1,7,5,9,3,6,8,2,0,4 };
    cout << "num :";
    for (int j = 0; j < 10; j++)
    {
        cout << num[j] << " ";
    }
    cout << endl;
    merge_sort(num, 10);
    cout << "num :";
    for (int i = 0; i < 10; i++)
    {
        cout << num[i] << " ";
    }
    
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
