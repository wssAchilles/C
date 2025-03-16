#include<stdio.h>
int main()
{
	int x;
	printf("请输入函数值：");
	scanf("%d",&x);
	int f;
	if (x<0){
		f=-1;
	}else if(x==0){
		f=0;
	}else
		f=2*x;
	
    printf("输出值为:%d",f);
}