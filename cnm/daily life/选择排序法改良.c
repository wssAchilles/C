#include <stdio.h>
int main()
{
	int a[10] = {0, 1, 23, 434, 3, 43243, 32, 11, 34, 23};
	int i, j, t;
	for (i = 0; i < 9; i++)
	{

		for (j = i + 1; j < 10; j++)
		{
			if (a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d,", a[i]);
	}
}
