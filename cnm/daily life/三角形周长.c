#include<stdio.h>
int main()
{
    int a[128];
	int cnt=0,m,n;
	scanf("%d",&n);
	while(n>0)
	{
		m=n%10;
		n=n/10;
		a[cnt++]=m;
	}
	for(int i=cnt-1;i>=0;i--) 
	{
		printf("%d",a[i]);
	}
}

/*#include <stdio.h>
#include <math.h>
int main()
{
	int m,a[1000],i=1;
	scanf("%d",&m);
	a[0]=m%10;
	m=m/10;
	while(a[i]!=0)
	{
		a[i]=m%10;
		i++;
		m=m/10;
	}
	for (i=1000;i>=0;i--)
		if (a[i]!='\0')
			printf("%d",a[i]);
	return 0;
}
*/