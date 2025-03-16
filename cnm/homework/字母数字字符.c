#include<stdio.h>
int main()
{
	char ch;
	int x=0,y=0,z=0;
	while((ch=getchar())!='\n')
	{
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		x++;
		else if(ch>='0'&&ch<='9')
		y++;
		else
		z++;
	}
	printf("%d,%d,%d",x,y,z);

}