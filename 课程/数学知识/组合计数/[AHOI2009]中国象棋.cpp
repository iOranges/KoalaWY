#include<cstdio>
const long long p = 9999973;
long long f[105][105][105];

inline long long C(long long x)
{
	return (x * (x - 1) / 2) % p;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	register int i,j,k;
	f[0][0][0] = 1;
	for(i = 1;i <= n;++ i)
		for(j = 0;j <= m;++ j)
			for(k = 0;k <= m - j;++ k)
			{
				f[i][j][k] = f[i - 1][j][k];
				if(j > 0)
					f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k] * (m - k - j + 1) % p) % p;
				if(k > 0)
				{
					f[i][j][k] = (f[i][j][k] + f[i - 1][j + 1][k - 1] * (j + 1) % p) % p;	
					f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1] * (m - j - k + 1) * j % p) % p;
				}
				if(j > 1) f[i][j][k] = (f[i][j][k] + f[i - 1][j - 2][k] * C(m - k - j + 2) % p) % p;
				if(k > 1) f[i][j][k] = (f[i][j][k] + f[i - 1][j + 2][k - 2] * C(j + 2) % p) % p;
			}
	long long ans = 0;
	for(i = 0;i <= m;++ i)
		for(j = 0;j <= m;++ j)
			ans = (ans + f[n][i][j]) % p;
	printf("%lld",ans);
	return 0;
}
