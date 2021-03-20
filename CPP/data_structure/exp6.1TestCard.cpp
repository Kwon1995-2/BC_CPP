#include <cstdlib>
#include <vector>
#include "CreditCard.h"

using namespace std;

void testCard() {
	vector<CreditCard*>wallot(10);

	wallot[0] = new CreditCard("5391 0375 9387 5309", "John Bowman", 2500);
	wallot[1] = new CreditCard("3485 0399 3395 1954", "John Bowman", 3500);
	wallot[2] = new CreditCard("6011 4902 3294 2994", "John Bowman", 5000);

	for (int j = 1; j <= 16; j++) { //balance 채우기
		wallot[0]->chargelt(double(j));
		wallot[1]->chargelt(2*j);
		wallot[2]->chargelt(double(3 * j));
	}
	cout << "Card payments:\n";
	for (int i = 0; i < 3; i++) { //balance를 100이하로 만들기
		cout << *wallot[i];
		while (wallot[i]->getBalance() > 100.0) {
			wallot[i]->makePayment(100.0);
			cout << "New balance = " << wallot[i]->getBalance() << "\n";
		}
		cout << "\n";
		delete wallot[i];
	}
}
int main()
{
	testCard();
	return EXIT_SUCCESS;
}
