#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int prime (int x);
void input(int *a,int n);
int count=0;
int main ( )
{
	int a[100];
	input(a,30);
	int i;
	for(i=0;i<30;i++)
	{
		if(prime(a[i]))
			count++;
	}
	printf("%d",count);
	return 0;
}
void input(int *a,int n)
{
	srand(time(NULL));
	int i;
	for(i=0;i<n;i++)
		a[i]=rand()%100+1;
}
int prime (int x)
{
	int i,k;
   k=(int)sqrt((double) x);
if(x==1)
	return 0;
for(i=2;i<=k;i++)
{
	if(x%i==0)
		return 0;
}
return 1;
}
