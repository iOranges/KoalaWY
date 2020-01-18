#include<iostream>
using namespace std;
int w[31],c[31],s[31],f[201];
int main()
{
	int n,m,i,v,j;
	cin >> m >> n;
	for(i=1;i<=n;i++)
		cin >> w[i] >> c[i] >> s[i];
	for(i=1;i<=n;i++)
	{
		if(s[i]==0)
			for(v=w[i];v<=m;v++)
				f[v]=max(f[v],f[v-w[i]]+c[i]);
		else
			for(j=1;j<=s[i];j++)
				for(v=m;v>=w[i];v--)
					f[v]=max(f[v],f[v-w[i]]+c[i]);
	}
	cout << f[m];
 	return 0;
}
