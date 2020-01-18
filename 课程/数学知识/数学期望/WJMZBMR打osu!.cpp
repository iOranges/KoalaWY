#include<cstdio>
char ch[300005];
double p[300005],x1[300005],x2[300005];

int main()
{
	int n;
	double ans = 0;
	scanf("%d",&n);
	register int i;
	scanf("%s",ch + 1);
	for(i = 1;i <= n;++ i)
		switch(ch[i])
		{
			case '?':p[i] = 0.5;break;
			case 'o':p[i] = 1;break;
			case 'x':p[i] = 0;break;
		}
	for(i = 1;i <= n;++ i)
	{
		x1[i] = (x1[i - 1] + 1) * p[i];
		x2[i] = (x2[i - 1] + 2 * x1[i - 1] + 1) * p[i];
		ans += x2[i - 1] * (1 - p[i]); 
	}
	ans += x2[n];
	printf("%.4lf",ans);
	return 0;
}
