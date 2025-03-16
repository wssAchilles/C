#include<stdio.h>
int leap(int year)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
	{return 1;}
	else
	{return 0;}
}
struct date
{
	int year;
	int month;
	int day;
}d;
int main()
{
	scanf("%d%d%d",&d.year,&d.month,&d.day);
	int a[12]={31,28,31,30,31,30,31,31,30,31};
	int sum=d.day,i=0;
	for(i=0;i<d.month-1;i++)
	{
		sum+=a[i];
	}
	if (leap(d.year)&&d.month>2)
	{
		sum++;
	}
	printf("%d",sum);
}