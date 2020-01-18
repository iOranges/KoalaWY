#include<cstdio>
struct node{
	int e,next,v;
}tree[100001];
int n,s,num,h[100001],nd,Maxdep;

void add(int a,int b,int k)
{
	tree[++num].e = b;
	tree[num].next = h[a];
	h[a] = num;
	tree[num].v = k;
 } 

void dfs(int dep,int u,int pre)
{
	if(dep>Maxdep)
	{
		Maxdep = dep;
		nd = u;
	}
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
			dfs(dep+tree[i].v,tree[i].e,u);
}

int main()
{
	char ch;
	int i,a,b,k;
	scanf("%d%d",&n,&s);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d %c",&a,&b,&k,&ch);
		add(a,b,k);
		add(b,a,k);
	}
	dfs(0,s,0);
	Maxdep = 0;
	dfs(0,nd,0);
	printf("%d",Maxdep);
	return 0;
}
