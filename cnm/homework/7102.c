#include <stdio.h>
#include<windows.h>
#define M 10
struct student
{
    int id;
    int score;
};
int fun(struct student *s, int low, int high, struct student *b)
{
	int cnt=0;
	int i;
	for(i=0;i<M;i++)
	{
		if(s[i].score>=low&&s[i].score<=high)
		{
			b[cnt++]=s[i];
		}
	}
	return cnt;
}  
void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
int main()
{
	color(18);
	struct student s[M],b[M];
	int i,low,high;
	for(i=0;i<M;i++)
	{
		scanf("%d%d",&s[i].id,&s[i].score);
	}
	scanf("%d%d",&low,&high);
	int cnt=fun(s,low,high,b);
	for(i=0;i<cnt;i++)
	{
		printf("%d,%d\n",b[i].id,b[i].score);
	}
	return 0;

}