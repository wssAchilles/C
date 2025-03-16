#include<stdio.h>
#include<string.h>
#define N 3
#define M 1
struct stduent
{
	int xh;
	char xm[128];
	int cj[128];
	double pj;
	int sum;
}stu[M];
void outputone(struct stduent stu[],int i)
{
	int j;
	printf("%d,%s,",stu[i].xh,stu[i].xm);
	for(j=0;j<N;j++)
	{
		printf("%d,",stu[i].cj[j]);
	}
	printf("%.2f\n",stu[i].pj);
}
void outputall(struct stduent stu[])
{
	int i;
	for(i=0;i<M;i++)
	{
		outputone(stu,i);
	}
	int m;
	double max=stu[0].pj;
	for(i=0;i<M;i++)
	{
		if(max<stu[i].pj)
		{
			max=stu[i].pj;
			m=i;
		}
	}
	outputone(stu,m);
}
int main()
{
	int i,j;
	for(i=0;i<M;i++)
	{
		scanf("%d",&stu[i].xh);
		getchar();
		gets(stu[i].xm);
		stu[i].sum=0;
		for(j=0;j<N;j++)
		{
			scanf("%d",&stu[i].cj[j]);
			stu[i].sum+=stu[i].cj[j];
		}
		stu[i].pj=(double)stu[i].sum/N;
	}
	outputall(stu);
}