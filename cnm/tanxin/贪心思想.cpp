#include<stdio.h>
#include<algorithm>
int main()
{
	int a[]={23,34,3,23,4,26,3,556,7,6,76,456,55,43,434};
	int cnt=sizeof(a)/sizeof(a[0]);
	std::sort(a,a+cnt);
	int max=500;
	int n=0,temp=0;
	for(int i=0;i<cnt;i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");
	for(int i=0;i<cnt;i++)
	{
		temp+=a[i];
		if(temp>max)
		{
			break;
		}
		n++;
	}
	printf("%d",n);
}