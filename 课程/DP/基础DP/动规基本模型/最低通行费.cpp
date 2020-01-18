#include<cstring>
#include<iostream>
using namespace std;
int a[101][101];
int main()
{
	int n,j,i;
	cin >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin >> a[i][j];
	for(i=n;i>=1;i--)
		for(j=n;j>=1;j--)
		{
			if(j+1>n&&i+1>n) continue;
			else if(j+1>n) a[i][j]+=a[i+1][j];
			else if(i+1>n) a[i][j]+=a[i][j+1];
			else  
				a[i][j]+=min(a[i][j+1],a[i+1][j]);			
		}
	cout << a[1][1] << endl;
	return 0;
}
