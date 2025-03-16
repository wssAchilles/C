#include<stdio.h>
int jc(int n)
{
	int m;
	if(n==1)
	{
		m=1;
	}
	else
	{
		m=n*jc(n-1);
	}
	return m;
}
int main()
{
	int n;
	scanf("%d",&n);
	int m=jc(n);
	printf("%d",m);
}