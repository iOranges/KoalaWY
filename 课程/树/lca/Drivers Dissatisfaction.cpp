#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(x,y) (x)>(y)?(x):(y)
#define swap(x,y) x^=y,y^=x,x^=y
using std::sort;
bool use[2400005];
int n,tot,d[200005],h[200005],p[200005][18],w[200005][18],f[200005];
struct edge{
	int to,v,c,fr,i;
	bool operator < (const edge a) const{
		return  this->v < a.v;
	}
}e[200005];

struct node{
	int to,v,c,next;
}t[400005];

void add(int a,int b,int v,int c)
{
	t[++tot].to = b;
	t[tot].c = c;
	t[tot].v = v;
	t[tot].next = h[a];
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
		if(t[i].to!=pre)
		{
			w[t[i].to][0] = t[i].v;
			dfs(t[i].to,u);
		}
}

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

int jump(int a,int b)
{
	int maxdep = -1;
	if(d[a] > d[b]) swap(a,b);
	for(int i=17;i>=0;i--)
		if(d[a] <= d[b]-(1<<i))
			maxdep=max(maxdep,w[b][i]),b = p[b][i];
	if(a == b) return maxdep;
	for(int i=17;i>=0;i--)
		if(p[a][i] != p[b][i])
		{
			maxdep = max(maxdep,max(w[a][i],w[b][i]));
			a = p[a][i],b = p[b][i];
		}
	return max(maxdep,max(w[a][0],w[b][0]));
}

int lca(int a,int b)
{
	if(d[a] > d[b]) swap(a,b);
	for(int i=17;i>=0;i--)
		if(d[a] <= d[b]-(1<<i))
			b = p[b][i];
	if(a == b) return a;
	for(int i=17;i>=0;i--)
		if(p[a][i] != p[b][i])
			a = p[a][i],b = p[b][i];
	return p[a][0];	
}

bool judge(int a,int b,int c)
{
	int x = lca(a,c),y = lca(b,c),z = lca(a,b);
	if(x == c&&y == z)
		return true;
	if(y == c&&x == z)
		return true;
	return false;
}

int main()
{
	int m,i,a,b,mini = 0,s,remove = 0;
	long long ans = 0,pre;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d",&e[i].v);
	for(i=1;i<=m;i++)
		scanf("%d",&e[i].c);
	for(i=1;i<=m;i++)
		scanf("%d%d",&e[i].fr,&e[i].to);
	for(i=1;i<=m;i++)
		e[i].i = i;
	for(i=1;i<=n;i++)
		f[i] = i;
	scanf("%d",&s);
	sort(e+1,e+m+1);
	for(i=1;i<=m;i++)
		if(check(e[i].fr,e[i].to))
		{
			use[i] = true;
			ans += 1ll * e[i].v;
			if(e[i].c < e[mini].c||!mini)
				mini = i;
			add(e[i].fr,e[i].to,e[i].v,e[i].c);
			add(e[i].to,e[i].fr,e[i].v,e[i].c);
		}
	dfs(1,0);
	pre = ans;
	for(i=1;i<=m;i++)
		if(!use[i]&&e[i].c < e[mini].c)
		{
			int maxdep = jump(e[i].fr,e[i].to);
			if(ans - 1ll * s / e[mini].c > pre - 1ll * maxdep + 1ll * e[i].v - 1ll * s / e[i].c)
				ans = pre - 1ll * maxdep + 1ll * e[i].v,mini = i,remove = maxdep;
		}
	printf("%lld\n",ans - 1ll * s / e[mini].c);
	use[mini] = true;
	bool flag = true;
	for(i=1;i<=m;i++)
		if(use[i])
		{
			if(i==mini) e[i].v -= s/e[i].c;
			else if(flag)
			{
				if(e[i].v == remove)
					if(judge(e[mini].fr,e[mini].to,e[i].fr)&&judge(e[mini].fr,e[mini].to,e[i].to))
					{
						flag  = false;continue;							
					}			
			}
			printf("%d %d\n",e[i].i,e[i].v);
		}
	return 0;
}
