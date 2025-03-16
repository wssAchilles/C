#include<stdio.h>
int max(int a[],int m)
{
	int max=a[0];
	for(int i=0;i<m;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	return max;
}
int min(int a[],int m)
{
	int min=a[0];
	for(int i=0;i<m;i++)
	{
		if(min>a[i])
		{
			min=a[i];
		}
	}
	return min;
}
double score(int a[],int m)
{
	double sum=0;
	for(int i=0;i<m;i++)
	{
		sum+=a[i];
	}
	double pj=(sum-max(a,m)-min(a,m))/(double)(m-2);
	return pj;
}
int main()
{
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	int a[n][m];
	double stu[128];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
		stu[i]=score(a[i],m);
	}
	double max=stu[0];
	for(i=0;i<n;i++)
	{
		if(max<stu[i])
		{
			max=stu[i];
		}
	}
	printf("%.2f",max);
}