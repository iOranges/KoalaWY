#include<cstdio>
int mp[25][25],pre[25],w[25],f[25];

int main()
{
	int n,k = 0,t;
	scanf("%d",&n);
	register int i,j;
	for(i = 1;i <= n;++ i)
		scanf("%d",&w[i]);
	for(i = 1;i < n;++ i)
		for(j = i + 1;j <= n;++ j)
			scanf("%d",&mp[i][j]);
	for(i = n;i > 0;-- i)
	{
		for(j = i + 1;j <= n;++ j)
			if(mp[i][j]&&f[j] > f[i])
				f[i] = f[j],pre[i] = j;
		f[i] += w[i];
	}
	for(i = 1;i <= n;++ i)
		if(f[i] > f[k]) k = i;
	t = k;
	while(t)
	{
		printf("%d ",t);
		t = pre[t];
	}
	printf("\n%d",f[k]);
	return 0;
}
