#include<vector>
#include<cstdio>
#define N 500005
using std::vector;
struct edge{
	int to,nxt;
}e[N];
struct node{
	int id,dep;
};
vector<node> query[N];
char ch[N]; 
bool vis[N],ans[N];
int w[N],d[N],tot,h[N],siz[N],son[N],cnt[N][27];
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
	d[u] = d[pre] + 1;
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

void calc(int u,int pre,int val)
{
	cnt[d[u]][w[u]] += val;
	for(int i =h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre||vis[v]) continue;
		calc(v,u,val);
	}
}

bool check(int s[])
{
	int res = 0;
	register int i;
	for(i = 1;i <= 26;++ i)
	{
		if(s[i] & 1) ++res;
		if(res > 1) return false;
	}
	return true;
}

void dfs2(int u,int pre,bool keep)
{
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre||v == son[u]) continue;
		dfs2(v,u,0);
	}
	if(son[u]) dfs2(son[u],u,1);
	vis[son[u]] = true;
	calc(u,pre,1);
	vis[son[u]] = false;
	for(register int i = 0;i < query[u].size();++ i)
		ans[query[u][i].id] = check(cnt[query[u][i].dep]);
	if(!keep) calc(u,pre,-1);
}

int main()
{
	int n,q,a,b;
	read(n),read(q);
	register int i;
	for(i = 2;i <= n;++ i)
	{
		read(a);
		add(a,i);
	}
	scanf("%s",ch + 1);
	for(i = 1;i <= n;++ i)
		w[i] = ch[i] - 'a' + 1;
	dfs1(1,0);
	for(i = 1;i <= q;++ i)
	{
		read(a),read(b);
		query[a].push_back((node){i,b});
	}
	dfs2(1,0,1);
	for(i = 1;i <= q;++ i)
		puts(ans[i] ? "Yes" : "No");
	return 0;
}
