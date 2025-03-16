#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	if((fp=fopen("upper.txt","w"))==NULL)
	{
		printf("NO");
		exit(0);
	}
	char ch;
	while((ch=getchar())!='!')
	{
		if(ch>='a'&&ch<='z')
		{
			ch=ch-32;
		}
		putchar(ch);
	}
	fclose(fp);
	return 0;
}