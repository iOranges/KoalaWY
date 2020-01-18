#include<cstdio>
double x[100005],x2[100005],x3[100005],p[100005];

int main()
{
	int n;
	register int i;
	double ans = 0;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		scanf("%lf",&p[i]);
	for(i = 1;i <= n;++ i)
	{
		x[i] = (x[i - 1] + 1) * p[i];
		x2[i] = (x2[i - 1] + 2 * x[i - 1] + 1) * p[i];
		x3[i] = (x3[i - 1] + 3 * x2[i - 1]+ 3 * x[i - 1] + 1) * p[i];
		ans += x3[i - 1] * (1 - p[i]);
	}
	ans += x3[n];
	printf("%.1lf",ans);
	return 0;
}
