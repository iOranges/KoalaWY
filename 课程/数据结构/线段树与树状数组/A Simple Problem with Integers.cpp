#include<cstdio>
struct node{
	int l,r;
	long long lazy;
	long long sum;
}tree[100001<<2];
int n,q;
int a[100001];

void pushup(int rt)
{
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}

void pushdown(int rt)
{
	if(tree[rt].lazy)
	{
		int res=tree[rt].r - tree[rt].l+1;
		tree[rt<<1].lazy+=tree[rt].lazy;
		tree[rt<<1|1].lazy+=tree[rt].lazy;
		tree[rt<<1].sum+=(res-(res>>1))*tree[rt].lazy; 
		tree[rt<<1|1].sum+=(res>>1)*tree[rt].lazy;
		tree[rt].lazy=0;
	}
}

void build(int l,int r,int rt)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if(l==r)
	{
		tree[rt].sum = a[l];
		return;
	}
	int m = (l+r) >> 1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void update(int x,int y,int c,int rt)
{
	int l = tree[rt].l,r = tree[rt].r;
	if(x==l&&y==r)
	{
		tree[rt].sum += (long long)(r-l+1)*c;
		tree[rt].lazy += c;
		return;
	 } 
	pushdown(rt);
	int m=(l+r)>>1;
	if(m>=y) update(x,y,c,rt<<1);
	else if(x>m) update(x,y,c,rt<<1|1);
	else 
	{
		update(x,m,c,rt<<1);
		update(m+1,y,c,rt<<1|1);
	}
	pushup(rt);
}

long long query(int x,int y,int rt)
{
	int l = tree[rt].l,r = tree[rt].r;
	if(x==l&&y==r)	return tree[rt].sum;
	pushdown(rt);
	int m = (l+r)>>1;
	if(m>=y) return query(x,y,rt<<1);
	else if(x>m) return query(x,y,rt<<1|1);
	else return query(x,m,rt<<1)+query(m+1,y,rt<<1|1);
}

int main()
{
	int i,x,y,k;
	char ch[10];
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,n,1);
	for(i=1;i<=q;i++)
	{
		scanf("%s",ch);
		if(ch[0] == 'C')
		{
			scanf("%d%d%d",&x,&y,&k);
			update(x,y,k,1);
		}
		else
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(x,y,1));
		}
	}
	return 0;
}
