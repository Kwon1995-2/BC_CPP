#include <stdio.h>
#include<stdlib.h>

struct gas cal_mpg(struct gas trip);
int cal_pmpg(struct gas* trip);

struct gas {
	float distance; //거리
	float gals; 
	float mpg;
};

int main(void)
{
	struct gas trip = {0,0,0};

	scanf("%f %f", &trip.distance, &trip.gals);  //"&" 빼먹지 말자
	trip = cal_mpg(trip);
	printf("Distance: %f, Gals: %f, mpg: %f\n", trip.distance, trip.gals, trip.mpg);
	cal_pmpg(&trip);
	printf("Distance: %f, Gals: %f, mpg: %f\n", trip.distance, trip.gals, trip.mpg);

	return 0;
}

struct gas cal_mpg(struct gas trip)
{
	
	trip.mpg = trip.distance / trip.gals;
	//trip.mpg += trip.distance % trip.gals; //% 연산을 int형만 가능??

	return trip;
}

int cal_pmpg(struct gas* trip)
{
	trip->mpg = trip->distance / trip->gals;

	return 0; //return trip->mpg;
}