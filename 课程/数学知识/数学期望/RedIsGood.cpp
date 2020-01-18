#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
double f[5005][5005];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	register int i,j;
	for(i = 1;i <= n;++ i)
		f[i][0] = f[i - 1][0] + 1;
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= m;++ j)
			f[i][j] = max(0,((f[i][j - 1] - 1.0) * j + (f[i - 1][j] + 1.0) * i) / ((i + j) * 1.0));
	printf("%.10lf",f[n][m]);
	return 0;
}
