#include<stdio.h>
#include<string.h>
int main()
{
	long htod(char s[]);
	char s[128];
	gets(s);
	printf("%ld",htod(s));
}
long htod(char s[])
{
	long sum=0;
	int i,t,len;
	char c;
	for(i=0;(c=s[i])!='\0';i++)//len=strlen(s);
	{
		len++;
	}
	for(i=0;i<len;i++)//strupr(s);
	{
		if(s[i]>='a'&&s[i]<='z')
			{s[i]=s[i]-32;}
	}
	
	for(i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			t=s[i]-'0';
		else if(s[i]>='A'&&s[i]<='A'+16-10)
			t=s[i]-'A'+10;
		sum=sum*16+t;
	}
	return sum;

}