#include<stdio.h>
int isprime(int n)
{
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return 0;
			break;
		}
	}
	return 1;
}
int hw(int n)
{
	int a[128];
	int cnt=0,m;
	while(n>0)
	{
		m=n%10;
		n=n/10;
		a[cnt++]=m;
	}
	int i=0,j=cnt-1;
	while(i<j)
	{
		if(a[i]!=a[j])
		{
			break;
		}
		i++;
		j--;
	}
	if(i<j)
	{
        return 0;
    }
   else
    {
        return 1;
    }
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=m;i<n;i=i+2)
	{
		if(isprime(i)&&hw(i))
		{
			printf("%d\n",i);
		}
	}
}