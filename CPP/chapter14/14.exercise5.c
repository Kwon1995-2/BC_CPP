#include<stdio.h>
#include<stdlib.h>

#define CSIZE 4

struct name {
	char first[10];
	char last[10];
};

struct student {
	struct name alias;
	float grade[3];
	float avg;
	//float cavg; => ���� ���� �۾�
};

void print_stds(struct student* stds, int size);
void avg_student(struct student* stds, int size);
void avg_class(struct student* stds, int size);

int main(void)
{
	int i;
	struct student stds[CSIZE] = {
		{{"Bob", "James"},{0,0,0},0},
		{{"Evan", "Village"},{0,0,0},0},
		{{"Amazon", "Google"},{0,0,0},0},
		{{"Aplron", "Good"},{0,0,0},0}
	};

	for (i = 0; i < CSIZE; i++)
	{
		printf("Input %s %s s scores : ", stds[i].alias.first, stds[i].alias.last);
		scanf("%f %f %f", &stds[i].grade[0], &stds[i].grade[1], &stds[i].grade[2]);
	}
	
	avg_student(stds, CSIZE); // ���� �;� �Ʒ� �Լ����� avg ��� ����
	print_stds(stds, CSIZE);
	avg_class(stds, CSIZE);
	
	return 0;
}


void avg_student(struct student* std, int size)
{
	/*for (int i = 0; i < size; i++)
	{
		std[i].avg = (std[i].grade[0] + std[i].grade[1] +std[i].grade[2]) / 3;
	}*/

	for (int i = 0; i < size; i++)
	{
		float sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += std[i].grade[j];
			//std[i].avg = sum / 3; -> ���� ��� ����
		}
		std[i].avg = sum/3;
	}
	
}

void avg_class(struct student* std, int size)  // ��ü����� �ƴ� ���� ��� ���ϴ� �Լ�
{
	//float sum = 0;
	//for (int i = 0; i < size; i++)
	//{
	//	//std->cavg += std[i].avg;
	//	sum += std[i].avg;
	//}
	//sum = sum / size;
	//printf("cavg is %.2f\n", sum); // =>���� 0�� ����
	/*std->cavg = std->cavg / size;
	printf("cavg is %.2f\n", std->cavg);*/

	for (int i = 0; i < 3; i++)
	{
		float sum = 0;
		for (int j = 0; j < size; j++)
		{
			sum += std[j].grade[i];
		}
		printf("avg of class%d: %.2f\n",i+1,sum/(float)size); //size�� ������ ���� ���
	}
}

void print_stds(struct student* std, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("Input %s %s s scores : \n", std[i].alias.first, std[i].alias.last);
		printf("%.2f %.2f %.2f\n", std[i].grade[0], std[i].grade[1], std[i].grade[2]);
		printf("avg is %.2f\n", std[i].avg);
	}
}
