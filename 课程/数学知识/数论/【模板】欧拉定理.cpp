#include<cstdio>
long long p;
long long qpow(long long a,long long b)
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
	bool flag = false;
	int a,t,phi;
	long long b = 0;
	scanf("%d%lld",&a,&p);
	register int i;
	t = phi = p;
	for(i = 2;i * 1ll * i <= t;++ i)
		if(t % i == 0)
		{
			phi = phi - phi / i;
			while(t % i == 0) t /= i;
		}
	if(t > 1) phi = phi - phi / t;
	char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0')
	{
		b = b * 10 + (ch ^ 48);
		if(b >= phi) b %= phi,flag = true;
		ch = getc(stdin);
	}
	if(flag) b += phi;
	printf("%lld",qpow(a,b));
	return 0;
}
