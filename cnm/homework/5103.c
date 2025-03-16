#include<stdio.h>
#include<string.h>
int main()
{
	void insert(char s1[128], char s2[128], char ch);
	char s1[128],s2[128];
	gets(s1);
	gets(s2);
	char ch=getchar();
	insert(s1,s2,ch);
	puts(s1);
}
void insert(char s1[128], char s2[128], char ch)
{
	
	int i,len1,len2,m;
	int bt=0;
	len1=strlen(s1);
	len2=strlen(s2);
	for(i=0;i<len1;i++)
	{
		if(s1[i]==ch)
		{
			bt=1;
			m=i;
			break;
		}
	
	}	
	if(bt==1)
		{
			
			for(i=len1;i>m;i--)
			{
				s1[len2+i]=s1[i];
			}
			for(i=0;i<len2;i++)
			{
				s1[m+i+1]=s2[i];
			
			}
	    
		}
    
}