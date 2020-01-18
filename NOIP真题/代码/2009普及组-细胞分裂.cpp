#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,s[100005],zs[100005],k,t=2,ans=999999;
int main()
{
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    if(m1==1) {cout<<0<<endl;return 0;}
    while(m1!=1)
    {
        while(!(m1%t)) m1/=t,zs[t]++;
        k=max(k,t);
        zs[t++]*=m2;
	}
    for(int i=1;i<=n;i++)
    {
        int maxx=0;
        for(int j=2;j<=k;j++)
        {
            if(!zs[j]) continue;
            int c=0;
            while(!(s[i]%j)) s[i]/=j,c++;
            if(!c){maxx=0x7fffffff;break;}
            maxx=max(maxx,(zs[j]-1)/c);
        }
        ans=min(ans,maxx);
    }
    if(ans==999999) printf("-1");
    else printf("%d",ans+1);
}
