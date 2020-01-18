#include<cstdio>
int f[25],d[25],s[25]; 

int main()
{
	int a,n,m,x,sf = 0,sd = 0,k;
	register int i;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	f[1] = s[1] = s[2] = a,d[2] = 1,s[n] = 0;
	for(i = 3;i <= n - 1;++ i)
	{
		f[i] = f[i - 1] + f[i - 2];
		d[i] = d[i - 1] + d[i - 2];
	}
	for(i = 1;i <= n - 3;++ i)
		sf += f[i],sd += d[i];	
	k = (m - a - sf) / sd;
	for(i = 1;i <= n - 1;++ i)
		f[i] = f[i] + d[i] * k;
	for(i = 3;i < n;++ i)
		s[i] = s[i - 1] + f[i - 2];
	printf("%d",s[x]);
	return 0;
}
