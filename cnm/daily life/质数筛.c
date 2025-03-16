#include<stdio.h>
int isprime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return 0;
			break;
		}
	}
	return 1;
}
int main()
{
	int isprime(int n);
	int n,i,s[128];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	int cnt=0;
	for(i=0;i<n;i++)
	{
		if(isprime(s[i]))
		{
			s[cnt++]=s[i];
		}
	}
	for(i=0;i<cnt;i++)
	{
		printf("%d ",s[i]);
	}
}