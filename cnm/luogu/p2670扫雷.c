#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n][m];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=0;
			if(a[i][j]=='*')
			{
				a[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1)
			{
				printf("*");
			}
			else
			{
				printf("%d",a[i][j-1]+a[i][j+1]+a[i-1][j]+a[i+1][j]+a[i-1][j-1]+a[i+1][j-1]+a[i-1][j+1]+a[i+1][j+1]);
			}
		}
	}
}
