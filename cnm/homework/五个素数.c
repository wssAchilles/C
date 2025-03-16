#include <stdio.h>
int main()
{
	int i, cs, cnt, sl;
	scanf("%d %d", &cs, &sl);

	for (cnt = 0; cnt < sl; cs++)
	{

		for (i = 2; i <= cs; i++)
		{
			if (cs % i == 0)
				break;
		}
		if (i == cs)
		{
			printf("%2d,", cs);
			cnt++;
		}
	}
}
