// ProtocolConsole.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ctime>
#include <windows.h>

// id 같은 것 처리
// block 처음 : (count+~), 이후 : (id+~)

int main()
{
    srand((unsigned int)time(NULL));
    int count = rand() % 5 + 1;

    short id;
    int day;
    int tm;
    short temperature;
    short hum;
    short press;

    int cnt = 0;
    int totalloop = 10;
    int* v = (int*)malloc(sizeof(int) * count* totalloop + 4);
   
    while (cnt < totalloop) {
        if (cnt == 0) v[0] = 0;
        for (int i = 0; i < count; i++)
        {
            id = rand() % 101 + 100;
            for (int j = 0; j < i + cnt*count; j++)
            {
                while(v[j] == id) id = rand() % 101 + 100; //same id 처리하기 --> 틀린 닶
            }
            day = 20200925;
            tm = 1438;
            temperature = rand() % 16 + 20;
            hum = rand() % 101;
            press = rand() % 601 + 600;
            v[i + 1 + (cnt*count)] = id;
            if (cnt == 0 && i == 0) printf("%d : %d.%d.%d.%d.%d.%d\n", count, id, day, tm, temperature, hum, press);
            else printf("%d.%d.%d.%d.%d.%d\n", id, day, tm, temperature, hum, press);
            
            
        }
        Sleep(1000);
        cnt++;
    }
    free(v);
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
