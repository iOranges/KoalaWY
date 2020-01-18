#include<iostream>
using namespace std;
bool a[201][201];
int w[201],f[201],c[201];
int main()
{
	int n,i,j,x,y,l,k;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> w[i];
	while(true)
	{
		cin >> x >> y;
		if(x==0&&y==0) break;
		a[x][y]=true;
	}
	f[n]=w[n];
	for(i=n-1;i>=1;i--)
	{
		l=0,k=0;
		for(j=i+1;j<=n;j++)
			if(a[i][j]&&f[j]>l)
			{
				l=f[j];
				k=j;
			}
		f[i]=w[i]+l;
		c[i]=k;
	}
	k=1;
	for(i=2;i<=n;i++)
		if(f[i]>f[k]) k=i;
	cout << k;
	l=c[k];
	while(l)
	{
		cout << '-' << l;
		l=c[l];
	}
	cout << endl << f[k] << endl;
	return 0;
 } 
