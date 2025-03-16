#include<stdio.h>
int main()
{
	int i,cnt=0,sum,n=0,x;
	int a[100];
	scanf("%d",&x);
	while(x!='\n')
	{
		a[cnt]=x;
		cnt++;
		sum+=x;
		n++;
		scanf("%d",&x);
	}
	double pj=sum/n;
	for(i=0;i<cnt;i++)
	{
		if(a[i]>pj){
			printf("%d",a[i]);
		}
	}

}