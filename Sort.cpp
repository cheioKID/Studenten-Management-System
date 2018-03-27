

#include"insert.h"

void SnoSort(STU* p,int n) //按学号升序排序 （伍雨馨 ）
{  	int i,j;
	STU turn;
	for(i=0;i<n-1;i++)
	{for(j=0;j<n-i-1;j++)  //泡沫排序(改进后)
		if((p+j)->num>(p+j+1)->num)
			{	
				turn=p[j];
				p[j]=p[j+1];
				p[j+1]=turn;
			}	
	}     
}
void Mathdescend(STU *p,int n) //按数学成绩排序 （王文）
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
void Endescend(STU *p,int n)  // 按英语成绩排序 （罗艳燕）
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
void Averdescend(STU *p,int n)   //按平均分降序排序 （陈可一）
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