#include<iostream>
using namespace std;
int a[10001];

int main()
{
	int n,m,i,q=0,k=1,l;
	cin >> n >> m;
	for(i=1;i<n;i++)
		a[i]=i+1;
	a[n]=1,l=n;
	while(q<n)
	{
		while(k<m)
		{
			l=a[l];
			k++;
		}
		cout << a[l] << " ";
		a[l]=a[a[l]],k=1,q++;
	}
	return 0;
}

