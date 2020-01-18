#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e16;
ll n,k,a[1000005],score[1000005],tz[1000005],d,sum;
int main()
{
	scanf("%lld%lld",&n,&k);ll maxx=-inf;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(d<=0) d=a[i];
		else d+=a[i];
		maxx=max(d,maxx);
		tz[i]=maxx%k;
	}
	sum=score[1]=tz[1],maxx=-inf;     //一定要用score[1]和tz[1]一起赋值sum 
	for(int i=2;i<=n;i++)
	{
		maxx=max(maxx,score[i-1]+tz[i-1]);
		score[i]=maxx;
		sum=max(sum,maxx)%k;
	}
	printf("%lld",sum);
}
