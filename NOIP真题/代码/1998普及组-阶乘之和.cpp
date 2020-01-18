#include<bits/stdc++.h>
using namespace std;
int a[500],sum[500];
void mmp(int x)
{
    for(int i=1;i<=a[0];i++)a[i]*=x;
    for(int i=1;i<=a[0];i++)
    {
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    int k=a[0];
    while(a[k+1]>0)k++;
    a[0]=k;
    while(a[k]>10)
    {
        a[k+1]+=a[k]/10;
        a[k]%=10;
        k++;
    }
    a[0]=k;
}
void add()
{
    if(sum[0]<=a[0]) sum[0]=a[0];
    for(int i=1;i<=sum[0];i++)
    {
        sum[i]+=a[i];
        sum[i+1]+=sum[i]/10;
        sum[i]%=10;
    }
    if(sum[sum[0]+1]>0) sum[0]+=1;
}
int main()
{
    int n;cin>>n;
    a[0]=a[1]=1;sum[0]=1;sum[1]=0;
    for(int i=1;i<=n;i++)
    {
        mmp(i);
        add();
    }
    for(int i=sum[0];i>=1;i--) cout<<sum[i];
}
