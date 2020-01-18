#include<cstdio>
#include<algorithm>
#define swap(x,y) (x ^= y,y ^= x,x^= y)
using std::sort;
struct edge{
	int fr,to,v;
	bool operator < (const edge b) const{
		return v > b.v;
	}
}e[50005];
struct node{
	int to,nxt;
}t[50005];
int f[50005],h[50005],w[50005],tot,cnt,siz[50005],son[50005],top[50005],d[50005],fa[50005];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);} 
}

inline void add(int a,int b)
{
	t[++tot].to = b;
	t[tot].nxt = h[a];
	h[a] = tot;
}

int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]);
 } 

void dfs1(int u)
{
	for(int i = h[u];i;i = t[i].nxt)
	{
		int v = t[i].to;
		d[v] = d[u] + 1;
		fa[v] = u;
		dfs1(v);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]])
			son[u] = v;
	}
	siz[u] = 1;
}

void dfs2(int u,int fa)
{
	top[u] = fa;
	if(!son[u]) return;
	dfs2(son[u],fa);
	for(int i = h[u];i;i = t[i].nxt)
	{
		int v = t[i].to;
		if(v == son[u]) continue;
		dfs2(v,v);
	}
}

inline int ask(int a,int b)
{
	if(find(a) != find(b)) return -1;
	while(top[a] != top[b])
	{
		if(d[top[a]] < d[top[b]]) swap(a,b);
		a = fa[top[a]];
	}
	if(d[a] > d[b]) swap(a,b);
	return w[a];
}

int main()
{
	int n,m,q,a,b;
	register int i;
	read(n),read(m);
	for(i = 1;i <= m;++ i)
		read(e[i].fr),read(e[i].to),read(e[i].v);
	for(i = 1;i <= n;++ i)
		f[i] = i;
	sort(e + 1,e + m + 1);
	cnt = n;
	for(i = 1;i <= m;++ i)
	{
		int u = find(e[i].fr),v = find(e[i].to);
		if(u == v) continue;
		++ cnt;
		f[u] = f[v] = f[cnt] = cnt;
		w[cnt] = e[i].v;
		add(cnt,u),add(cnt,v);
	}
	for(i = cnt;i >= 1;-- i)
		if(!d[i])
		{
			d[i] = 1;
			dfs1(i),dfs2(i,i);			
		}
	read(q);
	for(i = 1;i <= q;++ i)
	{
		read(a),read(b);
		printf("%d\n",ask(a,b));		
	}
	return 0;
}
