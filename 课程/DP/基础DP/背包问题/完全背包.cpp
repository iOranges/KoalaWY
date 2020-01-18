#include<iostream>
using namespace std;
int w[31],c[31],f[201]; 
int main()
{
	int n,m,i,v;
	cin >> m >> n;
	for(i=1;i<=n;i++)
		cin >> w[i] >> c[i];
	for(i=1;i<=n;i++)
		for(v=w[i];v<=m;v++)
			f[v]=max(f[v],f[v-w[i]]+c[i]);
	cout << "max=" << f[m];
	return 0;
}
