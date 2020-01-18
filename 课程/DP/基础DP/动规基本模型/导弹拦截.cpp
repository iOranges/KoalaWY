#include<iostream>
using namespace std;
int a[1001][2];
int main()
{
	int n,i,j,l,k=1;
	cin >> n; 
	for(i=1;i<=n;i++)
	{
		cin >> a[i][0];
		a[i][1]=1;
	}
	for(i=n-1;i>=1;i--)
	{
		l=0;
		for(j=i+1;j<=n;j++)
			if(a[j][0]<=a[i][0]&&a[j][1]>l)
				l=a[j][1];
		if(l!=0)
			a[i][1]=l+1;
	}
	for(i=1;i<=n;i++)
		if(a[i][1]>a[k][1]) k=i;
	cout << a[k][1] << endl;
	return 0;
}
