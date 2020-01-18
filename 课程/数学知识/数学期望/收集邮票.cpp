#include<cstdio>
double f[10005],dp[10005];

int main()
{
	int n;
	scanf("%d",&n);
	register int i;	
	dp[n] = f[n] = 0;
	for(i = n - 1;i >= 0;-- i)
	{
		dp[i] = dp[i + 1] + (1.0 * n) / (n - i);
//		f[i] = (1.0 * i) / n * (dp[i] + f[i] + 1) + (n - i) / (1.0 * n) * (dp[i + 1] + f[i + 1] + 1);
		f[i] = (i * dp[i] + (n - i) * dp[i + 1] + (n - i) * f[i + 1] + n) / (n - i);
	}
	printf("%.2lf",f[0]);
	return 0;
 } 
