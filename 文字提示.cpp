#include "insert.h"
void colorimply()
{
 printf("0:黑色 1:蓝色  2:绿色  3:浅绿色  4:红色  5:紫色  6:黄色  7:白色   8:灰色  \n\n9:淡蓝色  A:淡绿色   B:淡浅绿色  C:淡红色  D:淡紫色  E:淡黄色  F:亮白色\n");
}

int LoginMenu()  //显示登录界面
 {int choice;
 system("cls");
 gotoxy(10,2);printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆");
 gotoxy(10,3);printf("◆                          ◆");
 gotoxy(10,4);printf("◆       1->用户注册        ◆");
 gotoxy(10,5);printf("◆       2->教师登录        ◆");
 gotoxy(10,6);printf("◆       3->学生登录        ◆");
 gotoxy(10,7);printf("◆       4->退出系统        ◆");  
 gotoxy(10,8);printf("◆                          ◆");
 gotoxy(10,9);printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆");
 gotoxy(10,10);printf("请输入选项："); 
 scanf("%d",&choice);  
 return choice; 
}

void mainMenu(int choice) //显示主菜单格式
{												
     gotoxy(10,2);printf("**********学生成绩管理系统******\n");  
	 gotoxy(10,3);printf("|  1  |输入学生成绩%s  |\n",choice==3?"(没有权限)":"          ");
	 gotoxy(10,4);printf("|  2  |插入学生成绩%s  |\n",choice==3?"(没有权限)":"          ");
     gotoxy(10,5);printf("|  3  |删除学生成绩%s  |\n",choice==3?"(没有权限)":"          ");
     gotoxy(10,6);printf("|  4  |显示学生成绩            |\n");  //3是学生登录 没有权限修改学生信息
     gotoxy(10,7);printf("|  5  |退出系统                |\n");
     gotoxy(10,8);printf("********************************\n");
	 gotoxy(10,9);printf(" 请输入选项(1~5): ");
     
}

void subMenu(void) //显示子菜单格式
{
     system("cls");
	 gotoxy(10,2);printf("**********显示学生信息********\n");
	 gotoxy(10,3);printf("|  1  |  学号升序显示        |\n");
	 gotoxy(10,4);printf("|  2  |  数学成绩降序显示    |\n");
     gotoxy(10,5);printf("|  3  |  英语成绩降序显示    |\n");
	 gotoxy(10,6);printf("|  4  |  平均成绩降序显示    |\n");
     gotoxy(10,7);printf("|  5  |  返回到主菜单系统    |\n");
	 gotoxy(10,8);printf("******************************\n");
	 gotoxy(10,9);printf(" 请输入选项(1~5): ");

}