#include<cstdio>
#include<cstring>
#define swap(x,y) do{int temp = x;x = y;y = temp;}while(0)
int p[1005][10],h[1005],tot,d[1005];
struct node{
	int son,next;
}t[2005];

void add(int a,int b)
{
	t[++tot].son = b;
	t[tot].next = h[a];
	h[a] = tot;
}

void dfs(int u,int pre)
{
	d[u] = d[pre] + 1;
	p[u][0] = pre;
	for(int i=1;i<10;i++) p[u][i] = p[p[u][i-1]][i-1];
	for(int i=h[u];i;i=t[i].next)
		if(t[i].son!=pre)
			dfs(t[i].son,u);
}

int lca(int a,int b)
{
	if(d[a]>d[b]) swap(a,b);
	for(int i=9;i>=0;i--)
		if(d[a] <= d[b] - (1<<i)) b = p[b][i];
	if(b==a) return a;
	for(int i=9;i>=0;i--)
		if(p[a][i]!=p[b][i])
			a = p[a][i],b = p[b][i];
	return p[a][0];
}

int main()
{
	int n,i,m,a,j,b,o=0,T;
	scanf("%d",&T);
	for(o=1;o<=T;++o)
	{
		tot = 0;
		scanf("%d",&n);
		memset(p,0,sizeof p);
		memset(d,0,sizeof d);
		memset(h,0,sizeof h);
		memset(t,0,sizeof t);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			for(j=1;j<=a;j++)
			{
				scanf("%d",&b);
				add(i,b),add(b,i);
			}
		}
		dfs(1,0);
		printf("Case %d:\n",o);
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",lca(a,b));
		}
	}
	return 0;
}
