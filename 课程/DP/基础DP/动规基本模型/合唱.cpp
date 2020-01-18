#include<iostream>
using namespace std;
int a[101],b[101],c[101];
int main()
{
	int n,i,j,k=1,l;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> a[i];		
		b[i]=c[i]=1;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=i-1;j++)
			if(a[i]>a[j]&&b[j]+1>b[i])
				b[i]=b[j]+1;
	for(i=n-1;i>=1;i--)
		for(j=i+1;j<=n;j++)
			if((a[j]<a[i])&&(c[j]+1>c[i]))
				c[i]=c[j]+1;
	for(i=1;i<=n;i++)
		if(b[i]+c[i]>k)
			k=b[i]+c[i];
	cout << n-k+1; 
	return 0;
}
