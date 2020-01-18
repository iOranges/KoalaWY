#include<iostream>
using namespace std;
int g[1001][1001],f[1001],c[1001],n,m,t;

void find_c(int i)
{
	for(int j=1;j<=n;j++)
		if(g[i][j]==1)
		{
			g[i][j]=g[j][i]=0;
			find_c(j);
		}
	c[++t]=i;
}

int main()
{
	int i,x,y,start=1;
	cin >> n >> m;
	for(i=1;i<=m;i++)
	{
		cin >> x >> y;
		g[x][y]=g[y][x]=1;
		f[x]++;
		f[y]++;
	}
	for(i=1;i<=n;i++)
		if(f[i]%2==1)
			start=i;		
	find_c(start);
	for(i=1;i<=t;i++)
		cout << c[i] << " ";
	return 0;
}
