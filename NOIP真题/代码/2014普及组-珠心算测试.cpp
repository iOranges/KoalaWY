#include<bits/stdc++.h>
using namespace std;
int n,a[105],tot,s[20005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            s[a[i]+a[j]]=1;
    for(int i=1;i<=n;i++) if(s[a[i]]) tot++;
    printf("%d",tot);
}
