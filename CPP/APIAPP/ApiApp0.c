#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mysql.h"
int main()
{
	char arr_sql[100] = { 0, };

	scanf("%[^\n]", arr_sql);

	MYSQL mysql;
	if(!mysql_init(&mysql))
		return 0;

	if(!mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, NULL, 0))
		return 0;

	//mysql_query(&mysql, "select Code, Name, Region, SurfaceArea, Population, GNP from country");
	mysql_query(&mysql, arr_sql);

	MYSQL_RES* result = mysql_store_result(&mysql);

	if (!result)
	{
		mysql_close(&mysql);
		return 0;
	}
	int count = mysql_field_count(&mysql);

	FILE* fp = fopen("sql.log", "wt"); // 검색결과를 임시 저장할 로그파일을 쓰기모드로 열기

	MYSQL_ROW row;

	while (row = mysql_fetch_row(result))
	{
		for (int i = 0; i < count; i++)
		{
			printf("%s,", row[i]);
			fprintf(fp, "%s,", row[i]); // 검색결과를 로그파일에 출력
		}
		printf("\n");
		fprintf(fp, "\n");
		
	}
	fclose(fp); //로그 파일 닫기
	mysql_free_result(result);
	mysql_close(&mysql);

	return 0;
}
