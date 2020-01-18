#include<cstdio>
struct node{
	int to,nxt,v;
}e[200005];
int h[100005],tot,d[100005];
double f[100005];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b,int k)
{
	e[++tot].to = b;
	e[tot].v = k;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs(int u)
{
	if(f[u]) return;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		dfs(v);
		f[u] += (f[v] + e[i].v) * 1.0 / d[u];
	}
}

int main()
{
	int n,m,a,b,c;
	register int i;
	read(n),read(m);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b),read(c);
		add(a,b,c),++ d[a];
	}
	dfs(1);
	printf("%.2lf",f[1]);
	return 0;
}
