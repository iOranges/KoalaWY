#include<cstdio>
long long f[25];

int main()
{
	int n;
	register int i;
	f[1] = 0;
	f[2] = 1;
	for(i = 3;i <= 20;++ i)
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]); 
	while(~scanf("%d",&n))
		printf("%lld\n",f[n]);
	return 0;
}
