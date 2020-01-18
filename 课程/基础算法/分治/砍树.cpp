#include<cstdio>
#define max(x,y) ((x)>(y)?(x):(y))
int h[1000005],n,m;
bool check(int k)
{
	long long ans = 0;
	for(int i=1;i<=n;i++)
		if(h[i] > k)
			ans += 1ll * h[i] - k;
	if(ans >= 1ll*m)
		return true;
	return false;
}

int main()
{
	int i,l,r = 0,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);	
		r = max(h[i],r);
	}
	r -= 1,l = 0;
	while(l<=r)
	{
		mid = (l+r) >> 1;
		if(check(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	printf("%d",r);
	return 0;
}
