#include<cstdio>
#include<iostream>
#define N 100005
using namespace std;
inline void read(int &x)
{
	int f=1;char ch;
	ch = getchar(),x=0;
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();};
	while(ch >= '0' && ch <= '9') {x = x*10 + (ch ^ 48);ch = getchar();};
	x *= f;
}

struct node{
	int e,next;
}tree[N << 1];
int v[N],h[N],cnt,n;

void add(int a,int b)
{
	tree[++cnt].e = b;
	tree[cnt].next = h[a];
	h[a] = cnt;
}

int f[N],son[N],d[N],siz[N],rid[N],rnk[N],top[N],tot;

void dfs1(int u,int pre)
{
	d[u] = d[pre]+1;
	f[u] = pre;
	siz[u] = 1;
	for(int i=h[u];i;i=tree[i].next)
	{
		int V = tree[i].e;
		if(V == pre) continue;
		dfs1(V,u);
		siz[u] += siz[V];
		if(siz[V] > siz[son[u]])
			son[u] = V;		
	}
}

void dfs2(int u,int pre)
{
	rid[u] = ++tot;
	rnk[tot] = u;
	top[u] = pre;
	if(!son[u]) return;
	dfs2(son[u],pre);
	for(int i=h[u];i;i=tree[i].next)
		if(tree[i].e!=f[u] && tree[i].e!=son[u])
			dfs2(tree[i].e,tree[i].e);
}

struct node2{
	long long w,lazy;
}t[N<<2];

void pushup(int rt)
{
	t[rt].w = t[rt<<1].w + t[rt<<1|1].w;
}

void pushdown(int rt,int m)
{
	if(t[rt].lazy)
	{
		t[rt<<1].lazy += t[rt].lazy;
		t[rt<<1|1].lazy += t[rt].lazy;
		t[rt<<1].w += t[rt].lazy * (m - (m>>1));
		t[rt<<1|1].w += t[rt].lazy * 1ll * (m>>1);
		t[rt].lazy = 0;
	}
}

void build(int l,int r,int rt)
{
	if(l == r)
	{
		t[rt].w = v[rnk[l]];
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}

void update(int p,int c,int rt,int l,int r)
{
	if(l == r)
	{
		t[rt].w += 1ll * c;
		return;
	}
	pushdown(rt,r-l+1);
	int mid = (l+r) >> 1;
	if(mid>=p) update(p,c,rt<<1,l,mid);
	else update(p,c,rt<<1|1,mid+1,r);
	pushup(rt);
}

void upson(int x,int y,int c,int rt,int l,int r)
{
	if(l == x&&r == y)
	{
		t[rt].w += 1ll * c * (r-l+1);
		t[rt].lazy += c;
		return;
	}
	pushdown(rt,r-l+1);
	int mid = (l+r) >> 1;
	if(y <= mid) upson(x,y,c,rt<<1,l,mid);
	else if(x > mid) upson(x,y,c,rt<<1|1,mid+1,r);
	else upson(x,mid,c,rt<<1,l,mid),upson(mid+1,y,c,rt<<1|1,mid+1,r);
	pushup(rt);
}

long long query(int x,int y,int rt,int l,int r)
{
	if(l == x && r == y)
		return t[rt].w;
	pushdown(rt,r-l+1);
	int mid = (l+r) >> 1;
	if(mid >= y) return query(x,y,rt<<1,l,mid);
	else if(x>mid) return query(x,y,rt<<1|1,mid+1,r);
	else return query(x,mid,rt<<1,l,mid)+query(mid+1,y,rt<<1|1,mid+1,r);
}

long long qm(int x,int y)
{
	long long ans = 0;
	while(top[x]!=top[y])
	{
		if(d[top[x]] < d[top[y]])
			swap(x,y);
		ans += query(rid[top[x]],rid[x],1,1,n);
		x = f[top[x]];
	}
	if(d[x] > d[y])
		swap(x,y);
	ans += query(rid[x],rid[y],1,1,n);
	return ans;
} 

int main()
{
//	freopen("shu.in","r",stdin);
	int m,i,a,b,x;
	read(n),read(m);
	for(i=1;i<=n;i++)
		read(v[i]);
	for(i=1;i<n;i++)
	{
		read(a),read(b);
		add(a,b),add(b,a);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,n,1);
	for(i=1;i<=m;i++)
	{
		read(x);
		if(x == 1)
		{
			read(a),read(b);
			update(rid[a],b,1,1,n);
		}
		else if(x == 2)
		{
			read(a),read(b);
			upson(rid[a],rid[a]+siz[a]-1,b,1,1,n);
		}
		else if(x == 3)
		{
			read(a);
			printf("%lld\n",qm(a,1));
		}
	}
	return 0;
}
