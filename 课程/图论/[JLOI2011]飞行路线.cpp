#include<queue>
#include<cstdio>
#include<cstring>
#define N 10005
#define M 50005
#define min(x,y) ((x) > (y) ? (y) : (x))
using std::priority_queue; 
struct edge{
	int to,nxt,v;
}e[M << 1];
struct node{
	int dis,pos,k;
	bool operator < (const node b) const{
		return dis > b.dis;
	}
};
bool vis[N][11];
int dis[N][11],h[N],tot,k,n,m,st,ed,ans = 0x7f7f7f7f;
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
}

inline void add(int a,int b,int c)
{
	e[++ tot].to = b;
	e[tot].v = c;
	e[tot].nxt = h[a];
	h[a] = tot;
}
priority_queue<node> q;
void dij()
{
	memset(dis,0x7f,sizeof dis);
	register int i;
	for(i = 0;i <= k;++ i)
		dis[st][i] = 0;
	q.push((node){0,st,0});
	while(!q.empty())
	{
		node u = q.top();q.pop();
		if(u.pos == ed)
		{
			ans = min(ans,dis[u.pos][u.k]);
			continue;
		}
		if(vis[u.pos][u.k]) continue;
		vis[u.pos][u.k] = true;
		for(i = h[u.pos];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(dis[v][u.k] > dis[u.pos][u.k] + e[i].v)
			{
				dis[v][u.k] = dis[u.pos][u.k] + e[i].v;
				q.push((node){dis[v][u.k],v,u.k});
			}
			if(u.k + 1 <= k&&dis[v][u.k + 1] > dis[u.pos][u.k])
			{
				dis[v][u.k + 1] = dis[u.pos][u.k];
				q.push((node){dis[v][u.k + 1],v,u.k + 1});				
			}
		}
	}
}

int main()
{
	int a,b,c;
	read(n),read(m),read(k);
	register int i;
	read(st),read(ed);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b),read(c);
		add(a,b,c),add(b,a,c);
	}
	dij();
	printf("%d",ans);
	return 0;
}

