#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1005],n,k,tot,sum;
int main()
{
    scanf("%lld%lld",&n,&k);
    while(k) {a[++tot]=k%2;k/=2;}
    for(int i=tot;i>=1;i--) sum+=pow(n,i-1)*a[i];
    printf("%lld",sum);
}
