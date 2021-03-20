#include <iostream>
#include <string>
#include <time.h>
#include "myclass02.h"

using namespace std;

myclass02::myclass02()
{
}
myclass02::~myclass02()
{
}
void myclass02::setData(int _count)
{
	srand((unsigned int)time(NULL));

	int val;
	for (int i = 0; i < _count; i++)
	{
		val = rand() % 101;
		tlist.push_back(val);
		tmap.insert(make_pair(i + 1, val));
	}
}
void myclass02::displayList()
{
	int cnt = 1;
//	for (auto iter = tlist.begin(); iter != tlist.end(); iter++)
	for (auto list : tlist)
	{
		cout.width(4);
//		cout << *iter;
		cout << list;

		if ((cnt++)%10 == 0)
			cout << endl;
	}
	cout << endl;
}
void myclass02::displayMap()
{
	int cnt = 1;
//	for (auto map = tmap.begin() ; map != tmap.end() ; map++)
	for (auto map: tmap)
	{
		cout.width(7);
//		cout << to_string(map->first) + "," + to_string(map->second);
		cout << to_string(map.first) + "," + to_string(map.second);

		if ((cnt++) % 10 == 0)
			cout << endl;
	}
	cout << endl;
}
