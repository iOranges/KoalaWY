#include<cstdio>
int sg[10005];

int main()
{
	int t,n,cnt = 0,a;
	register int i,j;
	sg[0] = 0;
	for(i = 1;i <= 10000;++ i)
		sg[i] = ++ cnt;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		int ans = 0;
		for(i = 1;i <= n;++ i)
		{
			scanf("%d",&a);
			ans ^= sg[a];//ans ^= a;
		}
		puts(ans ? "Yes" : "No");
	}
	return 0;
 } 
