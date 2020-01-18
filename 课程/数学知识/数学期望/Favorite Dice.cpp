#include<cstdio>

int main()
{
	int t,n;
	register int i;
	scanf("%d",&t);
	while(t -- )
	{
		scanf("%d",&n);
		double ans = 0;
		for(i = 1;i <= n;++ i)
			ans += (1.0 * n) / (n - i + 1);
		printf("%.2lf\n",ans);
	}	
	return 0;
}
