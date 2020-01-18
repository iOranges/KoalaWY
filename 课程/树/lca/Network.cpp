#include<cstdio> 
#include<iostream>
#include<algorithm>
using namespace std; 
struct node{
	int e,next;
}tree[1600010];
int h[800005],d[800005],p[800005][21],cnt,dis[800005],s[100005];

void add(int a,int b)
{
	tree[++cnt].next = h[a];
	tree[cnt].e = b;
	h[a] = cnt;
}

void dfs(int u,int pre)
{
	d[u] = d[pre]+1;
	p[u][0] = pre;
	for(int i=1;(1<<i)<=d[u];i++)
		p[u][i] = p[p[u][i-1]][i-1];
	for(int i = h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
			dfs(tree[i].e,u);
} 

int lca(int a,int b)
{
	if(d[a]>d[b]) swap(a,b);
	for(int i=20;i>=0;i--)
		if(d[a]<=d[b]-(1<<i)) b=p[b][i];
	if(a==b) return a;
	for(int i=20;i>=0;i--)
		if(p[a][i]!=p[b][i])
			a = p[a][i],b = p[b][i];
	return p[a][0];
}

int main()
{
	int n,m,i,a,b,k,c,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&dis[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	dfs(1,0);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&k,&a,&b);
		if(k==0) dis[a] = b;
		else
		{
			int tot = 1;
			c = lca(a,b);
			s[1] = dis[c];
			while(a!=c)
			{
				s[++tot] = dis[a];
				a = p[a][0];
			}
			while(b!=c)
			{
				s[++tot] = dis[b];
				b = p[b][0];
			}
			if(tot<k)
			{
				printf("invalid request!\n");
				continue;
			}
			sort(s+1,s+1+tot);
			printf("%d\n",s[tot-k+1]);
		}
	}
	return 0;
}
