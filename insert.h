#ifndef I_N_T_E_R
#define I_N_T_E_R
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include<conio.h>
#define N 100    //����û�����Ϊ100

#include "mmsystem.h"       //�������ֺ���ԭ�����ڵ�ͷ�ļ�
#pragma comment (lib,"WinMM.lib")

typedef struct stu{     //�Զ���һ��ѧ����Ϣ�Ľṹ��
    int              num;      /*ѧ��*/
    char             name[20]; /*����*/
    int              a[2];    /*���ſεĳɼ�*/
   }STU;

struct user
{ 
   int  user_id;        //�û�ID
   char user_name[19];  //�û������18λ 
   char password[13];   //���13λ 
 };

int LoginMenu(void);      // ��¼������ʾ
int user_register(struct user *ptr_user,int size);  //�û�ע��
int is_my_user(struct user *p,int size);  // �û���¼

void mainMenu(int );      //��ʾ���˵���ʽ
void operation(STU *,int ,int ); // ���˵��Ĳ���
void color (void);      //�û����Ըı���ɫ
void colorimply(void);
void gotoxy(int x, int y);//��궨λ
    
void subMenu(void);     //��ʾ�Ӳ˵���ʽ

void inputScore(STU* ,int );     //����ѧ���ɼ�   ����ѧ������
void insertScore(STU*,int *p);  //����һ��ѧ���ɼ�    ��p����ѧ������
void deleteScore(STU*,int *p);  //ɾ��һ��ѧ���ɼ�  
void Show(STU *p,int ,int );     //��ʾѧ���ĳɼ�

void SnoSort(STU *,int );       //��ѧ������
void Mathdescend(STU *, int );  // ����ѧ�ɼ��Ӹߵ��ͽ���
void Endescend(STU *,int );     // ��Ӣ��ɼ�����
void Averdescend(STU *,int );   //��ƽ��������


#endif
 
