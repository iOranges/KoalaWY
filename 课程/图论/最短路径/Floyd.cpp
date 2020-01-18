#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long f[101][101],z;

int main()
{
	int i,j,k,n,m,x,y;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i!=j)
				f[i][j] = 1e16;		
			else
				f[i][i] = 0;
		}
	for(i=1;i<=m;i++)
	{
		cin >> x >> y >> z;
		f[x][y] = z;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	long long S,g=1e16;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			S^=f[i][j]+g;
	printf("%lld",S);
	return 0;
}
