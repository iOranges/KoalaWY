#include<cstdio>
#include<cstring>
#define swap(x,y) do{int temp = x;x = y;y = temp;}while(0)
int p[50005][16],h[50005],tot,dis[50005],d[50005];
struct node{
	int son,next,v;
}t[100005];

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
	for(int i=1;i<16;i++) p[u][i] = p[p[u][i-1]][i-1];
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
	for(int i=15;i>=0;i--)
		if(d[a] <= d[b] - (1<<i)) b = p[b][i];
	if(b==a) return a;
	for(int i=15;i>=0;i--)
		if(p[a][i]!=p[b][i])
			a = p[a][i],b = p[b][i];
	return p[a][0];
}

int main()
{
	bool flag = false;
	int n,i,m,a,b,c;
	while(~scanf("%d",&n))
	{
		if(flag) printf("\n");
		else flag = true;
		tot = 0;
		memset(p,0,sizeof p);
		memset(d,0,sizeof d);
		memset(h,0,sizeof h);
		memset(t,0,sizeof t);
		memset(dis,0,sizeof dis);
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			a+=1,b+=1;
			add(a,b,c),add(b,a,c);
		}
		dfs(1,0);
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			a+=1,b+=1,c+=1;
			printf("%d\n",dis[a] + dis[b] + dis[c] - dis[lca(a,b)] - dis[lca(a,c)] - dis[lca(b,c)]);
		}
	}
	return 0;
}
