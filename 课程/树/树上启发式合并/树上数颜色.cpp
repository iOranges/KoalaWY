#include<cstdio>
#define N 100005
struct node{
	int nxt,to;
}e[N << 1];
bool vis[N];
int c[N],cnt[N],tot,top,h[N],siz[N],son[N],ans[N];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs1(int u,int pre)
{
	siz[u] = 1;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		dfs1(v,u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]])
			son[u] = v; 
	}
}

void calc(int u,int pre,bool f)
{
	if(f){
		if(!cnt[c[u]]) ++ top;
		++ cnt[c[u]];
	}
	else{
		-- cnt[c[u]];
		if(!cnt[c[u]]) -- top;
	}
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre||vis[v]) continue;
		calc(v,u,f);
	}
}

void dfs2(int u,int pre,int keep)
{
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == son[u]||v == pre) continue;
		dfs2(v,u,0);
	}
	if(son[u]) dfs2(son[u],u,1);
	vis[son[u]] = true;
	calc(u,pre,1);
	vis[son[u]] = false;
	ans[u] = top;
	if(!keep) calc(u,pre,0);
}

int main()
{
	int n,q,a,b;
	read(n);
	register int i;
	for(i = 1;i < n;++ i)
	{
		read(a),read(b);
		add(a,b),add(b,a);
	}
	for(i = 1;i <= n;++ i)
		read(c[i]);
	dfs1(1,0);
	dfs2(1,0,1);
	read(q);
	for(i = 1;i <= q;++ i)
	{
		read(a);
		printf("%d\n",ans[a]);
	}
	return 0;
 } 
