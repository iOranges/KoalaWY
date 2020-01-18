#include<cstdio>

int main()
{
	int n,m;
	register int i; 
	while(~scanf("%d%d",&n,&m))
	{
		if(n == 0&&m == 0) break;
		double ans = 1.0;
		for(i = 1;i <= m;++ i)
			ans = ans * (double)(n - i + 1) / (double)i;
		printf("%d things taken %d at a time is %.0f exactly.\n",n,m,ans);
	}
	return 0;
}
