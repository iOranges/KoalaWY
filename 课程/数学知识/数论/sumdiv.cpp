#include<cmath>
#include<cstdio>
const long long p = 9901;
int prime[1000005],cnt[1000005],tot;
long long qpow(long long a,long long b)
{
	long long ans = 1;
	while(b)
	{
		if(b&1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1; 
	}
	return ans;
}

void work(int a)
{
	for(register int i = 2;i <= a;++ i)
		if(a % i == 0)
		{
			prime[++tot] = i;
			++ cnt[tot];
			a /= i;
			while(a % i == 0)
			{
				a /= i;
				++cnt[tot];
			}
		}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	work(a);
	long long sum = 1;
	for(register int i = 1;i <= tot;++ i)
		if(prime[i] % p == 1)
			sum = sum * (cnt[i] * b + 1) % p;
		else
			sum = (sum * (((qpow(prime[i],(cnt[i] * b + 1)) - 1 + p) % p) * qpow(prime[i] - 1,p - 2) % p)) % p;
	printf("%lld",sum);
	return 0;
}
