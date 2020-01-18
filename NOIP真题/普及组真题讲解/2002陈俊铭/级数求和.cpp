#include<bits/stdc++.h>
using namespace std;
int n=1,m;
double sum;
int main()
{
    scanf("%d",&m);
    while(1){
        sum+=1.0/n;
        if(sum>=m)break;
        n++;
    }
    printf("%d",n);return 0;
}
