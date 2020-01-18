#include<queue>
#include<cstdio>
#define SIZE 1<<20
#define N 10005
#define M 100005
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))
using std::queue;
char buf[SIZE],*S = buf,*T = buf;
inline char gc() {return S == T && (T = (S = buf) + fread(buf,1,SIZE,stdin),S == T) ? -1 : *S++;}
#define getc(stdin) gc()
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

struct node{
	int to,nxt;
}e[M << 1],E[M << 1];
bool instack[N];
int h[N],tot,v[N],w[N],cnt,bel[N],dfn[N],s[N],top,low[N],idx,f[N],H[N],TOT,r[N];
inline void add(int a,int b)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

inline void Add(int a,int b)
{
	E[++ TOT].to = b;
	E[TOT].nxt = H[a];
	H[a] = TOT;
}

void tarjan(int u)
{
	low[u] = dfn[u] = ++ idx;
	s[++ top] = u;
	instack[u] = true;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(instack[v])
			low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u])
	{
		w[++ cnt] += v[u];
		bel[u] = cnt;
		instack[u] = false;
		while(s[top] != u)
		{
			instack[s[top]] = false;
			bel[s[top]] = cnt;
			w[cnt] += v[s[top --]];
		}
		-- top;
	}
}
queue<int> q;

int main()
{
//	freopen("tarjan.in","r",stdin);
	int n,m,a,b,ans = 0;
	register int i,j;
	read(n),read(m);
	for(i = 1;i <= n;++ i)
		read(v[i]);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b);
		add(a,b);
	}
	for(i = 1;i <= n;++ i)
		if(!dfn[i]) tarjan(i);
	for(i = 1;i <= n;++ i)
		for(j = h[i];j;j = e[j].nxt)
		{
			int v = e[j].to;
			if(bel[v] == bel[i]) continue;
			Add(bel[i],bel[v]);
			++ r[bel[v]];
		}
	for(i = 1;i <= cnt;++ i)
		if(!r[i]) q.push(i),f[i] = w[i];
	while(!q.empty())
	{
		int u = q.front();q.pop();
		ans = max(ans,f[u]);
		for(i = H[u];i;i = E[i].nxt)
		{
			int v = E[i].to;
			-- r[v];
			f[v] = max(f[v],f[u] + w[v]);
			if(!r[v]) q.push(v);
		}
	}
	printf("%d",ans);
	return 0;
}
