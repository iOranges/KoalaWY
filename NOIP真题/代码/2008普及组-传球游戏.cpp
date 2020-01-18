#include<bits/stdc++.h>
using namespace std;
long long a[32][32],b[32][32],d[32][32],n,k;
void mul()
{
    memset(d,0,sizeof d);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                d[i][j]+=a[i][k]*b[k][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=d[i][j];
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++) b[i][i+1]=a[i][i+1]=1;
    b[n][1]=a[n][1]=1;
    for(int i=2;i<=n;i++) b[i][i-1]=a[i][i-1]=1;
    b[1][n]=a[1][n]=1;
    for(int i=1;i<k;i++) mul();
    printf("%lld ",a[1][1]);
}
