#include<iostream>
using namespace std;
int s[11],w[501],c[501],f[6001];
int main()
{
	int n,m,i,v,j;
	cin >> n >> m;
	for(i=1;i<=n;i++) 
		cin >> w[i] >> c[i] >> s[i];
	for(i=1;i<=n;i++)		
		for(v=m;v>=0;v--)
			for(j=1;j<=s[i];j++)
			{
				if(v-j*w[i]<0) break;
				f[v] = max(f[v],f[v-j*w[i]]+j*c[i]);
			}
	cout << f[m];
	return 0;
}
