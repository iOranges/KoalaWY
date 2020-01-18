#include<cstdio>
#include<iostream>
using std::swap;
const double eps = 1e-7;
double mp[105][105];

inline double abs(double x)
{
	return x > 0 ? x : -x; 
}

int main()
{
	int n;
	register int i,j,k;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= n + 1;++ j)
			scanf("%lf",&mp[i][j]);
	for(i = 1;i <= n;++ i)
	{
		int r = i;
		for(j = i + 1;j <= n;++ j)
			if(abs(mp[r][i]) < abs(mp[j][i]))
				r = j;
		if(abs(mp[r][i]) < eps)
		{
			printf("No Solution");
			return 0;
		}
		if(r != i) swap(mp[r],mp[i]);
		double div = mp[i][i];
		for(j = i;j <= n + 1;++ j)
			mp[i][j] /= div;
		for(j = i + 1;j <= n;++ j) 
		{
			div = mp[j][i];
			for(k = i;k <= n + 1;++ k)
				mp[j][k] -= mp[i][k] * div; 
		}
	}
	for(i = n - 1;i >= 1;-- i)
		for(j = i + 1;j <= n;++ j)
			mp[i][n + 1] -= mp[i][j] * mp[j][n + 1];
	for(i = 1;i <= n;++ i)
		printf("%.2lf\n",mp[i][n + 1]);
	return 0;
}
