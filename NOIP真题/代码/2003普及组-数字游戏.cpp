#include<bits/stdc++.h>
using namespace std;
int n,m,s[102],f[102][102][10],h,ans=1e9,c[102],ff[102][102][10],maxx;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]),s[n+i]=s[i];
	for(int i=1;i<=n*2;i++) c[i]=c[i-1]+s[i];
	for(int i=1;i<=n*2;i++)
		for(int j=i;j<=n*2;j++)
			for(int k=1;k<=m;k++)
			{
				if(k<2)
				{
					ff[i][j][k]=((ff[i][j-1][k]+s[j])%10+10)%10;
					f[i][j][k]=((f[i][j-1][k]+s[j])%10+10)%10;
				}
				else f[i][j][k]=1e9;
			}
	for(int i=2;i<=m;i++)
		for(int j=1;j<=n*2;j++)
			for(int k=i+j-1;k<=n*2;k++)
				for(int l=i+j-1;l<=k;l++)
				{
					f[j][k][i]=min(f[j][k][i],f[j][l-1][i-1]*(((c[k]-c[l-1])%10+10)%10));
					ff[j][k][i]=max(ff[j][k][i],ff[j][l-1][i-1]*(((c[k]-c[l-1])%10+10)%10));
				}
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,f[i][n+i-1][m]);
		maxx=max(maxx,ff[i][n+i-1][m]);
	}
	printf("%d\n%d",ans,maxx);
}
