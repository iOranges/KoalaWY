#include<iostream>
using namespace std;
int a[101][101],f[101],b[101];

int main()
{
	int n,i,j,l,k=1;
	cin >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) 
			cin >> a[i][j];
	for(i=1;i<n;i++)
		f[i]=100000;
	f[n]=0;
	for(i=n-1;i>=1;i--)
		for(j=i+1;j<=n;j++)
			if(a[i][j]>0&&!(f[j]==100000)&&(f[i]>a[i][j]+f[j]))
			{
				f[i]=a[i][j]+f[j];
				b[i]=j;
			}
	cout << "minlong=" << f[1] << endl;
	while(k)
	{
		cout << k << ' ';
		k=b[k];
	}
	return 0;
}
