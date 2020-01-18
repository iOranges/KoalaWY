#include<bits/stdc++.h>
using namespace std;
int s[1005][1005],dp[1005],n,m,p,c[1005],sum,q;
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	memset(dp,-0x7f,sizeof dp);
	dp[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&s[i][j]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(j==1) q=n;
			else q=j-1;
			sum=s[q][i];
			for(int k=1;k<=p;k++)
			{
				if(i-k<0) break;
				dp[i]=max(dp[i],dp[i-k]+sum-c[q]);
				q--;
				if(!q) q=n;
				sum+=s[q][i-k];
			}
		}
	printf("%d",dp[m]);
}
