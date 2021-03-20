#include <iostream>
#include "MyHash.h"

using namespace std;

int main()
{
	MyHash h(10);

	h.insertNode(11, "ȫ�ϵ�", 20000101);
	h.insertNode(21, "ȫ�̵�", 20000101);
	h.insertNode(31, "ȫ�ﵿ", 20000101);
	h.insertNode(2, "�ֹ��", 20000201);
	h.insertNode(3, "��ö��", 20000202);
	h.insertNode(4, "�̿���", 20000203);
	h.displayNodes();

	int key = 31;
	NODE* t = h.searchNode(key);
	cout << "searchNode(" << key << ")" << "\t[" << t->key << "," << t->name << "]" << endl;

	key = 21;
	cout << "deleteNode(" << key << ")" << endl;
	h.deleteNode(21);
	h.displayNodes();

	return 1;
}