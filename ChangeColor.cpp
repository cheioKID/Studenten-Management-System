#include<stdio.h>
#include"insert.h"
void color ()
{
 char color[9]="color ",answer;
 system("cls");
 printf("�Ƿ���Ҫ������ɫ(y/n or Y/N)?\n");
 scanf("%c",&answer);
 if(toupper(answer)=='Y')
 {  getchar();
	colorimply();
	printf("\t\t��������Ҫ������ɫ\n");
	printf("\t\t");
	scanf("%c",&color[6]);
	
	getchar();
    printf("\t\t��������Ҫ������ɫ\n");
	printf("\t\t");
	scanf("%c",&color[7]);
	color[8]='\0';
	system(color);
 }
}