#include<cstdio>
#include<cstring>
long long f[2005][2005];
const long long p = 1e9 + 7;
long long power(long long a,int b)
{
	long long ans = 1;
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
	int t,n,m;
	register int i,j;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&n,&m);
		memset(f,0,sizeof f);
		f[1][1] = m;
		for(i = 2;i <= n;++ i)
			for(j = 1;j <= m&&j <= i;++ j)
				f[i][j] = (f[i - 1][j] * j % p + f[i - 1][j - 1] * (m - j + 1) % p) % p;
		long long ans = 0;
		for(i = 1;i < m;++ i)
			ans = (ans + f[n][i] * power(m - i,n) % p) % p;
		printf("%lld\n",ans);
	}
	return 0;
}
