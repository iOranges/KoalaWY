#include<cstdio>
double p[100005],x1[100005],x2[100005];

int main()
{
	int n;
	double ans = 0;
	scanf("%d",&n);
	register int i;
	for(i = 1;i <= n;++ i)
		scanf("%lf",&p[i]);
	for(i = 1;i <= n;++ i)
	{
		x1[i] = (x1[i - 1] + 1) * p[i];
		x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * p[i];
		ans += x2[i - 1] * (1 - p[i]); 
	}
	ans += x2[n];
	printf("%.8lf",ans);
	return 0;
}
