#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
//#include <iomanip>
//using namespace std;
int main()
{
	//��� ����
	//int x, y;
	/*std::cout<< "Please enter two numbers"<<std::endl;
	std::cin >> x >> y;
	int sum = x + y;
	std::cout << "Their sum is " << sum << std::endl;*/

	/*cout << "Please enter two numbers" << endl;
	cin >> x >> y;
	int sum = x + y;
	cout << "Their sum is " << sum << endl;*/

	//���� Ÿ��
	/*char a = 'a';
	int n = 4;
	short n;
	int octalNumber = 0400;
	char newline_character = '\n'; //literal : 'a', '\n'
	long BIGnumber = 314159265L;
	short _aSTRANGE__1234_variABIE_NaMe;*/

	//cout << sizeof(short) << sizeof(int) << sizeof(long) << sizeof(char);

	//������
	/*enum Day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
	Day today = Thu;
	cout << today;
	enum Mood { Happy = 3, Sad = 1, Anxious = 4, Sleepy = 2 };
	Mood myMood = Happy;
	cout << Happy;*/

	//�ε� �Ҽ���
	//double dou = -1234.567;//3.14E5;//1.222222222222222222222225;
	//cout << dou<<endl;
	//float flo = 2.0f;//1.234e-3F;
	//cout <<flo<<endl; //->�Ǽ��� ����� �ȵ�
	//printf("%3.1f", flo);

	//������
	//char ch = 'Q';
	//void* p = &ch; ->������
	//cout << *p; //->������
	/*char* p = &ch;
	cout << *p;
	ch = 'Z';
	cout << *p;
	*p = 'X';
	cout << ch;*/

	//�迭
	/*double f[5];
	int m[10];
	f[4] = 2.5;
	m[2] = 4;
	cout << f[m[2]];*/
	/*int a[] = { 10, 11, 12, 13 };
	bool b[] = { false, true, false };
	char c[] = { 'a','b','c','d' };

	int* r[] = {&a[0],&a[1], &a[2], &a[3]};
	cout << *r[3];*/

	/*char c[] = { 'a','b','c','d' };
	char* p = c;
	char* q = &c[0];
	cout << c[2] << p[2] << q[2];*/

	//��Ʈ��
	//string s = "to be";
	//std::cout << s.size();
	//string t = "not " + s;
	//string u = s + " or " + t;
	////if (s > t) std::cout << u;

	/*string s = "John";
	int i = s.size();
	char c = s[1];
	std::cout << c << std::endl;

	s += " Smith";
	std::cout << s << std::endl;*/

	//c-style ����ü
	/*enum MealType {NO_PREF, REGULAR, LOW_FAT, VEGETARIAN};

	struct Passenger {
		string name;
		MealType mealPref;
		bool isFreqFlyer;
		string freqFlyerNo;
	};

	Passenger pass = { "Jonh Smith",REGULAR,true, "293145" };
	pass.name = "Simon";
	pass.mealPref = NO_PREF;*/

	//Passenger* p = new Passenger; //->p�� ���ο� Passenger�� ����Ŵ
	//(*p).mealPref = LOW_FAT;
	//p->mealPref = NO_PREF;
	//std::cout << (*p).mealPref; //->p�� �ʱ�ȭ���� ������ ����
	//delete p;

	/*char* buffer = new char[100];
	buffer[3] = 'a';
	buffer = (char*)"aaaaaaa";
	std::cout << &buffer;
	delete[] buffer;*/

	//���۷���
	//string author = "Samuel Clemens";
	//std::cout << author;
	//string& penName = author; //���۷����� �ݵ�� ����� ���ÿ� �ʱ�ȭ
	//penName = "Mark Twain";
	//std::cout << author;

	//���
	/*const double PI = 3.14159265;
	const int CUR_OFF[] = { 90, 80, 70, 60 };
	const int N_DAYS = 7;
	const int N_HOURS = 24 * N_DAYS;
	int counter[N_HOURS];*/

	//typedef
	/*typedef char* BufferPtr;
	typedef double Coordinate;

	BufferPtr p;
	Coordinate x, y;*/



	return NULL;//EXIT_SUCCESS;
}