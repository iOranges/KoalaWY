#include<cmath>
#include<cstdio>
#include<algorithm>
using std::sort;
struct edge{
	int to,nxt;
}e[200005];
int h[100005],cnt[100005],L[100005],R[100005],tot,idx;
int col[100005],n,m,block,rid[100005],ans[100005],c[100005];
struct node{
	int l,r,id,k;
	bool operator < (const node b){
		return (l / block == b.l / block) ? r < b.r : l < b.l; 
	}
}q[100005];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch >= '0'&&ch <= '9') {x = x * 10 + (ch ^ 48);ch = getc(stdin);} 
}
 
inline int lowbit(int x)
{
	return x & (-x);
}
 
inline void update(int x,int k)
{
	for(int i = x + 1;i <= n + 1;i += lowbit(i))
		c[i] += k;
}
 
inline int query(int x)
{
	int res = 0;
	for(int i = x + 1;i > 0;i -= lowbit(i))
		res += c[i];
	return res; 
}
 
inline void add_edge(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}
 
void dfs(int u,int pre)
{
	L[u] = ++idx;
	rid[idx] = u;
	for(int i = h[u];i;i = e[i].nxt)
		if(e[i].to != pre)
			dfs(e[i].to,u);
	R[u] = idx;
}
 
inline void del(int x)
{
	update(cnt[x]--,-1);
	update(cnt[x],1);
}
 
inline void add(int x)
{
	update(cnt[x]++,-1);
	update(cnt[x],1);
}
 
int main()
{
	int a,b;
	register int i,l = 1,r = 0;
	read(n),read(m);
	block = sqrt(n);
	for(i = 1;i <= n;++ i)
		read(col[i]);
	for(i = 1;i < n;++ i)
	{
		read(a),read(b);
		add_edge(a,b),add_edge(b,a);
	}
	dfs(1,0);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b);
		q[i].l = L[a],q[i].r = R[a];
		q[i].id = i,q[i].k = b;
	}
	sort(q + 1,q + m + 1);
	for(i = 1;i <= m;++ i)
	{
		int ql = q[i].l,qr = q[i].r;
		while(l > ql) add(col[rid[-- l]]);
		while(r < qr) add(col[rid[++ r]]);
		while(l < ql) del(col[rid[l ++]]);
		while(r > qr) del(col[rid[r --]]);
		if(q[i].k!=0)
			ans[q[i].id] = query(n) - query(q[i].k - 1);
		else
			ans[q[i].id] = n;
	}
	for(i = 1;i <= m;++ i)
		printf("%d\n",ans[i]);
	return 0;
}
