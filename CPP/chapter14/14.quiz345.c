#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

//quiz3
struct month {
	char mname[20]; // name of month
	char malias[3]; // a three letter
	int mdays; // 일수
	int mnum; // 월수
};

//int totaldays(int month_num); 

int main(void)
{
	//quiz4, 구조체 초기화
	struct month year[12] = {
		{"January","Jan",31,1 }, //arr[0] initialization
		{"Feburary", "Feb",28,2}, //arr[1] initialization
		{"March", "Mar",31,3}, //arr[2] initialization
		{"April", "Apr",30,4},
		{"May", "May",31,5},
		{"June", "Jun",30,6},
		{"July", "Jul",31,7},
		{"August", "Aug",31,8},
		{"September", "Sep",30,9},
		{"October", "Oct",31,10},
		{"November", "Nov",30,11},
		{"December", "Dec",31,12}
	};

	int monthnum;
	int result = 0;
	scanf("%d", &monthnum);
	//result = totaldays(monthnum);

	// quiz5  insert your code here
	for (int i = 0; i < monthnum; i++)
	{
		result += year[i].mdays;
	}

	printf("Total days are %d\n", result);

}

//int totaldays(month_num)
//{
//	for (int i = 0; i < month_num; i++)
//    {
//	  result += year[i].mdays;
//    }
//      return result;
//}


