//Bellman-Ford(福特）算法
//可以求出存在负权边的图  但是负权回路不行 
#include<bits/stdc++.h>
using namespace std;
double a[101][3];//横纵坐标
double dis[10001],w[10001];
//dis[i] 源点到i的最短路 ，w[i]第i条边的长度
int f[10001][3]; 
//  f[i][1] f[i][2]第i条边的起点和终点 
int  n,m,x,y,s,t; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i][1]>>a[i][2];
	cin>>m;
	memset(dis,0x7f,sizeof dis);
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		f[i][1]=x;
		f[i][2]=y;
		w[i]=sqrt(pow(a[x][1]-a[y][1],2)+pow(a[x][2]-a[y][2],2));		
	}
	cin>>s>>t;
	dis[s]=0;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
		{
			int u=f[j][1],v=f[j][2];
			if(dis[u]+w[j]<dis[v]) dis[v]=dis[u]+w[j];
			if(dis[v]+w[j]<dis[u]) dis[u]=dis[v]+w[j];
		}
	printf("%.2lf\n",dis[t]);
	return 0;
} 
