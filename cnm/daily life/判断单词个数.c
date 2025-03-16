#include<stdio.h>
int main()
{
	char f[128];
	char c;
	int i,num=0,world=0;
	gets(f);
	for(i=0;(c=f[i])!='\n';i++)
	{
		if(c==' ')
		{world=0;}
		else if(world==0)
		{world=1;num++;}
		
	}
	printf("%d",num);
}

