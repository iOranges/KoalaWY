#include<cstring>
#include<iostream>
using namespace std;
int a[1001],b[1001],w[1001],f[101][101];
int main()
{
	int n,i,O2,N,v,k;
	cin >> O2 >> N >> n;
	memset(f,127,sizeof(f));
	f[0][0]=0;
	for(i=1;i<=n;i++)
		cin >> a[i] >> b[i] >> w[i];
	for(i=1;i<=n;i++)
		for(v=O2;v>=0;v--)
			for(k=N;k>=0;k--)
			{
				int x=v+a[i],y=k+b[i];
				if(x>O2) x=O2;
				if(y>N)  y=N;
				f[x][y]=min(f[x][y],f[v][k]+w[i]);
			}
	cout << f[O2][N];
	return 0;
}
