#include<cstdio>
#include<cstring>
#include<iostream>
using std::max;
struct node{
	int next,e,v;
}tree[20010];
int h[10001],tot,nd,Maxdep,ans[10001];
void add(int a,int b,int k)
{
	tree[++tot].e = b;
	tree[tot].next = h[a];
	h[a] = tot;
	tree[tot].v = k;
}

void dfs(int dep,int u,int pre)
{
	if(dep>Maxdep)
	{
		Maxdep = dep;
		nd = u;
	}
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
			dfs(dep+tree[i].v,tree[i].e,u);
}

void dfs2(int dep,int u,int pre)
{
	ans[u] = max(ans[u],dep);
	if(dep>Maxdep)
	{
		Maxdep = dep;
		nd = u;
	}
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
			dfs2(dep+tree[i].v,tree[i].e,u);
}

int main()
{
	int n,i,a,b;
	while(scanf("%d",&n)==1)
	{
		memset(h,0,sizeof h);
		memset(ans,0,sizeof ans);
		tot = 0,Maxdep = 0;
		for(i=2;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			add(i,a,b),add(a,i,b);
		}
		dfs(0,1,0);
		Maxdep = 0;
		dfs2(0,nd,0);
		Maxdep = 0;
		dfs2(0,nd,0);
		for(i=1;i<=n;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
