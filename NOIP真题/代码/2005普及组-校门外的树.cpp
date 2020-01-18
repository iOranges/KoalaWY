#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],b[105],vis[10005],tot;
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        for(int j=a[i];j<=b[i];j++)
            vis[j]=1;
    }
    for(int i=0;i<=m;i++)
        if(!vis[i]) tot++;
    cout<<tot;
}
