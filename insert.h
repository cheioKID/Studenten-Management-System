#ifndef I_N_T_E_R
#define I_N_T_E_R
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include<conio.h>
#define N 100    //最大用户个数为100

#include "mmsystem.h"       //播放音乐函数原型所在的头文件
#pragma comment (lib,"WinMM.lib")

typedef struct stu{     //自定义一个学生信息的结构体
    int              num;      /*学号*/
    char             name[20]; /*姓名*/
    int              a[2];    /*二门课的成绩*/
   }STU;

struct user
{ 
   int  user_id;        //用户ID
   char user_name[19];  //用户名最大18位 
   char password[13];   //最大13位 
 };

int LoginMenu(void);      // 登录界面提示
int user_register(struct user *ptr_user,int size);  //用户注册
int is_my_user(struct user *p,int size);  // 用户登录

void mainMenu(int );      //显示主菜单格式
void operation(STU *,int ,int ); // 主菜单的操作
void color (void);      //用户可以改变颜色
void colorimply(void);
void gotoxy(int x, int y);//光标定位
    
void subMenu(void);     //显示子菜单格式

void inputScore(STU* ,int );     //输入学生成绩   返回学生个数
void insertScore(STU*,int *p);  //插入一个学生成绩    由p带回学生个数
void deleteScore(STU*,int *p);  //删除一个学生成绩  
void Show(STU *p,int ,int );     //显示学生的成绩

void SnoSort(STU *,int );       //按学号排序
void Mathdescend(STU *, int );  // 按数学成绩从高到低降序
void Endescend(STU *,int );     // 按英语成绩降序
void Averdescend(STU *,int );   //按平均分排序


#endif
 
