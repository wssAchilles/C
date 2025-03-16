#include<stdio.h>
struct student
{
	int xh;
	char xm[128];
	int cj[128];
	int sum;
}stu[1];
int main()
{
	
	scanf("%d\n",&stu[1].xh);
	getchar();
	gets(stu[1].xm);
	scanf("%d\n",&stu[1].cj);
}