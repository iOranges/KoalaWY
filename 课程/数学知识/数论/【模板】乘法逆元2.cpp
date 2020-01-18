#include<cstdio>
#define ll long long
ll a[5000006],sum[5000006];
inline void read(ll &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

ll ksm(ll a,ll b,ll p)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1) ans = (ans * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ans;
}

int main()
{
	register int i;
	ll p,k,n,ans = 0,all,s = 1,K = 1;
	read(n),read(p),read(k);
	for(i = 1;i <= n;++ i)
		read(a[i]);
	sum[1] = 1;
	for(i = 1;i < n;++ i)
		sum[i+1] = (sum[i] * a[i]) % p;
	all = (sum[n] * a[n]) % p;
	for(i = n;i > 1;-- i)
	{
		s = (s * a[i]) % p;
		sum[i-1] = (sum[i-1] * s) % p;		
	}
	for(i = 1;i <= n;++ i)
	{
		K = (k * K) % p;
		ans = (ans + (K * sum[i]) % p) % p;		
	}
	ans = (ans * ksm(all,p-2,p)) % p;
	printf("%lld",ans);
	return 0;
 } 
