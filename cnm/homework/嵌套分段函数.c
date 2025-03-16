#include <stdio.h>
int main()
{
	double x, y;
	scanf("%lf", &x);
	if (x <= 0)
	{
		y = -(1 / 3.00) * x + 5;
	}
	else if (x > 0 && x <= 10)
	{
		y = (1 / 3.00) * x;
	}
	else if (x > 10 && x <= 20)
	{
		y = (1 / 3.00) * x - 5;
	}
	else if (x > 20)
		y = (1 / 3.00) * x - 10;

	printf("%.2f", y);
}
