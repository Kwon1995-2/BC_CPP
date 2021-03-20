#include <iostream>  //띄어쓰기
#include <time.h>
#include <iomanip>
#include <list>
#include <map>
#include<vector>
using namespace std;
class myclass02 {
private:
	std::list<int> tlist;
	std::map<int, int> tmap;  //(key,value)
public:
	myclass02();
	~myclass02();
	void setData(int count);
	void diplayList();
	void displayMap();
};
myclass02::myclass02() {

}
myclass02::~myclass02() {

} 
void myclass02::setData(int count) {  //타입, 클래스
	int num;
	for (int i = 0; i < count; i++) {
		num = rand() % 101;
		tlist.push_back(num);
		tmap.insert(make_pair(i, num));
	}
}
void myclass02::diplayList() {
	/*for (int i : tlist) {
		cout << i<<' ';
	}
	cout << endl;*/

	for (list<int>::iterator iter = tlist.begin(); iter != tlist.end();iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}
void myclass02::displayMap() {
	for (auto i = tmap.begin(); i != tmap.end();i++) {
		cout <<setw(2)<< i->first << ":" << i->second;
	}
	cout << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	myclass02 my;
	my.setData(5);
	my.diplayList();
	my.displayMap();
	
}