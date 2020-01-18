#include<cmath>
#include<cstdio>

int main()
{
	int n,cnt = 0;
	register int i;
	double h,s,l,k,v,dh,dh2,t,t2;
	scanf("%lf%lf%lf%lf%lf%d",&h,&s,&v,&l,&k,&n);
	for(i = 0;i < n;++ i)
	{
		t = (s - i - 0.00001) / v;
		if(t < 0) continue;
		dh = t * t * 5.0;
		if(h - dh >= 0.00001&&h - dh <= k + 0.00001)
			++ cnt;
		else
		{
			t = (s - i + 0.00001) / v;
			t2 = sqrt((h - k - 0.00001) / 5.0) - t;
			if(t2 < 0) continue;
		//	printf("%d %.5lf %.5lf %.5lf\n",i,h - dh,t,t2);
			if(t2 * v <= l + 0.00002)
				++ cnt;
		}
	}
	printf("%d",cnt);
	return 0;
}
