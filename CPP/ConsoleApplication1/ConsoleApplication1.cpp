// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <process.h>        // _beginthreadex/_endthreadex
#include <Windows.h>

// Thread Function
unsigned __stdcall ThreadFunc1(void* data)
{
    int s = (int)data;
    for (int i = 1; i <= 9; i++)
    {
        Sleep(1000);
        printf("%d * %d = %d\n", s, i, s*i);

//        printf("%d * %d = %d\n", idx, i, idx * i);
    }
    return 0;
}

int main()
{
    for (int i = 2; i <= 9; i++)
    {
        _beginthreadex(NULL, 0, &ThreadFunc1, (void*)i, 0, NULL);
        Sleep(1);
    }

    //for (int i = 0; i < 10000; i++)
    //{
    //    printf("Main\n");
    //    Sleep(100);
    //}
    Sleep(100000);
}


//int main()
//{
//    for (int i = 2; i <= 9; i++)
//    {
//        for (int j = 1; j <= 9; j++)
//        {
//            printf("%d * %d = %d\n", i, j, i * j);
//            Sleep(1000);
//        }
//    }
//}
