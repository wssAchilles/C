#include<stdio.h>
#include<string.h>
void fun(char  s1[], char  s2[])
{
	int cnt=0,i;
	for(i=0;s1[i]!=0;i++)
	{
		if((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z'))
		{
			s2[cnt++]=s1[i];
		}
	}
	for(i=0;s1[i]!=0;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			s2[cnt++]=s1[i];
		}
	}
	for(i=0;s1[i]!=0;i++)
	{
		if(!((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z'))&&!(s1[i]>='0'&&s1[i]<='9'))
		{
			s2[cnt++]=s1[i];
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