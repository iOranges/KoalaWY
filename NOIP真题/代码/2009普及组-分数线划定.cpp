#include<bits/stdc++.h>
using namespace std;
struct xs{
    int num;
    int score;
}a[10000];
int x,y,n,m,tot;
bool cmp(xs a,xs b)
{
    if(a.score!=b.score) return a.score>b.score;
    else return a.num<b.num;
}
int main()
{
    scanf("%d%d",&n,&m);
    x=floor(1.5*m);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].num,&a[i].score);
    stable_sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        if(i==x) y=a[i].score;
    for(int i=1;i<=n;i++)
        if(a[i].score>=y) tot++;
    printf("%d %d\n",y,tot);
    for(int i=1;i<=tot;i++) printf("%d %d\n",a[i].num,a[i].score);
}
