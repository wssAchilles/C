#include<stdio.h>
#include<string.h>
void  fun(char *s)
{
	int t;
	char *i=s;
	char *j=s+strlen(s)-1;
	while(i<j)
	{
		t=*i;
		*i=*j;
		*j=t;
		i++;
		j--;
	}
}
int main()
{
	char s[128];
	gets(s);
	fun(s);
	puts(s);
}