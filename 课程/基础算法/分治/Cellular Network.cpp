#include<cstdio>
int n,m,c[100005],t[100005];

bool check(int k)
{
	int j = 1;
	for(int i=1;i<=m;i++)
	{
		while(1ll * c[j] >= 1ll * t[i] - k&&1ll * c[j] <= 1ll * t[i] + k&&j <= n) ++j;
		if(j == n + 1) return false;
	}
	return true;
}

int main()
{
	int i;
	long long l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);	
	for(i=1;i<=m;i++)
		scanf("%d",&t[i]);
	r = 2000000000;
	l = 0;
	while(l<=r)
	{
		mid = (l + r) >> 1;
		if(check((int)mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%lld",l);
	return 0;
}
