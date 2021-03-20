// musha256.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <ctime>
#include "sha256.h"

using namespace std;
//한 블록의 트랜잭션이라고 가정
//vector<string> tr = {
//    "sender:'aaa',receiver:111,amount:1,tid:101",
//    "sender:'bbb',receiver:222,amount:2,tid:102",
//    "sender:'ccc',receiver:333,amount:3,tid:103",
//    "sender:'ddd',receiver:444,amount:4,tid:104",
//    "sender:'eee',receiver:555,amount:5,tid:105",
//    "sender:'fff',receiver:666,amount:6,tid:106",
//    "sender:'ggg',receiver:777,amount:7,tid:107",
//    "sender:'hhh',receiver:888,amount:8,tid:108",
//    "sender:'iii',receiver:999,amount:9,tid:109",
//    "sender:'jjj',receiver:000,amount:0,tid:100"
//};
//머클트리 함수 생성
//vector 한 원소씩 들어가서 트리 생성
//
string my_Merkle(vector<string>& v) 
{
     //시행착오
     /*cv.push_back(sha256(v[0]));
    cv.push_back(sha256(v[1]));
    cv.push_back(sha256(v[2]));
    cv.push_back(sha256(v[3]));*/

    /* ccv.push_back(sha256(cv[0] + cv[1]));
     ccv.push_back(sha256(cv[2] + cv[3]));*/

     //cccv.push_back(sha256(ccv[0] + sha256(ccv[1])));

    vector<string> ccv;
    //vector<string> cccv;
    if (v.size() == 1)
    {
        return "result:"+v[0];
    }

    if (v.size() % 2 == 1)
    {
        v.push_back(v[v.size() - 1]);
    }

    //이것이 재귀로 돌아야 함
    for (int j = 0; j < v.size()/2; j++)
    {
        string o = sha256(v[j*2] + v[j*2 + 1]); //not v[j] + v[j+1] --> 겹침
        ccv.push_back(o);
        cout << o << endl;
    }

    return my_Merkle(ccv);//sha256(ccv[0] + ccv[1]);
}

//void mining_B(string b_Head)
//{
//    int nounce = 0;
//    string n_str;
//    clock_t start, end;
//    double taken_time;
//    start = clock();
//    while (1)
//    {
//        n_str = sha256(b_Head + to_string(nounce));
//        string result = sha256(n_str);//sha256(sha256(n_str)); -> hash를 두 번 하면 맞는 코드
//        if (result.substr(0, 4) == "0000")
//        {
//            //cout << "result:" << "          " << result;
//            end = clock();
//            printf("result:%10d:   %s\r", nounce, result.c_str());
//            taken_time = (double(end) - double(start)) / double(1000);
//            printf("\ntime taken : %f", taken_time);
//            break;
//        }
//        printf("result:%10d:   %s\r",nounce, result.c_str());
//        nounce++;
//    }
//}

void mining_B(string b_Head, int z)
{
    string zstr = "0";
    for (int i = 1; i < z; i++)
        zstr += "0";

    int nounce = 0;
    string n_str;
    clock_t start, end;
    double taken_time;
    start = clock();
    while (1)
    {
        n_str = sha256(sha256(b_Head + to_string(nounce)));
        //string result = sha256(n_str);//sha256(sha256(n_str));
        if (n_str.substr(0,z) == zstr)
        {
            //cout << "result:" << "          " << result;
            end = clock();
            printf("result:%10d:   %s\r", nounce, n_str.c_str());
            taken_time = (double(end) - double(start)) / double(1000);
            printf("\ntime taken : %f", taken_time);
            break;
        }
        printf("result:%10d:   %s\r", nounce, n_str.c_str());
        nounce++;
    }
}

//int main()
//{
//    //std::cout << sha256("Hello World!\n");
//    vector<string> cv;
//    for (int i = 0; i < tr.size(); i++)
//    {
//        cv.push_back(sha256(tr[i]));
//    }
//    string M_hash = my_Merkle(cv);
//    //cout << M_hash << endl;
//    string block_H = "bid100,prevH:000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f,time:2020.10.16.15.21,merkle:" + M_hash;
//    mining_B(block_H);
//}

int main(int argc, char* argv[])
{

    int zc = 0;
    if (argc == 2) zc = atoi(argv[1]);
    if (zc == 0) zc = 4;

    vector<string> tr = {
    "sender:'aaa',receiver:111,amount:1,tid:101",
    "sender:'bbb',receiver:222,amount:2,tid:102",
    "sender:'ccc',receiver:333,amount:3,tid:103",
    "sender:'ddd',receiver:444,amount:4,tid:104",
    "sender:'eee',receiver:555,amount:5,tid:105",
    "sender:'fff',receiver:666,amount:6,tid:106",
    "sender:'ggg',receiver:777,amount:7,tid:107",
    "sender:'hhh',receiver:888,amount:8,tid:108",
    "sender:'iii',receiver:999,amount:9,tid:109",
    "sender:'jjj',receiver:000,amount:0,tid:100"
    };

    //std::cout << sha256("Hello World!\n");
    vector<string> cv;
    for (int i = 0; i < tr.size(); i++)
    {
        cv.push_back(sha256(tr[i]));
    }
    string M_hash = my_Merkle(cv);
    //cout << M_hash << endl;
    string block_H = "bid100,prevH:000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f,time:2020.10.16.15.21,merkle:" + M_hash;
    mining_B(block_H, zc);
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
