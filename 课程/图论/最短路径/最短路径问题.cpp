#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
double f[101][101];
int c[101][2];

int main()
{
	int i,j,k,n,m,x,y;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> x >> y;
		c[i][0]=x,c[i][1]=y;
	}
	cin >> m;
	memset(f,0x7f,sizeof(f));
	for(i=1;i<=m;i++)
	{
		cin >> x >> y;
		f[x][y] = f[y][x] = sqrt(pow(c[x][0]-c[y][0],2)+pow(c[x][1]-c[y][1],2));
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j&&j!=k&&k!=i)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	cin >> x >> y;
	printf("%.2lf",f[x][y]);
	return 0;
}
