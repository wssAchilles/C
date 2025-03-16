#include<stdio.h>
#include<string.h>
#define N 20
int main()
{
	int x,y,n,tot=0;
	scanf("%d",&n);
	int a[N][N];
	memset(a,0,sizeof(a));
	x=0,y=n-1,tot=1;
	a[0][n-1]=1;
	while(tot<n*n)
	{
		while(x<n-1&&(!a[x+1][y])) {a[++x][y]=++tot;}
		while(y>0&&(!a[x][y-1])  ) {a[x][--y]=++tot;}
		while(x>0&&(!a[x-1][y])  ) {a[--x][y]=++tot;}
		while(y<n-1&&(!a[x][y+1])) {a[x][++y]=++tot;}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
}