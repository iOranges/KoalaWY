#include<bits/stdc++.h>
using namespace std;
long long f[500005],a[500005][2],n,d,k,ans=-1;
bool check(int g)
{
	int minn=d-g,maxx=d+g;
	if(minn<=0) minn=1;
	memset(f,-127,sizeof(f));f[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[i][0]-a[j][0]<minn) continue;
			if(a[i][0]-a[j][0]>maxx) break;
			f[i]=max(f[i],f[j]+a[i][1]);
			if(f[i]>=k) return true;
		}
	}
	return false;
}
int main()
{
	scanf("%lld%lld%lld",&n,&d,&k);
	for(int i=1; i<=n; i++)
		scanf("%lld%lld",&a[i][0],&a[i][1]);
	int l=0, r=100005,mid=(l+r)/2;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%lld",ans);
}
