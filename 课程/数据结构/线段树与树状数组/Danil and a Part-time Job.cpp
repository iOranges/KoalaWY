#include<cstdio>
bool v[200005],lzy[200005<<2];
int n,tot,h[200005],L[200005],R[200005],cnt,sum[200005<<2],siz[200005<<2];
struct node{
	int son,next;
}t[400005];

void add(int a,int b)
{
	t[++tot].son = b;
	t[tot].next = h[a];
	h[a] = tot;
}

void dfs(int u)
{
	L[u] = ++ cnt;
	for(int i=h[u];i;i=t[i].next)
		dfs(t[i].son);
	R[u] = cnt;
}

inline void pushdown(int rt)
{
	if(lzy[rt])
	{
		sum[rt<<1] = siz[rt<<1] - sum[rt<<1];
		sum[rt<<1|1] = siz[rt<<1|1] - sum[rt<<1|1];
		lzy[rt<<1] = !lzy[rt<<1];
		lzy[rt<<1|1] = !lzy[rt<<1|1];
		lzy[rt] = false;
	}
}

inline void pushup(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l,int r,int rt)
{
	if(l == r)
	{
		sum[rt] = v[l];	
		siz[rt] = 1;
		return ;	
	}
	int mid = (l + r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
	siz[rt] = siz[rt<<1] + siz[rt<<1|1];
}

void update(int x,int y,int rt,int l,int r)
{
	if(x <= l&&y >= r)
	{
		sum[rt] = siz[rt] - sum[rt];
		lzy[rt] = !lzy[rt];
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(x <= mid) update(x,y,rt<<1,l,mid);
	if(y > mid) update(x,y,rt<<1|1,mid+1,r);
	pushup(rt);
}

int query(int x,int y,int rt,int l,int r)
{
	if(x == l&&y == r)
		return sum[rt];
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(y <= mid) return query(x,y,rt<<1,l,mid);
	else if(x > mid) return query(x,y,rt<<1|1,mid+1,r);
	else return query(x,mid,rt<<1,l,mid) + query(mid+1,y,rt<<1|1,mid+1,r);
}

int main()
{
	int i,x,m;
	char ch[10];
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		add(x,i);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		v[L[i]] = (bool)x;		
	}	
	build(1,n,1);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%s%d",ch,&x);
		if(ch[0] == 'p')
			update(L[x],R[x],1,1,n);
		else
			printf("%d\n",query(L[x],R[x],1,1,n));
	}
	return 0;
}
