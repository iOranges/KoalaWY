#include<cstdio>
#include<iostream>
using std::swap;
struct node{
	int next,e;
}tree[200001],query[200001];
int h[100001],dp[100001],cnt,tot,h2[100001],f[100001];
bool visit[100001];
inline void read(int& x) {
    int f = 1; x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

inline int find(int x)	
{
	if(x != f[x]) f[x] = find(f[x]);
	return f[x];
}

inline void add(int a,int b)
{
	tree[++cnt].e = b;
	tree[cnt].next = h[a];
	h[a] = cnt;
}

inline void add2(int a,int b)
{
	query[++tot].e = b;
	query[tot].next = h2[a];
	h2[a] = tot;
}

void dfs(int u,int pre)
{
	for(int i = h[u];i;i = tree[i].next)
		if(tree[i].e != pre)
		{
			dfs(tree[i].e,u);
			f[tree[i].e] = u; 
		}
	visit[u] = true;	
	for(int i = h2[u] ; i ; i = query[i].next)
		if(visit[query[i].e])
		{
			int k = find(query[i].e);
			dp[u]++,dp[query[i].e]++;
			dp[k]-=2;
		}
}

void dfs2(int u,int pre)
{
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
		{
			dfs2(tree[i].e,u);
			dp[u] += dp[tree[i].e];
		}
}

int main()
{
	int i,n,m,a,b,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		f[i] = i;
	for(i=1;i<n;i++)
	{
		read(a),read(b);
		add(a,b),add(b,a);
	}
	for(i=1;i<=m;i++)
	{
		read(a),read(b);
		add2(a,b),add2(b,a);
	}
	dfs(1,0);
	dfs2(1,0);
	for(i=2;i<=n;i++)
	{ 
		if(dp[i] == 1) ans++;
		else if(dp[i] == 0) ans+=m;
	}
	printf("%d\n",ans);
	return 0;
}
