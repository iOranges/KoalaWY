#include<cstdio>
int father[20001];
int find(int x)
{
	if(father[x]!=x) father[x] = find(father[x]);
	return father[x];
}

int main()
{
	int i,j,n,m,q,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		father[i] = i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		a = find(a),b = find(b);
		father[a] = b;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		if(find(a)==find(b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
