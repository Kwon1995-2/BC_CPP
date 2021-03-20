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

	FILE* fp = fopen("sql.log", "wt"); // �˻������ �ӽ� ������ �α������� ������� ����

	MYSQL_ROW row;

	while (row = mysql_fetch_row(result))
	{
		for (int i = 0; i < count; i++)
		{
			printf("%s,", row[i]);
			fprintf(fp, "%s,", row[i]); // �˻������ �α����Ͽ� ���
		}
		printf("\n");
		fprintf(fp, "\n");
		
	}
	fclose(fp); //�α� ���� �ݱ�
	mysql_free_result(result);
	mysql_close(&mysql);

	return 0;
}
