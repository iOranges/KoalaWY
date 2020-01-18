#include<cstdio>
double a,b,c,d;
double f(double x)
{
	return x*x*x*a+x*x*b+x*c+d;
}

int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	double x1,x2;
	for(double x=-10000;x<=10000;x++)
	{
		x1 = (x-0.05)/100,x2 = (x+0.05)/100;
		if(f(x1)*f(x2)<0||f(x1)==0)
			printf("%.2lf ",x/100.0);
	} 
	return 0;
}
