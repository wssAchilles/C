#include <stdio.h>
int main()
{
	int m, n, i, p, sum = 0, cj;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
	{
		for (p = 0; p < n; p++)
		{
			scanf("%d", &cj);
			sum += cj;
		}
		printf("%.2f", sum / (double)n);
		sum = 0;
	}
}