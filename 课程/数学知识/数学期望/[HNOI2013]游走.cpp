#include<cstdio>
#include<iostream>
#include<algorithm>
using std::swap;
using std::sort;
struct node{
	int nxt,to;
}e[500005];
double f[505][505],g[250005];
int tot,h[505],st[250005],ed[250005],r[505];
template <typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

bool cmp(double a,double b)
{
	return a > b;
}

inline void add(int a,int b)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

inline double abs(double x)
{
	return x > 0 ? x : -x;
}

void Gauss(int n)
{
	register int i,j,k;
	for(i = 1;i <= n;++ i)
	{
		int o = i;
		for(j = i + 1;j <= n;++ j)
			if(abs(f[o][i]) < abs(f[j][i]))
				o = j;
		if(o != i) swap(f[o],f[i]);
		double div = f[i][i];
		for(j = i;j <= n + 1;++ j)
			f[i][j] /= div;
		for(j = i + 1;j <= n;++ j)
		{
			div = f[j][i];
			for(k = i;k <= n + 1;++ k)
				f[j][k] -= f[i][k] * div;
		}
	}
	for(i = n - 1;i >= 1;-- i)
		for(j = i + 1;j <= n;++ j)
			f[i][n + 1] -= f[i][j] * f[j][n + 1];
}

int main()
{
	int n,m;
	read(n),read(m);
	register int i,j;
	for(i = 1;i <= m;++ i)
	{
		read(st[i]),read(ed[i]);
		++ r[st[i]],++ r[ed[i]];
		add(st[i],ed[i]),add(ed[i],st[i]);
	}
	f[1][n] = 1;
	for(i = 1;i < n;++ i)
	{
		f[i][i] = 1;
		for(j = h[i];j;j = e[j].nxt)
		{
			int v = e[j].to;
			if(v == n) continue;
			f[i][v] = -1.0 / r[v];
		}
	}
	Gauss(n - 1);
	for(i = 1;i <= m;++ i)
	{
		int u = st[i],v = ed[i];
		if(u != n) g[i] += f[u][n] / r[u];
		if(v != n) g[i] += f[v][n] / r[v];
	}
	sort(g + 1,g + m + 1,cmp);
	double ans = 0;
	for(i = 1;i <= m;++ i)
		ans += g[i] * i;
	printf("%.3lf",ans);
	return 0;
}
