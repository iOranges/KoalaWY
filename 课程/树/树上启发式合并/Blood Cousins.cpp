#include<vector>
#include<cstdio>
#include<cstring>
#define N 100005
using std::vector;
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

struct edge{
	int to,nxt;
}e[N];
struct node{
	int id,dep;
};
char ch[25];
bool vis[N];
int h[N],tot,n,q,d[N],siz[N],son[N],ans[N],cnt[N],p[N][17];
vector<node> query[N];

inline void add(int a,int b)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs1(int u,int pre)
{
	siz[u] = 1;
	p[u][0] = pre;
	for(register int i = 1;i <= 16;++ i)
		p[u][i] = p[p[u][i-1]][i-1];
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		d[v] = d[u] + 1;
		dfs1(v,u);
		siz[u] += siz[v];
		if(!son[u]||siz[v] > siz[son[u]])
			son[u] = v;
	}
}

void calc(int u,int pre,int val)
{
	cnt[d[u]] += val;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre||vis[v]) continue;
		calc(v,u,val);
	 } 
}

void dfs2(int u,int pre,bool keep)
{
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre||son[u] == v) continue;
		dfs2(v,u,0);
	}
	if(son[u]) dfs2(son[u],u,1);
	vis[son[u]] = true;
	calc(u,pre,1);
	vis[son[u]] = false;
	for(register int i = 0;i < query[u].size();++ i)
		ans[query[u][i].id] = cnt[query[u][i].dep];
	if(!keep) calc(u,pre,-1);
}

inline int getfa(int a,int k)
{
	for(register int i = 16;i >= 0;-- i)
		if(k - (1 << i) >= 0)
			k -= (1 << i),a = p[a][i];
	return a;
}

int main()
{
	int a,len,k;
	read(n);
	register int i,j;
	for(i = 1;i <= n;++ i)
		read(a),add(a,i);
	dfs1(0,0);
	read(q);
	for(i = 1;i <= q;++ i)
	{
		read(a),read(k);
		if(d[a] - k < 1) ans[i] = 1;
		else query[getfa(a,k)].push_back((node){i,d[a]});
	}
	dfs2(0,0,1);
	for(i = 1;i <= q;++ i)
		printf("%d\n",ans[i] - 1);
	return 0;
}
