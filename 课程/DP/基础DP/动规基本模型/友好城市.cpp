#include<iostream>
using namespace std;
int a[5001][2],b[5001];

int main()
{
	int n,i,j,l,k;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> a[i][0] >> a[i][1];	
		b[i]=1;
	}
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(a[i][0]>a[j][0])
				swap(a[i],a[j]);
//	for(i=1;i<=n;i++)
//		cout << a[i][0] << ' ' << a[i][1] << endl;	
	for(i=n-1;i>=1;i--)
	{
		l=0;
		for(j=i+1;j<=n;j++)		
			if(a[j][1]>=a[i][1]&&b[j]>l)
				l=b[j];
		if(l)
			b[i]=l+1;
	}		
	for(i=1;i<=n;i++)
		if(b[k]<b[i]) k=i;
	cout << b[k];
	return 0;
}
