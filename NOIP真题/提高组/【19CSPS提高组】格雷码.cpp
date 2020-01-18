#include<cstdio>
#define unll unsigned long long
unll pw[65];
void dfs(int n,unll x)
{
	if(!n) return;
	if(x < pw[n - 1])
	{
		putchar('0');
		dfs(n - 1,x);
	}
	else
	{
		putchar('1');
		dfs(n - 1,pw[n - 1] - (x - pw[n - 1]) - 1);
	}
}

int main()
{
	int n;
	unll k;
	scanf("%d%llu",&n,&k);
	register int i;
	pw[0] = 1;
	for(i = 1;i < n;++ i)
		pw[i] = pw[i - 1] * 2;
	dfs(n,k);
	return 0;
}
