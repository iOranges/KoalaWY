#include<cstdio>
#include<cstring>
#include<iostream>
using std::swap;
struct node{
	int next,e,v;
}tree[80005];
int d[40005],p[40005][16],n,h[40005],tot;
long long dis[40005]; 
void add(int a,int b,int k)
{
	tree[++tot].e = b;
	tree[tot].next = h[a];
	tree[tot].v = k;
	h[a] = tot; 
}

void dfs(int u,int pre)
{
	d[u] = d[pre] + 1;
	p[u][0] = pre;
	for(int i=1;(1<<i)<=d[u];i++)
		p[u][i] = p[p[u][i-1]][i-1];
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e != pre)
		{
			dis[tree[i].e] = dis[u] + tree[i].v;
			dfs(tree[i].e,u);
		}
}

int lca(int a,int b)
{
	if(d[a]>d[b]) swap(a,b);
	for(int i=15;i>=0;i--)
		if(d[a] <= d[b]-(1<<i)) b = p[b][i];
	if(a==b) return a;
	for(int i=15;i>=0;i--)
		if(p[a][i] != p[b][i])
			a = p[a][i],b = p[b][i];
	return p[a][0];
}

int main()
{
	int t,m,i,a,b,k;
	scanf("%d",&t);
	while(t--)
	{
		tot = 0;
		memset(d,0,sizeof d);
		memset(h,0,sizeof h);
		memset(p,0,sizeof p);
		scanf("%d%d",&n,&m);
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&k);
			add(a,b,k),add(b,a,k);
		}
		dfs(1,0);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			k = lca(a,b);
			printf("%lld\n",dis[a]+dis[b]-2*dis[k]);
		}
	}
	return 0;
 } 
