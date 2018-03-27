#include "insert.h"

void gotoxy(int x, int y)
{ 
	COORD c;
	c.X = x;
	c.Y = y;
//  	用于在相应的设备设置光标的位置，两个参数分别是设备句柄和光标位置结构
//  当参数标识为STD_OUTPUT_HANDLE时获得标准输出句柄
	SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
} 
void colorchange()
{
 printf("0=黑色，8=灰色\n""1=蓝色，9=淡蓝色\n""2=绿色，A=淡绿色\n""3=浅绿色，B=淡浅绿色\n");
 printf("4=红色，C=淡红色\n""5=紫色，D=淡紫色\n""6=黄色，E=淡黄色\n""7=白色，F=亮白色\n");
}

void mainMenu(void) //显示主菜单格式
{
     printf("---------学生成绩管理系统-----------\n");
	 printf("|  1  |输入学生的成绩             |\n");
	 printf("|  2  |插入一个学生的成绩         |\n");
     printf("|  3  |删除一个学生的成绩          |\n");
	 printf("|  4  |显示学生的成绩              |\n");
     printf("|  5  |退出系统                    |\n");
	 printf("------------------------------------\n");
	 printf(" 请输入选项(1~5): ");
     
}

void subMenu(void) //显示子菜单格式
{
     system("cls");
	 gotoxy(40,6); printf("---------显示学生信息----------\n");
	 gotoxy(40,7); printf("|    1. 按学号升序显示        |\n");
	 gotoxy(40,8); printf("|    2. 按数学成绩降序显示    |\n");
     gotoxy(40,9); printf("|    3. 按英语成绩降序显示    |\n");
	 gotoxy(40,10);printf("|    4. 按平均分成绩降序显示  |\n");
     gotoxy(40,11);printf("|    5. 返回主菜单系统        |\n");
	 gotoxy(40,12);printf("-------------------------------\n");
	 gotoxy(40,13);printf(" 请输入选项(1~5): ");
     
}

void  inputScore(STU* p,int n)  /*输入学生成绩 纪芳 */
{    
 /*请给出相关的中文提示,让用户正确输入数据*/
	
   int i;
   printf("学号姓名数学成绩英语成绩\n");
   for(i=0;i<=n-1;i++)
   {
   	scanf("%d",&p[i].num);
	getchar(); 
	scanf("%s",p[i].name);
    scanf("%d",&p[i].a[0]);
	scanf("%d",&p[i].a[1]);
   }
}
void insertScore( STU* p, int *num) //插入一个学生的学号及成绩 施凤娇 
{
 int i=0,k=0;
 STU newstu;
 printf("将按照学号升序插入该同学的成绩");

 SnoSort(p,*num);

 printf("请输入学生学号 姓名 数学成绩 英语成绩\n");
 scanf("%d",&newstu.num);
 getchar();
 scanf("%s",newstu.name);
 scanf("%d",&newstu.a[0]);
 scanf("%d",&newstu.a[1]);
 for(i=0;i<*num-1;i++)
	if(p[i].num>newstu.num)
	{k=i;
	break;
	}	
if(i=*num-1)
	p[*num]=newstu;
else
   {for(i=*num;i<=k+1;i--)
	  p[i]=p[i-1];
	p[k]=newstu;
	}	
}

void deleteScore(STU* p,int* num) //删除一个学生的成绩 丘惠桃 
{   /*请给出相关的中文提示,让用户正确输入数据*/
	
	int i,k,j,n,a;
	printf("请输入要删除的学生的学号\n");
	n=*num;
	scanf("%d",&a);//输入要删除的学生的号数；
	for(i=0;i<=n-1;i++)
	{                     //找到要删除的那个学生的号数，记下此时的数组下标； 
		if(p[i].num==a)
		k=i;
	} 
	for(j=k;j<=n-1;j++)
	{                           //找到要删除的学生的数据的数组下标是K，把K赋给J；把J之 
		p[j]=p[j+1];             //的数据全部前移一个 
	}
}


void Show(STU* p,int num)  //显示学生的成绩,num为学生个数
{   int k,i=0;
	subMenu();
	scanf("%d",&k);
	switch(k)
	{case 1:SnoSort(p,num);
			break;
	 case 2:Mathdescend(p,num);
			break;
	 case 3:Endescend(p,num);
		    break;
	 case 4:Averdescend(p,num);
		    break;
	 case 5:mainMenu();
			exit(0);
			break;
	
	}
	if(k>0&&k<5)
	{printf("学号 姓名 数学成绩 英语成绩\n");
	for(i=0;i<num;i++)
		printf("%d %s %d %d\n",(p+i)->num,(p+i)->name,(p+i)->a[0],(p+i)->a[1]);
	}
}
