#include<bits/stdc++.h>
using namespace std;
int a[45],s[45][45],dp[45][8],n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%1d",&a[i]);
        s[i][i]=a[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            s[i][j]+=10*s[i][j-1]+a[j];
    for(int i=1;i<=n;i++) dp[i][0]=s[1][i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            for(int l=j;l<i;l++)
                dp[i][j]=max(dp[i][j],dp[l][j-1]*s[l+1][i]);
    printf("%d",dp[n][k]);
}
