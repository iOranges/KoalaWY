#include<iostream>
using namespace std;
long long f[21][21],a[21][21],l;
void show(int n,int m)
{
	if(n==0) return;
	for(int k=0;k<=m;k++)
	{
		if(l==f[n-1][k]+a[n][m-k])
		{
			l-=a[n][m-k];
			show(n-1,k);
			cout << n << ' ' << m-k << endl;
			break;
		}
	}
}

int main()
{
	int n,m,i,j,k;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin >> a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			l=0;
			for(k=0;k<=j;k++)
				if(f[i-1][k]+a[i][j-k]>l)
					l=f[i-1][k]+a[i][j-k];
			f[i][j]=l;
		}	
	cout << f[n][m] << endl;
	show(n,m);
	return 0;
}
