#include<bits/stdc++.h>
using namespace std;
int n,a[205],tot=200;
int main()
{
    scanf("%d",&n);a[1]=1;
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=n;j++) a[j]*=2;
        for(int k=1;k<=n;k++)
            if(a[k]>=10){a[k+1]+=1;a[k]%=10;}
    }a[1]-=2;
    while(!a[tot]&&tot>1) tot--;
    for(int i=tot;i>=1;i--) printf("%d",a[i]);
}
