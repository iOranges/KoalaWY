#include<cstdio>
#include<cstring>
#include<iostream>
using std::max;
struct node{
	int e,next;
}tree[40005];
int h[40005],tot,n,d[40005],minn,id;
void add(int a,int b)
{
	tree[++tot].e = b;
	tree[tot].next = h[a];
	h[a] = tot;
}

void dfs(int u,int pre)
{
	d[u] = 1;
	int maxx = 0;
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
		{
			dfs(tree[i].e,u);
			d[u] += d[tree[i].e];
			maxx = max(maxx,d[tree[i].e]);
		}
	maxx = max(maxx,n-d[u]);
	if(maxx < minn)
	{
		minn = maxx;
		id = u;
	}
}

int main()
{
	int t,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tot = 0;
		minn = 0x7ffffff;
		memset(h,0,sizeof h);
		memset(d,0,sizeof d);
		memset(tree,0,sizeof tree);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			add(a,b),add(b,a);
		}
		dfs(1,0);
		printf("%d %d \n",id,minn);
	}
	return 0;
 } 
