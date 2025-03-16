#include<stdio.h>
int main()
{
	int i;
	int a[20]={1,1};
	for( i=2;i<20;i++)
	{
		a[i]=a[i-1]+a[i-2];
		
	}
	for(i=0;i<20;i++)
	{
		if(i%5==0){
		printf("\n");}
		printf("%12d",a[i]);
		
	}
	
}