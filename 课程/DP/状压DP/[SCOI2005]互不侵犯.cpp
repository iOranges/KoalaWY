#include<cstdio>
int s[1 << 10],tot,num[1 << 10],n,K;
long long f[10][101][1 << 10];
void dfs(int i,int cnt,int j)
{
	if(j >= n)
	{
		s[++tot] = i;
		num[tot] = cnt;
		return;
	}
	dfs(i,cnt,j + 1);
	dfs(i + (1 << j),cnt + 1,j + 2);
}

bool fit(int i,int j)
{
	if((i&j)!=0||(i&(j<<1))!=0||(i&(j>>1))!=0||((i<<1)&j)!=0||((i>>1)&j)!=0)
		return false;
	return true;
}

int main()
{
	register int i,j,k,l;
	scanf("%d%d",&n,&K);
	dfs(0,0,0);
	for(i = 1;i <= tot;++ i)
		f[1][num[i]][i] = 1;
	for(i = 2;i <= n;++ i)
		for(j = 1;j <= tot;++ j)
			for(k = 1;k <= tot;++ k)
				if(fit(s[j],s[k]))
					for(l = K;l >= num[j];-- l)
						f[i][l][j] += f[i-1][l - num[j]][k];
	long long ans = 0;
	for(i = 1;i <= tot;++ i)
		ans += f[n][K][i];
	printf("%lld",ans);
	return 0;
 } 
