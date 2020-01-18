#include<cstdio>
#define N 50005
#define min(x,y) ((x) < (y) ? (x) : (y))
int fir[N],sec[N],s[N],num[N],anti_num[N];

int main()
{
	int n,k,ans = 0x7f7f7f7f;
	register int i;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		scanf("%d%d",&fir[i],&sec[i]);
	for(i = 1;i <= n;++ i)
	{
		bool flag = true;
		if(!(fir[fir[i]] == i||sec[fir[i]] == i)) flag = false;
		if(!(fir[sec[i]] == i||sec[sec[i]] == i)) flag = false;
		if(!flag)
		{
			printf("-1");
			return 0;
		}
	}
	for(i = 1,k = 1;i <= n;++ i)
	{
		s[i] = k;
		++ num[(k - i + n) % n];
		++ anti_num[(k + i) % n];
		k = (fir[k] == s[i - 1] ? sec[k] : fir[k]);
	}
	for(i = 0;i < n;++ i)
		ans = min(ans,min(n - num[i],n - anti_num[i]));
	printf("%d",ans);
	return 0;
}
