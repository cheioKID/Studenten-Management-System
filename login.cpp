#include"insert.h"


int user_register(struct user *ptr_user,int size)  //用户注册 (丘惠桃)
{ 
    char password[13];
    char repassword[13]; 
	int i=0,namelen=0,passlen=0;
    printf("请输入注册姓名:");
    fflush(stdin);            //清空缓冲区 读取的函数有时候直接从缓冲区取数据，这就导致了一种问题 
    gets(ptr_user[size].user_name);
	namelen=strlen(ptr_user[size].user_name);
		if(namelen<1||namelen>18)
        {  
			 printf("您输入的姓名无效,用户名长度在1-18之间");  
             return 0; 
		}
    printf("\n请输入注册密码:");           
    
	i=0;
	password[i]=getch();
	while(!isspace(password[i]))
	{i++;
    printf("*");
	password[i]=getch();
	}
	printf("\n");
	password[i]='\0';
	passlen=i;  //密码长度
    printf("请再次输入注册密码:");                 //前面数据读过之后，回车确认
	
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
		printf("\n\t两次输入的密码不一致!\n\n");  
	    system("PAUSE");
		return 0;
	} 
	else		//将密码保存到用户信息
	{  strcpy(ptr_user[size].password,password); }
	if(passlen<6||passlen>12)
	{  
		printf("\n\t您输入的密码无效,密码应在6-12之间\n"); 
	    system("PAUSE");
		return 0;
	} 
	 printf("\n\t您的编号为:%d这将是您的登陆帐号.\n\n",
		    ptr_user[size].user_id=10000+size); 
	 system("PAUSE");
	 return 1;
}
int is_my_user(struct user *p,int size)//若注册成功 则查找用户信息 (丘惠桃)
{ 
   int i=0; 
   int zhanghu; 
   char mima[15]; 
   printf("请输入您的帐号: "); 
   scanf("%d",&zhanghu); 
   getchar();
   printf("请输入您的密码: "); 
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
