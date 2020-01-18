#include<cstdio>
struct node{
	int to,nxt;
}e[200005];
int tot,h[100005],d[100005];
template <typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs(int u,int pre)
{
	d[u] = d[pre] + 1;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		dfs(v,u);
	} 
}

int main()
{
	int n,a,b;
	read(n);
	register int i;
	for(i = 1;i < n;++ i)
	{
		read(a),read(b);
		add(a,b),add(b,a);
	}
	dfs(1,0);
	double ans = 0;
	for(i = 1;i <= n;++ i)
		ans += 1.0 / d[i];
	printf("%.8lf",ans);
	return 0;
}
