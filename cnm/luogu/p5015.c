#include<stdio.h>
#include<string.h>
int main()
{
	char a[128];
	gets(a);
	int cnt=0;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]!=' '&&a[i]!='\n')
		{
			cnt++;
		}
	}
	printf("%d",cnt);
}
