#include<stdio.h>
int main()
{
	char a[128],b[128],c;
	int i,lenb=0,lena=0,max,m;
	gets(a);
	gets(b);
	for(i=0;(c=b[i])!='\0';i++)
	{
		lenb++;
	}
	for(i=0;(c=a[i])!='\0';i++)
	{
		lena++;
	}
	max=a[0];
	for(i=0;i<lena;i++)
	{
		if(a[i]>=max)
		{
			max=a[i];
			m=i;
		}
	}
	for(i=lena;i>m;i--)
	{
		a[i+lenb]=a[i];
	}
	for(i=0;i<lenb;i++)
	{
		a[m+i+1]=b[i];
	}
	puts(a);
}