#include <iostream>
using namespace std;
class String {
public:
	String(); //default ������
	String(const String&); // ���� ������
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
	cout << "[default ������ ȣ��]" << endl;
	string = new char[10]; //string = NULL;
	MaxLength = 0;
}
String::String(const char* _string) {
	cout << "[parameter�� �ִ� ������ ȣ��]" << endl;
	MaxLength = strlen(_string) + 1;
	string = new char[strlen(_string) + 1]; //string = new char[MaxLength]; ���ڿ� ���� ���� ǥ���ϴ� NULL ���� ����
	strcpy_s(string, strlen(_string) + 1, _string); //strcpy(string, src);

	//MaxLength = 0;
}
String::String(const String& str) {
	cout << "[���� ������ ȣ��]" << endl;
	string = new char[strlen(str.string) + 1];
	strcpy_s(string, strlen(str.string) + 1, str.string);

	MaxLength = str.MaxLength;
}
String& String::operator=(const String& source) {
	cout << "[�������� assign �Լ�ȣ��]" << endl;
	MaxLength = source.MaxLength;
	string = new char[strlen(source.string) + 1]; //stirng = new char[MaxLength];
	strcpy_s(string, strlen(source.string) + 1, source.string); //strcpy(string, src.string);
	return *this;
}
String::~String() {
	cout << "[�Ҹ��� ȣ��]" << endl;
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
	cout << string[6] << endl; // �迭[] ������ �����ε�

	String string2("Good morning");
	String name("bob");
	strcpy(string2, "Good afternoon"); //Ÿ�Ժ�ȯ �����ε�
	cout << string2 << endl;
}