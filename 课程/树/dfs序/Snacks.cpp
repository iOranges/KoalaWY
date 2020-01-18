#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#define max(x,y) (x)>(y)?(x):(y)
int n,h[100005],tot,cnt,l[100005],r[100005],v[100005],num[100005];
long long dis[100005];
struct node{
	int to,next;
	void add(int a,int b)
	{
		to = b;
		next = h[a];
		h[a] = tot;
	}
}e[200005];

struct tree{
	int l,r;
	long long w,lazy;
}t[100005<<2];

inline void read(int &x)
{
	char ch;int f = 1;x = 0;
	ch = getc(stdin);
	while(ch<'0'||ch>'9') {if(ch == '-') f=-1;ch = getc(stdin);}
	while(ch<='9'&&ch>='0') {x = (x<<1) + (x<<3) + (ch^48);ch = getc(stdin);}
	x*=f;
}

void dfs(int u,int pre)
{
	l[u] = ++cnt;
	num[cnt] = u;
	for(int i=h[u];i;i=e[i].next)
		if(e[i].to!=pre)
		{
			dis[e[i].to] = dis[u] + 1ll * v[e[i].to];
			dfs(e[i].to,u);			
		}
	r[u] = cnt;
}

inline void pushup(int rt)
{
	t[rt].w = max(t[rt<<1].w,t[rt<<1|1].w);
}

void pushdown(int rt)
{
    if(t[rt].lazy != 0)
    {
        t[rt<<1].w += t[rt].lazy;
        t[rt<<1|1].w += t[rt].lazy;
        t[rt<<1].lazy += t[rt].lazy;
        t[rt<<1|1].lazy += t[rt].lazy;
        pushup(rt);
        t[rt].lazy = 0;
    }
}

void build(int l,int r,int rt)
{
	t[rt].l = l,t[rt].r = r;
	if(l == r)
	{
		t[rt].w = dis[num[l]];
		return ;
	}
	int mid = (l+r) >> 1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}

void update(int x,int y,int c,int rt)
{
	int l = t[rt].l,r = t[rt].r;
	if(l == x&&r == y)
	{
		t[rt].lazy += 1ll * c; 
		t[rt].w = t[rt].w + 1ll * c;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(mid >= y) update(x,y,c,rt<<1);
	else if(mid < x) update(x,y,c,rt<<1|1);
	else update(x,mid,c,rt<<1),update(mid+1,y,c,rt<<1|1);
	pushup(rt);
}

long long query(int x,int y,int rt)
{
	int l = t[rt].l,r = t[rt].r;
	if(l == x&&r == y)
		return t[rt].w;
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(mid >= y) return query(x,y,rt<<1);
	else if(mid < x) return query(x,y,rt<<1|1);
	else return max(query(x,mid,rt<<1),query(mid+1,y,rt<<1|1));
	pushup(rt);
}

int main()
{
	register int i;
	int T,a,b,x,m;
	read(T);
	for(int o=1;o<=T;++o)
	{
		tot = cnt = 0;
		memset(h,0,sizeof h);
		memset(t,0,sizeof t);
		memset(v,0,sizeof v);
		memset(e,0,sizeof e);
		memset(num,0,sizeof num);
		memset(dis,0,sizeof dis);		
		read(n),read(m);
		for(i=1;i<n;++i)
		{
			read(a),read(b);
			++ tot;
			e[tot].add(a,b);
			++ tot;
			e[tot].add(b,a);
		}
		for(i=0;i<n;++i)
			read(v[i]);
		dis[0] = v[0];
		dfs(0,-1);
		build(1,cnt,1);
		printf("Case #%d:\n",o);
		for(i=1;i<=m;++i)
		{
			read(x),read(a);
			if(x == 1)
				printf("%lld\n",query(l[a],r[a],1));
			else
			{
				read(b);
				update(l[a],r[a],b - v[a],1);
				v[a] = b;
			}
		}
	}
	return 0;
}
