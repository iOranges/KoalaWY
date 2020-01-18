#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int main()
{
    scanf("%d",&n);
    if(n==0) cout<<0;
    else
    {
        if(n<0){cout<<'-';n=-n;}
        while(n)
        {
            x=n%10;
            y=y*10+x;
            n/=10;
        }
        cout<<y;
    }  
}
