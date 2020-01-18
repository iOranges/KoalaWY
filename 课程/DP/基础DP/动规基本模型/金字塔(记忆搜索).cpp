#include<iostream>
using namespace std;
int n,a[1001][1001],f[1001][1001];
int dfs(int x,int y)
{
	if(!f[x][y])
	{
		if(x==n) f[x][y]=a[x][y];
		else f[x][y]=a[x][y]+max(dfs(x+1,y),dfs(x+1,y+1));
	}
	return f[x][y];
}

int main()
{
	cin >> n;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			cin >> a[i][j];
	cout << dfs(1,1);
	return 0;
 } 
