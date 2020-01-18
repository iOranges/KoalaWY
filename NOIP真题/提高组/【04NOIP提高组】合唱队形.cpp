#include<cstdio>
#define min(x,y) ((x) < (y) ? (x) : (y))
int a[105],dp[105][2];

int main()
{
	int n,minn = 0x7ffffff;
	register int i,j;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		scanf("%d",&a[i]);
	dp[n][0] = dp[1][1] = 1;
	for(i = n - 1;i > 0; --i)
	{
		int k = 0;
		for(j = i + 1;j <= n;++ j)
			if(a[i] > a[j]&&dp[j][0] > dp[k][0])
				k = j;
		dp[i][0] = dp[k][0] + 1;
	}
	for(i = 2;i <= n;++ i)
	{
		int k = 0;
		for(j = i - 1;j > 0;-- j)
			if(a[i] > a[j]&&dp[j][1] > dp[k][1])
				k = j;
		dp[i][1] = dp[k][1] + 1;
	}
	for(i = 1;i <= n;++ i)
		minn = min(minn,n - dp[i][1] - dp[i][0] + 1);
	printf("%d",minn);
	return 0;
}
