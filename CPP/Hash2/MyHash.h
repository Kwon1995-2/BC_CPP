#ifndef _MYHASH_H_
#define _MYHASH_H_

#include <string>

using namespace std;

// ���Ͽ� ���Ե� ��� Ŭ����
class NODE
{
public:
    NODE(int _key, string _name, int _ymd) : key(_key), name(_name), ymd(_ymd), next(NULL) {}

    int key;        // key
    string name;    // ȫ�浿
    int ymd;        // �������
    NODE* next;
};

// �ؽ� Ŭ����
class MyHash
{
    NODE** bucketArray; // ���� �迭
    int bucketSize;     // ���� ������
public:
    MyHash(int N = 10); // ������ (����Ʈ ���� ������� 10���� ����)
    ~MyHash();

    NODE* searchNode(const int _key);
    bool insertNode(const int _key, const string _name, const int ymd);
    void deleteNode(const int _key);
    void deleteAll();
    void displayNodes();

private:
    int hash_func(const int key);   // �ؽ� �Լ�
    double polynomial(char* b, int n, int idx, double a);   // ���׽� �ؽ��ڵ�����Լ�
};

#endif