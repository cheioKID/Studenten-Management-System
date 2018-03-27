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

void color ()     //改变颜色
{
 char color[9]="color ",answer;
 printf("\n是否想要设置颜色(y/n or Y/N)?\n");
 printf("您的回答是:");
 scanf("%c",&answer);
 if(toupper(answer)=='Y')
 {  getchar();
	colorimply();
	printf("\n请输入想要背景颜色\n");
	printf("您的回答是:");
	scanf("%c",&color[6]);
    getchar();
    printf("\n请输入想要字体颜色\n");
	printf("您的回答是:");
	scanf("%c",&color[7]);
	color[8]='\0';
	system(color);
 }
}


void operation(STU* p,int choice,int n )  //主菜单操作
{ int k;
  
   
 
  color(); 
   while(1)
	{	system("cls");      //清屏
		mainMenu(choice);   //显示主菜单格式  
		scanf("%d",&k);    
		switch(k)
		{
			case 1:  
			{printf("\n请输入学生个数: ");
			scanf("%d",&n);
			p=(STU *)malloc(n*sizeof(struct stu));
			inputScore(p,n);             //输入学生的成绩
			break;} 
	    	case 2:  insertScore(p,&n); //插入一个学生的成绩,带回学生个数
		       break;
			case 3:  deleteScore(p,&n); //删除一个学生的成绩,带回学生个数
		       break;
			case 4:  Show(p,n,choice);  //显示学生的成绩
		       break; 
			case 5: 
			{   free(p);
			    return ;
			}	
				
		}
		system("PAUSE");
	} 
 
}

void  inputScore(STU* p,int n)  /*输入学生成绩 纪芳 */
{    
 /*请给出相关的中文提示,让用户正确输入数据*/
	
   int i;
   printf("学号 姓名 数学成绩 英语成绩\n");
   for(i=0;i<=n-1;i++)
   {
   	scanf("%d",&p[i].num);
	getchar(); 
	scanf("%s",p[i].name);
    scanf("%d",&p[i].a[0]);
	scanf("%d",&p[i].a[1]);
   }
}
void insertScore(STU* p, int* num) //导入一个学生的学号及成绩 施凤娇 
{
 int i=0,k=0;
 STU newstu;
 printf("(将按照学号升序插入该同学的成绩输入该生信息以回车结束)\n");
 SnoSort(p,*num);
 printf("\n学生学号： ");
 scanf("%d",&newstu.num);
 getchar();
 printf("学生姓名： ");
 scanf("%s",newstu.name);
 printf("数学成绩： ");
 scanf("%d",&newstu.a[0]);
 printf("英语成绩： ");
 scanf("%d",&newstu.a[1]);
 
for(i=0;i<*num-1;i++)
	if(p[i].num>newstu.num)
	{k=i;
	break;
	}	
if(i==*num-1)
	p[*num]=newstu;
else if(*num==0)
	printf("\n\t请使用：输入学生成绩\n");
else
   {for(i=*num;i<=k+1;i--)
	  p[i]=p[i-1];
	p[k]=newstu;
	}
   *num=*num+1;
printf("\n\t成功导入该生信息\n\t");	
}

void deleteScore(STU* p,int* num) //删除一个学生的成绩 丘慧桃 
{   /*请给出相关的中文提示,让用户正确输入数据*/
	
	int i,k=0,j,n,a;
	
	do{printf("\n\t请输入要删除的学生的学号\n");
		printf("\t"); 
		n=*num;

		scanf("%d",&a);                 //输入要删除的学生的号数；
	  
		for(i=0;i<n;i++)
		{                               //找到要删除的那个学生的号数，记下此时的数组下标； 
			if(p[i].num==a)
			{k=i;
			 break;
			}
		}
		if(i==n)
		{	
			printf("\n\t没有记录!\n");   //没有该生记录
			break ;
		}	
		else
		{   for(j=k;j<n-1;j++) 
				p[j]=p[j+1]; 
			*num=*num-1;
			printf("\n\t已经删除该条记录\n");	
		}
	}while(!k);
		
	

}


void Show(STU* p,int num,int choice)  //显示学生的成绩,num为学生个数
{   int k,i=0;
    FILE *file;
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
	 case 5:mainMenu(choice);
			exit(0);
			break;
	
	}
	file=fopen("student.txt","w");
	if(k>0&&k<5)
	{	if(num==0)
		{
			printf("\n\t没有记录!\n");}
		else
		{
			system("cls");
			gotoxy(10,1);printf("学号   姓名    数学成绩   英语成绩\n");
			for(i=0;i<num;i++)
			{   gotoxy(10,i+2);
			    printf("%-8d%-8s%-10d%-12d\n",
				(p+i)->num,(p+i)->name,(p+i)->a[0],(p+i)->a[1]);
				fprintf(file,"%-8d%-8s%-10d%-12d\n",
				(p+i)->num,(p+i)->name,(p+i)->a[0],(p+i)->a[1]);
			}
		}
	}
	fclose(file);
}
