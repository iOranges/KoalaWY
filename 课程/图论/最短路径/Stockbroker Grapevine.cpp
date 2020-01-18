#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int f[101][101];

int main()
{
	int n,i,j,m,x,sum,ans,k,pos;
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		memset(f,0x3f,sizeof f);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&x);
				scanf("%d",&f[i][x]);
			}
		}
		for(k=1;k<=n;++k)
			for(i=1;i<=n;++i)
				for(j=1;j<=n;++j)
					if(i!=j&&j!=k&&i!=k)
						f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
		ans = 0x3f3f3f3f;
		for(i=1;i<=n;i++)
		{
			sum = 0;
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				sum = max(sum,f[i][j]);	
			}
			if(sum!=0x3f3f3f3f&&ans>sum)
			{
				ans = sum;
				pos = i;
			 }
		}
		if(ans!=0x3f3f3f3f)
			printf("%d %d\n",pos,ans);
		else
			printf("disjoint\n");
	}
	return 0;
}
