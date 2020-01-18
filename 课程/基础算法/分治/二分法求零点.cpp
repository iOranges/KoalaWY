#include<cstdio>
double f(double x)
{
	return x*x*x*x*x-x*x*x*x*15+x*x*x*85-x*x*225+x*274-121;
}

int main()
{
	double x1,x2;
	for(double x=15;x<=24;x++)
	{
		x1=x/10;
		x2=x1+0.1;
		if(f(x1) == 0) printf("%.6lf",x1);
		else if(f(x1)*f(x2)<0)
		{
			while(x2-x1>=0.000001)
			{
				double xx = (x2+x1)/2.0;
				if((f(x1) * f(xx))<= 0)
					x2 = xx;
				else x1 = xx;
			}
			printf("%.6lf",x1);
		}
	}
}
