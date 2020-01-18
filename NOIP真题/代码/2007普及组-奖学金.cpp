#include<bits/stdc++.h>
using namespace std;
struct st{int num,math,Chinese,English,total;}a[400];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].Chinese,&a[i].math,&a[i].English);
        a[i].num=i;a[i].total=a[i].Chinese+a[i].math+a[i].English;
    }
    for(int i=1;i<n;i++)
        for(int j=1;j<=n-i;j++)
        {
            if(a[j].total<a[j+1].total) swap(a[j],a[j+1]);
            else if(a[j].total==a[j+1].total)
            {
                if(a[j].Chinese<a[j+1].Chinese) swap(a[j],a[j+1]);
                else if(a[j].Chinese==a[j+1].Chinese) {if(a[j].num>a[j+1].num) swap(a[j],a[j+1]);}
            }
        }
    for(int i=1;i<=5;i++) printf("%d %d\n",a[i].num,a[i].total);
}
