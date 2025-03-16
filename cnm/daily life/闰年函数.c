#include<stdio.h>
int leap(int year)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
	{return 1;}
	else
	{return 0;}
}
int main()
{
	int x,y,i;
	int cnt=0,a[128];
	scanf("%d %d",&x,&y);
	for(i=x;i<y;i++)
	{
		if(leap(i))
		{
			a[cnt++]=i;
		}
	}
	printf("%d\n",cnt);
	for(i=0;i<cnt;i++)
	{
		printf("%d ",a[i]);
	}
}
