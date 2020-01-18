#include<cstdio>
#define ll long long
long long a[15],b[15];

ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x = 1,y = 0;
		return a;
	}
	ll ans = exgcd(b,a%b,x,y);
	ll z = x;
	x = y;
	y = z - a / b * y;
	return ans;
}

int main()
{
	int n;
	ll ai,mi,m = 1,M,t,ans = 0,x,y;
	register int i;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
	{
		scanf("%d%d",&b[i],&a[i]);
		m *= b[i];
	}
	for(i = 1;i <= n;++ i)
	{
		M = m / b[i];
		exgcd(M,b[i],x,y);
		ans += x * M * a[i];
	}
	ans = (ans%m + m) % m;
	printf("%lld",ans);
	return 0;
}
