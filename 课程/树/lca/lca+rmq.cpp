#include<cmath>
#include<cstdio>
#include<iostream>
using std::swap;
struct node{
	int next,e,v;
}tree[100005];
int d[100005],pos[40005],o[100005],maxx[100005][20],h[40005],cnt,tot,n,dis[40005];
//o代表欧拉回路 pos[i]表示数i第一次在o数组中出现的位置 d[i]表示o[i]的深度 
int Max(int a,int b)		//返回点的标号，而不是对应的深度 
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
	pos[u] = cnt;		//记录来时路 
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
		{
			dis[tree[i].e] = dis[u] + tree[i].v;
			dfs(tree[i].e,u,dep+1);
			o[++cnt] = u;
			d[cnt] = dep;	//把返回的路记一遍，确保2点之间一定有它们的lca
		}
}

void rmq()
{
	for(int j=1;(1<<j)<=cnt;j++)
		for(int i=1;i<=cnt;i++)  //注意，比的是欧拉路中的点 
			if(i+(1<<j)-1<=cnt)
				maxx[i][j] = Max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);
}

int ask(int l,int r)
{
	if(l>r) swap(l,r);
	int x = log(r-l+1)/log(2.0); //万能的换底公式 
	return Max(maxx[l][x],maxx[r+1-(1<<x)][x]); //找出深度最小的点，即为lca 
}

int main()
{
	int k,i,a,b,c;
	scanf("%d%d",&n,&k);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c),add(b,a,c);
	}
	dfs(1,0,1);
	for(i=1;i<=cnt;i++)
		maxx[i][0] = i;   //maxx中存的是点的编号！！！ 
	rmq(); 
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&a,&b);
		c = o[ask(pos[a],pos[b])];
		printf("%d\n",dis[a]+dis[b]-2*dis[c]);
	}
	return 0;
 } 
