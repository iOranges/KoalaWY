#include<cstdio>
#include<cstring>
#define maxn 200005
struct node{
	int e,next;
}tree[400011];
int h[maxn],tot,n,Maxdep,nd,f[maxn],a[maxn],b[maxn];
void add(int a,int b)
{
	tree[++tot].e = b;
	tree[tot].next = h[a];
	h[a] = tot;
}

void dfs(int dep,int u,int pre)
{
	if(dep > Maxdep)
	{
		Maxdep = dep;
		nd = u;
	}
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=pre)
			dfs(dep+1,tree[i].e,u);
}

int find(int x)
{
	if(f[x]!=x) f[x] = find(f[x]);
	return f[x];
}

int main()
{
	int i,ta,tb;
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&h[i]);
		f[i] = i;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		ta = find(a[i]),tb = find(b[i]);
		if(h[ta]==h[tb])
			f[ta] = f[tb];
	}
	memset(h,0,sizeof h);
	for(i=1;i<=n;++i)
		f[i] = find(f[i]);
	for(i=1;i<n;++i)
		if(f[a[i]]!=f[b[i]])
			add(f[a[i]],f[b[i]]),add(f[b[i]],f[a[i]]);
	dfs(0,f[1],0);
//	Maxdep = 0;
	dfs(0,nd,0);
	printf("%d",(Maxdep+1)>>1);
	return 0;
}
