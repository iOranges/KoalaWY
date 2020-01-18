#include<cstdio>
#include<cstring>
#define N 205
#define max(x,y) ((x) > (y) ? (x) : (y))
int a[N],f[N][N],dp[N][N];

int main()
{
	int n,ans = 0;
	scanf("%d",&n);
	register int i,j,k;
	for(i = 1;i <= n;++ i)
		scanf("%d",&a[i]),a[i + n] = a[i];
	for(i = 2;i < 2 * n;++ i)
		for(j = i - 1;i - j < n&&j >= 1;-- j)
			for(k = j;k <= i - 1;++ k)
				f[j][i] = max(f[j][i],f[j][k] + f[k + 1][i] + a[k + 1] * a[j] * a[i + 1]);
	for(i = 1;i <= n;++ i)
		ans = max(ans,f[i][i + n - 1]);
	printf("%d",ans);
	return 0;
}
