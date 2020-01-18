#include<cstdio>
#include<iostream>
using namespace std;
int n,m,f[301][301],w[301],h[301],tot,d[301];
struct node{
	int next,son;
}t[301];

void add(int a,int b)
{
	t[++tot].son = b;
	t[tot].next = h[a];
	h[a] = tot;
}

void work(int x)
{
	for(int i = h[x];i;i = t[i].next)
	{
		work(t[i].son);
		d[x] += d[t[i].son];
		for(int j=d[x];j>=1;j--)
			for(int k=j-1;k>=0;k--)
				f[x][j] = max(f[x][j],f[x][j-k-1]+f[t[i].son][k]+w[t[i].son]);
	}
	d[x] += 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	int i,a;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&w[i]);
		add(a,i);
	}
	work(0);
	printf("%d",f[0][m]);
	return 0;
}
