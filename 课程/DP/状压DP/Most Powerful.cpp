#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int f[1<<10],d[11][11];

int main()
{
	int n,i,j,k,m,ans;
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		memset(f,0,sizeof f);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&d[i][j]);
		m = (1<<n) - 1;
		for(i=0;i<=m;i++)
			for(j=0;j<n;j++)
				if(!(i&(1<<j)))
					for(k=0;k<n;k++)
						if(k!=j&&!(i&(1<<k)))
							f[i|(1<<j)] = max(f[i|(1<<j)],f[i] + d[k][j]);
		ans = 0;
		for(i=((1<<(n-1))-1);i<=m;i++)
			ans = max(ans,f[i]);
		printf("%d\n",ans);
	}
	return 0;
}
