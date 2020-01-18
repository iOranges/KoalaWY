#include<iostream>
using namespace std;
int g[2001][2001],f[2001],c[1001],n,m,t;

void find_c(int i)
{
	for(int j=1;j<=n;j++)
		if(g[i][j])
		{
			g[i][j]--,g[j][i]--;
			find_c(j);
		}
	c[++t]=i;
}

int main()
{
	int i,x,y,start=1;
	cin >> m;
	for(i=1;i<=m;i++)
	{
		cin >> x >> y;
		g[x][y]++,g[y][x]++;
		f[x]++,f[y]++;
		n = max(n,max(x,y));
	}
	for(i=1;i<=n;i++)
		if(f[i]%2==1)
		{
			start=i;			
			break;
		}		
	find_c(start);
	for(i=t;i>=1;i--)
		cout << c[i] << endl;
	return 0;
}
