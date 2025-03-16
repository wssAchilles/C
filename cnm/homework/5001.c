#include<stdio.h>
int main()
{
	long long jc(int m);
	int m,n;
	int zhs;
	scanf("%d%d",&m,&n);
	zhs=(jc(m)/(jc(n)*jc(m-n)));
	printf("%d",zhs);
	return 0;

}

long long jc(int m) 
{
	int zhs;
	if (m==1)
    {
        zhs=1;
    }
    else
    {
        zhs=m*jc(m-1);
    }
	return zhs;
}