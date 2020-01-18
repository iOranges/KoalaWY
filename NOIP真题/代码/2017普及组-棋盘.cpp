#include<bits/stdc++.h>
using namespace std;
#define inf 0x7f7f7f7f
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int f[110][110];
int color[110][110];
int m,n,ans=inf;
void dfs(int x,int y,int sum,bool flag)
{
	if(x<1||y<1||x>m||y>m) return;
	if(!color[x][y]) return;
	if(sum>=f[x][y]) return;
	f[x][y]=sum;
	if(x==m&&y==m)
	{
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(color[nx][ny])
		{
			if(color[nx][ny]==color[x][y]) dfs(nx,ny,sum,false);
			else dfs(nx,ny,sum+1,false);
		}
		else if(!color[nx][ny]&&!flag)
		{
			color[nx][ny]=color[x][y];
			dfs(nx,ny,sum+2,true);
			color[nx][ny]=0;
		}
	}
}
int main()
{
	memset(f,0x7f,sizeof f);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		color[x][y]=z+1;
	}
	dfs(1,1,0,false);
	if(ans==inf) cout<<-1;
	else cout<<ans;
}
