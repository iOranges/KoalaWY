#include<cstdio>
int f[20001];

int find(int x)
{
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}

int main()
{
	int n,m,i,j,q,x,y,u,v;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) f[i] = i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		u = find(x),v = find(y);
		f[v] = u;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		if(find(x)==find(y))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
