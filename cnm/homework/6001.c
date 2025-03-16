#include<stdio.h>
int main()
{
	int m,n,i,j;
	int a[128];
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{
		a[i]=i+1;
	}
	a[m]=-2;
	int *p=a+m-1;
	for(i=0,j=0;i<m;i++)
	{
		while(j<n)
		{
			p++;
			if(*p==-2) p=a;
			if(*p!=-1) j++;
		}	
		j=0;
		printf("%d,",*p);
		*p=-1;
	}
}