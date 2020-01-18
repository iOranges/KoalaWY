#include<cmath>
#include<cstdio>
#include<cstring>
#define N 20
#define min(x,y) ((x) < (y) ? (x) : (y))
const double eps = 1e-8;
double x[N],y[N];
int lowbit[1 << N],line[N][N],pw[N],f[1 << N];
inline double ABS(double x)
{
	return x > eps ? x : -x;
}

int main()
{
	int t,n,m;
	register int i,j,k;
	pw[0] = 1;
	for(i = 1;i <= 18;++ i)
		pw[i] = pw[i - 1] * 2;
	for(i = 0;i < pw[18];++ i)
	{
		for(j = 1;j < 18&&(i & pw[j - 1]);++ j);
		lowbit[i] = j;
	}
	scanf("%d",&t);
	while(t --)
	{
		memset(f,0x3f,sizeof f);
		memset(line,0,sizeof line);
		scanf("%d%d",&n,&m);
		for(i = 1;i <= n;++ i)
			scanf("%lf%lf",&x[i],&y[i]);
		for(i = 1;i <= n;++ i)
			for(j = 1;j <= n;++ j)
			{
				if(i == j) continue;
				double a = (x[j] * y[i] - x[i] * y[j]) / (x[i] * x[i] * x[j] - x[j] * x[j] * x[i]);
				double b = (x[i] * x[i] * y[j] - x[j] * x[j] * y[i]) / (x[j] * x[i] * x[i] - x[i] * x[j] * x[j]);
				if(a > -eps) continue;
				for(k = 1;k <= n;++ k)
					if(ABS(a * x[k] * x[k] + b * x[k] - y[k]) <= eps) line[i][j] |= pw[k - 1];
			}
		f[0] = 0;
		for(i = 0;i < pw[n];++ i)
		{
			j = lowbit[i];
			f[i|pw[j - 1]] = min(f[i|pw[j - 1]],f[i] + 1);
			for(k = 1;k <= n;++ k)
				f[i|line[j][k]] = min(f[i|line[j][k]],f[i] + 1);
		}
		printf("%d\n",f[pw[n] - 1]);
	}
	return 0;
}

