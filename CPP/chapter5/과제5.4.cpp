#include <iostream>
using namespace std;
class String {
public:
	String(); //default 생성자
	String(const String&); // 복사 생성자
	String(const char* _string);
	~String();
	String& operator=(const String&);
	int operator==(const String&) const;
	operator char* () { return strdup(string); }
	char operator[](int i);
	friend ostream& operator<<(ostream& os, String& str);
private:
	char* string;
	int MaxLength;
};
String::String() {
	cout << "[default 생성자 호출]" << endl;
	string = new char[10]; //string = NULL;
	MaxLength = 0;
}
String::String(const char* _string) {
	cout << "[parameter가 있는 생성자 호출]" << endl;
	MaxLength = strlen(_string) + 1;
	string = new char[strlen(_string) + 1]; //string = new char[MaxLength]; 문자열 끝에 끝을 표시하는 NULL 문자 포함
	strcpy_s(string, strlen(_string) + 1, _string); //strcpy(string, src);

	//MaxLength = 0;
}
String::String(const String& str) {
	cout << "[복사 생성자 호출]" << endl;
	string = new char[strlen(str.string) + 1];
	strcpy_s(string, strlen(str.string) + 1, str.string);

	MaxLength = str.MaxLength;
}
String& String::operator=(const String& source) {
	cout << "[재정의한 assign 함수호출]" << endl;
	MaxLength = source.MaxLength;
	string = new char[strlen(source.string) + 1]; //stirng = new char[MaxLength];
	strcpy_s(string, strlen(source.string) + 1, source.string); //strcpy(string, src.string);
	return *this;
}
String::~String() {
	cout << "[소멸자 호출]" << endl;
	delete []string;
}
char String:: operator[](int i) {
	return string[i];
}
ostream& operator<<(ostream& os, String& str) {
	os << str.string<<endl;
	return os;
}
int String::operator==(const String& src) const {
	return !strcmp(string, src.string);
}
void main(void)
{
	String string("Good afternoon to everybody");

	cout << string << endl;
	cout << string[6] << endl; // 배열[] 연산자 오버로딩

	String string2("Good morning");
	String name("bob");
	strcpy(string2, "Good afternoon"); //타입변환 오버로딩
	cout << string2 << endl;
}