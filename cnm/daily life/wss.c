#include<stdio.h>
struct student
{
	char name[128];
	int score[128];
	int sum;
};
int main()
{
	int m,maxi;
	scanf("%d",&m);
	struct student stu[m];
	for(int i=0;i<m;i++)
	{
		scanf("%s",stu[i].name);
		stu[i].sum=0;
		for(int j=0;j<3;j++)
		{
			scanf("%d",&stu[i].score[j]);
			stu[i].sum+=stu[i].score[j];
		}
	}
	int max=stu[0].sum;
	for(int i=0;i<m;i++)
	{
		if(max<stu[i].sum)
		{
			max=stu[i].sum;
			maxi=i;
		}
	}
	printf("%s ",stu[maxi].name);
	for(int i=0;i<3;i++)
	{
		printf("%d ",stu[maxi].score[i]);
	}
}