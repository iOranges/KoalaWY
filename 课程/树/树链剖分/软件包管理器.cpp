#include<cstdio>
#define rint register int
#define N 100005
#define swap(x,y) (x^=y,y^=x,x^=y)
int n,h[N],cnt,tot,top[N],rid[N],son[N],siz[N],f[N],d[N];
struct node{
	int to,nxt;
}e[N];

inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs1(int u)
{
	siz[u] = 1;
	for(rint i = h[u];i;i = e[i].nxt)
	{
		f[e[i].to] = u;
		d[e[i].to] = d[u] + 1;
		dfs1(e[i].to);
		siz[u] += siz[e[i].to];
		if(siz[e[i].to] > siz[son[u]])
			son[u] = e[i].to;
	}
}

void dfs2(int u,int fa)
{
	rid[u] = ++ cnt;
	top[u] = fa;
//	rnk[cnt] = u;
	if(!son[u]) return;
	dfs2(son[u],fa);
	for(rint i = h[u];i;i = e[i].nxt)
		if(e[i].to != son[u])
			dfs2(e[i].to,e[i].to);
}

struct node2{
	int w,lzy;
}t[N << 2];

inline void pushup(int rt)
{
	t[rt].w = t[rt<<1].w + t[rt<<1|1].w;
}

inline void pushdown(int rt,int m)
{
	if(t[rt].lzy)
	{
		if(t[rt].lzy == 1)
		{
			t[rt<<1].w = m - (m >> 1);
			t[rt<<1|1].w = (m >> 1);
			t[rt<<1].lzy = t[rt<<1|1].lzy = 1;			
		}
		else
		{
			t[rt<<1].w = t[rt<<1|1].w = 0;
			t[rt<<1].lzy = t[rt<<1|1].lzy = 2;
		}
		t[rt].lzy = 0;
	}
}

void build(int l,int r,int rt)
{
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(l,mid,rt<<1);
	build(mid + 1,r,rt<<1|1);
}

void update(int x,int y,int rt,int l,int r,bool install)
{
	if(x <= l&&r <= y)
	{
		if(install)
		{
			t[rt].w = r - l + 1;
			t[rt].lzy = 1;			
		}
		else
		{
			t[rt].w = 0;
			t[rt].lzy = 2;
		}
		return;
	}
	pushdown(rt,r - l + 1);
	int mid = (l + r) >> 1;
	if(x <= mid) update(x,y,rt<<1,l,mid,install);
	if(y > mid) update(x,y,rt<<1|1,mid + 1,r,install);
	pushup(rt); 
}

/*int query(int x,int y,int rt,int l,int r)
{
	if(x <= l && r <= y)
		return t[rt].w;
	pushdown(rt,r - l + 1);
	int mid = (l + r) >> 1,ans = 0;
	if(x <= mid) ans += query(x,y,rt<<1,l,mid);
	if(y > mid) ans += query(x,y,rt<<1|1,mid + 1,r);
	return ans;
}*/

int install(int a,int b)
{
	int ans = t[1].w;
	while(top[a] != top[b])
	{
		if(d[top[a]] < d[top[b]]) swap(a,b);
		update(rid[top[a]],rid[a],1,1,n,true);
		a = f[top[a]];
	}
	if(d[a] > d[b])
		swap(a,b);
	update(rid[a],rid[b],1,1,n,true);
	ans -= t[1].w;
	if(ans < 0) ans = - ans;
	return ans;
}

int uninstall(int a,int b)
{
	int ans = t[1].w;
	update(a,b,1,1,n,false);
	ans -= t[1].w;
	if(ans < 0) ans = - ans;
	return ans;
}

int main()
{
//	freopen("machine.in","r",stdin);
//	freopen("machine.out","w",stdout);
	rint i;
	int x,m;
	char ch[20];
	scanf("%d",&n);
	for(i = 2;i <= n;++ i)
	{
		scanf("%d",&x);
		add(x + 1,i);
	}
	dfs1(1);
	dfs2(1,1);
	build(1,n,1);
	scanf("%d",&m);
	for(i = 1;i <= m;++ i)
	{
		scanf("%s%d",ch,&x);
		++ x;
		if(ch[0] == 'i')
			printf("%d\n",install(1,x));
		else
			printf("%d\n",uninstall(rid[x],rid[x] + siz[x] - 1));
	}
	return 0;
}
