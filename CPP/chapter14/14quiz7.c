#include<stdio.h>
#include<stdlib.h>

struct name {
	char first[20];
	char last[20];
};

struct bem {
	int limbs;
	struct name title;
	char type[30];
};

void concat(struct bem* m);

int main(void)
{
	struct bem* pb;

	struct bem deb = { 6,{"Berbnazel", "Gwolkapwolk"},"Arcturan"};
	pb = &deb;

	printf("%d\n", deb.limbs);
	printf("%s\n", pb->type);
	printf("%s\n", pb->type + 2);
	//printf 2ways
	printf("%s\n", pb->title.last);
	printf("%s\n", deb.title.last);

	concat(pb);
}

void concat(struct bem* m) //print_bem
{
	printf("%s ", m->title.first);
	printf("%s is a ", m->title.last);
	printf("%d-limbs ", m->limbs);
	printf("%s\n", m->type);
	//교수님은 한 줄로 코딩하심
}