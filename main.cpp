/**************************************
 *  项 目  名：学生成绩管理.dsw       *
 *  作     者：                       *
 *  编制时间：2015年12月              *
 *  主要功能：实现对学生成绩的录入、修*
 *      改、删除、插入、显示功能      *
 **************************************/
#include "insert.h"

void main()
{ 
	struct user our_users[N]; 
	int count =0,n=0; 
	int current_user,choice; 
	STU* p=NULL;
    
	while(1) 
	{choice=LoginMenu();
		

     switch(choice)  
		{   
		case 1:if(user_register(our_users,count))   
				{     
					count++;     
					printf("\n注册成功!\n");
				}
			    else
					printf("\n注册失败!\n");
				break;    //注册   
		case 2:
		case 3:  PlaySound("久石让 - 菊次郎的夏天.wav",NULL,SND_FILENAME|SND_ASYNC); 
			    if((current_user = is_my_user(our_users,count)))  
				{     
					 printf("\n登陆成功!\n");
					 operation(p,choice,n);    
				}  
				else  
					printf("\n登陆失败!");  
	            break;       
	     case 4:exit(0);  
		} 
		 

	} 
}
