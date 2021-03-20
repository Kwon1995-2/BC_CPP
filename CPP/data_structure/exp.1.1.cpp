#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
//#include <iomanip>
//using namespace std;
int main()
{
	//헤더 파일
	//int x, y;
	/*std::cout<< "Please enter two numbers"<<std::endl;
	std::cin >> x >> y;
	int sum = x + y;
	std::cout << "Their sum is " << sum << std::endl;*/

	/*cout << "Please enter two numbers" << endl;
	cin >> x >> y;
	int sum = x + y;
	cout << "Their sum is " << sum << endl;*/

	//변수 타입
	/*char a = 'a';
	int n = 4;
	short n;
	int octalNumber = 0400;
	char newline_character = '\n'; //literal : 'a', '\n'
	long BIGnumber = 314159265L;
	short _aSTRANGE__1234_variABIE_NaMe;*/

	//cout << sizeof(short) << sizeof(int) << sizeof(long) << sizeof(char);

	//열거형
	/*enum Day {Sun, Mon, Tue, Wed, Thu, Fri, Sat};
	Day today = Thu;
	cout << today;
	enum Mood { Happy = 3, Sad = 1, Anxious = 4, Sleepy = 2 };
	Mood myMood = Happy;
	cout << Happy;*/

	//부동 소수점
	//double dou = -1234.567;//3.14E5;//1.222222222222222222222225;
	//cout << dou<<endl;
	//float flo = 2.0f;//1.234e-3F;
	//cout <<flo<<endl; //->실수로 출력이 안됨
	//printf("%3.1f", flo);

	//포인터
	//char ch = 'Q';
	//void* p = &ch; ->가능함
	//cout << *p; //->빨간줄
	/*char* p = &ch;
	cout << *p;
	ch = 'Z';
	cout << *p;
	*p = 'X';
	cout << ch;*/

	//배열
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

	//스트링
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

	//c-style 구조체
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

	//Passenger* p = new Passenger; //->p는 새로운 Passenger를 가리킴
	//(*p).mealPref = LOW_FAT;
	//p->mealPref = NO_PREF;
	//std::cout << (*p).mealPref; //->p를 초기화하지 않으면 오류
	//delete p;

	/*char* buffer = new char[100];
	buffer[3] = 'a';
	buffer = (char*)"aaaaaaa";
	std::cout << &buffer;
	delete[] buffer;*/

	//레퍼런스
	//string author = "Samuel Clemens";
	//std::cout << author;
	//string& penName = author; //레퍼런스는 반드시 선언과 동시에 초기화
	//penName = "Mark Twain";
	//std::cout << author;

	//상수
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