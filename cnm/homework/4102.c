#include <stdio.h>

int main()
{
    int a[10][10];
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            a[i][j]=i*2*n+(j+1)*2;
        }
    }
   
	for (i=0;i<n;i++)
    {
	   for (j=0;j<m;j++)
     	{
            printf("%6d",a[j][i]);
        }
        printf("\n");
    }
}