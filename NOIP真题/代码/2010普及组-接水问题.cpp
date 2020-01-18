#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
int a[10005],s[105],n,m,k,maxx=-inf;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int minn=inf;
        for(int j=1;j<=m;j++)
            if(s[j]<minn){minn=s[j];k=j;}
        s[k]+=a[i];
    }
    for(int i=1;i<=m;i++)
        maxx=max(maxx,s[i]);
    cout<<maxx;
}
