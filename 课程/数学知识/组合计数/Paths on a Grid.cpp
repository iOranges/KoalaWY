#include<cstdio>
#define min(x,y) ((x) < (y) ? (x) : (y))
long long unsigned k,n,m,ans,j,i;
int main()
{
	while(~scanf("%llu%llu",&n,&m))
	{
		if(!n && !m) break;
		k = 1llu * m + 1llu * n;
		j = min(n,m),ans = 1;
		for(i = 1;i <= j;++ i)
			ans = ans * (k - i + 1) / i;
		printf("%llu\n",ans);
	}
	return 0;
}
