#include"insert.h"


int user_register(struct user *ptr_user,int size)  //�û�ע�� (�����)
{ 
    char password[13];
    char repassword[13]; 
	int i=0,namelen=0,passlen=0;
    printf("������ע������:");
    fflush(stdin);            //��ջ����� ��ȡ�ĺ�����ʱ��ֱ�Ӵӻ�����ȡ���ݣ���͵�����һ������ 
    gets(ptr_user[size].user_name);
	namelen=strlen(ptr_user[size].user_name);
		if(namelen<1||namelen>18)
        {  
			 printf("�������������Ч,�û���������1-18֮��");  
             return 0; 
		}
    printf("\n������ע������:");           
    
	i=0;
	password[i]=getch();
	while(!isspace(password[i]))
	{i++;
    printf("*");
	password[i]=getch();
	}
	printf("\n");
	password[i]='\0';
	passlen=i;  //���볤��
    printf("���ٴ�����ע������:");                 //ǰ�����ݶ���֮�󣬻س�ȷ��
	
	i=0;
	repassword[i]=getch();
	while(!isspace(repassword[i]))
	{i++;
    printf("*");
	repassword[i]=getch();
	}
	printf("\n");
	repassword[i]='\0';

	if(strcmp(password,repassword))    
	{  
		printf("\n\t������������벻һ��!\n\n");  
	    system("PAUSE");
		return 0;
	} 
	else		//�����뱣�浽�û���Ϣ
	{  strcpy(ptr_user[size].password,password); }
	if(passlen<6||passlen>12)
	{  
		printf("\n\t�������������Ч,����Ӧ��6-12֮��\n"); 
	    system("PAUSE");
		return 0;
	} 
	 printf("\n\t���ı��Ϊ:%d�⽫�����ĵ�½�ʺ�.\n\n",
		    ptr_user[size].user_id=10000+size); 
	 system("PAUSE");
	 return 1;
}
int is_my_user(struct user *p,int size)//��ע��ɹ� ������û���Ϣ (�����)
{ 
   int i=0; 
   int zhanghu; 
   char mima[15]; 
   printf("�����������ʺ�: "); 
   scanf("%d",&zhanghu); 
   getchar();
   printf("��������������: "); 
   mima[i]=getch();
   while(!isspace(mima[i]))
   {i++;
   printf("*");
   mima[i]=getch();
   }
   printf("\n");
   mima[i]='\0';
   for(i=0;i<size;i++) 
   {  
       if((zhanghu == p[i].user_id)&&(strcmp(mima,p[i].password)==0)) 
	    {   
		   return i+1; 
	    } 
   } 
   return 0;
}
