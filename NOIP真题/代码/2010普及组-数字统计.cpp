#include<bits/stdc++.h>
using namespace std;
int m,n,tot;
void js(int x)
{
    while(x)
    {
        if(x%10==2) tot++;
        x/=10;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=n;i<=m;i++) js(i);
    printf("%d",tot);
}
