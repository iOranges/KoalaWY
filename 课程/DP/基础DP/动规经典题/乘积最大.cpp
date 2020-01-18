#include<iostream>
using namespace std;
long long f[11][6],a[11][11];
char ch[11];
int main()
{
	int i,j,n,l,k;
	cin >> n >> l >> ch;
	for(i=1;i<=n;i++)
		a[i][i]=ch[i-1]-'0';
	for(i=2;i<=n;i++)
		for(j=i-1;j>=1;j--)
			a[j][i] = a[j][i-1]*10+a[i][i];
	for(i=1;i<=n;i++)
		f[i][0]=a[1][i];
	for(k=1;k<=l;k++)
		for(i=k+1;i<=n;i++)
			for(j=k;j<i;j++)
				f[i][k] = max(f[i][k],f[j][k-1]*a[j+1][i]);
	cout << f[n][l];
	return 0;
 } 
