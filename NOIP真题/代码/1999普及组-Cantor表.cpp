#include<bits/stdc++.h>
using namespace std;
int n,sum,k;
int main()
{
    scanf("%d",&n);
    int l=0,r=n,mid=(l+r)/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(mid*(mid+1)/2<=n)
        {
            k=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    sum=n-k*(k+1)/2;
//  cout<<k<<' '<<sum<<endl;
    if(!sum)
    {
        if(k%2) cout<<1<<'/'<<k;
        else cout<<k<<'/'<<1;
    }
    else
    {
        k++;
        if(k%2==0) cout<<sum<<'/'<<k+1-sum;
        else cout<<k+1-sum<<'/'<<sum;
    }
}
