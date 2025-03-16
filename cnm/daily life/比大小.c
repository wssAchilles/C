#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int max;
	if(a>b){
		if(a>c){
			max=a;
		}else{
			max=c;
		}
		
	}else{
		if(b<c){
			max=c;
		}else{
			max=b;
		}
	}
    printf("??????:%d",max);
}