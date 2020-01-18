#include<cstdio>
#include<algorithm>
#define rint register int
using std::sort;
int c[1000005],h[1000005],num[1000005],n,res[1000005];
struct node{
	int l,r,p;
	bool operator < (node next) const{
		return this->r < next.r;
	}
}q[1000005];

inline int lowbit(int x)
{
	return x & (-x);
}

void add(int x,int k)
{
	for(rint i = x;i <= n;i += lowbit(i))
		c[i] += k;
}

int query(int x)
{
	int ans = 0;
	for(rint i = x;i > 0;i -= lowbit(i))
		ans += c[i];
	return ans;
}

int main()
{
	rint i,j;
	int m,p = 1;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		scanf("%d",&num[i]);
	scanf("%d",&m);
	for(i = 1;i <= m;++ i)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].p = i;
	}
	sort(q+1,q+m+1);
	for(i = 1;i <= m;++ i)
	{
		for(j = p;j <= q[i].r;++ j)
		{
			if(h[num[j]])
				add(h[num[j]], -1);
			h[num[j]] = j;
			add(j,1);
		}
		p = q[i].r + 1;
		res[q[i].p] = query(q[i].r) - query(q[i].l - 1);
	}
	for(i = 1;i <= m;++ i)
		printf("%d\n",res[i]);
	return 0;
}
