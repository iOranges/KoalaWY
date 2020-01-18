#include<bits/stdc++.h>
using namespace std;
int n,ans,k;
int main()
{
    scanf("%d",&n);
    int l=1,r=n,mid=(l+r)/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(mid*(mid+1)/2<=n)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
//  cout<<ans<<endl;
    k=ans*(ans+1)*(2*ans+1)/6;
    for(int i=ans*(ans+1)/2+1;i<=n;i++) k+=ans+1;
    printf("%d",k);
}
