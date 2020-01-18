#include<bits/stdc++.h>
using namespace std;
int dx[9]={1,1,2,2,-1,-1,-2,-2,0};
int dy[9]={2,-2,1,-1,2,-2,1,-1,0};
int n,m,x,y;
long long dp[30][30]={1};
bool f[30][30];
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=0;i<9;i++)f[x+dx[i]+5][y+dy[i]+5]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            if(!(i==0&&j==0)&&!f[i+5][j+5])dp[i][j]=dp[i==0?i:i-1][j]+dp[i][j==0?j:j-1];
    printf("%lld\n",dp[n][m]);return 0;
}
