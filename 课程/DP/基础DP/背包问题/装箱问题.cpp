#include<iostream>
using namespace std;
int w[31],c[31],f[20001];
int main()
{
	int m,n,i,v,x;
	cin >> m >> n;
	for(i=1;i<=n;i++)
	{
		cin >> x;
		w[i] = c[i] = x;
	}
	for(i=1;i<=n;i++)
		for(v=m;v>=w[i];v--)
			f[v]=max(f[v-w[i]]+c[i],f[v]);
	cout << m-f[m];
	return 0;
}
