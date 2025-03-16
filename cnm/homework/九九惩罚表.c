#include <stdio.h>
int main()
{
	int x, y;
	for (x = 1; x <= 9; x++)
	{
		for (y = 1; y <= 9; y++)
		{
			if (x > y)
				printf("        ");
			else
				printf("%d*%d=%2d  ", x, y, x * y);
		}
		printf("\n");
	}
}
