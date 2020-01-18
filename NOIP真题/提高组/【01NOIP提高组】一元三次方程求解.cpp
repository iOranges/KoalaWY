#include<cstdio>
#define f(x) (x * x * x * a + x * x * b + x * c + d)

int main()
{
	double a,b,c,d;
	register double l = -100,r = 100,mid,eps = 1e-3,k = -100;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(int i = -100000;i <= 100000;++ i)
	{
		double k = i / 1000.0;
		if(f(k) <= eps&&f(k) >= -eps)
			printf("%.2lf ",k);		
	}
	return 0;
}
