#include<cstdio>
#include<iostream>
#define N 300005
#define SIZ 1<<10|1
using std::max;
struct edge{
	int to,nxt,v;
}e[N << 1];
struct node{
	int dis,u,v,lca;
}len[N];
struct query{
	int to,nxt,id;
}q[N << 1];
bool vis[N];
int h[N],tot,w[N],n,m,f[N],h2[N],tot2,d[N],res,s[N],num,maxlen;
char buf[SIZ],*S = buf,*T = buf;
inline char GET() {return S == T&&(T = (S = buf) + fread(buf,1,SIZ,stdin),S == T) ? -1 : *(S++);}
#define getchar() GET()
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
}
inline void add(int a,int b,int c)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	e[tot].v = c;
	h[a] = tot;
}

inline void add2(int a,int b,int c)
{
	q[++ tot2].to = b;
	q[tot2].nxt = h2[a];
	q[tot2].id = c;
	h2[a] = tot2;
}

int find(int x)
{
	return f[x] != x ? f[x] = find(f[x]) : x;
 } 

void tarjan(int u,int pre)
{
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		w[v] = e[i].v;
		d[v] = d[u] + e[i].v;
		tarjan(v,u);
		f[v] = u;
	}
	vis[u] = true;
	for(int i = h2[u];i;i = q[i].nxt)
	{
		int v = q[i].to;
		if(vis[v]) 
		{
			len[q[i].id].lca = find(v);
			len[q[i].id].dis = d[u] + d[v] - 2 * d[len[q[i].id].lca];			
		}
	}
}

void dfs(int u,int pre)
{
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		dfs(v,u);
		s[u] += s[v];
		s[v] = 0;
	}
	if(s[u] == num)
		res = max(res,w[u]);
}

bool check(int t)
{
	register int i;
	res = num = 0;
	for(i = 1;i <= m;++ i)
		if(len[i].dis > t)
		{
			++ num;
			++ s[len[i].u],++ s[len[i].v];
			s[len[i].lca] -= 2;
		}
	dfs(1,0);
	if(maxlen - res > t) return false;
	else return true;
}

int main()
{
	int a,b,c;
	read(n),read(m);
	register int i,l = 0,r = 0,mid;
	for(i = 1;i < n;++ i)
	{
		read(a),read(b),read(c);
		add(a,b,c),add(b,a,c); 
	}
	for(i = 1;i <= n;++ i) f[i] = i;
	for(i = 1;i <= m;++ i)
	{
		read(len[i].u),read(len[i].v);	
		add2(len[i].u,len[i].v,i),add2(len[i].v,len[i].u,i);
	}
	tarjan(1,0);
	for(i = 1;i <= m;++ i) maxlen = max(maxlen,len[i].dis);
	r = maxlen;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d",l);
	return 0; 
}

