#include<bits/stdc++.h>
using namespace std;
int a[233];
int main()
{
//  freopen("poly.in","r",stdin);
//  freopen("poly.out","w",stdout);
    int n;cin>>n;
    for(int i=n;i>=0;i--) cin>>a[i];
    for(int i=n;i>=0;i--)
    {
        if(a[i]==0) continue;
        else if(i==n&&n!=1)
        {
            if(a[i]==1) cout<<"x^"<<n;
            else if(a[i]==-1) cout<<"-x^"<<n;
            else cout<<a[i]<<"x^"<<n;
        }
        else if(i==n&&n==1) cout<<"x";
        else if(i==1)
        {
            if(a[i]==1) cout<<"+x";
            else if(a[i]<0)
            {
                if(a[i]==-1) cout<<"-x"; 
                else cout<<a[i]<<"x";  
            }
            else cout<<"+"<<a[i]<<"x";   
        }
        else if(i==0)
        {
            if(a[i]>0) cout<<"+";
            cout<<a[i];  
        }
        else
        {
            if(a[i]==1) cout<<"+x^"<<i;
            else if(a[i]<0)
            {
                if(a[i]==-1) cout<<"-x^"<<i;   
                else cout<<a[i]<<"x^"<<i;
            }
            else cout<<"+"<<a[i]<<"x^"<<i; 
        }      
    }
}
