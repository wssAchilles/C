#include <stdio.h>
int main()
{
	int a = 1, b = 3, d, i = 1, n;
	double sum, c = 1;
	scanf("%d", &n);
	for (sum = 0, d = -1; i <= n; i++)
	{
		c *= a / (double)b;
		c *= d;
		sum = (double)(sum + c);
		a++;
		b += 2;
	}
	printf("%.6f", -1 * sum);
}
