#include<cstdio>
long long quick_pow(long long a,long long b,long long p)
{
	long long ans = 1;
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
	long long n,k,m,x;
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	printf("%lld",(x + quick_pow(10,k,n) * m % n) % n);
	return 0;
}
