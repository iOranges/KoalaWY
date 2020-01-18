#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int w[21][21],dp[1<<20][21];

int main()
{
	int n,i,j,m,k,minn = 0x7ffffff;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&w[i][j]);
	m = (1<<n) - 1;
	memset(dp,0x7f,sizeof dp);
	dp[1][0] = 0;
	for(i=1;i<=m;i+=2)
		for(j=0;j<n;++j)
			if((i>>j)&1)
				for(k=0;k<n;++k)
					if((i >> k) & 1 && j != k)
						dp[i][j] = min(dp[i][j],dp[i^(1<<j)][k]+w[k][j]);
	for(i=0;i<n;i++)
		minn = min(dp[m][i] + w[i][0],minn);
	printf("%d",minn);
	return 0;
}
