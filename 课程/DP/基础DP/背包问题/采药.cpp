#include<iostream>
using namespace std;
int t[101],v[101],f[1001];

int main()
{
	int n,m,i,j;
	cin >> m >> n;
	for(i=1;i<=n;i++)
		cin >> t[i] >> v[i];
	for(i=1;i<=n;i++)
		for(j=m;j>=t[i];j--)
			f[j]=max(f[j],f[j-t[i]]+v[i]);
	cout << f[m];
	return 0;
}
