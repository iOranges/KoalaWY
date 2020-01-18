#include<iostream>
using namespace std;
int n,a[1001][1001][3];
int main()
{
	cin >> n;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			cin >> a[i][j][0];
			a[i][j][1]=a[i][j][0];
		}
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)
			a[i][j][1]=a[i][j][1]+max(a[i-1][j][1],a[i-1][j-1][1]);
	for(i=1;i<=n;i++)	
		a[n][1][1]=max(a[n][1][1],a[n][i][1]);
	cout << a[n][1][1];
	return 0;
}
