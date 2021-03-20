#include<iostream>
#include <time.h>
using namespace std;
class Polynomial;

class Term
{
	friend Polynomial;
private:
	float coef;
	int exp;
};
class Polynomial {
private:
	static Term* TermElement;
	static int free;
	int start, finish;
	int terms;
public:
	Polynomial(int);
	~Polynomial() {};
	int get_data();
	int show_data();
	int addPolynomial(Polynomial&, Polynomial&);
	void sort();
	//void sort_sum();

};

int Polynomial::free = 0;
Term* Polynomial::TermElement = new Term[100];

Polynomial::Polynomial(int x) {
	start = free;
	finish = start + x ;
	free += x ;
	terms = x;

	memset(TermElement, 0, sizeof(Term)*100);
}
int Polynomial::get_data() {
	int num = terms;
	for (int i = start; i < finish; i++) {
		TermElement[i].coef = rand() % 10 + 1;
		TermElement[i].exp = terms--;
	}
	return 0;
}
int Polynomial::show_data() {
	for (int i = start; i < finish; i++) {
		cout << TermElement[i].coef << "x^" << TermElement[i].exp << ' ';
	}
	cout << endl;
	return 0;
}
int Polynomial::addPolynomial(Polynomial& a, Polynomial& b) {
	int i = start, j = a.start, k = b.start;
	while (k < b.finish) {
		if (TermElement[i].exp < a.TermElement[j].exp) {
			b.TermElement[k].exp = a.TermElement[j].exp;
			b.TermElement[k].coef = a.TermElement[j].coef; k++; j++;
		}
		else if (TermElement[i].exp == a.TermElement[j].exp) {
			b.TermElement[k].exp = TermElement[i].exp;
			b.TermElement[k].coef = TermElement[i].coef + a.TermElement[j].coef; k++; i++; j++; b.finish--;
		}
		else if (TermElement[i].exp > a.TermElement[j].exp) {
			b.TermElement[k].exp = TermElement[i].exp;
			b.TermElement[k].coef = TermElement[i].coef; k++; i++;
		}
		/*else if (a.TermElement[j].exp < 1) {
			TermElement[j].exp = NULL;
			TermElement[j].coef = NULL;
		}
		else if (TermElement[i].exp < 1) {
			a.TermElement[i].exp = NULL;
			a.TermElement[i].coef = NULL;
		}*/
		else if (i>=finish){
			b.TermElement[k].exp = a.TermElement[j].exp;
			b.TermElement[k].coef = a.TermElement[j].coef; k++; j++;
		}
		else if (j >= finish) {
			b.TermElement[k].exp = TermElement[i].exp;
			b.TermElement[k].coef = TermElement[i].coef; k++; i++;
		}
	}
	return 0;
}

void Polynomial::sort() {
	
	for (int i = start; i < finish; i++) {
		for (int j = start; j < finish; j++) {
			if (TermElement[i].exp < TermElement[j].exp) {
				int temp1 = TermElement[j].exp;
				TermElement[j].exp = TermElement[i].exp;
				TermElement[i].exp = temp1;

				int temp2 = TermElement[j].coef;
				TermElement[j].coef = TermElement[i].coef;
				TermElement[i].coef = temp2;
			}
		}
	}
}

//void Polynomial::sort_sum() {
//	
//	for (int i = start; i < finish; i++) {
//		for (int j = start; j < finish; j++) {
//			if (TermElement[i].exp = TermElement[j].exp) {
//				T[i].coef += 
//}

int main(void)
{
	Polynomial a(3), a1(3), b(4), c(7);

	srand((unsigned int)time(NULL));
	a.get_data();//계수와 지수를 난수를 생성하여 입력, 지수는 같은 것이 없어야 한다.
	a.show_data();
	//a1.get_data();
	//a1.show_data();
	b.get_data();
	b.show_data();
	//a1.sort();
	//a1.show_data();
	//c.get_data();
	a.addPolynomial(b,c);  //a + a1 = c
	c.show_data();
	//system("pause");
	return 0;
}