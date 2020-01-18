#include<cstdio> 
#include<cstring> 
#include<iostream>
using std::swap;
struct node{
	int e,next;
}tree[2001];
int h[1001],lca[1001],cnt,r[1001],p[1001][12],d[1001];
void add(int a,int b)
{
	tree[++cnt].e = b;
	tree[cnt].next = h[a];
	h[a] = cnt;
 } 
 
void dfs(int u,int pre)
{
	d[u] = d[pre]+1;
	p[u][0] = pre;
	for(int i=1;(1<<i)<=d[u];i++)
		p[u][i] =  p[p[u][i-1]][i-1];
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
			dfs(tree[i].e,u);
}

int Lca(int a,int b)
{
	if(d[a]>d[b]) swap(a,b);
	for(int i=10;i>=0;i--)
		if(d[a]<=d[b]-(1<<i)) b=p[b][i];
	if(a==b) return a;
	for(int i=10;i>=0;i--)
		if(p[a][i]!=p[b][i])
			a=p[a][i],b=p[b][i];
	return p[a][0];
}

int main()
{
	char ch;
	int n,i,a,b,j,k,m;
	while(scanf("%d",&n))
	{
		memset(h,0,sizeof h);
		memset(d,0,sizeof d);
		memset(r,0,sizeof r);
		memset(p,0,sizeof p);
		memset(lca,0,sizeof lca);
		cnt = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d:(%d)",&a,&b);
			for(j=1;j<=b;j++)
			{
				scanf("%d",&k);
				r[k]++;
				add(a,k),add(k,a);
			}
		}
		for(i=1;i<=n;i++)
			if(!r[i])
			{
				dfs(i,0);	
				break;		
			}		
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			while(ch=getchar())
				if(ch=='(')
					break;
			scanf("%d %d%c",&a,&b,&ch);
			lca[Lca(a,b)]++;
		}
		for(i=1;i<=n;i++)
			if(lca[i]!=0)
				printf("%d:%d\n",i,lca[i]);		
	}
	return 0;
}
