#include<cstdio>
#include<cstring>
#define min(x,y) ((x) > (y) ? (y) : (x))
const long long p = 1000000007;
char a[1005],b[205];
long long f[2][1005][205],ans,sum[2][205][1005];

int main()
{
	int n,m,K,q,o;
	register int i,j,k,l;
	scanf("%d%d%d%s%s",&n,&m,&K,a + 1,b + 1);
	for(i = 1;i <= n;++ i)
		if(a[i] == b[1])
			f[1][i][1] = 1;
	for(l = 1;l <= K;++ l)
	{
		q = l % 2;
		if(l != 1) memset(f[q],0,sizeof f[q]);	
		memset(sum[q],0,sizeof sum[q]);
		for(j = l;j <= m;++ j)
		{
			for(i = 1;i <= n;++ i)
				if(a[i] == b[j])
				{
					f[q][i][j] = (f[q][i][j] + sum[q ^ 1][j - 1][i - 1])% p;
					if(a[i - 1] == b[j - 1]) f[q][i][j] = (f[q][i][j] + f[q][i - 1][j - 1]) % p;
					sum[q][j][i] = (sum[q][j][i - 1] + f[q][i][j]) % p;
				}
				else sum[q][j][i] = sum[q][j][i - 1];
		}
	}
	for(i = 1;i <= n;++ i)
		ans = (ans + f[K % 2][i][m]) % p;
	printf("%lld",ans);
	return 0;
}
