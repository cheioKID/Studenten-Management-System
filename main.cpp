/**************************************
 *  �� Ŀ  ����ѧ���ɼ�����.dsw       *
 *  ��     �ߣ�                       *
 *  ����ʱ�䣺2015��12��              *
 *  ��Ҫ���ܣ�ʵ�ֶ�ѧ���ɼ���¼�롢��*
 *      �ġ�ɾ�������롢��ʾ����      *
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
					printf("\nע��ɹ�!\n");
				}
			    else
					printf("\nע��ʧ��!\n");
				break;    //ע��   
		case 2:
		case 3:  PlaySound("��ʯ�� - �մ��ɵ�����.wav",NULL,SND_FILENAME|SND_ASYNC); 
			    if((current_user = is_my_user(our_users,count)))  
				{     
					 printf("\n��½�ɹ�!\n");
					 operation(p,choice,n);    
				}  
				else  
					printf("\n��½ʧ��!");  
	            break;       
	     case 4:exit(0);  
		} 
		 

	} 
}
