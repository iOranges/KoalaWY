#include<vector>
#include<cstdio>
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))
using std::vector;
bool safe[305];
vector<int> floor[305];
int n,ans,h[305],tot,f[305],depth[305],siz[305],maxdep;
struct edge{
	int to,nxt;
}e[705];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs1(int u,int pre) 
{
	siz[u] = 1;
	f[u] = pre;
	depth[u] = depth[pre] + 1;
	maxdep = max(maxdep,depth[u]);
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		dfs1(v,u);
		siz[u] += siz[v];
	}
}

void dfs2(int dep,int cnt)
{
	if(dep > maxdep) {ans = min(ans,cnt);return;}
	bool cut = false;
	int sz = floor[dep].size();
	for(int i = 0;i < sz;++ i)
		if(safe[f[floor[dep][i]]]) safe[floor[dep][i]] = true;
	for(int i = 0;i < sz;++ i)
		if(!safe[floor[dep][i]])
		{
			safe[floor[dep][i]] = cut = true;
			dfs2(dep + 1,cnt - siz[floor[dep][i]]);
			safe[floor[dep][i]] = false;
		}
	if(!cut) {ans = min(ans,cnt);return;}
	for(int i = 0;i < sz;++ i)
		safe[floor[dep][i]] = false;
}

int main()
{
	int m,a,b;
	read(n),read(m);
	register int i;
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b);
		add(a,b),add(b,a);
	}
	dfs1(1,0);
	for(i = 1;i <= n;++ i)
		floor[depth[i]].push_back(i);
	ans = 0x7f7f7f7f;
	dfs2(2,n);
	printf("%d",ans);
	return 0;
}
