#include <iostream>
#include <string>
#include "Hashpp.h"

using namespace std;

int main(void)
{
	MyHash h;
	h.initializeNode(10);
	
	h.insertNode(11, "ȫ�ϵ�", 2000, 1, 1);
	h.insertNode(21, "ȫ�̵�", 2000, 1, 1);
	h.insertNode(31, "ȫ�ﵿ", 2000, 1, 1);
	h.insertNode(2, "�ֹ��", 2000, 1, 1);
	h.insertNode(3, "��ö��", 2000, 1, 2);
	h.insertNode(4, "�̿���", 2000, 1, 3);
	h.displayNode();

	int key = 31;
	NODE* t = h.searchNode(key);
	cout << "searchNode(" << key << ")";
	cout << "\t[" << key << "," << t->name << "]" << endl;

	key = 21;
	cout << "deleteNode(" << key << ")" << endl;
	h.deleteNode(21);
	h.displayNode();

	return 1;
}