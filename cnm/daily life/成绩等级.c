#include<stdio.h>
int fun(int b,int c)
{
	
	double sum;
	sum=0.7*b+0.3*c;
	if(sum*10>=800&&(b+c)>140)
	{
		return 1;
 	}
	return 0;
}
int main()
{
	
	int a[128][128];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
		if(fun(a[i][1],a[i][2]))
		{
			printf("Excellent");
		}else 
		{
			printf("Not excellent");
		}
	}

}