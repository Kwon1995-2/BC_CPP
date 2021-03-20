#ifndef _MYHASH_H_
#define _MYHASH_H_

#include <string>

using namespace std;

// 버켓에 삽입될 노드 클래스
class NODE
{
public:
    NODE(int _key, string _name, int _ymd) : key(_key), name(_name), ymd(_ymd), next(NULL) {}

    int key;        // key
    string name;    // 홍길동
    int ymd;        // 생년월일
    NODE* next;
};

// 해시 클래스
class MyHash
{
    NODE** bucketArray; // 버켓 배열
    int bucketSize;     // 버켓 사이즈
public:
    MyHash(int N = 10); // 생성자 (디폴트 버켓 사이즈는 10으로 설정)
    ~MyHash();

    NODE* searchNode(const int _key);
    bool insertNode(const int _key, const string _name, const int ymd);
    void deleteNode(const int _key);
    void deleteAll();
    void displayNodes();

private:
    int hash_func(const int key);   // 해시 함수
    double polynomial(char* b, int n, int idx, double a);   // 다항식 해시코드생성함수
};

#endif