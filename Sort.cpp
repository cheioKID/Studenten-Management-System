

#include"insert.h"

void SnoSort(STU* p,int n) //��ѧ���������� ������ܰ ��
{  	int i,j;
	STU turn;
	for(i=0;i<n-1;i++)
	{for(j=0;j<n-i-1;j++)  //��ĭ����(�Ľ���)
		if((p+j)->num>(p+j+1)->num)
			{	
				turn=p[j];
				p[j]=p[j+1];
				p[j+1]=turn;
			}	
	}     
}
void Mathdescend(STU *p,int n) //����ѧ�ɼ����� �����ģ�
{   STU turn;
	int i,k;
	for(i=0;i<n-1;i++) {
     for(k=0;k<n-i-1;k++)
			if((p+k)->a[0]<(p+k+1)->a[0])
		 		{
					turn=*(p+k);
					*(p+k)=*(p+k+1);
					*(p+k+1)=turn;
				}			
	}
  
}
void Endescend(STU *p,int n)  // ��Ӣ��ɼ����� �������ࣩ
{
   STU turn;
	int i,k;
	for(i=0;i<n-1;i++) {
     for(k=0;k<n-i-1;k++)
			if((p+k)->a[1]<(p+k+1)->a[1])
		 		{
					turn=*(p+k);
					*(p+k)=*(p+k+1);
					*(p+k+1)=turn;
				}			
	}
 }
void Averdescend(STU *p,int n)   //��ƽ���ֽ������� ���¿�һ��
{   STU turn;
	int i,k;
	for(i=0;i<n-1;i++) {
     for(k=0;k<n-i-1;k++)
			if(((p+k)->a[0]+(p+k)->a[1])<((p+k+1)->a[0]+(p+k+1)->a[1]))
		 		{
					turn=*(p+k);
					*(p+k)=*(p+k+1);
					*(p+k+1)=turn;
				}			
	}
}