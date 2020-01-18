#include<cstdio>
#include<cstring>
#define swap(x,y) do{int temp = x;x = y;y = temp;}while(0)
int p[500005][19],h[500005],tot,d[500005];
struct node{
	int son,next;
}t[1000005];

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
	for(int i=1;i<19;i++) p[u][i] = p[p[u][i-1]][i-1];
	for(int i=h[u];i;i=t[i].next)
		if(t[i].son!=pre)
			dfs(t[i].son,u);
}

int lca(int a,int b)
{
	if(d[a]>d[b]) swap(a,b);
	for(int i=18;i>=0;i--)
		if(d[a] <= d[b] - (1<<i)) b = p[b][i];
	if(b==a) return a;
	for(int i=18;i>=0;i--)
		if(p[a][i]!=p[b][i])
			a = p[a][i],b = p[b][i];
	return p[a][0];
}

int main()
{
	int n,i,m,a,b,s;
	scanf("%d%d%d",&n,&m,&s);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	dfs(s,0);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}
