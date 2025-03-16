#include<stdio.h>
#include<math.h>
int main()
{
	int i,gw,sw,bw;
	for(i=100;i<=999;i++)
	{
		gw=i%10;
		sw=i/10%10;
		bw=i/100;
		if(i==pow(gw,3)+pow(sw,3)+pow(bw,3)){
			printf("%d ",i);
		}

	}
}
