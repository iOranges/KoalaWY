#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
}
struct node{
	int v,nxt,to;
}e[605];
bool d[305];
int dis[305],h[305],tot,k,f[305],ans = 0x7f7f7f7f;
inline void add(int a,int b,int c)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	e[tot].v = c;
	h[a] = tot;
}

void dfs(int u,int pre,int type)
{
	if(type&1) f[u] = pre;
	if(type&&dis[u] > dis[k]) k = u;
	if(!type&&!d[u]) ans = max(ans,dis[u]);
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre||d[v]) continue;
		dis[v] = dis[u] + e[i].v;
		dfs(v,u,type);
	}
}

int main()
{
	int n,s,a,b,c;
	register int i,j;
	read(n),read(s);
	for(i = 1;i < n;++ i)
	{
		read(a),read(b),read(c);
		add(a,b,c),add(b,a,c);
	}
	dfs(1,0,2);
	dis[k] = 0;
	dfs(k,0,1);
	for(i = k,j = k;i&&j;i = f[i])
	{
		while(dis[j] - dis[i] > s) j = f[j];
		ans = min(ans,max(dis[i],dis[k] - dis[j]));
	}
	for(i = k;i;i = f[i]) d[i] = true;
	for(i = k;i;i = f[i])
		dis[i] = 0,dfs(i,0,0);
	printf("%d",ans);
	return 0;	
}

