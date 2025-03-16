#include<stdio.h>
int main()
{
	char x;
	scanf("%c",&x);
	if(x=='A'||x=='a')
	printf("America");
	else if(x=='B'||x=='b')
	printf("Britain");
	else if(x=='C'||x=='c')
	printf("China");
	else
	printf("Country");

}