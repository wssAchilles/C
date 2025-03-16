#include<stdio.h>
bool flower(int a[],int size,int n)
{
	if(n==0) return true;
	int i=0;
	int cnt=0;
	while(i<size)
	{
		if(a[i]==1) i+=2;
		else if(i>0&&a[i-1]==1) i++;
		else if(i<size-1&&a[i+1]==1) i+=3;
		else 
		{
			a[i]=1;
			cnt++;
			i+=2;
			if(cnt==n) return true;
		}
	}
	return false;
}
int main()
{
	int a[]={0,1,0,0,0,1,0,0,0,0,1,0,};
	if(flower(a,sizeof(a)/sizeof(a[0]),4))
	{
		printf("YES\n");
	}else 
	{
		printf("NO\n");
	}
	int cnt=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<cnt;i++)
	{
		printf("%d,",a[i]);
	}
}