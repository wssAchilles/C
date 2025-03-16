#include<stdio.h>
# define M 10
struct stduent
{
	int xh;
	char xm[128];
	int birth;
	int age;
}stu[M];
void input(struct stduent stu[])
{
	int i;
	for(i=0;i<M;i++)
	{
		scanf("%d",&stu[i].xh);
		getchar();
		gets(stu[i].xm);
		scanf("%d",&stu[i].birth);
	}
}
void age(struct stduent stu[],int year)
{
	int i;
	for(i=0;i<M;i++)
	{
		stu[i].age=year-stu[i].birth;
	}
}
void output(struct stduent stu[])
{
	int i;
	for(i=0;i<M;i++)
	{
		if(stu[i].age>20)
		{
			printf("%d,%s,%d,%d\n",stu[i].xh,stu[i].xm,stu[i].birth,stu[i].age);
		}
	}
}
int main()
{
	input(stu);
	int year;
	scanf("%d",&year);
	age(stu,year);
	output(stu);
}
	