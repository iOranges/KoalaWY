#include<bits/stdc++.h>
using namespace std;
long long tot1,tot2,tot3,n,s[5],c[5],minn;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3;i++)
        scanf("%d%d",&s[i],&c[i]);
    while(tot1*s[1]<n) tot1++;
    while(tot2*s[2]<n) tot2++;
    while(tot3*s[3]<n) tot3++;
    minn=min(min(tot1*c[1],tot2*c[2]),tot3*c[3]);
    printf("%d",minn);
}
