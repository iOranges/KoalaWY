#include<cstdio>
#include<iostream> 
using namespace std;
int a[50001],n;
struct node{
	int l,r;
	int sum; 
}tree[50001<<2];

void pushup(int rt)
{
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
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
	int m = (l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void update(int p,int c,int rt)
{
	if(tree[rt].l==tree[rt].r)
	{
		tree[rt].sum+=c;
		return;
	}
	int m=(tree[rt].l+tree[rt].r)>>1;
	if(p<=m) update(p,c,rt<<1);
	else update(p,c,rt<<1|1);
	pushup(rt);
}

int query(int l,int r,int rt)
{
	if(l<=tree[rt].l&&tree[rt].r<=r)
		return tree[rt].sum;
	int m=(tree[rt].l+tree[rt].r)>>1,ret=0;
	if(l<=m) ret+=query(l,r,rt<<1); 
	if(m<r) ret+=query(l,r,rt<<1|1); 
	return ret;
}

int main()
{
	int t,i,j,p,q;
	char s[20];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
			scanf("%d",&a[j]);
		build(1,n,1);
		printf("Case %d:\n",i);
		while(1)
		{
			scanf("%s",s); 
			if(s[0]=='E')
				break;
			scanf("%d%d",&p,&q);
			if(s[0]=='Q')
				printf("%d\n",query(p,q,1));
			else if(s[0]=='A')
				update(p,q,1);
			else if(s[0]=='S')
				update(p,-q,1);		
		}
	}
	return 0;
 } 
