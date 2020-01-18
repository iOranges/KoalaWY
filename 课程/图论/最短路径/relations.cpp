#include<cstdio>
using namespace std;
int f[1000001],c[1000001];

int find(int x)
{
	if(f[x]!=x) f[x] = find(f[x]);
	return f[x];
}

int main()
{
	char ch;
	int n,m,i,j,a,b,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) c[i] = 1,f[i] = i;
	for(i=1;i<=m;i++)
	{
		scanf(" %c",&ch);
		if(ch == 'M')
		{
			scanf("%d%d",&a,&b);
			x = find(a),y = find(b);
			if(x!=y)
				f[y] = x,c[x] += c[y];			
		}
		else if(ch == 'Q')
		{
			scanf("%d",&a);
			printf("%d\n",c[find(a)]);
		}
	}
	return 0;
}
