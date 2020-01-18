#include<cstdio>
int n,m,v[200005],h[200005],tot,cnt,l[200005],r[200005],d[200005],c[200005];
struct node{
	public:
		int to,next;
		node(int u=0,int v=0,int k=0)
		{
			to = v;
			next = h[u];
			h[u] = k;
		}
}t[400005];

void dfs(int u,int pre)
{
	d[u] = d[pre] + 1;
	l[u] = ++cnt;
	for(int i=h[u];i;i=t[i].next)
		if(t[i].to != pre)
			dfs(t[i].to,u);
	r[u] = cnt;
}

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int k)
{
	for(int i=x;i<=n;i+=lowbit(i))
		c[i] += k;
}

int query(int x)
{
	int ans = 0;
	for(int i=x;i>0;i-=lowbit(i))
		ans += c[i];
	return ans;
}

int main()
{
	int a,b,i,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		++tot;
		t[tot] = node(a,b,tot);
		++tot;
		t[tot] = node(b,a,tot);
	}
	dfs(1,0);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&a);
		if(x==1)
		{
			scanf("%d",&b);
			if(d[a]&1)
				add(l[a],b),add(r[a]+1,-b);
			else
				add(l[a],-b),add(r[a]+1,b);
		}
		else
			if(d[a]&1)
				printf("%d\n",v[a] + query(l[a]));
			else
				printf("%d\n",v[a] - query(l[a]));
	}
	return 0;
}
