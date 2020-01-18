#include<cstdio>
#include<cstring>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
int a[205],s[205],f1[205][205],f2[205][205];

int main()
{
	int n,m;
	register int i,j,k,p;
	memset(f1,0,sizeof f1);
	memset(f2,0x7f,sizeof f2);
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
	{
		scanf("%d",&a[i]);
		a[i + n] = a[i];
	}
	m = n * 2;
	for(i = 1;i <= m;++ i)
	{
		s[i] = s[i - 1] + a[i];		
		f1[i][i] = f2[i][i] = 0;
	}
	for(p = 1;p < n;++ p)
		for(i = 1,j = p + 1;i <= m&&j <= m;++i,++ j)
			for(k = i;k < j;++ k)
			{
				f1[i][j] = max(f1[i][j],f1[i][k] + f1[k + 1][j] + s[j] - s[i - 1]);
				f2[i][j] = min(f2[i][j],f2[i][k] + f2[k + 1][j] + s[j] - s[i - 1]);
			}
	int maxx = 0,minn = 0x7f7f7f7f;
	for(i = 1;i <= n;++ i)
	{
		maxx = max(maxx,f1[i][i + n - 1]);
		minn = min(minn,f2[i][i + n - 1]);
	}
	printf("%d\n%d",minn,maxx);
	return 0;
 } 
