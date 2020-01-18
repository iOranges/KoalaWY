#include<cstdio>
#define ll long long
inline void read(ll &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

ll msc(ll a,ll b,ll p)
{
	ll ans = 0;
	while(b)
	{
		if(b&1) ans = (ans + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return ans;
}

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
	ll n,ai,mi,x,y,ans,m,k,c,p;
	register int i;
	read(n),read(mi),read(ai);
	m = mi,ans = ai;
	for(i = 2;i <= n;++ i)
	{
		read(mi),read(ai);
		c = (ai - ans % mi + mi) % mi;
		k = exgcd(m,mi,x,y); 
		p = mi / k;
		ans += m * msc(x,c/k,p);
		m *= p;
		ans = (ans%m + m) % m;
	}
	printf("%lld",ans);
	return 0;
}
