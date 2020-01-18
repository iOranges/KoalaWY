#include<cstdio>
#include<cstring>
#define max(x,y) ((x) > (y) ? (x) : (y))
const int N = 1e6 + 5;
struct node{
	int to,nxt,v;
}e[N << 1];
bool inloop[N];
int h[N],dfn[N],tot,idx,loop[N],top,fa[N],q[N << 1],s[N];
long long dis[N],dist,f[N << 1],g[N];

inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b,int c)
{
	e[++ tot].to = b;
	e[tot].v = c;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void get_loop(int u,int pre)
{
	dfn[u] = ++ idx;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(i == (pre & 1 ? pre + 1 : pre - 1)) continue;
		if(dfn[v])
		{
			if(dfn[v] < dfn[u]) 
			{
				s[v] = e[i].v;
				continue;
			}
			loop[++ top] = v;
			inloop[v] = true;
			while(v != u)
			{
				f[top + 1] = f[top] + s[v]; 
				v = fa[v];
				inloop[v] = true;
				loop[++ top] = v;
			}
			f[top + 1] = f[top] + s[u]; 
			continue;
		}
		s[v] = e[i].v;
		fa[v] = u;
		get_loop(v,i);
	}
}

void dfs(int u,int pre)
{
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre||inloop[v]) continue;
		dfs(v,u);
		dis[u] = max(dis[u],max(g[u] + g[v] + e[i].v,dis[v]));
		g[u] = max(g[u],g[v] + e[i].v);
	}
}

void prepare()
{
	dist = f[top + 1];
	register int i;
	for(i = 1;i <= top;++ i)
		loop[i + top] = loop[i];
	for(i = 2;i <= top;++ i)
		f[i + top] = f[i] + dist;
}

int main()
{
	int n,a,b;
	read(n);
	register int i,j;
	for(i = 1;i <= n;++ i)
	{
		read(a),read(b);
		add(i,a,b),add(a,i,b);
	}
	long long ans = 0;
	for(i = 1;i <= n;++ i)
	{
		if(dfn[i]) continue;
		top = 0;dist = 0;
		get_loop(i,0);
		long long res = 0;
		for(j = 1;j <= top;++ j)
		{
			dfs(loop[j],0);
			res = max(res,dis[loop[j]]);	
		}
		prepare();
		register int l = 1,r = 0;
		q[0] = q[1] = 0;
		for(j = 1;j <= top * 2;++ j)
		{
			while(l <= r&&j - q[l] >= top) ++ l;
			if(l <= r) res = max(res,f[j] - f[q[l]] + g[loop[j]] + g[loop[q[l]]]);
			while(l <= r&&g[loop[q[r]]] - f[q[r]] < g[loop[j]] - f[j]) -- r;
			q[++ r] = j;
		}
		ans += res;
	}
	printf("%lld\n",ans);
	return 0;
}
