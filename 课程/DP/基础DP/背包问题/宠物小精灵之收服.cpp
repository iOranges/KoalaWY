#include<iostream>
using namespace std;
int  w[101],h[101],f[1001][1001],o[1001][1001];
int main()
{
	int n,k,m,i,v,j,q=0; 
	cin >> k >> m >> n;
	for(i=1;i<=n;i++)
		cin >> w[i] >> h[i];
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(h[i]>h[j])
				swap(h[i],h[j]),swap(w[i],w[j]);
	for(i=1;i<=n;i++)
		for(v=k;v>=0;v--)
			for(j=m;j>=0;j--)
			{
				int x=v-w[i],y=j-h[i];
				if(x>0&&y>0&&f[v][j]<f[x][y]+1)
				{
					f[v][j]=f[x][y]+1;
					o[v][j]=o[x][y]+h[i];
				}
			}  
	cout << f[k][m] << " " << m-o[k][m]; 
	return 0;
}
