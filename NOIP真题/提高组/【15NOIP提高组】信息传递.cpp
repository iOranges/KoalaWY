#include<cstdio>
#define min(x,y) ((x) < (y) ? (x) : (y))
struct node{
	int to,nxt;
}e[200005];
bool ins[200005];
int h[200005],tot,idx,dfn[200005],low[200005],s[200005],top,ans = 0x7f7f7f7f;
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

void tarjan(int u)
{
	dfn[u] = low[u] = ++ idx;
	s[++ top] = u;
	ins[u] = true;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(ins[v])
			low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u])
	{
		int cnt = 1;
		while(s[top] != u)
		{
			ins[s[top --]] = false;
			++ cnt;
		}
		-- top;
		if(cnt > 1) ans = min(cnt,ans);
	}
}

int main()
{
	int n,to;
	register int i;	
	read(n);
	for(i = 1;i <= n;++ i)
	{
		read(to);
		add(i,to);
	}
	for(i = 1;i <= n;++ i)
		if(!dfn[i])
			tarjan(i);
	printf("%d\n",ans);
	return 0;
}
