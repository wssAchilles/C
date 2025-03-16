#include <stdio.h>
int main()
{
	int x, n, sum = 0, day = 0;
	double f;
	scanf("%d", &n);
	for (x = 2; sum <= n; day++)
	{
		sum = sum + x;
		x = x * 2;
	}
	f = 0.8 * (sum - x / 2) / (day - 1);
	printf("%.2f", f);
}