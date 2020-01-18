#include <bits/stdc++.h>
using namespace std;
int n,s[1005][1005],maxx,ans,xzy[10005],nb[10005];
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cin >> s[i][j];
			s[j][i]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			xzy[j]=s[i][j];
		}
		sort(xzy+1,xzy+n+1);
		nb[i]=xzy[n-1];
	}
	sort(nb+1,nb+n+1);
	cout << 1 << endl;
	cout << nb[n];
	return 0;
}	
