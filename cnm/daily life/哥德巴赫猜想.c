#include<stdio.h>
int isprime(int n)
{
	int i;
	if(n==0||n==1)
	{
		return 0;
	}
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{return 0;
		break;}
	}
	return 1;
}
int fun(int p[128], int len,int n)
{
	for(int i=0;i<len;i++)
	{
		if(p[i]==n)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int N;
	scanf("%d",&N);
	int a[N];
	int len=0;
	for(int i=2;i<=N;i++)
	{
		if(isprime(i))
		{
			a[len++]=i;
		}
	}
	for(int i=4;i<=N;i+=2)
	{
		for(int p=0;p<len;p++)
		{
			int y=i-a[p];
			if(fun(a,len,y))
			{
				printf("%d=%d+%d\n",i,a[p],y);
				break;
			}
		}
	}
}