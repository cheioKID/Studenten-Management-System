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

void color ()     //�ı���ɫ
{
 char color[9]="color ",answer;
 printf("\n�Ƿ���Ҫ������ɫ(y/n or Y/N)?\n");
 printf("���Ļش���:");
 scanf("%c",&answer);
 if(toupper(answer)=='Y')
 {  getchar();
	colorimply();
	printf("\n��������Ҫ������ɫ\n");
	printf("���Ļش���:");
	scanf("%c",&color[6]);
    getchar();
    printf("\n��������Ҫ������ɫ\n");
	printf("���Ļش���:");
	scanf("%c",&color[7]);
	color[8]='\0';
	system(color);
 }
}


void operation(STU* p,int choice,int n )  //���˵�����
{ int k;
  
   
 
  color(); 
   while(1)
	{	system("cls");      //����
		mainMenu(choice);   //��ʾ���˵���ʽ  
		scanf("%d",&k);    
		switch(k)
		{
			case 1:  
			{printf("\n������ѧ������: ");
			scanf("%d",&n);
			p=(STU *)malloc(n*sizeof(struct stu));
			inputScore(p,n);             //����ѧ���ĳɼ�
			break;} 
	    	case 2:  insertScore(p,&n); //����һ��ѧ���ĳɼ�,����ѧ������
		       break;
			case 3:  deleteScore(p,&n); //ɾ��һ��ѧ���ĳɼ�,����ѧ������
		       break;
			case 4:  Show(p,n,choice);  //��ʾѧ���ĳɼ�
		       break; 
			case 5: 
			{   free(p);
			    return ;
			}	
				
		}
		system("PAUSE");
	} 
 
}

void  inputScore(STU* p,int n)  /*����ѧ���ɼ� �ͷ� */
{    
 /*�������ص�������ʾ,���û���ȷ��������*/
	
   int i;
   printf("ѧ�� ���� ��ѧ�ɼ� Ӣ��ɼ�\n");
   for(i=0;i<=n-1;i++)
   {
   	scanf("%d",&p[i].num);
	getchar(); 
	scanf("%s",p[i].name);
    scanf("%d",&p[i].a[0]);
	scanf("%d",&p[i].a[1]);
   }
}
void insertScore(STU* p, int* num) //����һ��ѧ����ѧ�ż��ɼ� ʩ�ｿ 
{
 int i=0,k=0;
 STU newstu;
 printf("(������ѧ����������ͬѧ�ĳɼ����������Ϣ�Իس�����)\n");
 SnoSort(p,*num);
 printf("\nѧ��ѧ�ţ� ");
 scanf("%d",&newstu.num);
 getchar();
 printf("ѧ�������� ");
 scanf("%s",newstu.name);
 printf("��ѧ�ɼ��� ");
 scanf("%d",&newstu.a[0]);
 printf("Ӣ��ɼ��� ");
 scanf("%d",&newstu.a[1]);
 
for(i=0;i<*num-1;i++)
	if(p[i].num>newstu.num)
	{k=i;
	break;
	}	
if(i==*num-1)
	p[*num]=newstu;
else if(*num==0)
	printf("\n\t��ʹ�ã�����ѧ���ɼ�\n");
else
   {for(i=*num;i<=k+1;i--)
	  p[i]=p[i-1];
	p[k]=newstu;
	}
   *num=*num+1;
printf("\n\t�ɹ����������Ϣ\n\t");	
}

void deleteScore(STU* p,int* num) //ɾ��һ��ѧ���ĳɼ� ����� 
{   /*�������ص�������ʾ,���û���ȷ��������*/
	
	int i,k=0,j,n,a;
	
	do{printf("\n\t������Ҫɾ����ѧ����ѧ��\n");
		printf("\t"); 
		n=*num;

		scanf("%d",&a);                 //����Ҫɾ����ѧ���ĺ�����
	  
		for(i=0;i<n;i++)
		{                               //�ҵ�Ҫɾ�����Ǹ�ѧ���ĺ��������´�ʱ�������±ꣻ 
			if(p[i].num==a)
			{k=i;
			 break;
			}
		}
		if(i==n)
		{	
			printf("\n\tû�м�¼!\n");   //û�и�����¼
			break ;
		}	
		else
		{   for(j=k;j<n-1;j++) 
				p[j]=p[j+1]; 
			*num=*num-1;
			printf("\n\t�Ѿ�ɾ��������¼\n");	
		}
	}while(!k);
		
	

}


void Show(STU* p,int num,int choice)  //��ʾѧ���ĳɼ�,numΪѧ������
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
			printf("\n\tû�м�¼!\n");}
		else
		{
			system("cls");
			gotoxy(10,1);printf("ѧ��   ����    ��ѧ�ɼ�   Ӣ��ɼ�\n");
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
