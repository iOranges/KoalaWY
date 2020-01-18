#include<iostream>
using namespace std;
int f[100005],dis[100005];
int cnt,n,m,k,x,y,i,j,u,v;
int find(int x)
{
	if(f[x]!=x)
	{
		int z = f[x];
		f[x] = find(z);
		dis[x] = (dis[x]+dis[z])%3;
	}
	return f[x];
}

int main()
{
	cin >> n >> k;
	for(i=1;i<=n;i++) f[i] = i,dis[i] = 0;
	for(i=1;i<=k;i++)
	{
		cin >> m >> x >> y;
		if(x>n||y>n) {cnt++;continue;}
		u = find(x),v = find(y);
		if(m==1)
		{
			if(x==y) continue;
			if(u == v)
			{
				if(dis[x]!=dis[y])
					cnt++;
			}	
			else
			{
				dis[v] = 3 - dis[y];
				f[v] = x;
			}
		}
		else
		{
			if(x==y) {cnt++;continue;}
			if(u == v)
			{
				if((3+dis[x]-dis[y])%3!=2)
					cnt++;	
			}
			else
			{
				dis[v] = (1-dis[y]+3)%3;
				f[v] = x;
			}
		}
	}
	cout << cnt;
	return 0;
}
