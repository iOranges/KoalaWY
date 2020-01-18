#include<bits/stdc++.h>
using namespace std;
int n,a[505][505],maxn,vis[505];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
        }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);vis[i]=1;
        int maxx=0,w,sum=0;
        for(int j=1;j<=n;j++)
            if(maxx<a[i][j]&&vis[j]==0) {maxx=a[i][j];w=j;}
        vis[w]=1;
        for(int j=1;j<=n;j++)
            if(j!=w&&vis[j]==0) sum=max(sum,a[i][j]);
        maxn=max(maxn,sum);
    }
    printf("1\n%d",maxn);
}
