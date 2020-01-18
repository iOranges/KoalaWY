#include<cstdio>
#define rint register int
#define N 100005
#define swap(x,y) (x^=y,y^=x,x^=y)

struct node{
	int e,next;
}tree[N << 1];

int mod,n,h[N],tot;

inline void add(int a,int b)
{
	tree[++tot].e = b;
	tree[tot].next = h[a];
	h[a] = tot;
}

int cnt,v[N],rid[N],rnk[N],top[N],son[N],siz[N],f[N],d[N];

void dfs1(int u,int pre)
{
	f[u] = pre;
	d[u] = d[pre] + 1;
	siz[u] = 1;
	for(rint i = h[u];i;i = tree[i].next)
		if(tree[i].e != pre)
		{
			dfs1(tree[i].e,u);
			siz[u] += siz[tree[i].e];
			if(siz[tree[i].e] > siz[son[u]])
				son[u] = tree[i].e;
		}
}

void dfs2(int u,int fa)
{
	rid[u] = ++ cnt;
	rnk[cnt] = u;
	top[u] = fa;
	if(!son[u]) return;
	dfs2(son[u],fa);
	for(rint i = h[u];i;i = tree[i].next)
		if(tree[i].e != son[u] && tree[i].e != f[u])
			dfs2(tree[i].e,tree[i].e);
}

struct node2{
	int w,lzy;
}t[N << 2];

inline void pushup(int rt)
{
	t[rt].w = (t[rt << 1].w + t[rt << 1 | 1].w) % mod;
}

inline void pushdown(int rt,int len)
{
	if(t[rt].lzy)
	{
		t[rt<<1].w = (t[rt<<1].w + t[rt].lzy * (len - (len >> 1)) % mod) % mod;
		t[rt<<1|1].w = (t[rt<<1|1].w + t[rt].lzy * (len >> 1) % mod) % mod;
		t[rt<<1|1].lzy = (t[rt<<1|1].lzy + t[rt].lzy) % mod;
		t[rt<<1].lzy = (t[rt<<1].lzy + t[rt].lzy) % mod;
		t[rt].lzy = 0; 
	}
}

void build(int l,int r,int rt)
{
	if(l == r)
	{
		t[rt].w = v[rnk[l]] % mod;
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,rt<<1);
	build(mid + 1,r,rt<<1|1);
	pushup(rt);
}

void update(int x,int y,int v,int rt,int l,int r)
{
	if(x == l&&y == r)
	{
		t[rt].w = (t[rt].w + (v * (r - l + 1)) % mod) % mod;
		t[rt].lzy = (t[rt].lzy + v) % mod;
		return;
	}
	pushdown(rt,r - l + 1);
	int mid = (l + r) >> 1;
	if(y <= mid) update(x,y,v,rt<<1,l,mid);
	else if(x > mid) update(x,y,v,rt<<1|1,mid+1,r);
	else update(x,mid,v,rt<<1,l,mid),update(mid+1,y,v,rt<<1|1,mid+1,r);
	pushup(rt);
}

int query(int x,int y,int rt,int l,int r)
{
	if(x == l&&y == r)
		return t[rt].w;
	pushdown(rt,r - l + 1);
	int mid = (l + r) >> 1,ans = 0;
	if(y <= mid) ans = (ans + query(x,y,rt<<1,l,mid)) % mod;
	else if(x > mid) ans = (ans + query(x,y,rt<<1|1,mid + 1,r)) % mod;
	else ans = (query(x,mid,rt<<1,l,mid) + query(mid + 1,y,rt<<1|1,mid + 1,r)) % mod;
	return ans;
}

void update(int x,int y,int v)
{
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]])	swap(x,y);
		update(rid[top[x]],rid[x],v,1,1,n);
		x = f[top[x]];
	}
	if(d[x] > d[y]) swap(x,y);
	update(rid[x],rid[y],v,1,1,n);
}

int query(int x,int y)
{
	int ans = 0;
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]])	swap(x,y);
		ans = (ans + query(rid[top[x]],rid[x],1,1,n)) % mod;
		x = f[top[x]];
	}
	if(d[x] > d[y]) swap(x,y);
	ans = (ans + query(rid[x],rid[y],1,1,n)) % mod;
	return ans;
}

int main()
{
	rint i;
	int m,p,a,b,opt,c;
	scanf("%d%d%d%d",&n,&m,&p,&mod);
	for(i = 1;i <= n;++ i)
		scanf("%d",&v[i]);
	for(i = 1;i < n;++ i)
	{
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	dfs1(p,0);
	dfs2(p,p);
	build(1,n,1);
	for(i = 1;i <= m;++ i)
	{
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:scanf("%d%d%d",&a,&b,&c);update(a,b,c % mod);break;
			case 2:scanf("%d%d",&a,&b);printf("%d\n",query(a,b));break;
			case 3:scanf("%d%d",&a,&b);update(rid[a],rid[a] + siz[a] - 1,b % mod,1,1,n);break;
			case 4:scanf("%d",&a);printf("%d\n",query(rid[a],rid[a] + siz[a] - 1,1,1,n));break;
		}
	}
	return 0;
}
