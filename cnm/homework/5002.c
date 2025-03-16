#include<stdio.h>
#include<math.h>
int main()
{
	double ball(int n);
	double sum(int n);
	int n;
	
	scanf("%d",&n);
	
	printf("%.4f,%.4f",ball(n),sum(n));
}

double ball(int n)
{
	double high;
	if(n==0)
	{high=100;}
	else
	{
	high=ball(n-1)/2.0;
	}
	return high;
}
double sum(int n)
{
	double sum=0;
	if(n==0)
	{sum=0;}
	else
	{
		double k=pow(0.5,n);
		sum=300*(1-k);
	}
	return sum;
}