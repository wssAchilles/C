#include<stdio.h>
#include<string.h>
int main()
{
	char a[128];
	gets(a);
	strupr(a);
	puts(a);
}