#include <stdio.h>
#include <math.h>
// int main()
// {
// 	int n;
// 	scanf("%d",&n);
// 	int m;
// 	m=3*pow(2,n-1)-2;
// 	printf("%d",m);
// }

int main()
{
	int a[31];
	int sum = 0;
	int cnt = 0;
	while (scanf("%d", &a[cnt]) !=EOF)
	{
		sum += a[cnt];
		cnt++;
	}
	int s = sum * pow(2, cnt - 1);
	printf("%d", s);
}

