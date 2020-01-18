#include<bits/stdc++.h>
using namespace std;
long long tot,a,b,x,y,p,q,r;
int dx(int m)
{
    int n=0;while(m>0){n*=10;n+=m%10;m/=10;}
    return n;
}
void hw(int i)
{
    int t=dx(i),s=t/100,h=t%100;
    if(s<=12&&s>=1&&i%100!=0)
    {
        if(i%4==0) r=29;
        else r=28;
        if(s%2==0)
        {
            if(s>=8&&h<=31) tot++;
            else
            {
                if(s==2) {if(h<=r) tot++;}
                else {if(h<=30) tot++;}
            }
        }
        else
        {
            if(s>=9){if(h<=30) tot++;}
            else{if(h<=31) tot++;}
        }
    }
}
int main()
{
//  freopen("date.in","r",stdin);
//  freopen("date.out","w",stdout);
    scanf("%d%d",&a,&b);
    x=a/10000,y=b/10000,p=a%10000,q=b%10000;
    if(a==b)
    {
        if(dx(a)==a) cout<<1;
        else cout<<0;
        return 0;
    }
    else
    {
        for(int i=x;i<=y;i++)
        {
            int t=dx(i),s=t/100,h=t%100;
            if(i==x&&t>=p) hw(i);
            else if(i==y&&t<=q) hw(i);
            else hw(i);
        }  
    }
    cout<<tot;
}
