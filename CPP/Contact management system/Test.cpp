#include <iostream>
#include "ContactM.h"

using namespace std;

int main()
{
	MyHash h;
	h.initializeNode(10); 
	//������ �ε�(contact.txt)
	h.dataload();
	h.displayNodes();

	//������ �߰� �Է�
	cout << endl;
	h.insertNode("Simon","000","","","000","");
	h.displayNodes();

	//������ ��ȸ
	cout << endl;
	Node* t = h.searchNode("Simon");
	cout << "[" << t->name << "," << t->mobile_tel << "," << t->office_tel << "," << t->home_tel << "," << t->e_mail << ", " << t->birth << "]"<<endl;
	cout << endl;
	//������ ����
	h.deleteNode("Kimchulsoo");
	h.displayNodes();

	//������ ����

	h.modifyNode("Simon");
	cout << endl;
	h.displayNodes();
	
	//cout << endl;
	
}