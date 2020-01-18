#include<cstdio>
const long long p = 10007;
long long fac[1005];
long long quick_pow(long long a,long long b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

int main()
{
	int n,m,k;
	long long a,b;
	scanf("%lld%lld%d%d%d",&a,&b,&k,&n,&m);
	fac[0] = fac[1] = 1;
	for(register int i = 2;i <= k;++ i)
		fac[i] = fac[i - 1] * i % p;
	printf("%lld",fac[k] * quick_pow(fac[n] * fac[m] % p,p - 2) * quick_pow(a,n) % p * quick_pow(b,m) % p);
	return 0;
}
