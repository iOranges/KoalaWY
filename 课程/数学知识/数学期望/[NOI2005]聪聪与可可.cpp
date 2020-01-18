#include<queue>
#include<cstdio>
#include<cstring>
using std::queue;
struct edge{
	int to,nxt;
}e[2005];
struct node{
	int pos,pre;
	node(int a,int b) :pos(a),pre(b){}
};
bool vis[1005][1005];
double f[1005][1005];
int p[1005][1005],tot,h[1005],dis[1005],r[1005];
#define SIZE 1<<10|1
char buf[SIZE],*S = buf,*T = buf;
inline char gc() {return S == T&&(T = (S = buf) + fread(buf,1,SIZE,stdin),S == T) ? -1 : *(S++);}
#define getc(stdin) gc()
template <typename e>inline void read(e &x)
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

queue<node> q;
void Spfa(int s)
{
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	q.push(node(s,0));
	while(!q.empty())
	{
		int u = q.front().pos,pre = q.front().pre;
		q.pop();
		for(int i = h[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(v == pre) continue;
			if(dis[v] > dis[u] + 1||(dis[v] == dis[u] + 1&&p[v][s] > u))
			{
				dis[v] = dis[u] + 1;
				p[v][s] = u;
				q.push(node(v,u));
			}
		}
	}
}

double dfs(int s,int t)
{
	if(vis[s][t]) return f[s][t];
	if(s == t) return 0;
	int nxt = p[s][t];
	int to = p[nxt][t];
	if(nxt == t||to == t) return 1;
	for(int i = h[t];i;i = e[i].nxt)
	{
		int v = e[i].to;
		f[s][t] += (dfs(to,v) + 1.0) / (r[t] + 1);
	}
	f[s][t] += (dfs(to,t) + 1.0) / (r[t] + 1);
	vis[s][t] = true;
	return f[s][t];
}

int main()
{
	int n,m,st,ed,a,b;
	read(n),read(m);
	register int i;
	read(st),read(ed);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b);
		++ r[a],++ r[b];
		add(a,b),add(b,a);
	}
	for(i = 1;i <= n;++ i)
		Spfa(i);
	printf("%.3lf",dfs(st,ed));
	return 0;
}
