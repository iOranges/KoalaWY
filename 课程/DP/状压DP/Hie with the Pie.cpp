#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int f[1<<11][11],d[11][11];

int main()
{
	int n,i,j,k,m,ans;
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		memset(f,0x3f,sizeof f);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				scanf("%d",&d[i][j]);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				if(i!=j)
					for(k=0;k<=n;k++)
						if(i!=k&&j!=k)
							d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		m = (1<<(n+1)) - 1;
		f[1][0] = 0;
		for(i=1;i<=m;i+=2)
			for(j=0;j<=n;j++)
				if((i>>j)&1)
					for(k=0;k<=n;k++)
						if(k!=j&&(i>>k)&1)
							f[i][j] = min(f[i][j],f[i^(1<<j)][k] + d[k][j]);
		ans = f[m][0];
		for(i=1;i<=n;i++)
			ans = min(ans,f[m][i] + d[i][0]);
		printf("%d\n",ans);
	}
	return 0;
}
