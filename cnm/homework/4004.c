#include<stdio.h>
#include<string.h>
#define N 4
int main()
{
	char a[N][128];
	char c;
	int i,j;
	for(i=0;i<N;i++)
	{
		gets(a[i]);
	}
	for(i=0;i<N;i++)
	{
		int z=0,s=0,other=0;
		
		for(j=0;(c=a[i][j])!='\0';j++)
		{
			if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
			z++;
			else if(c>='0'&&c<='9')
			s++;
			else
			other++;

		}
		printf("%d,%d,%d\n",z,s,other);
	}

}