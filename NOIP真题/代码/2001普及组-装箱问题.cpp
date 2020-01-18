#include<bits/stdc++.h>
using namespace std;
int dp[20005],v[35],m,n;
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
    printf("%d",m-dp[m]);
}
