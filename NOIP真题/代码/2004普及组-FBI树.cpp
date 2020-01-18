#include<bits/stdc++.h>
using namespace std;
int n;
char a[1050];
void fuck(int l,int r)
{
    int mid=(l+r)/2;
    if(l!=r)
    {
        fuck(l,mid);
        fuck(mid+1,r);
    }
    int tot1=0,tot2=0;
    for(int i=l;i<=r;i++)
    {
        if(a[i]=='1') tot1++;
        else tot2++;
    }
    if(tot1&&tot2) printf("F");
    else if(!tot1) printf("B");
    else printf("I");
}
int main()
{
    scanf("%d%s",&n,a+1);
    fuck(1,pow(2,n));
}
