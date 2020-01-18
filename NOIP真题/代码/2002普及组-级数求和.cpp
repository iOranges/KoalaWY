#include<bits/stdc++.h>
using namespace std;
int k,tot;
double s;
int main()
{
    scanf("%d",&k);
    while(s<=k)
    {
        tot++;
        s+=1.0/tot;
    }
    cout<<tot;
}
