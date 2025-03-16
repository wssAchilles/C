#include <stdio.h>
//#define N 10
int main()
{
    int a[128];
    int *p1=a;
    int len=0;
    int *p2;
    for(p2=a;*p2!='@';p2++)
    {
        scanf("%d",p2);
        len++;
    }
    p2=a+len-2;
    while(p1<p2)
    {
        if(*p1!=*p2)
        {
            break;    
        }     
        p1++;
        p2--;
    } 
    if(p1<p2)
	{
        printf("no");
    }
   else
    {
        printf("yes");
    }
    return 0;
}
