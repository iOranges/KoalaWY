#include<cstdio>
#include<iostream>
using namespace std;
int w[18],c[18][18];
long long f[1<<18][18];

int main()
{
	int n,m,k,i,j,q,a,b,p;
	long long ans = -1;
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);		
		f[1<<i][i] = w[i];
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		scanf("%d",&c[a-1][b-1]);
	}
	p = (1<<n) - 1;
	for(i=0;i<=p;++i)
	{
		int cnt = 0;
		for(j=0;j<n;++j)
		{
			if(!((i>>j)&1))
				continue;
			++cnt;
			for(k=0;k<n;++k)
				if(k!=j&&(i>>k)&1)
					f[i][j] = max(f[i][j],f[i^(1<<j)][k] + c[k][j] + w[j]);
		}
		if(cnt == m)
			for(j=0;j<n;j++)
				if((i>>j)&1)
					ans = max(ans,f[i][j]);
	}
	printf("%lld",ans);
	return 0;
}
