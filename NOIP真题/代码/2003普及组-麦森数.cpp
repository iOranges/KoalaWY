#include<bits/stdc++.h>
using namespace std;
int a[505],s[505];
int n;
void mul(int a[],int b[])
{
    int c[1100]={0};
    for(int i=1;i<=500;i++)
        for(int j=1;j<=500;j++)
        {
            c[i+j-1]+=a[j]*b[i];
            c[i+j]+=c[i+j-1]/10;
            c[i+j-1]%=10;
        }
    for(int i=1;i<=500;i++) a[i]=c[i];
}
int main()
{
    scanf("%d",&n);a[1]=1,s[1]=2;
    printf("%d\n",(int)(log10(2)*n+1));
    while(n)
    {
        if(n&1) mul(a,s);
        mul(s,s);
        n>>=1;
    }
    int p=500;a[1]--;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=50;j++) printf("%d",a[p--]);
        cout<<endl;
    }
}
