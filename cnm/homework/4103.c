#include<stdio.h>
int main()
{
	char a[128],b[128],c;
	int n,lena,lenb,i;
	gets(a);
	gets(b);
	scanf("%d",&n);
	for(i=0;(c=a[i])!='\0';i++)
	{
		lena++;
	}
	for(i=0;(c=b[i])!='\0';i++)
	{
		lenb++;
	}
	if(n>lenb)
	{
		n=lenb;
	}
	for(i=0;i<n;i++)
	{
		a[lena+i]=b[i];
	}
	puts(a);

}