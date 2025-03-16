#include <stdio.h>
#define N 10
int main()
{
	void sort(int a[N], int ud);
	int i, a[N], ud;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &ud);
	sort(a, ud);
	for(i=0;i<10;i++)
	{
		printf("%d,",a[i]);
	}
}	
void sort(int a[N], int ud)
{
	int  i, j, t;
	
		for (i = 0; i < 9; i++)
		{
			
			for (j = i + 1; j < 10; j++)
			{
				if ((ud==1&&a[i] > a[j]))
				{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				}
				else if(ud!=1&&a[i]<a[j])
				{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				}
			}
		}
	
}