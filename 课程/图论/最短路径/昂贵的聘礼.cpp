#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node
{
	int v,to,next;
}e[10010];
bool visit[101];
int h[101],w[101],dis[101],tot;

void add(int a,int b,int k)
{
	e[++tot].to = b;
	e[tot].v = k;
	e[tot].next = h[a];
	h[a] = tot;
}

int spfa(int low,int high)
{
	memset(visit,0,sizeof visit);
	memset(dis,0x7f,sizeof dis);
	queue<int> q;
	visit[1] = true;
	dis[1] = 0;
	q.push(1);
	do{
		int u = q.front();
		q.pop();
		visit[u] = false;
		for(int i=h[u];i;i=e[i].next)
		{
			int v =e[i].to;
			if(w[v] >= low && w[v] <= high &&dis[u] + e[i].v < dis[v])
			{
				dis[v] = dis[u] + e[i].v;
				if(!visit[v])
					visit[v] = true,q.push(v);
			}
		}
	}while(!q.empty());
	return dis[0];
}

int main()
{
	int m,n,a,b,c,i,j,mincost = 0x7fffffff;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&w[i],&c);
		add(i,0,a);
		for(j=1;j<=c;j++)
		{
			scanf("%d%d",&a,&b);
			add(i,a,b);
		}
	}
	w[0] = w[1];
	for(i=w[1]-m;i<=w[1];i++)
		mincost = min(spfa(i,i+m),mincost);
	printf("%d",mincost);
	return 0;
}
