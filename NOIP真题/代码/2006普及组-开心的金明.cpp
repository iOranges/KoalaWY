#include<bits/stdc++.h>
using namespace std;
int m,n,w[30],c[30],a,dp[30005];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&a);
        c[i]=w[i]*a;
    }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
    printf("%d",dp[m]);
}
