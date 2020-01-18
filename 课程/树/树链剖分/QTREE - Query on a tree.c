#include<stdio.h>
#include<string.h>
#define N 100005
#define max(x,y) ((x)>(y)?(x):(y))

char nc() {
    static char buf[1000000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}

int read() 
{
    int s=0;
	char c=nc();
    while(c<'0'||c>'9') 
    	c = nc();
    while(c>='0'&&c<='9'){
    	s = (s * 10) + (c ^ 48);
    	c = nc();
	}
    return s;
}

int n,h[N],tot,v[N],to[N<<1],nxt[N<<1],w[N<<1],U[N],V[N];

void add(int u,int v,int c)
{
    to[++tot]=v;
    nxt[tot]=h[u];
    h[u]=tot;
    w[tot]=c;
}

int cnt,rid[N],rnk[N],top[N],son[N],siz[N],f[N],d[N],t[N << 2];

void dfs1(int u)
{
	siz[u] = 1;
	son[u] = 0;
	int i;
	for(i = h[u];i;i = nxt[i])
	{
		int p = to[i];
		if(p == f[u]) continue;
		v[p] = w[i];
		f[p] = u;
		d[p] = d[u] + 1;
		dfs1(p);
		siz[u] += siz[p];
		son[u] = siz[p] > siz[son[u]] ? p : son[u];		
	}
}

void dfs2(int u,int fa)
{
	rid[u] = ++ cnt;
	rnk[cnt] = u;
	top[u] = fa;
	if(!son[u]) return;
	dfs2(son[u],fa);
	int i;
	for(i = h[u];i;i = nxt[i])
	{
		int p = to[i];
		if(p == son[u] || p == f[u])
			continue;
		dfs2(p,p);		
	}
}

void pushup(int rt)
{
	t[rt] = max(t[rt<<1],t[rt<<1|1]);
}

void build(int l,int r,int rt)
{
	if(l == r)
	{
		t[rt] = v[rnk[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(l,mid,rt<<1);
	build(mid + 1,r,rt<<1|1);
	pushup(rt);
}

void update(int x,int v,int rt,int l,int r)
{
	if(l == r)
	{
		t[rt] = v;
		return;
	}
	int mid = (l + r) >> 1;
	mid >= x ? update(x,v,rt<<1,l,mid) : update(x,v,rt<<1|1,mid + 1,r);
	pushup(rt);
}

int query(int x,int y,int rt,int l,int r)
{
	if(l >= x&&r <= y)
		return t[rt];
	int mid = (l + r) >> 1,ans = 0;
	if(x <= mid) 
	{
		int c = query(x,y,rt<<1,l,mid);
		ans = max(ans,c);
	}
	if(y > mid)
	{
		int c = query(x,y,rt<<1|1,mid + 1,r);
		ans = max(ans,c);
	 } 
	return ans;
}

int Query(int a,int b)
{
	int ans = 0,c;
	while(top[a]!=top[b])
	{
		if(d[top[a]]<d[top[b]])
		{
			int temp = a;
			a = b;
			b = temp;			
		}
		c = query(rid[top[a]],rid[a],1,1,n);
		ans = max(c,ans);
		a = f[top[a]];
	}
	if(d[a]>d[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	c = query(rid[a] + 1,rid[b],1,1,n);
	ans = max(c,ans);
	return ans;	
}

int main()
{
	int i;
	char ch;
	int T;
	T = read();
	while(T)
	{
		-- T;
/*		memset(h,0,sizeof h);
		memset(v,0,sizeof v);
		memset(V,0,sizeof V);
		memset(U,0,sizeof U);
		memset(w,0,sizeof w);
		memset(f,0,sizeof f);
		memset(d,0,sizeof d);
		memset(t,0,sizeof t);
		memset(to,0,sizeof to);
		memset(son,0,sizeof son);
		memset(nxt,0,sizeof nxt);
		memset(siz,0,sizeof siz);
		memset(top,0,sizeof top);
		memset(rid,0,sizeof rid);
		memset(rnk,0,sizeof rnk);*/
		tot = cnt = 0;
		n = read();
		for(i = 1;i < n;++ i)
		{
			int a,b,c;
			a = read();
			b = read();
			c = read();
			U[i] = a,V[i] = b;
			add(a,b,c),add(b,a,c);
		}
		dfs1(1);
		dfs2(1,1);
		build(1,n,1);
		while(1)
		{
			ch = nc();
			while(ch > 'Z'||ch < 'A') ch = nc();
			if(ch == 'D')
				break;
			if(ch == 'C')
			{
				int a,b;
				a = read();
				b = read();
				a = d[U[a]] > d[V[a]] ? U[a] : V[a];
				update(rid[a],b,1,1,n);
			}
			else
			{
				int a,b;
				a = read();
				b = read();
				printf("%d\n",Query(a,b));
			}
		}
		for(i = 1;i <= n;++ i)
			h[i] = 0;
	}
	return 0;
}
