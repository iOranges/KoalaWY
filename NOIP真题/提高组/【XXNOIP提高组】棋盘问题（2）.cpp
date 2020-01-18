#include<cstdio>
bool use[105],f[105];
int n,n2,s[105],ans[105],prime[105],tot,minn = 0x7f7f7f7f;
void work()
{
	register int i,j;
	int m = n2 * 2;
	for(i = 2;i <= m;++ i)
	{
		if(!f[i]) prime[++ tot] = i;
		for(j = 1;j <= tot&&prime[j] * i <= m;++ j)
		{
			f[prime[j] * i] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

void dfs(int k,int res)
{
	if(k > n2)
	{
		register int i;
		if(res < minn) 
		{
			minn = res;
			for(i = 1;i <= n2;++ i)
				ans[i] = s[i];
		}
		return;
	}
	if(res > minn) return;
	for(int i = 2;i <= n2;++ i)
		if(!use[i])
		{
			if(k % n != 1&&f[i + s[k - 1]])  continue;
			if(k > n&&f[i + s[k - n]]) continue;
			use[i] = true;
			s[k] = i;
			dfs(k + 1,(k <= n||k % n == 1) ? res + i : res);
			use[i] = false;
		}
}

int main()
{
	scanf("%d",&n);
	n2 =  n * n;
	f[1] = use[1] = s[1] = 1;
	work();
	dfs(2,1);
	if(minn == 0x7f7f7f7f||n == 1) 
	{
		printf("NO");
		return 0;
	}	
	register int i;
	for(i = 1;i <= n2;++ i)
	{
		printf("%d",ans[i]);
		if(i % n == 0) putchar('\n');
		else putchar(' ');
	}
	return 0;
}

