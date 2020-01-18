#include<cstdio>
#include<iostream>
using namespace std;
int f[101][101],n,m,h[101],tot;
struct node{
	int next,son,v;
}t[101];

void add(int a,int b,int k)
{
	t[++tot].son = b;
	t[tot].next = h[a];
	t[tot].v = k;
	h[a] = tot;
}

void work(int x)
{
	for(int i=h[x];i;i=t[i].next)
	{
		work(t[i].son);
		for(int j = m;j >= 1;j --)
			for(int k = j - 1;k >= 0;k --)
				f[x][j] = max(f[x][j],f[x][j-k-1] + f[t[i].son][k] + t[i].v);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	int a,b,i,k;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&k);
		add(a,b,k);
	}
	work(1);
	printf("%d",f[1][m]);
	return 0;
}
