#include<stdio.h>
int bj(int a[],int b[])
{
	int cnt=0;
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(b[j]==a[i])
			{
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	int n;
	int a[7];
	scanf("%d",&n);
	for(int i=0;i<7;i++)
	{
		scanf("%d",&a[i]);
	}
	int b[n][7];
	int c[7]={0,0,0,0,0,0,0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<7;j++)
		{
			scanf("%d",&b[i][j]);
		}
		int cnt=bj(a,b[i]);
		if(cnt!=0)
		{
			c[7-cnt]++;
		}
	}
	for(int i=0;i<7;i++)
	{
		printf("%d ",c[i]);
	}
}