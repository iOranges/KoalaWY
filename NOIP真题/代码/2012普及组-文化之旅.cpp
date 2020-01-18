#include<bits/stdc++.h>
using namespace std;
int c[105],a[105][105],dis[105][105],vis[105][105][105];
int main()
{
	int n,k,m,s,t,x,y,z;
	scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(c[x]!=c[y])
		{
			if(!a[c[y]][c[x]]) dis[x][y]=min(dis[x][y],z);
			if(!a[c[x]][c[y]]) dis[y][x]=min(dis[y][x],z);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vis[i][j][c[i]]=vis[i][j][c[j]]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!a[c[k]][c[i]]&&!a[c[j]][c[k]]&&!vis[i][k][c[j]]&&!vis[k][j][c[i]]&&dis[i][k]+dis[k][j]<dis[i][j])
				{
					for(int l=1;l<=n;l++)
						vis[i][j][l]=vis[i][k][l]||vis[k][j][l];
					vis[i][j][c[k]]=1;
					dis[i][j]=dis[i][k]+dis[k][j];
				}
	if(dis[s][t]==0x3f3f3f3f){cout<<-1;}
	else printf("%d",dis[s][t]);
}
