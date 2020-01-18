#include<cstdio>
int a[8],n,sum;

int main()
{
	register int i; 
	for(i = 1;i <= 7;++ i)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	double ans = 1;
	for(i = 1;i <= 7;++ i)
		ans *= i * a[i];
	for(i = 0;i < 6;++ i)
		ans /= 1.0 * (sum - i);
	printf("%.3lf",ans);
	return 0;
}
