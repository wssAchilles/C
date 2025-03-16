#include<stdio.h>
int dc(char s[])
{
	int cnt=0;
	int word=0;
	for(int i=0;s[i];i++)
	{
		if(s[i]==' ')
		{
			word=0;
		}
		else
		if(word==0)
		{
			word=1;
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	char s[128];
	gets(s);
	int cnt=dc(s);
	printf("%d",cnt);
}