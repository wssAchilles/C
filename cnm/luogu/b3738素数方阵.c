#include <stdio.h>
#include <string.h>
int ss(int n)
{
	if (n < 2)
	{
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
			break;
		}
	}
	return 1;
}
int main()
{
	int n, x, y, cnt = 0;
	scanf("%d", &n);
	int b[n * n], a[n][n];
	for (int i = 2; cnt < n * n; i++)
	{
		if (ss(i))
		{
			b[cnt++] = i;
		}
	}
	cnt = 0;
	memset(a, 0, sizeof(a));
	a[x = 0][y = 0] = b[cnt];
	while (cnt < n * n - 1)
	{
		while (y < n - 1 && (!a[x][y + 1]))
		{
			a[x][++y] = b[++cnt];
		}
		while (x < n - 1 && (!a[x + 1][y]))
		{
			a[++x][y] = b[++cnt];
		}
		while (y > 0 && (!a[x][y - 1]))
		{
			a[x][--y] = b[++cnt];
		}
		while (x > 0 && (!a[x - 1][y]))
		{
			a[--x][y] = b[++cnt];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
// #include <stdio.h>
// #include <string.h>
// int is_prime(int n)
// {
//     if (n < 2)
//         return 0;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main()
// {
//     int n, p, q;
//     scanf("%d%d%d", &n, &p, &q);

//     int b[n * n], a[n][n];
//     int cnt = 0;

//     for (int i = 2; cnt < n * n; i++)
//     {
//         if (is_prime(i))
//         {
//             b[cnt++] = i;
//         }
//     }

//     memset(a, 0, sizeof(a));
//     cnt = 0;
//     int x = 0, y = 0;
//     a[x][y] = b[cnt];
//     while (cnt < n * n -1)
//     {
//         while (y < n - 1 && a[x][y + 1] == 0)
//         {
//             a[x][++y] = b[++cnt];
//         }
//         while (x < n - 1 && a[x + 1][y] == 0)
//         {
//             a[++x][y] = b[++cnt];
//         }
//         while (y > 0 && a[x][y - 1] == 0)
//         {
//             a[x][--y] = b[++cnt];
//         }
//         while (x > 0 && a[x - 1][y] == 0)
//         {
//             a[--x][y] = b[++cnt];
//         }
//     }
//     printf("%d\n", a[p - 1][q - 1]);
//     return 0;
// }
