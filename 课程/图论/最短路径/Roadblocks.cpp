#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int v,next,to;
}e[200005];
queue<int> q;
bool visit[5001];
int h[5001],tot,dis[5001][2];

void add(int a,int b,int k)
{
	e[++tot].to = b;
	e[tot].v = k;
	e[tot].next = h[a];
	h[a] = tot;
}

int main()
{
	int n,m,i,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	memset(dis,0x7f,sizeof dis);
	visit[1] = true;
	dis[1][0] = 0;
	q.push(1);
	do{
		int u = q.front();
		visit[u] = false;
		q.pop();
		for(i=h[u];i;i=e[i].next)
		{
			int v = e[i].to;
			if(e[i].v + dis[u][0] < dis[v][0])
			{
				dis[v][1] = dis[v][0];
				dis[v][0] = e[i].v + dis[u][0];
				if(!visit[v]) visit[v] = true,q.push(v);
			}
			else if(e[i].v + dis[u][0] > dis[v][0] && e[i].v + dis[u][0] < dis[v][1])
			{
				dis[v][1] = e[i].v + dis[u][0];
				if(!visit[v]) visit[v] = true,q.push(v);
			}
			if(e[i].v + dis[u][1] < dis[v][1])
			{
				dis[v][1] = e[i].v + dis[u][1];
				if(!visit[v]) visit[v] = true,q.push(v);
			}
		}
	}while(!q.empty());
	printf("%d",dis[n][1]);
	return 0;
}
