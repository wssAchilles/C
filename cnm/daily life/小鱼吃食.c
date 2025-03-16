#include<stdio.h>
int main()
{
	int a[128],b[128];
	int i,len=0;

	for(i=0;;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0){break;}
		len++;
		
		
	}
	for(i=0;i<len;i++)
	{
		b[len-1-i]=a[i];
	}
	for(i=0;i<len;i++)
	{
		printf("%d ",b[i]);
	}
}