#include<stdio.h>
#include<string.h>
void fun(char  s1[], char  s2[])
{
	int cnt=0;
	int *p=&s1;
	for(p=s1;s1;p++)
	{
		if((p>='a'&&p<='z')||(p>='A'&&p<='Z'))
		{
			s2[cnt++]=*p;
		}
	}
	for(p=s1;s1;p++)
	{
		if(p>='0'&&p<='9')
		{
			s2[cnt++]=*p;
		}
	}
	for(p=s1;s1;p++)
	{
		if(!((p>='a'&&p<='z')||(p>='A'&&p<='Z'))&&!(p>='0'&&p<='9'))
		{
			s2[cnt++]=*p;
		}
	}
}
int main()
{
	char s1[128],s2[128];
	gets(s1);
	fun(s1,s2);
	puts(s2);
}