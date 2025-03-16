#include<stdio.h>
int fun(char s[])
{
	int cnt=0;
	int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	for(int i=0;s[i];i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			cnt+=num[s[i]-'a'];
		}
		else if(s[i]==' ')
		{
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	char s[128];
	gets(s);
	int cnt=fun(s);
	printf("%d",cnt);
}