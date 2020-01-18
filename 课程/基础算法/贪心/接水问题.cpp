#include<iostream>
#include<limits.h>
using namespace std;
int a[10001],b[10001];
int main()
{
	int m,n,i,j,q=0;
	cin >> n >> m;
	for(i=1;i<=n;i++) cin >> a[i];
	for(i=1;i<=n;i++)
	{
		int min = INT_MAX;
		for(j=1;j<=m;j++)
			if(b[j]<min)
			{
				min=b[j];
				q=j;
			}
		b[q]+=a[i];
	}
	for(i=2;i<=m;i++)
		if(b[1]<b[i])
			swap(b[1],b[i]);
	cout << b[1];
	return 0;
}
