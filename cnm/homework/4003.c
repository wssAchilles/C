#include<stdio.h>
int main()
{
	char s1[128],s2[128];
	gets(s1);
	char c;
	int len=0,i;
	for(i=0;(c=s1[i])!='\0';i++)
	{
		len++;
	}
	for(i=0;i<len;i++)
	{
		s2[len-1-i]=s1[i];
	}
	puts(s2);
}