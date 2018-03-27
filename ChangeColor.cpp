#include<stdio.h>
#include"insert.h"
void color ()
{
 char color[9]="color ",answer;
 system("cls");
 printf("是否想要更换颜色(y/n or Y/N)?\n");
 scanf("%c",&answer);
 if(toupper(answer)=='Y')
 {  getchar();
	colorimply();
	printf("\t\t请输入想要背景颜色\n");
	printf("\t\t");
	scanf("%c",&color[6]);
	
	getchar();
    printf("\t\t请输入想要字体颜色\n");
	printf("\t\t");
	scanf("%c",&color[7]);
	color[8]='\0';
	system(color);
 }
}