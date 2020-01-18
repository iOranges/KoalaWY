#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
int f[351][41][41][41],n1,n2,n3,n4,a[351];

int main()
{
	int n,m,x,ans = 0;
	scanf("%d%d",&n,&m);
	register int i,j,k,l,p;
	for(i = 0;i < n;++ i)
		scanf("%d",&a[i]);
	for(i = 1;i <= m;++ i)
	{
		scanf("%d",&x);
		switch(x)
		{
			case 1:++ n1;break;
			case 2:++ n2;break;
			case 3:++ n3;break;
			case 4:++ n4;break;
		}
	}
	f[0][0][0][0] = ans = a[0];
	for(i = 1;i < n;++ i)
		for(j = 0;j <= n1&&j <= i;++ j)
			for(k = 0;k <= n2&&j + k * 2 <= i;++ k)
				for(l = 0;l <= n3;++ l)
				{
					p = i - (j + k * 2 + l * 3);
					if(p < 0||p % 4) continue;
					p /= 4;
					if(p > n4) continue;
					if(j > 0) f[i][j][k][l] = max(f[i][j][k][l],f[i - 1][j - 1][k][l] + a[i]);
					if(k > 0) f[i][j][k][l] = max(f[i][j][k][l],f[i - 2][j][k - 1][l] + a[i]);
					if(l > 0) f[i][j][k][l] = max(f[i][j][k][l],f[i - 3][j][k][l - 1] + a[i]);
					if(p > 0) f[i][j][k][l] = max(f[i][j][k][l],f[i - 4][j][k][l] + a[i]);
					ans = max(ans,f[i][j][k][l]);
				}
	printf("%d",ans);
	return 0;
}
