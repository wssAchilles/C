#include<stdio.h>
int main()
{
	int a,i,max;
	printf("input No.1 date:");
	i=1;
	scanf("%d",&a);
	max=a;
L1:
    i=i+1;
	printf("input No.%d date:",i);
	scanf("%d",&a);
	if(max<a)
	max=a;
	if(i<10)
	goto L1;
	printf("Max=%d",max);



}