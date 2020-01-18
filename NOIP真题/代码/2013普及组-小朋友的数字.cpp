#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=999999999999;
ll n,p,num[1000002],score[1000002],tz[1000002];
int main()
{
	scanf("%lld%lld",&n,&p);
	ll ans,maxx=-inf; 
	ll d=0;
	for(register int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		if(d<=0)d=num[i];
		else d+=num[i];
		maxx=max(maxx,d);
		tz[i]=maxx%p;
	}
	ans=score[1]=tz[1];
	maxx=-inf;
	for(register int i=2;i<=n;i++)
	{
		maxx=max(maxx,score[i-1]+tz[i-1]);
		score[i]=maxx;
		if(maxx>ans) ans=maxx%p;
	}
	printf("%lld",ans);
}
