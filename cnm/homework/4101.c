#include <stdio.h>
#define N 13

int main()
{
    int i;
	int a[N];
    double b[N-1];
    for (i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<N-1;i++)
    {
        b[i]=(double)a[i+1]/a[i];
    }
    for (i=0;i<N-1;) 
    {
        
		
		printf("%8.2f",b[i]);
        i++;
        if(i%3==0){
        printf("\n");}
    }
}