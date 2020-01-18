#include<cstdio>
#include<cstring>
int n,tot,h[50005],cnt,l[50005],r[50005],g[50005];
struct node{
	int l,r,w;
}t[50005<<2];

void build(int l,int r,int rt)
{
	t[rt].l = l,t[rt].r = r;
	if(l == r)
		return;
	int mid = (l+r) >> 1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
}

void update(int x,int y,int rt,int c)
{
	int l = t[rt].l,r = t[rt].r;
	if(l == r)
	{
		t[rt].w = c;
		return;
	}
	int mid = (l+r) >> 1;
	if(mid>=y) update(x,y,rt<<1,c);
	else if(mid<x) update(x,y,rt<<1|1,c);
	else update(x,mid,rt<<1,c),update(mid+1,y,rt<<1|1,c);
}

int query(int x,int rt)
{
	int l = t[rt].l,r = t[rt].r;
	if(l==r)
		return t[rt].w;
	int mid = (l + r) >> 1;
	if(mid >= x) return query(x,rt<<1);
	else return query(x,rt<<1|1);
}

struct edge{
	int to,next;
	edge(int u=0,int v=0,int k=0)
	{
		to = v;
		next = h[u];
		h[u] = k;
	}
}e[50005];

void dfs(int u)
{
	l[u] = ++ cnt;
	for(int i=h[u];i;i=e[i].next)
		dfs(e[i].to);
	r[u] = cnt;
}

void clear()
{
	memset(t,0,sizeof t);
	memset(h,0,sizeof h);
	memset(g,0,sizeof g);
	memset(e,0,sizeof e);
	tot = cnt = 0;
}

int main()
{
	char ch[10];
	int T,i,o,m,a,b;
	scanf("%d",&T);
	for(o=1;o<=T;o++)
	{
		clear();
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			++ tot;
			e[tot] = edge(b,a,tot);
			g[a] ++;	
		}
		for(i=1;i<=n;i++)
			if(!g[i])
			{
				dfs(i);		
				break;		
			}
		build(1,cnt,1);
		scanf("%d",&m);
		printf("Case #%d:\n",o);
		for(i=1;i<=m;i++)
		{
			scanf("%s",ch);
			if(ch[0] == 'C')
			{
				scanf("%d",&a);
				b = query(l[a],1);
				if(b) printf("%d\n",b);
				else printf("-1\n");
			}
			else
			{
				scanf("%d%d",&a,&b);
				update(l[a],r[a],1,b);
			}
		}
	}
	return 0;
}
