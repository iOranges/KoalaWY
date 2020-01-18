#include<queue>
#include<cstdio>
#include<cstring>
#define N 100005
#define M 500005
#define SIZE 1<<20
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
using std::priority_queue;
char buf[SIZE],*S = buf,*T = buf;
inline char gc() {return S == T && (T = (S = buf) + fread(buf,1,SIZE,stdin),S == T) ? -1 : *S++;}
#define getc(stdin) gc()
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

struct node{
	int to,nxt;
}e[M << 1];
struct Pair{
	int dis,pos;
	Pair(int d,int p) :dis(d),pos(p){}
	bool operator < (const Pair b) const{
		return dis > b.dis;
	}
};
int w[N],f[N],h[N],tot,ans,dp[N];

inline void add(int a,int b)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

priority_queue<Pair> q;
void dij()
{
	q.push(Pair(w[1],1));
	memset(f,0x7f,sizeof f);
	f[1] = w[1];
	register int i;
	while(!q.empty())
	{
		int u = q.top().pos;q.pop();
		f[u] = min(f[u],w[u]);
		for(i = h[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(f[v] > f[u])
			{
				f[v] = f[u];
				dp[v] = max(dp[v],w[v] - f[u]);
				q.push(Pair(f[v],v));
			}
			if(dp[v] < dp[u])
			{
				dp[v] = dp[u];
				q.push(Pair(f[v],v));
			}
		}
	}
} 

int main()
{
	int n,m,a,b,z;
	read(n),read(m);
	register int i;
	for(i = 1;i <= n;++ i)
		read(w[i]);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b),read(z);
		add(a,b);
		if(z ^ 1) add(b,a);
	}
	dij();
	printf("%d\n",dp[n]);
	return 0;
}
