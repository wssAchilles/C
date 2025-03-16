#include<stdio.h>
int sum(int a,int b)
{
	int sum=a+b;
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n][3],b[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
}