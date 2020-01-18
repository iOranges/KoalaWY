#include<bits/stdc++.h>
using namespace std;
int n,m,f[105][105],a[1000005];
int main()
{
	scanf("%d%d",&n,&m);f[0][0]=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=a[i];k++)
			{
				if(j<k) continue;
				f[i][j]=(f[i-1][j-k]+f[i][j])%1000007;
			}
	printf("%d",f[n][m]);
}
