#include<stdio.h>
int main()
{
	double fun(int n,double x);
	int n;
	double x;
	scanf("%d%lf",&n,&x);
	printf("%.2f",fun(n,x));
}

double fun(int n,double x)
{
	double y;
	if(n==0)
	{y=1;}
	else if(n==1)
	{y=x;}
	else
	{y=((2*n-1)*x-fun(n-1,x)-(n-1)*fun(n-2,x))/(double)n;}
	return y;
}
