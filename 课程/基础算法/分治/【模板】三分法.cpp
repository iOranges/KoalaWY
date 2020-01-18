#include<cstdio>
int n;
double a[20],eps = 1e-7;
inline double f(double x)
{
	double sum = a[0];
	register int i;
	for(i = 1;i <= n;++ i)
		sum = sum * x + a[i];
	return sum;
}

int main()
{
	register int i;
	register double l,r,mid1,mid2,k;
	scanf("%d%lf%lf",&n,&l,&r);
	for(i = 0;i <= n;++ i)
		scanf("%lf",&a[i]);
	while(r - l > eps)
	{
		k = (r - l) / 3.0;
		mid1 = k + l,mid2 = r - k;
		if(f(mid1) > f(mid2)) r = mid2;
		else l = mid1;
	} 
	printf("%.5lf",l);
	return 0;
}
