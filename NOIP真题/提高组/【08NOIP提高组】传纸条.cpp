#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
int f[55][55][55],mp[55][55];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	register int i,j,k,p;
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= m;++ j)
			scanf("%d",&mp[i][j]);
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= m;++ j)
			for(k = 1;k <= n;++ k)
			{
				p = i + j - k;
				if(p <= 0) break;
				if(p > m || (i == k&&j == p&&((i != n)||(j != m)))) continue;
				f[i][j][k] = max(f[i - 1][j][k] + mp[i][j] + mp[k][p],f[i][j][k]);
				f[i][j][k] = max(f[i][j - 1][k] + mp[i][j] + mp[k][p],f[i][j][k]);
				f[i][j][k] = max(f[i - 1][j][k - 1] + mp[i][j] + mp[k][p],f[i][j][k]);
				f[i][j][k] = max(f[i][j - 1][k - 1] + mp[i][j] + mp[k][p],f[i][j][k]);
			}
	printf("%d",f[n][m][n]);
	return 0;
}
