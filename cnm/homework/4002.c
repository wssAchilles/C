#include <stdio.h>
#define M 4
#define N 6

int main()
{
    double score[M][N];
    int i,j;
	for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        { 
            scanf("%lf",&score[i][j]);
        }
    }
    for(i=0;i<M;i++)
    {
        double sum=0;
        for(j=0;j<N;j++)
        {
            printf("%7.2f",score[i][j]);
            sum+=score[i][j];
        }
        printf("%7.2f\n",sum/N);
    }
    for (i=0;i<N;i++)
    {
        double sum=0;
        for (j=0;j<M;j++)
        {
            sum+=score[j][i];
        }
        printf("%7.2f",sum/M);
    }
    
}