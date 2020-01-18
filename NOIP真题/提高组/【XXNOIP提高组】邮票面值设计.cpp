#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
int n,k,num[15],ans,res[15];
bool f[15][100005];
int dp(int m)
{
	bool flag = true;
	register int i,j,l;
	f[0][0] = true;
	for(i = 1;i;++ i)
	{
		flag = true;
		for(l = 1;l <= n;++ l)
			for(j = 1;j <= m;++ j)
				if(i >= num[j]&&f[l - 1][i - num[j]]) f[l][i] = true,flag = false;
		if(flag) break;	
	}
	for(j = 1;j < i;++ j)
		for(l = 1;l <= n;++ l)
			f[l][j] = false;
	return i - 1;
}

void dfs(int cnt)
{
	int maxx = dp(cnt);
	if(cnt == k)
	{
		if(maxx > ans)
		{
			register int i;
			for(i = 1;i <= k;++ i)
				res[i] = num[i];
			ans = maxx;
		}
		return ;
	}
	for(int i = num[cnt] + 1;i <= maxx + 1;++ i)
	{
		num[cnt + 1] = i;
		dfs(cnt + 1);
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	num[1] = 1;
	dfs(1);
	for(register int i = 1;i <= k;++ i)
		printf("%d ",res[i]);
	printf("\nMAX=%d",ans);
	return 0;
}

