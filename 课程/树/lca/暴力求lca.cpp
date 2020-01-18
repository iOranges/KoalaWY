#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int next,e;
}tree[80005];
int d[40005],n,h[40005],tot,f[40005];
void add(int a,int b)
{
	tree[++tot].e = b;
	tree[tot].next = h[a];
	h[a] = tot; 
}

void dfs(int u,int pre)
{
	f[u] = pre;
	d[u] = 1 + d[pre];
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
			dfs(tree[i].e,u);
}

int main()
{
	int t,m,i,a,b,k;
	scanf("%d",&t);
	while(t--)
	{
		tot = 0;
		memset(d,0,sizeof d);
		memset(h,0,sizeof h);
		scanf("%d%d",&n,&m);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			add(a,b),add(b,a);
		}
		dfs(1,0);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			if(d[a]<d[b]) swap(a,b);
			k = d[a] - d[b];
			while(k--)
				b = f[b];
			while(true)
			{
				a = f[a],b = f[b];
				if(a == b)
				{
					printf("%d\n",a);
					break;
				}
			}
		}
	}
	return 0;
 } 
