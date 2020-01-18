#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],minn,s[]={1,10,100,1000,10000,100000,1000000,10000000};
struct node{
    int num,len;
}p[1005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d%d",&p[i].len,&p[i].num);
    for(int i=1;i<=m;i++)
    {
        minn=10000005;
        for(int j=1;j<=n;j++)
        {
            int x=p[i].num,y=p[i].len;
            if(a[j]>=x&&((a[j])%s[y])==x)
                if(a[j]<minn) minn=a[j];
        }
        if(minn==10000005) cout<<-1<<endl;
        else cout<<minn<<endl;
    }
}
