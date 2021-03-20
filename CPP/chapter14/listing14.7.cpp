// Listing 14.7 The funds3.c Program
/* funds3.c -- passing a structure */
#include <stdio.h>
#include <stdlib.h>

#define FUNDLEN 50
struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
//double sum(struct funds moolah); /* argument is a structure */
//double sum(struct funds* moolah);
struct funds sum(struct funds moolah);

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};
	printf("Stan has a total of $%.2f.\n", sum(stan));  
	// sum(stan) : struct 자체를 넘겨줌, pointer로 넘겨줄 때는 &구조체 이름
	//stan = sum(stan);
	printf("main()::stan.bankfund = %f\n", stan.bankfund);
	system("pause");

	return 0;
}
//double sum(struct funds moolah)  // moolah(별칭?) == stan
//{
//	moolah.bankfund += 1000.00;
//	printf("sum()::bankfund = %f\n", moolah.bankfund);  //여기서의 값은 flush
//	return(moolah.bankfund + moolah.savefund);
//}

//double sum(struct funds *moolah)  // pointer of struct funds
//{
//	moolah->bankfund += 1000.00;
//	printf("sum()::bankfund = %f\n", moolah->bankfund); 
//	return(moolah->bankfund + moolah->savefund);
//}

struct funds sum(struct funds moolah)
{
	moolah.bankfund += 1000.00;
	printf("sum()::bankfund = %f\n", moolah.bankfund);  
	return moolah;
}
