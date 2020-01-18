#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],p[1005],q[1005],m,n,k,l,d,a1,a2,b1,b2,tot1,tot2;
int main()
{
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
    for(int i=1;i<=d;i++)
    {
        scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
        if(a1==a2&&b1!=b2) b[min(b1,b2)]++;
        if(a1!=a2&&b1==b2) a[min(a1,a2)]++;
    }
    for(int i=1;i<=k;i++)
    {
        int ss=1;
        for(int j=2;j<m;j++)
            if(a[j]>a[ss]) ss=j;
        p[++tot1]=ss;a[ss]=0;
    }
    for(int i=1;i<=l;i++)
    {
        int ss=1;
        for(int j=2;j<n;j++)
            if(b[j]>b[ss]) ss=j;
        q[++tot2]=ss;b[ss]=0;
    }
    stable_sort(p+1,p+1+tot1);
    for(int i=1;i<=tot1;i++) cout<<p[i]<<" ";
    cout<<endl;stable_sort(q+1,q+tot2+1);
    for(int i=1;i<=tot2;i++) cout<<q[i]<<" ";
}
