#include<stdio.h>
int os(int o[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(o[i]%2!=0)
        {
            return 0;
            break;
        }
    }
	return 1;
}
int js(int j[],int size)
{
    for(int i=0;i<size;i++)
	{
		if(j[i]%2==0)
		{
			return 0;
			break;
		}
	}
	return 1;
}
int xzq(int n) {
    int o[128], j[128];
    int x = 0, y = 0;
    int temp = n;
    while (temp > 0) {
        j[x++] = temp % 10;
        temp = temp / 10;
        if (temp > 0) {
            o[y++] = temp % 10;
            temp = temp / 10;
        }
    }
    if (!os(o, y) || !js(j, x)) {
        return 0;
    }
    return 1;
}
int  main()
{
	int n;
	scanf("%d",&n);
	//int a[128];
	int cnt=0;
	for(int i=1;i<n;i++)
	{
		if(xzq(i))
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
	// for(int i=0;i<cnt;i++)
	// {
	// 	printf("%d,",a[i]);
	// }
}