#include<bits/stdc++.h>
using namespace std;
long long n,m,tot;
void sw(int x)
{
    while(x>0)
    {
        int a=x%10;
        if(a==m) tot++;
        x/=10;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) sw(i);
    printf("%d",tot);
}
