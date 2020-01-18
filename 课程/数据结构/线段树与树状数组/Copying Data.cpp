#include<cstdio>
int n,m,cnt,a[100005],b[100005],t[100005<<2],la[100005],lb[100005];

inline void pushdown(int rt)
{
	if(t[rt])
	{
		t[rt<<1] = t[rt<<1|1] = t[rt];
		t[rt] = 0;
	}
}

void update(int x,int y,int c,int rt,int l,int r)
{
	if(x <= l&& y >= r)
	{
		t[rt] = c;
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if(x <= mid) update(x,y,c,rt<<1,l,mid);
	if(y > mid) update(x,y,c,rt<<1|1,mid+1,r);
}

int query(int x,int rt,int l,int r)
{
	if(l == r)
		return t[rt];
	pushdown(rt);
	int mid = (l+r) >> 1;
	if(x <= mid) return query(x,rt<<1,l,mid);
	else if(x > mid) return query(x,rt<<1|1,mid+1,r);
}

int main()
{
	int i,op,k,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if(op == 1)
		{
			++ cnt;
			scanf("%d%d%d",&la[cnt],&lb[cnt],&k);
			update(lb[cnt],lb[cnt]+k-1,cnt,1,1,n);
		}
		else
		{
			scanf("%d",&x);
			k = query(x,1,1,n);
			if(!k) printf("%d\n",b[x]);
			else
				printf("%d\n",a[la[k] + x - lb[k]]);
		}
	}
	return 0;
}
