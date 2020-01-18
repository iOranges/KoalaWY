#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,a[18][18],dp[18][18];
//第i列中所有元素的值w
//第i列与第j列之间，所有同行元素的差的绝对值的和h
int w[18],h[18][18],f[18],sum=0x7fffffff;
void dfs(int x,int y)
{
	if(y>r)
	{
		memset(dp,0x7f,sizeof(dp));
		memset(w,0,sizeof(w));
		memset(h,0,sizeof(h)); 
		for(int i=1;i<=m;i++)
			for(int j=1;j<r;j++)
				w[i]+=abs(a[f[j]][i]-a[f[j+1]][i]);
		for(int i=1;i<=m;i++) 
			for(int j=i+1;j<=m;j++) 
				for(int k=1;k<=r;k++)
					h[i][j]+=abs(a[f[k]][i]-a[f[k]][j]);
		dp[0][0]=0;
		for(int i=1;i<=c;i++) //选了i列
			for(int j=i;j<=m;j++) //最后一列为j
				for(int k=0;k<j;k++) //枚举上一次选的列数
					dp[i][j]=min(dp[i-1][k]+w[j]+h[k][j],dp[i][j]);
		for(int i=c;i<=m;i++) sum=min(sum,dp[c][i]);
		return;
	}
	if(x>n) return;
	dfs(x+1,y);
	f[y]=x;
	dfs(x+1,y+1); 
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	dfs(1,1);
	printf("%d",sum);
}
