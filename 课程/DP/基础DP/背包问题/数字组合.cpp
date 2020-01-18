#include<iostream>
using namespace std;
int w[1001];
long long f[10001];
int main()
{
	int m,n,i,v;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		cin >> w[i];
	f[0]=1;
	for(i=1;i<=n;i++)
		for(v=m;v>=w[i];v--)
			f[v]+=f[v-w[i]];
	cout << f[m];
	return 0;
}
