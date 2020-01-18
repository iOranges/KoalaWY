#include<cstring>
#include<iostream>
using namespace std;
int f[1001][1001],s[1001];
int main()
{
	int n,i,j,m,k;
	memset(f,127/3,sizeof(f));
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> m;
		s[i]=s[i-1]+m; 
	}
	for(i=1;i<=n;i++)
		f[i][i] = 0;
	for(i=n-1;i>=1;--i)
		for(j=i+1;j<=n;j++)
			for(k=i;k<=j-1;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
	cout << f[1][n];
	return 0;
 } 
