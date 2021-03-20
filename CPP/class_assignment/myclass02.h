#ifndef _MYCLASS02_H_
#define _MYCLASS02_H_

#include <list>
#include <map>

using namespace std;

class myclass02
{
	list<int> tlist;
	map<int, int> tmap;

public:
	myclass02();
	~myclass02();

	void setData(int _count);
	void displayList();
	void displayMap();
};

#endif