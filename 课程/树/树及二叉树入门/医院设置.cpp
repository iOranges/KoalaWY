#include<iostream>
using namespace std;
int a[101],f[101][101];

int main()
{
	int n,i,j,k,r,l,tot,minn=999999;
	cin >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f[i][j]=10000;
	for(i=1;i<=n;i++)
	{
		f[i][i]=0;
		cin >> a[i] >> l >> r;
		if(l!=0) f[i][l] = f[l][i] = 1;		
		if(r!=0) f[i][r] = f[r][i] = 1;		
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		if(i!=k)
			for(j=1;j<=n;j++)
				if(j!=k&&j!=i)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(i=1;i<=n;i++)
	{
		tot=0;
		for(j=1;j<=n;j++)	
			tot += a[j]*f[i][j];
		minn=min(tot,minn);
	}
	cout << minn;
	return 0;
}
