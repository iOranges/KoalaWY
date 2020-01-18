#include<queue>
#include<cstdio>
#include<cstring>
using std::priority_queue;
bool visit[100005];
int n,m,s,tot,h[100005],dis[100005];
struct edge{
	int v,nxt,to;
}e[400005];

struct node{
	int dis;
	int pos;
	bool operator < (const node b) const{
		return dis > b.dis;
	}
};

priority_queue<node> q;

inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b,int k)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	e[tot].v = k;
	h[a] = tot;
}

void dij()
{
	register int i;	
	memset(dis,0x7f,sizeof dis);
	dis[s] = 0;
	q.push((node){0,s});
	do{
		int u = q.top().pos;
		q.pop();
		if(visit[u]) continue;
		visit[u] = true;
		for(i = h[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].v)
			{
				dis[v] = dis[u] + e[i].v;	
				if(!visit[v]) q.push((node){dis[v],v});			
			}
		}
	}while(!q.empty());
}

int main()
{
	int a,b,c;
	register int i;
	read(n),read(m),read(s);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b),read(c);
		add(a,b,c);
	}
	dij();
	for(i = 1;i <= n;++ i)
		printf("%d ",dis[i]);
	return 0;
}
