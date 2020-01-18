#include<iostream>
using namespace std;
int a[1001][2];
int main()
{
	int n,i,j,k,l,maxx=1;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> a[i][0];
		a[i][1]=a[i][0];
	}
	for(i=n-1;i>=1;i--)
	{
		k=0,l=0;
		for(j=i+1;j<=n;j++)
			if(a[j][0]>a[i][0]&&a[j][1]>l)
			{
				l=a[j][1];				
			}
		if(l!=0)
			a[i][1]=l+a[i][0];
	}
	for(j=1;j<=n;j++)
		if(a[j][1]>a[maxx][1]) maxx=j;
	cout << a[maxx][1] << endl;
	return 0;
}
