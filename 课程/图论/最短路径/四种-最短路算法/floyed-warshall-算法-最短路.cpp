//floyed-warshall-算法 
//万能 就是复杂度太高 
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[110];
double g[110][110];
int n,m,s,t;
double lenth(int x,int y,int x1,int y1)
{
	return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}
int main()
{
	cin>>n;
	memset(g,127,sizeof(g));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		g[i][i]=0;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s>>t;
		g[s][t]=g[t][s]=lenth(a[s].x,a[s].y,a[t].x,a[t].y);
	}
	cin>>s>>t;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=k)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j&&k!=j&&g[i][j]>g[i][k]+g[k][j])
					g[i][j]=g[i][k]+g[k][j];
				}
			}
			
		}
	}//
	printf("%.2lf",g[s][t]);
	return 0;
}

