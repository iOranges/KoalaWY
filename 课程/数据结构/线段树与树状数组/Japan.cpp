#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
int c[1001],n,m;
struct node{
	int x,y;
}a[1000001];

bool cmp(node p,node q)
{
	if(p.x != q.x)
		return p.x < q.x;
	return p.y < q.y;
}

inline int lowbit(int k)
{
	return k&(-k);
}

void add(int x)
{
	for(int i=x;i<=m;i+=lowbit(i))
		c[i]++;
}

int query(int x)
{
	int ret=0;
	for(int i=x;i>=1;i-=lowbit(i))
		ret+=c[i];
	return ret;
}

int main()
{
	int i,k,x,t,p,y;
	long long ans;
	scanf("%d",&t);
	for(p=1;p<=t;p++)
	{
		ans = 0;
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=k;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a+1,a+1+k,cmp);
		for(i=1;i<=k;i++)
		{
			add(a[i].y);
			ans = ans+i-query(a[i].y);
		}
		printf("Test case %d: %lld\n",p,ans);
	}
	return 0;
}
