#include<iostream>
using namespace std;
int a[201][3];
int main()
{
	int n,i,j,k,l,maxx=1;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> a[i][0];
		a[i][1]=1,a[i][2]=0;
	}
	for(i=n-1;i>=1;i--)
	{
		k=0,l=0;
		for(j=i+1;j<=n;j++)
			if(a[j][0]>=a[i][0]&&a[j][1]>l)
			{
				l=a[j][1];
				k=j;
			}	
		if(l!=0)
		{
			a[i][1]=l+1;
			a[i][2]=k;
		}
	}
	for(j=1;j<=n;j++)
		if(a[j][1]>a[maxx][1]) maxx=j;
	cout << "max=" << a[maxx][1] << endl;
	k=maxx;
	while(k!=0)
	{
		cout << a[k][0] << " ";
		k = a[k][2];
	}
	return 0;
}
