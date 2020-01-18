#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))
const int inf = 0x7f7f7f7f;
bool pipe[10005];
int f[2][2005],up[10005],down[10005],l[10005],h[10005];

int main()
{
	int n,m,p,t,cnt = 0,a,b;
	register int i,j,k = 0;
	scanf("%d%d%d",&n,&m,&p);
	for(i = 0;i < n;++ i)
		scanf("%d%d",&up[i],&down[i]);
	for(i = 0;i <= n;++ i)
		l[i] = 1,h[i] = m;
	for(i = 1;i <= p;++ i)
	{
		scanf("%d%d%d",&t,&a,&b);
		l[t] = a + 1,h[t] = b - 1,pipe[t] = true;		
	}
	for(i = 1;i <= n;++ i)
	{
		memset(f[k],0x7f,sizeof f[k]);
		bool flag = false;
		for(j = 1 + up[i - 1];j <= m + up[i - 1];++ j)
			f[k][j] = min(f[k][j],min(f[k ^ 1][j - up[i - 1]],f[k][j - up[i - 1]]) + 1);
		for(j = m + 1;j <= m + up[i - 1];++ j)
			f[k][m] = min(f[k][j],f[k][m]);
		for(j = 1;j <= m - down[i - 1];++ j)
			f[k][j] = min(f[k][j],f[k ^ 1][j + down[i - 1]]);
		for(j = 1;j < l[i];++ j)
			f[k][j] = inf;
		for(j = h[i] + 1;j <= m + up[i - 1];++ j)
			f[k][j] = inf;
		for(j = l[i];j <= h[i];++ j)
			if(f[k][j] != inf) flag = true;
		if(!flag) break;
		else if(pipe[i]) ++ cnt;
		k ^= 1;
	}
	if(i == n + 1)
	{
		printf("1\n");
		int ans = inf;
		for(i = l[n];i <= h[n];++ i)
			ans = min(ans,f[k ^ 1][i]);
		printf("%d",ans);
	}
	else printf("0\n%d",cnt);
	return 0;
}

