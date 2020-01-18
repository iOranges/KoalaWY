#include<cstdio>
#define ll long long
const ll p = 100003;
ll ksm(ll a,ll b)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1) ans = a * ans % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

int main()
{
	long long n,m;
	scanf("%lld%lld",&m,&n);
	printf("%lld",(ksm(m,n) - m * ksm(m - 1,n - 1) % p + p) % p);
	return 0;
}
