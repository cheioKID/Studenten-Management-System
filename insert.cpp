#include "insert.h"

void gotoxy(int x, int y)
{ 
	COORD c;
	c.X = x;
	c.Y = y;
//  	��������Ӧ���豸���ù���λ�ã����������ֱ����豸����͹��λ�ýṹ
//  ��������ʶΪSTD_OUTPUT_HANDLEʱ��ñ�׼������
	SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
} 
void colorchange()
{
 printf("0=��ɫ��8=��ɫ\n""1=��ɫ��9=����ɫ\n""2=��ɫ��A=����ɫ\n""3=ǳ��ɫ��B=��ǳ��ɫ\n");
 printf("4=��ɫ��C=����ɫ\n""5=��ɫ��D=����ɫ\n""6=��ɫ��E=����ɫ\n""7=��ɫ��F=����ɫ\n");
}

void mainMenu(void) //��ʾ���˵���ʽ
{
     printf("---------ѧ���ɼ�����ϵͳ-----------\n");
	 printf("|  1  |����ѧ���ĳɼ�             |\n");
	 printf("|  2  |����һ��ѧ���ĳɼ�         |\n");
     printf("|  3  |ɾ��һ��ѧ���ĳɼ�          |\n");
	 printf("|  4  |��ʾѧ���ĳɼ�              |\n");
     printf("|  5  |�˳�ϵͳ                    |\n");
	 printf("------------------------------------\n");
	 printf(" ������ѡ��(1~5): ");
     
}

void subMenu(void) //��ʾ�Ӳ˵���ʽ
{
     system("cls");
	 gotoxy(40,6); printf("---------��ʾѧ����Ϣ----------\n");
	 gotoxy(40,7); printf("|    1. ��ѧ��������ʾ        |\n");
	 gotoxy(40,8); printf("|    2. ����ѧ�ɼ�������ʾ    |\n");
     gotoxy(40,9); printf("|    3. ��Ӣ��ɼ�������ʾ    |\n");
	 gotoxy(40,10);printf("|    4. ��ƽ���ֳɼ�������ʾ  |\n");
     gotoxy(40,11);printf("|    5. �������˵�ϵͳ        |\n");
	 gotoxy(40,12);printf("-------------------------------\n");
	 gotoxy(40,13);printf(" ������ѡ��(1~5): ");
     
}

void  inputScore(STU* p,int n)  /*����ѧ���ɼ� �ͷ� */
{    
 /*�������ص�������ʾ,���û���ȷ��������*/
	
   int i;
   printf("ѧ��������ѧ�ɼ�Ӣ��ɼ�\n");
   for(i=0;i<=n-1;i++)
   {
   	scanf("%d",&p[i].num);
	getchar(); 
	scanf("%s",p[i].name);
    scanf("%d",&p[i].a[0]);
	scanf("%d",&p[i].a[1]);
   }
}
void insertScore( STU* p, int *num) //����һ��ѧ����ѧ�ż��ɼ� ʩ�ｿ 
{
 int i=0,k=0;
 STU newstu;
 printf("������ѧ����������ͬѧ�ĳɼ�");

 SnoSort(p,*num);

 printf("������ѧ��ѧ�� ���� ��ѧ�ɼ� Ӣ��ɼ�\n");
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

void deleteScore(STU* p,int* num) //ɾ��һ��ѧ���ĳɼ� ����� 
{   /*�������ص�������ʾ,���û���ȷ��������*/
	
	int i,k,j,n,a;
	printf("������Ҫɾ����ѧ����ѧ��\n");
	n=*num;
	scanf("%d",&a);//����Ҫɾ����ѧ���ĺ�����
	for(i=0;i<=n-1;i++)
	{                     //�ҵ�Ҫɾ�����Ǹ�ѧ���ĺ��������´�ʱ�������±ꣻ 
		if(p[i].num==a)
		k=i;
	} 
	for(j=k;j<=n-1;j++)
	{                           //�ҵ�Ҫɾ����ѧ�������ݵ������±���K����K����J����J֮ 
		p[j]=p[j+1];             //������ȫ��ǰ��һ�� 
	}
}


void Show(STU* p,int num)  //��ʾѧ���ĳɼ�,numΪѧ������
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
	{printf("ѧ�� ���� ��ѧ�ɼ� Ӣ��ɼ�\n");
	for(i=0;i<num;i++)
		printf("%d %s %d %d\n",(p+i)->num,(p+i)->name,(p+i)->a[0],(p+i)->a[1]);
	}
}
