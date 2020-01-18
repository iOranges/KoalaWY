#include<cstdio>
#include<iostream>
using std::max;
struct node{
	int next,e;
}tree[300001];
int h[300001],tot,f[300001],ans[300001],s[300001],minn,id,Max;

inline void read(int& x) {
    int f = 1; x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

inline void add(int a,int b)
{
	tree[++tot].e = b;
	tree[tot].next = h[a];
	h[a] = tot;
}


void dfs(int u)
{
	int maxx=0;
	ans[u] = u;
	s[u] = 1;
	for(int i=h[u];i;i=tree[i].next)
	{
		dfs(tree[i].e);
		s[u] += s[tree[i].e];
		if(s[maxx]<s[tree[i].e]) maxx = tree[i].e;
	}
	if(2*s[maxx]>s[u])
	{
		int now = ans[maxx];
		while((s[u] - s[now])*2>s[u])
			now = f[now];
		ans[u] = now;
	}
}

int main()
{
	int m,i,n,k;
	read(n),read(m);
	f[1] = 1;
	for(i=2;i<=n;i++)
	{
		read(k);
		add(k,i);
		f[i] = k;
	}
	dfs(1);
	for(i=1;i<=m;i++)
	{
		read(k);
		printf("%d\n",ans[k]);
	}
	return 0;
}
