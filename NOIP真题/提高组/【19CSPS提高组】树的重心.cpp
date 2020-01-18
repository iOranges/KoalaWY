#include<cstdio>
#include<cstring>
#define N 300005
#define max(x,y) ((x) > (y) ? (x) : (y))
struct node{
	int to,nxt;
}e[N << 1];
bool bel[N];
long long ans;
int n,h[N],tot,siz[N],f[N],rt,fison,scson,c1[N],c2[N];
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
}

inline int lowbit(int x)
{
	return x & (-x);
}

inline void add(int *c,int x,int k)
{
	for(register int i = x + 1;i <= n + 1;i += lowbit(i))
		c[i] += k;
}

inline int query(int *c,int x)
{
	int res = 0;
	for(register int i = x + 1;i > 0;i -= lowbit(i))
		res += c[i];
	return res;
}

inline void add(int a,int b)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs1(int u,int pre)
{
	siz[u] = 1,f[u] = 0;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		dfs1(v,u);
		siz[u] += siz[v];
		f[u] = max(f[u],siz[v]);
	}
	if(n - siz[u] <= (n >> 1)&&f[u] <= (n >> 1)&&!rt) rt = u;
}

void dfs2(int u,int pre)
{
	add(c1,siz[pre],-1);
	add(c1,n - siz[u],1);
	if(u ^ rt)
	{
		ans += u * 1ll * (query(c1,n - 2 * f[u]) - query(c1,n - 2 * siz[u] - 1));
		ans += u * 1ll * (query(c2,n - 2 * f[u]) - query(c2,n - 2 * siz[u] - 1));
		if(!bel[u]) bel[u] = bel[pre];
		ans += rt * 1ll * (n - siz[u] >= 2 * siz[bel[u] ? scson : fison]);
	}
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		dfs2(v,u);
	}
	add(c2,siz[u],1);
	add(c1,siz[pre],1);
	add(c1,n - siz[u],-1);	
	if(u ^ rt) ans -= u * 1ll * (query(c2,n - 2 * f[u]) - query(c2,n - 2 * siz[u] - 1));
}

int main()
{
	int t,a,b;
	register int i;
	read(t);
	while(t --)
	{
		tot = rt = 0;ans = 0;
		memset(h,0,sizeof h);
		memset(c1,0,sizeof c1);
		memset(c2,0,sizeof c2);
		memset(bel,0,sizeof bel);
		scanf("%d",&n);
		for(i = 1;i < n;++ i)
		{
			read(a),read(b);
			add(a,b),add(b,a);
		}
		dfs1(1,0);
		dfs1(rt,0);
		fison = scson = 0;
		for(i = h[rt];i;i = e[i].nxt)
		{
			if(siz[e[i].to] > siz[scson]) scson = e[i].to;	
			if(siz[scson] > siz[fison]) fison ^= scson ^= fison ^= scson;		
		}
		bel[fison] = true;
		for(i = 0;i <= n;++ i)	add(c1,siz[i],1);
		dfs2(rt,0);
		printf("%lld\n",ans);
	}
	return 0;
}

