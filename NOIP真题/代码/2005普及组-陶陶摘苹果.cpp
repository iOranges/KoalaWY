#include<bits/stdc++.h>
using namespace std;
int a[11],k,tot;
int main()
{
    for(int i=1;i<=10;i++) scanf("%d",&a[i]);
    scanf("%d",&k);
    for(int i=1;i<=10;i++)
        if(a[i]<=k+30) tot++;
    printf("%d",tot);
}
