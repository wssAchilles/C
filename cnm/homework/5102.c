#include<stdio.h>
int main()
{
	int isprime(int n);
	void fun(int m,int k,int xx[]);
	int m,k,i;
	int xx[128];
	scanf("%d%d",&m,&k);
	fun(m,k,xx);
	for(i=0;i<k;i++)
	{
		printf("%d,",xx[i]);
	}
}
int isprime(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{return 0;
		break;}
	}

	return 1;
}

void fun(int m,int k,int xx[])
{
	int i;
	for(i=0,m++;i<k;m++)
	{
		if(isprime(m))
		{
			xx[i++]=m;
			
		}
	}
}