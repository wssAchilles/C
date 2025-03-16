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
	int a[jc(n)][n];
	void sord(int a[][],int n);
    scanf("%d",&n);
	sord(a,n);
	for(int i=0;i<jc(n);i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

void sord(int a[][],int n)
{
	for(int i=0;i<jc(n);i++)
	{
		
	}
}
