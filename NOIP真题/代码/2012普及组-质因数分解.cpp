#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;cin>>n;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0) printf("%d",(n/i));
}
