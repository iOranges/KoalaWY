#include<iostream>
using namespace std;
int w[31],c[31],f[201];
int main()
{
	int m,n,i,v;
	cin >> m >> n;
	for(i=1;i<=n;i++)
		cin >> w[i] >> c[i];
	for(i=1;i<=n;i++)
		for(v=m;v>=w[i];v--)
			f[v]=max(f[v-w[i]]+c[i],f[v]);
	cout << f[m];
	return 0;
}
