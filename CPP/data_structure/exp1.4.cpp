//ÇÔ¼ö
#include <cstdlib>
#include <iostream>
using namespace std;

//bool evenSum(int a[], int n);
void f(int value, int& ref) {
	value++;
	ref++;
	cout << value << endl;
	cout << ref << endl;
}

inline int min(int x, int y) { return (x < y ? x : y); }

int main(void)
{
	/*int list[] = { 4, 2, 7 ,8, 5, 1 };
	bool result = evenSum(list, 6);
	if (result) cout << "the sum is even\n";
	else cout << "the sum is odd\n";*/

	int cat = 1;
	int dog = 5;
	int q = min(cat, dog);
	cout << q;
	/*f(cat, dog);
	cout << cat << endl;
	cout << dog << endl;*/

	return EXIT_SUCCESS;
}

//bool evenSum(int a[], int n) {
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += a[i];
//	}
//	return (sum % 2) == 0;
//}