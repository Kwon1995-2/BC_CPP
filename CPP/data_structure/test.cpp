#include<iostream>
#include"myclass01.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	myclass01 a;
	a.displayTable();
	myclass01 b(2,3);
	b.diplayMatrix();
	b.free_Matrix();
	//a.setMatrix(2,3);
	//a.diplayMatrix();

	
}