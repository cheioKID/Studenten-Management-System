#include "insert.h"
void colorimply()
{
 printf("0:��ɫ 1:��ɫ  2:��ɫ  3:ǳ��ɫ  4:��ɫ  5:��ɫ  6:��ɫ  7:��ɫ   8:��ɫ  \n\n9:����ɫ  A:����ɫ   B:��ǳ��ɫ  C:����ɫ  D:����ɫ  E:����ɫ  F:����ɫ\n");
}

int LoginMenu()  //��ʾ��¼����
 {int choice;
 system("cls");
 gotoxy(10,2);printf("������������������������������");
 gotoxy(10,3);printf("��                          ��");
 gotoxy(10,4);printf("��       1->�û�ע��        ��");
 gotoxy(10,5);printf("��       2->��ʦ��¼        ��");
 gotoxy(10,6);printf("��       3->ѧ����¼        ��");
 gotoxy(10,7);printf("��       4->�˳�ϵͳ        ��");  
 gotoxy(10,8);printf("��                          ��");
 gotoxy(10,9);printf("������������������������������");
 gotoxy(10,10);printf("������ѡ�"); 
 scanf("%d",&choice);  
 return choice; 
}

void mainMenu(int choice) //��ʾ���˵���ʽ
{												
     gotoxy(10,2);printf("**********ѧ���ɼ�����ϵͳ******\n");  
	 gotoxy(10,3);printf("|  1  |����ѧ���ɼ�%s  |\n",choice==3?"(û��Ȩ��)":"          ");
	 gotoxy(10,4);printf("|  2  |����ѧ���ɼ�%s  |\n",choice==3?"(û��Ȩ��)":"          ");
     gotoxy(10,5);printf("|  3  |ɾ��ѧ���ɼ�%s  |\n",choice==3?"(û��Ȩ��)":"          ");
     gotoxy(10,6);printf("|  4  |��ʾѧ���ɼ�            |\n");  //3��ѧ����¼ û��Ȩ���޸�ѧ����Ϣ
     gotoxy(10,7);printf("|  5  |�˳�ϵͳ                |\n");
     gotoxy(10,8);printf("********************************\n");
	 gotoxy(10,9);printf(" ������ѡ��(1~5): ");
     
}

void subMenu(void) //��ʾ�Ӳ˵���ʽ
{
     system("cls");
	 gotoxy(10,2);printf("**********��ʾѧ����Ϣ********\n");
	 gotoxy(10,3);printf("|  1  |  ѧ��������ʾ        |\n");
	 gotoxy(10,4);printf("|  2  |  ��ѧ�ɼ�������ʾ    |\n");
     gotoxy(10,5);printf("|  3  |  Ӣ��ɼ�������ʾ    |\n");
	 gotoxy(10,6);printf("|  4  |  ƽ���ɼ�������ʾ    |\n");
     gotoxy(10,7);printf("|  5  |  ���ص����˵�ϵͳ    |\n");
	 gotoxy(10,8);printf("******************************\n");
	 gotoxy(10,9);printf(" ������ѡ��(1~5): ");

}