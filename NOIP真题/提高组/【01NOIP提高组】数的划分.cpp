#include<cstdio>
int cnt;
void dfs(int x,int s,int rem)
{
	if(rem == 0&&s == 0)
	{
		++ cnt;
		return;
	}
	if(s == 0)
		return;
	for(int i = x;i <= rem / s;++ i)
		dfs(i,s - 1,rem - i);
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	dfs(1,k,n);
	printf("%d",cnt);
	return 0;
}
