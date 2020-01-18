#include<cstdio>
#define min(x,y) ((x) < (y) ? (x) : (y))
bool instack[2000005];
int n,m,tot,h[2000005],dfn[2000005],low[2000005],s[2000005],top,idx,bel[2000005],cnt;
struct node{
	int nxt,to;
}e[2000005];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch < '0' || ch > '9') ch = getc(stdin);
	while(ch >= '0'&&ch <= '9'){x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++ idx;
	instack[u] = true;
	s[++ top] = u;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(instack[v])
			low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u])
	{
		++cnt;
		bel[u] = cnt;
		while(s[top] != u)
		{
			instack[s[top]] = false;
			bel[s[top --]] = cnt;
		}
		-- top;
		instack[u] = false;
	}
}

int main()
{
	int a,b,x,y;
	register int i;
	read(n),read(m);
	for(i = 1;i <= m;++ i)
	{
		read(x),read(a),read(y),read(b);
		add(x + n * (a & 1),y + n * (b ^ 1));
		add(y + n * (b & 1),x + n * (a ^ 1));			
	 } 
	for(i = 1;i <= n * 2;++ i)
		if(!dfn[i])
			tarjan(i);
	for(i = 1;i <= n;++ i)
		if(bel[i] == bel[i + n])
		{
			printf("IMPOSSIBLE");
			return 0;
		}
	printf("POSSIBLE\n");
	for(i = 1;i <= n;++ i)
		if(bel[i] < bel[i + n]) printf("1 ");
		else printf("0 ");
	return 0;
}
