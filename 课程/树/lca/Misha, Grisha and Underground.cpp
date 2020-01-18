#include<cstdio>
#include<cstring>
#define max(x,y) (x)>(y)?(x):(y)
#define swap(x,y) do{int temp = x;x = y;y = temp;}while(0)
int p[100005][17],h[100005],tot,dis[100005],d[100005];
struct node{
	int son,next,v;
}t[200005];

void add(int a,int b,int k)
{
	t[++tot].son = b;
	t[tot].next = h[a];
	h[a] = tot;t[tot].v = k;
}

void dfs(int u,int pre)
{
	d[u] = d[pre] + 1;
	p[u][0] = pre;
	for(int i=1;i<17;i++) p[u][i] = p[p[u][i-1]][i-1];
	for(int i=h[u];i;i=t[i].next)
		if(t[i].son!=pre)
		{
			dis[t[i].son] = dis[u] + t[i].v;
			dfs(t[i].son,u);
		}
}

int lca(int a,int b)
{
	if(d[a]>d[b]) swap(a,b);
	for(int i=16;i>=0;i--)
		if(d[a] <= d[b] - (1<<i)) b = p[b][i];
	if(b==a) return a;
	for(int i=16;i>=0;i--)
		if(p[a][i]!=p[b][i])
			a = p[a][i],b = p[b][i];
	return p[a][0];
}

int main()
{
	int n,i,m,a,b,c,ac,ab,bc;
	scanf("%d%d",&n,&m);		
	for(i=2;i<=n;i++)
	{
		scanf("%d",&a);
		add(i,a,1),add(a,i,1);
	}
	dfs(1,0);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		ab = lca(a,b),bc = lca(b,c),ac = lca(a,c);
		int da = dis[a] + dis[bc] - dis[ac] - dis[ab] + 1;
		int db = dis[b] + dis[ac] - dis[bc] - dis[ab] + 1;
		int dc = dis[c] + dis[ab] - dis[ac] - dis[bc] + 1;
		printf("%d\n",max(max(da,db),dc));
	}
	return 0;
}
