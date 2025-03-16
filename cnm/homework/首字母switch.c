#include<stdio.h>
int main()
{
	char x;
	scanf("%c",&x);
	switch (x)
	{
	case 'a':
	case 'A':
	printf("America");break;
	
	case'b':
	case'B':printf("Britain");break;
	
	case 'c':
	case 'C':printf("China");break;
	
	default:printf("Country");break;
		                           
	}
}