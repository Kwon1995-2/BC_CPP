#include <iostream>
#include "myclass01.h"
#include "myclass02.h"

using namespace std;

int main()
{
	//myclass01 my;

	//my.setMatrix(5, 10);

	//my.displayTable();
	//my.displayMatrix();

	myclass02 my;
	my.setData(100);

	my.displayList();
	my.displayMap();

	return 1;
}