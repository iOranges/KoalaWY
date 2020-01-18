#include<bits/stdc++.h>
using namespace std;
int a[8],m[8],n[8];
int main()
{
    for(int i=1;i<=7;i++){scanf("%d%d",&m[i],&n[i]);a[i]=m[i]+n[i];}
    stable_sort(a+1,a+8);
    if(a[7]>8)
        for(int i=1;i<=7;i++)
            if(a[7]==m[i]+n[i]){cout<<i;return 0;}
    else cout<<0;
}
