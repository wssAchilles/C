#include <stdio.h>
#define N 10

int main()
{
    int a[N+1]={10,20,30,40,50,60,70,80,90,100};
    int b,c,i;
    scanf("%d",&b);
    for(i=0;i<N;i++)
    {
        if(b<a[i])
        {
            break;
        }
    }
    if (i!=N)
    {
        for(c=N;c>=i;c--)
        {
            a[c]=a[c-1];
        }
    }
    a[i]=b;
    
    
    
    for (i=0;i<N+1;i++)
    {
        printf("%d ",a[i]);
    }
    
}
