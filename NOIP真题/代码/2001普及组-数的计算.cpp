#include<bits/stdc++.h>
using namespace std;
int n,a[1005]={1};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i%2==1) a[i]=a[i-1];
        else a[i]=a[i-1]+a[i/2];
    }
    printf("%d",a[n]);
}
