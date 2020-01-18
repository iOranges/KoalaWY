#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(x,y) (x)<(y)?(x):(y)
#define swap(x,y) do{int temp = x;x = y;y = temp;}while(0)
using namespace std;
bool s[100005],visit[100005];
long long dis[43][100005];
int p[100005][17],h[100005],tot,d[100005],f[100005];
struct node{
	int son,next;
	long long v;
}t[200005];
struct edge{
	int fr,to,v;
	bool operator < (const edge b) const
	{
		return this->v < b.v;
	}
}e[100005];
struct Pair{
	int i;
	long long dis;
	bool operator < (const Pair b) const
	{
		return this->dis > b.dis;
	} 
};

void add(int a,int b,int k)
{
	t[++tot].son = b;
	t[tot].next = h[a];
	h[a] = tot;t[tot].v = (long long)k;
}

void dfs(int u,int pre)
{
	d[u] = d[pre] + 1;
	p[u][0] = pre;
	for(int i=1;i<17;i++) p[u][i] = p[p[u][i-1]][i-1];
	for(int i=h[u];i;i=t[i].next)
		if(t[i].son!=pre)
		{
			dis[0][t[i].son] = dis[0][u] + t[i].v;
			dfs(t[i].son,u);
		}
}

int lca(int a,int b)
{
	if(d[a]>d[b]) swap(a,b);
	for(int i=16;i>=0;i--)
		if(d[a] <= d[b] - (1<<i)) b = p[b][i];
	if(b==a) return a;
	for(int i=16;i>=0;i--)
		if(p[a][i]!=p[b][i])
			a = p[a][i],b = p[b][i];
	return p[a][0];
}

int find(int x)
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

void kruskal(int m)
{
	for(int i=1;i<=m;i++)
		if(check(e[i].fr,e[i].to))
			add(e[i].fr,e[i].to,e[i].v),add(e[i].to,e[i].fr,e[i].v);
		else
			s[i] = true;		
}

void dijkstra(int id,int k)
{
	memset(visit,false,sizeof visit);
	memset(dis[id],0x7f,sizeof dis[id]);
	priority_queue<Pair> q;
	dis[id][k] = 0;
	q.push((Pair){k,dis[id][k]});
	do{
		Pair u = q.top();
		q.pop();
		if(visit[u.i]) continue;
		visit[u.i] = true;
		for(int i=h[u.i];i;i=t[i].next)
		{
			int v = t[i].son;
			if(dis[id][v] > dis[id][u.i] + t[i].v)
			{
				dis[id][v] = dis[id][u.i] + t[i].v;
				q.push((Pair){v,dis[id][v]});
			}
		}
	}while(!q.empty());
}

int main()
{
	int n,i,m,a,b,q,op=0,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].fr,&e[i].to,&e[i].v);
	sort(e+1,e+m+1);
	for(i=1;i<=n;i++)
		f[i] = i;
	kruskal(m); 
	dfs(1,0);
	for(i=1;i<=m;i++)
		if(s[i])
			add(e[i].fr,e[i].to,e[i].v),add(e[i].to,e[i].fr,e[i].v);
	for(i=1;i<=m;i++)
		if(s[i])
		{
			dijkstra(++op,e[i].fr);
			dijkstra(++op,e[i].to);
		}	
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		long long ans = dis[0][a] + dis[0][b] - 2*dis[0][lca(a,b)];
		for(j=1;j<=op;j++)
			ans = min(ans,dis[j][a]+dis[j][b]);
		printf("%lld\n",ans);
	}
	return 0;
}
