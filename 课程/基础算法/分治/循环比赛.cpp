#include<iostream>
#include<cmath>
using namespace std;
int a[10001][10001];
int main()
{
	int m,n,i,j;
	cin >> m;
	a[1][1] = 1;
	n = pow(2,m);
	for(int k=0;k<=m-1;k++)
	{
		int q = pow(2,k);
		for(i=1;i<=q;i++)
			for(j=1;j<=q;j++)
			{
				a[i][j+q]=a[i][j]+q;
				a[i+q][j]=a[i][j+q];
				a[i+q][j+q]=a[i][j];
			}
	} 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout << a[i][j] << " ";
		cout << endl;		
	}
	return 0;
 } 
