#include <cstdlib>
#include <iostream>

using namespace std;
int main()
{
	//int a[] = { 0,1,2,3 };
	//int i = 2;
	//int j = i++; //2�� ��ȯ �� 3
	//int k = --i; //2�� ���� �� ��ȯ
	//cout << a[k++]; //a[2]

	/*int i = 10;
	int j = 5;
	string s = "yes";
	i -= 4;
	j *= -2;
	s += " or no";
	cout << i << ' ' << j << ' ' << s << endl;*/

	/*int x, y;
	cin >> x >> y;
	int smaller = (x < y ? x : y);
	cout << smaller;*/

	//int cat = 14;
	//double dog = (double)cat; //c-style type casting
	//double pig = double(cat); //c++ �Լ� ��Ÿ�� �� ��ȯ

	//int i1 = 18;
	//int i2 = 16;
	//double dv1 = i1 / i2; //-> ���� ������ �� �Ҽ��� ���ϰ� �����
	////double dv2 = (double)i1 / (double)i2;
	//double dv2 = double(i1) / double(i2);
	//double dv3 = double(i1 / i2); //���� ������ �� ����ȯ �̷���

	//cout << dv1 << ' ' << dv2 << ' ' << dv3;

	//double d1 = 3.2;
	//double d2 = 3.9999;
	//int i1 = static_cast<int>(d1); //���� ����ȭ
	//int i2 = static_cast<int>(d2);
	//cout << d1 << ' ' << d2 << ' ' << i1 << ' ' << i2;

	int i = 3;
	double d = 4.8;
	double d3 = i / d; //->double(i)/d
	int i3 = d3; //int(d3)
	cout << i << ' ' << d << ' ' << d3 << ' ' << i3;

	return NULL;
}