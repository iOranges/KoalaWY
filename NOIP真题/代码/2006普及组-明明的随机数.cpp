#include<bits/stdc++.h>
using namespace std;
int a[2333],tot,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sTable_sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]==a[j]) a[j]=0;
    for(int i=1;i<=n;i++)
        if(a[i]>0) tot++;
    cout<<tot<<endl;
    for(int i=1;i<=n;i++)
        if(a[i]>0) cout<<a[i]<<' '; 
}
