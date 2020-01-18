#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
using std::swap;
using std::max;
struct node{
	int e,to,v;
}e[30010],tree[50010];
int f[15010],h[15010],tot,cnt,p[15010][17],d[15010];
int find(int x)
{
	if(x!=f[x]) f[x] = find(f[x]);
	return f[x];
}

bool check(int a,int b)
{
	a = find(a);
	b = find(b);
	if(a!=b)
	{
		f[a] = b;
		return true;
	}
	return false;
}

bool cmp(node a,node b)
{
	if(a.v!=b.v)
		return a.v < b.v;
}

void add(int a,int b,int k)
{
	tree[++tot].e = b;
	tree[tot].to = h[a];
	tree[tot].v = k;
	h[a] = tot;
}

void dfs(int u,int pre)
{
	d[u] = d[pre] + 1;
	p[u][0] = pre;
	for(int i=1;(1<<i)<=d[u];i++)
		p[u][i] = p[p[u][i-1]][i-1];
	for(int i=h[u];i;i=tree[i].to)
		if(tree[i].e!=pre)
		{
			f[tree[i].e] = tree[i].v;
			dfs(tree[i].e,u);
		}
}

int lca(int a,int b)
{
	if(d[a]>d[b]) swap(a,b);
	for(int i=16;i>=0;i--)
		if(d[a] <= d[b]-(1<<i)) b = p[b][i];
	if(a==b) return a;
	for(int i=16;i>=0;i--)
		if(p[a][i] != p[b][i])
			a=p[a][i],b=p[b][i];
	return p[a][0];
}

int main()
{
	int n,m,k,i,a,b,c,minn;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		f[i] = i;
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].e,&e[i].to,&e[i].v);
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;i++)
		if(check(e[i].e,e[i].to))
		{
			add(e[i].e,e[i].to,e[i].v);
			add(e[i].to,e[i].e,e[i].v);
			cnt++;
			if(cnt>=n-1) break;
		}
	memset(f,0,sizeof f);
	dfs(1,0);
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&a,&b);
		c = lca(a,b);
		minn = -1 * 0x7fffff;
		while(a!=c)
		{
			minn = max(minn,f[a]);
			a = p[a][0];
		}
		while(b!=c)
		{
			minn = max(minn,f[b]);
			b = p[b][0];
		}
		printf("%d\n",minn);
	}
	return 0;
}
