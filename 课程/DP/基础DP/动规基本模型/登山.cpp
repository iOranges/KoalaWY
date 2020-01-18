#include<iostream>
using namespace std;
int a[1001][3];
int main()
{
	int n,i,j,k=1,l;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> a[i][0];
		a[i][1]=1,a[i][2]=1;
	}
	for(i=n-1;i>=1;i--)
	{
		l=0;
		for(j=i+1;j<=n;j++)
			if(a[j][0]<a[i][0]&&a[j][1]>l)
				l=a[j][1];	
		if(l!=0)
			a[i][1]=l+1;
	}
	for(i=2;i<=n;i++)
	{
		l=0;
		for(j=1;j<=i-1;j++)
			if(a[j][0]<a[i][0]&&a[j][2]>l)
				l=a[j][2];	
		if(l!=0)
			a[i][2]=l+1;
	}	
	for(j=2;j<=n;j++)
		if(a[j][2]+a[j][1]>a[k][2]+a[k][1]) k=j;	
	cout << a[k][1]+a[k][2]-1;
	return 0;
}
