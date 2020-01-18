#include<cstdio>
#include<cstring>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
int n,m,a[1000005],c[1000005];
struct node{
	int st,ed,d;
}b[1000005];

inline int lowbit(int x)
{
	return x & (-x);
}

inline void add(int x,int k)
{
	for(register int i=x;i<=n;i+=lowbit(i))
		c[i] += k;
}

int query(int x)
{
	int ans = 0;
	for(register int i=x;i>0;i-=lowbit(i))
		ans += c[i];
	return ans;
}

bool check(int k)
{
	register int i;
	memset(c,0,sizeof c);
	for(i=1;i<=k;++i)
		add(b[i].st,b[i].d),add(b[i].ed+1,-1*b[i].d);
	for(i=1;i<=n;++i)
		if(query(i) > a[i])
			return false;
	return true;
}

int main()
{
	int i,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&b[i].d,&b[i].st,&b[i].ed);
	l = 1,r = m;
	while(l<=r)
	{
		mid = (l + r) >> 1;
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	if(l == m + 1)	printf("0");
	else printf("-1\n%d",r+1);
	return 0;
}
