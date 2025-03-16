#include<stdio.h>
#include<string.h>
int main()
{
	void cat_rev(char s[]);
	char s[128];
	gets(s);
	cat_rev(s);
	puts(s);
}
void cat_rev(char s[])
{
/*	char a[128];
	int len,i;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		a[i]=s[len-i-1];
	}
	strcat(s,a);
*/
	int i,j;
	for(i=0;s[i]!='\0';i++)
	;
	for(j=i-1;j>=0;j--,i++)
	{
		s[i]=s[j];
	}
	s[i]='\0';
}