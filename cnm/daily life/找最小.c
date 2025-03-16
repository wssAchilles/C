#include<stdio.h>
int main()
{
	int i,n,max,a;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		max=a;
		if(a>=max)
		{
			max=a;
		}
	}
	printf("%d",max);
}
