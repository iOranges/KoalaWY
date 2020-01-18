#include<queue>
#include<cstdio>
#include<cstring>
using std::queue;
using std::priority_queue;
struct node{
	int to,nxt;
}e[200005],E[200005];
struct Pair{
	int dis,pos;
	Pair(int d,int p) :dis(d),pos(p) {}
	bool operator < (const Pair b) const{
		return dis > b.dis;
	}
};
bool vis[200005],CanUse[200005],checked[200005];
int h[200005],H[200005],tot,TOT,st,ed,dis[200005];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

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

void Fake_Topo()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(ed);
	vis[ed] = true; 
	register int i;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(i = H[u];i;i = E[i].nxt)
		{
			int v = E[i].to;
			if(!vis[v])
			{
				vis[v] = true;
				q.push(v);
			}
		}
	}
} 

void Twice_judge()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(st);
	register int i;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		CanUse[u] = vis[u];
		checked[u] = true;
		if(!CanUse[u]) continue;
		for(i = h[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(!vis[v])
				CanUse[u] = false;
			if(!checked[v]) q.push(v);
		}
	}
}
priority_queue<Pair> q;
void dij()
{
	memset(dis,0x7f,sizeof dis);
	dis[st] = 0;
	register int i;
	q.push(Pair(0,st));
	while(!q.empty())
	{
		int u = q.top().pos;
		q.pop();
		if(!CanUse[u]) continue;
		for(i = h[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				q.push(Pair(dis[v],v));
			}
		}
	}
}

int main()
{
	int n,m,a,b;
	read(n),read(m);
	register int i;
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b);
		add(a,b);
		Add(b,a);
	}
	read(st),read(ed);
	Fake_Topo();
	Twice_judge();
	dij();
	if(dis[ed] == 0x7f7f7f7f) printf("-1");
	else printf("%d",dis[ed]);
	return 0;
}
