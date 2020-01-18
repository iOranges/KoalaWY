#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using std::swap;
struct node{
	int next,e,v;
}tree[100005];
int d[100005],pos[40005],o[100005],maxx[100005][20],h[40005],cnt,tot,n,dis[40005];
int Max(int a,int b)
{
	if(d[a]<d[b]) return a;
	else return b;
}

void add(int a,int b,int k)
{
	tree[++tot].e = b;
	tree[tot].next = h[a];
	tree[tot].v = k;
	h[a] = tot; 
}

void dfs(int u,int pre,int dep)
{
	o[++cnt] = u;
	d[cnt] = dep;
	pos[u] = cnt;
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
		{
			dis[tree[i].e] = dis[u] + tree[i].v;
			dfs(tree[i].e,u,dep+1);
			o[++cnt] = u;
			d[cnt] = dep;
		}
}

void rmq()
{
	for(int j=1;(1<<j)<=cnt;j++)
		for(int i=1;i<=cnt;i++)
			if(i+(1<<j)-1<=cnt)
				maxx[i][j] = Max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);
}

int ask(int l,int r)
{
	if(l>r) swap(l,r);
	int x = log(r-l+1)/log(2.0);
	return Max(maxx[l][x],maxx[r+1-(1<<x)][x]);
}

int main()
{
	int k,i,a,b,c,t;
	scanf("%d",&t);
	while(t--)
	{
		cnt = tot =0;
		memset(h,0,sizeof h);
		memset(d,0,sizeof d);
		memset(o,0,sizeof o);
		memset(pos,0,sizeof pos);
		memset(dis,0,sizeof dis);
		memset(maxx,0,sizeof maxx);
		memset(tree,0,sizeof tree);
		scanf("%d%d",&n,&k);
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c),add(b,a,c);
		}
		dfs(1,0,1);
		for(i=1;i<=cnt;i++)
			maxx[i][0] = i;
		rmq(); 
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&a,&b);
			c = o[ask(pos[a],pos[b])];
			printf("%d\n",dis[a]+dis[b]-2*dis[c]);
		}		
	}
	return 0;
 } 
