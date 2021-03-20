#include <iostream>
#include <vector>
using namespace std;

class MyC
{
public:
	MyC(int cnt) { count = cnt;  }
	int count;
};

int main()
{
	vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	vector<int>::iterator iter;

	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << endl;
		continue;
	}

	vector<string> vecs;

	vecs.push_back("a");
	vecs.push_back("b");
	vecs.push_back("c");
	vecs.push_back("d");

	vector<string>::iterator iters;

	for (iters = vecs.begin(); iters != vecs.end(); iters++)
	{
		cout << *iters << endl;
		continue;
	}

	vector<MyC*> vecC;

	vecC.push_back(new MyC(1));
	vecC.push_back(new MyC(2));
	vecC.push_back(new MyC(3));
	vecC.push_back(new MyC(4));

	vector<MyC*>::iterator iterC;

	for (iterC = vecC.begin(); iterC != vecC.end(); iterC++)
	{
		cout << (*iterC)->count << endl;
		continue;
	}

	return 1;
}