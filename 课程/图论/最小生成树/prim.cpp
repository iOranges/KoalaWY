#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,w[5001][5001],dis[5001];
bool visit[5001];

int main()
{
	int i,j,a,b,c;
	long long sum = 0;
	scanf("%d%d",&n,&m);
	memset(w,0x7f,sizeof w);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		w[a][b] = w[b][a] = min(c,w[a][b]);
	}
	for(i=2;i<=n;i++)
		dis[i] = w[1][i];
	visit[1] = true; 
	for(i=2;i<=n;i++)
	{
		int minn = 0x7f7f7f7f,mini = 0;
		for(j=2;j<=n;j++)
			if(!visit[j]&&dis[j]<minn)
			{
				minn = dis[j];
				mini  = j;
			}
		if(mini == 0)
		{
			printf("orz");
			return 0;
		}
		sum += minn*1ll;
		visit[mini] = true;
		for(j=1;j<=n;j++)
			dis[j] = min(dis[j],w[mini][j]);
	}
	printf("%lld",sum);
	return 0;
}
