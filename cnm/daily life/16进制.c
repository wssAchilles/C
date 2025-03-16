#include<stdio.h>
#include<string.h>
int main()
{
	long fun(char s[]);
	char s[128];
	long sw;
	gets(s);
	sw=fun(s);
	printf("%ld",sw);
}
long fun(char s[])
{
	int len=strlen(s);
	strupr(s);
	/*for(i=0;i<len;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
			{s[i]=s[i]-32;}
	}
	*/
	long sw=0;
	int pow=1;
	for(int i=len-1;i>=0;i--)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sw+=(s[i]-'0')*pow;
		}else if (s[i]>='A'&&s[i]<='F')
		
		{
			sw+=(s[i]-'A'+10)*pow;
		}
		pow*=16;
	}
		return sw;
}