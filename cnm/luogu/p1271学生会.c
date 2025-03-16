#include<stdio.h>
int main()
{
	int n,m,t;
	scanf("%d%d",&n,&m);
	int b[m];
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(b[i]>b[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		printf("%d ",b[i]);
	}
}

