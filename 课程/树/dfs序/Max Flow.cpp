#include<cstdio>
#define max(x,y) (x)>(y)?(x):(y)
#define swap(x,y) x^=y,y^=x,x^=y
int n,tot,cnt;
int h[50005],p[50005][16],d[50005],c[50005],maxx = -1;
struct node{
	int to,next;
	void add(int a,int b)
	{
		to = b;
		next = h[a];
		h[a] = tot;
	}
}t[200005];

void dfs(int u,int pre)
{
//	l[u] = ++ cnt;
	d[u] = d[pre] + 1;
	p[u][0] = pre;
	for(int i=1;i<16;i++)
		p[u][i] = p[p[u][i-1]][i-1];
	for(int i=h[u];i;i=t[i].next)
		if(t[i].to!=pre)
			dfs(t[i].to,u);
//	r[u] = cnt;
}

int lca(int a,int b)
{
	if(d[a] > d[b]) 
		swap(a,b);
	for(int i=15;i>=0;i--)
		if(d[a] <= d[b] - (1<<i))
			b = p[b][i];
	if(a == b) return a;
	for(int i=15;i>=0;i--)
		if(p[a][i] != p[b][i])
			a = p[a][i],b = p[b][i];
	return p[a][0];
}

void work(int u,int pre)
{
	for(int i=h[u];i;i=t[i].next)
		if(t[i].to!=pre)
		{
			work(t[i].to,u);
			c[u] += c[t[i].to];
		}
	maxx = max(maxx,c[u]);
}

int main()
{
	int m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		++ tot;
		t[tot].add(a,b);
		++ tot;
		t[tot].add(b,a);
	}
	dfs(1,0);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		int LCA = lca(a,b);
//		add(1,1),add(1,1),add(1,-1),add(1,-1);
		c[a] ++,c[b] ++;
		c[LCA] --,c[p[LCA][0]] --;
	}
	work(1,0);
	printf("%d",maxx);
	return 0;
}
