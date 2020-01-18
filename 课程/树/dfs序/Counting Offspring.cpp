#include<cstdio>
#include<cstring>
int n,p,h[100005],tot,cnt,l[100005],r[100005],c[100005];
class node{
	public:
		int to,next;
		node(int u=0,int v=0,int k=0)
		{
			to = v;
			next = h[u];
			h[u] = k;
		}
}t[200005];

void dfs(int u,int pre)
{
	l[u] = ++cnt;
	for(int i=h[u];i;i=t[i].next)
		if(t[i].to!=pre)
			dfs(t[i].to,u);
	r[u] = cnt;
}

inline int lowbit(int x)
{
	return x & (-x);
}

void add(int x)
{
	for(int i=x;i<=cnt;i+=lowbit(i))
		c[i] ++;
}

int query(int x)
{
	int ans = 0;
	for(int i = x;i>0;i-=lowbit(i))
		ans += c[i];
	return ans;
}

int main()
{
	int i,a,b;
	while(true)
	{
		scanf("%d%d",&n,&p);
		if(!n&&!p) break;
		tot = cnt = 0;
		memset(h,0,sizeof h);
		memset(t,0,sizeof t);
		memset(c,0,sizeof c);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			++ tot;
			t[tot] = node(a,b,tot);
			++ tot;
			t[tot] = node(b,a,tot);
		}
		dfs(p,0);
		for(i=1;i<=n;i++)
		{
			printf("%d",query(r[i]) - query(l[i]-1));
			if(i!=n) putchar(' ');
			add(l[i]);
		}
		putchar('\n');
	}
	return 0;
}
