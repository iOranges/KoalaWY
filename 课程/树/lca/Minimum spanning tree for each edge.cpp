#include<cstdio>
#include<iostream>
#include<algorithm>
#define max(x,y) (x)>(y)?(x):(y)
#define swap(x,y) x^=y,y^=x,x^=y
using std::sort;
bool use[200005];
int h[200005],f[200005],tot,d[200005],w[200005][18],p[200005][18];
struct node{
	int son,v,next;
}t[400005];

struct edge{
	int fr,to,v,i;
	bool operator < (const edge b) const{
		return this->v < b.v;
	}
}e[200005],g[200005];

inline int find(int x)
{
	if(x!=f[x]) f[x] = find(f[x]);
	return f[x];
}

bool check(int a,int b)
{
	a = find(a),b = find(b);
	if(a!=b)
	{
		f[a] = b;
		return true;
	}
	return false;
 } 

inline void add(int a,int b,int c)
{
	t[++tot].son = b;
	t[tot].next = h[a];
	t[tot].v = c;
	h[a] = tot;
}

void dfs(int u,int pre)
{
	d[u] = d[pre] + 1;
	p[u][0] = pre;
	for(int i=1;i<18;i++)
	{
		p[u][i] = p[p[u][i-1]][i-1];
		w[u][i] = max(w[u][i-1],w[p[u][i-1]][i-1]);
	}
	for(int i=h[u];i;i=t[i].next)
		if(t[i].son!=pre)
		{
			w[t[i].son][0] = t[i].v;
			dfs(t[i].son,u);
		}
}

int jump(int a,int b)
{
	int ans = 0;
	if(d[a] > d[b]) swap(a,b);
	for(int i=17;i>=0;i--)
		if(d[a] <= d[b] - (1<<i))
			ans = max(ans,w[b][i]),b = p[b][i];
	if(a==b) return ans;
	for(int i=17;i>=0;i--)
		if(p[a][i]!=p[b][i])
		{
			ans = max(ans,max(w[a][i],w[b][i]));
			a = p[a][i],b = p[b][i];
		}
	return max(ans,max(w[a][0],w[b][0]));
}

int main()
{
	int n,m,i;
	long long ans = 0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].fr,&e[i].to,&e[i].v),e[i].i = i;
		g[i] = e[i];		
	}
	for(i=1;i<=n;i++)
		f[i] = i;
	sort(e+1,e+m+1);
	for(i=1;i<=m;i++)
		if(check(e[i].fr,e[i].to))
		{
			use[e[i].i] = true;
			ans += 1ll * e[i].v;
			add(e[i].fr,e[i].to,e[i].v);
			add(e[i].to,e[i].fr,e[i].v);
		}
	dfs(1,0);
	for(i=1;i<=m;i++)
		if(use[i])
			printf("%lld\n",ans);
		else
			printf("%lld\n",ans + 1ll * g[i].v - 1ll * jump(g[i].fr,g[i].to));
	return 0;
}
