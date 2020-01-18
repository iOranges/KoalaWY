#include<cstdio>
#include<iostream>
using namespace std;
struct node{
	int e,next;
}t[60001];
int n,m,h[30001],cnt,tot,v[30001];
int siz[30001],son[30001],d[30001],f[30001],rid[30001],rnk[30001],top[30001];
struct node2{
	int l,r,mx,w;
}tree[120005];
void add(int a,int b)
{
	t[++cnt].e = b;
	t[cnt].next = h[a];
	h[a] = cnt;
}

void dfs1(int u,int pre)
{
	siz[u] = 1;
	d[u] = d[pre]+1;
	f[u] = pre;
	for(int i=h[u];i;i=t[i].next)
		if(t[i].e!=pre)
		{
			dfs1(t[i].e,u);
			siz[u] += siz[t[i].e];
			if(siz[t[i].e] > siz[son[u]])
				son[u] = t[i].e;
		}
}

void dfs2(int u,int fa)
{
	rid[u] = ++tot;
	rnk[tot] = u;
	top[u] = fa;
	if(!son[u]) return;
	dfs2(son[u],fa);
	for(int i=h[u];i;i=t[i].next)
		if(t[i].e != son[u]&&t[i].e != f[u])
			dfs2(t[i].e,t[i].e); 
}

void pushup(int rt)
{
	tree[rt].mx = max(tree[rt<<1].mx,tree[rt<<1|1].mx);
	tree[rt].w = tree[rt<<1].w + tree[rt<<1|1].w;
}

void build(int l,int r,int rt)
{
	tree[rt].l = l,tree[rt].r = r;
	if(l == r)
	{
		tree[rt].mx = tree[rt].w = v[rnk[l]];
		return;
	}
	int mid = (l+r) >> 1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt); 
}

void update(int p,int v,int rt)
{
	int l=tree[rt].l,r=tree[rt].r;
	if(l == r)
	{
		tree[rt].w = tree[rt].mx = v;
		return;
	}
	int mid = (l+r) >> 1;
	if(p<=mid) update(p,v,rt<<1);
	else update(p,v,rt<<1|1);
	pushup(rt);
 } 

int Mquery(int x,int y,int rt)
{
	int l=tree[rt].l,r=tree[rt].r;
	if(l == x&&r == y)
		return tree[rt].mx;
	int mid = (l+r) >> 1;
	if(y <= mid) return Mquery(x,y,rt<<1);
	else if(x > mid) return Mquery(x,y,rt<<1|1);
	else return max(Mquery(x,mid,rt<<1),Mquery(mid+1,y,rt<<1|1));
}

int Squery(int x,int y,int rt)
{
	int l=tree[rt].l,r=tree[rt].r;
	if(l == x&&r == y)
		return tree[rt].w;
	int mid = (l+r) >> 1;
	if(y <= mid) return Squery(x,y,rt<<1);
	else if(x > mid) return Squery(x,y,rt<<1|1);
	else return Squery(x,mid,rt<<1)+Squery(mid+1,y,rt<<1|1); 
}

int qm(int a,int b)
{
	int ans = -1 * 0x7f7f7f7f;
	while(top[a]!=top[b])
	{
		if(d[top[a]]<d[top[b]])
			swap(a,b);
		ans = max(Mquery(rid[top[a]],rid[a],1),ans);
		a = f[top[a]];
	}
	if(d[a]>d[b])
		swap(a,b);
	ans = max(Mquery(rid[a],rid[b],1),ans);
	return ans;
}
int qs(int a,int b)
{
	int ans = 0;
	while(top[a]!=top[b])
	{
		if(d[top[a]]<d[top[b]])
			swap(a,b);
		ans += Squery(rid[top[a]],rid[a],1);
		a = f[top[a]];
	}
	if(d[a]>d[b])
		swap(a,b);
	ans += Squery(rid[a],rid[b],1);
	return ans;
}

int main()
{
	int a,b,i;
	char ch[10];
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	dfs1(1,0); 
	dfs2(1,1);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	build(1,n,1);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%s%d%d",ch,&a,&b);
		if(ch[1] == 'H')
			update(rid[a],b,1);
		else if(ch[1] == 'M')
			printf("%d\n",qm(a,b));
		else
			printf("%d\n",qs(a,b));
	}
	return 0;
}
