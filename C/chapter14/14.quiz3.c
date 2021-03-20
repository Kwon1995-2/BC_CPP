#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

//3번
struct month {
	char mname[20]; // name of month
	char malias[3]; // a three letter
	int mdays; // 일수
	int mnum; // 월수
};

int main(void)
{
	//4번, 구조체 초기화
	struct month year[12] = {
		{"January","Jan",31,1 }, //첫번째 구조체 초기화
		{"Feburary", "Feb",28,2},
		{"March", "Mar",31,3},
		{"April", "Apr",30,4},
		{"May", "May",31,5},
		{"June", "Jun",28,6},
		{"July", "Jul",31,7},
		{"August", "Aug",31,8},
		{"September", "Sep",30,9},
		{"October", "Oct",31,10},
		{"November", "Nov",30,11},
		{"December", "Dec",31,12}
	};

	int monthnum;
	int result=0;
	scanf("%d", &monthnum);
	//result = totaldays(monthnum);

	// insert your code here
	for (int i = 0; i < monthnum; i++)
	{
		result += year[i].mdays;
	}

	printf("Total days are %d\n", result);


	
	//5번
}

