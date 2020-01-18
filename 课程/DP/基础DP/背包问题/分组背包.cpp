#include<iostream>
using namespace std;
int w[31],c[31],p[11][31],f[201];

int main()
{
	int v,n,t,i,j,k,q;
	cin >> v >> n >> t;
	for(i=1;i<=n;i++)
	{
		cin >> w[i] >> c[i] >> q;
		p[q][++p[q][0]]=i;
	}
	for(k=1;k<=t;k++)
		for(j=v;j>=0;j--)
			for(i=1;i<=p[k][0];i++)
				if(j>=w[p[k][i]])
				{
					int x=p[k][i];
					f[j]=max(f[j-w[x]]+c[x],f[j]);
				}
	cout << f[v];
	return 0;
}
