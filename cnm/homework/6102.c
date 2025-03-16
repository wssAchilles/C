#include<stdio.h>
#define N 10
void  rev(int a[], int m, int n)
{
	int *p=a+m-1;
	int *q=a+m+n-2;
	int t;
	while(p<q)
	{
		t=*p;
		*p=*q;
		*q=t;
		p++;
		q--;
	}
}
int main()
{
	int m,n,a[128],i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d%d",&m,&n);
	if(m+n>N)
	{
		n=N-m+1;
	}
	rev(a,m,n);
	for(i=0;i<N;i++)
	{
		printf("%d,",a[i]);
	}
}