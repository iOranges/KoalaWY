#include<iostream>
using namespace std;
int a[101][101];
int main()
{
	int n,i,j,max=-99999,sum=0;
	cin >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin >> a[i][j];	
			a[i][j]+=a[i][j-1];		
		}
	for(i=0;i<=n-1;i++)
		for(j=i+1;j<=n;j++)
		{
			sum=0;
			for(int k=1;k<=n;k++)
			{
				sum+=a[k][j]-a[k][i];
				if(sum>max) max=sum;
				if(sum<0) sum=0;
			}
		}
	cout << max;
	return 0;
}
