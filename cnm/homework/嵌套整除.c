#include <stdio.h>
int main()
{
	int x;
	scanf("%d", &x);
	if (x % 3 == 0 && x % 5 == 0 && x % 7 == 0)
	{
		printf("ALL");
	}
	else if (x % 3 != 0 && x % 5 != 0 && x % 7 != 0)
	{
		printf("NONE");
	}
	else if (x % 3 == 0 && x % 5 != 0 && x % 7 == 0)
	{
		printf("3AND7");
	}
	else if (x % 3 != 0 && x % 5 == 0 && x % 7 == 0)
	{
		printf("5AND7");
	}
	else if (x % 3 == 0 && x % 5 == 0 && x % 7 != 0)
	{
		printf("3AND5");
	}
	else if (x % 3 == 0 && x % 5 != 0 && x % 7 != 0)
	{
		printf("3ONLY");
	}
	else if (x % 3 != 0 && x % 5 == 0 && x % 7 != 0)
	{
		printf("5ONLY");
	}
	else if (x % 3 != 0 && x % 5 != 0 && x % 7 == 0)
	{
		printf("7ONLY");
	}
}
