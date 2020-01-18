#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,h[50005],tot,f[50005],p[50005][16],d[50005],w[50005][16];
struct node{
	int son,v,next;
}t[100005];

struct edge{
	int fr,to,v;
	bool operator < (const edge b) const{
		return this->v < b.v;
	}
}e[100005];

inline void add(int a,int b,int k)
{
	t[++tot].son = b;
	t[tot].next = h[a];
	t[tot].v = k;
	h[a] = tot;
}

inline int find(int x)
{
	if(x!=f[x]) f[x] = find(f[x]);
	return f[x];
}

inline bool check(int a,int b)
{
	a = find(a),b = find(b);
	if(a!=b)
	{
		f[a] = b;
		return true;
	}
	return false;
}

void dfs(int u,int pre)
{
	d[u] = d[pre] + 1;
	p[u][0] = pre;
	for(int i=1;i<16;i++)
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
	int ans = -1 * 0x7ffffff;
	if(d[a] > d[b]) swap(a,b);
	for(int i=15;i>=0;i--)
		if(d[a] <= d[b] - (1<<i))
			ans = max(ans,w[b][i]),b = p[b][i];
	if(a==b) return ans;
	for(int i=15;i>=0;i--)
		if(p[a][i]!=p[b][i])
		{
			ans = max(ans,max(w[a][i],w[b][i]));
			a = p[a][i],b = p[b][i];
		}
	return max(ans,max(w[a][0],w[b][0]));
}

int main()
{
	bool flag = false;
	int i,a,b,c,q;
	while(~scanf("%d%d",&n,&m))
	{
		if(flag) puts("");
		else flag = true;
		tot = 0;
		memset(e,0,sizeof e);
		memset(t,0,sizeof t);
		memset(p,0,sizeof p);
		memset(d,0,sizeof d);
		memset(h,0,sizeof h);
		memset(w,0,sizeof w);
		for(i=1;i<=n;i++)
			f[i] = i;
		for(i=1;i<=m;i++)
			scanf("%d%d%d",&e[i].fr,&e[i].to,&e[i].v);
		sort(e+1,e+m+1);
		for(i=1;i<=m;i++)
			if(check(e[i].to,e[i].fr))
			{
				add(e[i].fr,e[i].to,e[i].v);
				add(e[i].to,e[i].fr,e[i].v);
			}
		dfs(1,0);
		scanf("%d",&q);
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",jump(a,b));
		}
	}
	return 0;
}
