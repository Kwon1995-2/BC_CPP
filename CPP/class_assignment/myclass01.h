#ifndef _MYCLASS01_H_
#define _MYCLASS01_H_

class myclass01
{
	int table[5][5];
	int** pMatrix;
	int row;
	int col;

public:
	myclass01();
	~myclass01();

	void setMatrix(int _row, int _col);
	void displayTable();
	void displayMatrix();

private:
	void deleteMatrix();
};

#endif