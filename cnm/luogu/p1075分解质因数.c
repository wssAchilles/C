#include<stdio.h>
int zs(int n)
{
	if(n==1)
	{
		return 0;
	}
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			break;
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[128],b[128];
	int x,y;
	int cnt=0,xzq=0;
	for(x=2,y=2;x<n&&y<n;x++,y++)
	{
		if((x*y==n)&&zs(x)&&zs(y))
		{

		}
	}
}