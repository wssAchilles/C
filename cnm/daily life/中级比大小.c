#include<stdio.h>
int main()
{
	int a,i,max,b;
	b=1;
	scanf("%d\n",&i);
	scanf("%d",&a);
	max=a;
L1:
    b=b+1;
	scanf("%d",&a);
	if(max<a){
	max=a;}
    if(b<i){
	goto L1;}
	
	
	printf("%d",max);


	
}