#include<stdio.h>
int main()
{
	int a[10]={0,1,23,434,3,43243,32,11,34,23};
	int min,i,j,t;
	for(i=0;i<9;i++)
	{
		min=i;
		for(j=i+1;j<10;j++)
		{
			if(a[min]<a[j])
			{
				min=j;
			}
		}
		if(i!=min)
			{
				t=a[i];
				a[i]=a[min];
				a[min]=t;
			}
		
	}
	for(i=0;i<10;i++)
	{
		printf("%d,",a[i]);
	}
}
	
