#include<cstdio>
const int N = 5e5 + 5;
const long long p = 1e9 + 7;
int a[N],b[N];
long long sa[N],sb[N],ssa[N],ssb[N],ssab[N];

int main()
{
	int n;
	scanf("%d",&n);
	register int i,j;
	for(i = 1;i <= n;++ i)
	{
		scanf("%d",&a[i]);
		sa[i] = (sa[i - 1] + a[i]) % p;
	}
	for(i = 1;i <= n;++ i)
	{
		scanf("%d",&b[i]);
		sb[i] = (sb[i - 1] + b[i]) % p;
	}
	long long ans = 0;
	for(i = 1;i <= n;++ i)
	{
		ssab[i] = (ssab[i - 1] + sa[i] * sb[i] % p) % p;	
		ssa[i] = (ssa[i - 1] + sa[i]) % p;
		ssb[i] = (ssb[i - 1] + sb[i]) % p;
	}
	for(i = 1;i <= n;++ i)
		ans = ((ans + (ssab[n] - ssab[i - 1] + p) % p + sa[i - 1] * sb[i - 1] % p * (n - i + 1) % p - sb[i - 1] * ((ssa[n] - ssa[i - 1] + p) % p) % p + p) % p - sa[i - 1] * ((ssb[n] - ssb[i - 1] + p) % p) % p + p) % p;
	printf("%lld",ans);
	return 0;
}
