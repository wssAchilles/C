#include<stdio.h>
#define M 10
int  low(int *score,int *below)
{
	int cnt=0,i;
	double sum=0,pj=0;
	int *p=score,*q=below;
	for(p=score;p<score+M;p++)
	{
		sum+=*p;
	}
	pj=sum/M;
	for(p=score;p<score+M;p++)
	{
		if(*p<pj)
		{
			*q++=*p;
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	int score[128],below[128];
	int i;
	for(i=0;i<M;i++)
	{
		scanf("%d",&score[i]);
	}
	int cnt=low(score,below);
	printf("%d\n",cnt);
	for(i=0;i<cnt;i++)
	{
		printf("%d,",below[i]);
	}
}