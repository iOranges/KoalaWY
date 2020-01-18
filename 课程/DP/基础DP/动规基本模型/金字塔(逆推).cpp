#include<iostream>
using namespace std;
int a[1001][1001],n;
int main()
{
	cin >> n;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			cin >> a[i][j];
	for(i=n;i>=1;i--)
		for(j=i;j>=1;j--)
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
	cout << a[1][1];
	return 0;
}
