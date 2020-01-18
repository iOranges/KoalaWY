#include<iostream>
using namespace std;
int w[3501],v[3501],f[13000];

int main()
{
	int n,m,i,j;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		cin >> w[i] >> v[i];
	for(i=1;i<=n;i++)
		for(j=m;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
	cout << f[m];
	return 0;
}
