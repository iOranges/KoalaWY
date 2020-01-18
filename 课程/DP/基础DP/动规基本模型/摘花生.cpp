#include<cstring>
#include<iostream>
using namespace std;
int a[101][101];
int main()
{
	int n,j,i,t,m;
	cin >> t;
	while(t)
	{
		memset(a,0,sizeof(a));
		--t;
		cin >> n >> m;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin >> a[i][j];
		for(i=n;i>=1;i--)
			for(j=m;j>=1;j--)
				a[i][j]+=max(a[i][j+1],a[i+1][j]);
		cout << a[1][1] << endl;
	}
	return 0;
}
