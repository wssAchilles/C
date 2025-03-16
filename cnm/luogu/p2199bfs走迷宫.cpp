#include<bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
int n,m;
char mz[16395/2][16395/2];
int jbx,jby,hpx,hpy;
bool vis[16395/2][16395/2];
bool check(int x,int y)
{
	for(int dir=0;dir<8;dir++)
	{
		int nx=x;
		int ny=y;
		if(nx==jbx&&ny==jby)return true;
		while(nx<=n&&nx>=1&&ny<=m&&ny>=1)
		{
			nx+=dx[dir];
			ny+=dy[dir];
			if(mz[nx][ny]=='X')break;
			if(nx==jbx&&ny==jby)return true;
		}
	}
	return false;
}
int main(void)
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)cin>>mz[i][j];
	}
	do
	{
		queue<int>qx;
		queue<int>qy;
		queue<int>step;
		cin>>jbx>>jby>>hpx>>hpy;
		if(jbx==0&&jby==0&&hpx==0&&hpy==0)break;
		memset(vis,false,sizeof(vis));
		if(check(hpx,hpy))
		{
			cout<<0<<endl;
			continue;
		}
		qx.push(hpx);
		qy.push(hpy);
		step.push(0);
		vis[hpx][hpy]=true;
		int tmp=false;
		while(!qx.empty())
		{
			int x=qx.front();
			int y=qy.front();
			int st=step.front();
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx<1||nx>n||ny<1||ny>m)continue;
				if(mz[nx][ny]=='X')continue;
				if(vis[nx][ny])continue;
				vis[nx][ny]=true;
				qx.push(nx);
				qy.push(ny);
				step.push(st+1);
				if(check(nx,ny))
				{
					cout<<st+1<<endl;
					tmp=true;
					break;
				}
			}
			if(tmp)
			{
				break;
			}
			qx.pop();
			qy.pop();
			step.pop();
		}
		if(!tmp)
		{
			cout<<"Poor Harry"<<endl;
		}
	}while(jbx!=0||jby!=0||hpx!=0||hpy!=0);
	return 0;
}
