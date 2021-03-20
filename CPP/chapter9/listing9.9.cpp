// Listing 9.9 The usehotel.c Control Module
/* usehotel.c -- room rate program */
/* compile with Listing 9.10 
header file을 사용하는 방법을 실습 - 9장 코딩 시험에 적용한다
*/
#include <stdio.h>
#include <stdlib.h>
#include "hotel.h" /* defines constants, declares functions */
int main(void)
{
	int nights;
	double hotel_rate;
	int code;
	while ((code = menu()) != QUIT)
	{
		switch (code)
		{
		case 1: hotel_rate = HOTEL1;
			break;
		case 2: hotel_rate = HOTEL2;
			break;
		case 3: hotel_rate = HOTEL3;
			break;
		case 4: hotel_rate = HOTEL4;
			break;
		default: hotel_rate = 0.0;
			printf("Oops!\n");

			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("Thank you and goodbye.\n");
	system("pause");
	return 0;
}
