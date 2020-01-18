#include<cstdio>
#include<cstring>
int b[1<<22],a[1000005];

int main()
{
	int n,i,inf,j;
	scanf("%d",&n);
	inf = (1<<22) - 1;
	memset(b,0xcf,sizeof b); 
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[inf ^ a[i]] = a[i];
	}
	for(i=inf;i>=0;i--)
	{
		if(b[i]<0) continue;
		else 
			for(j=0;j<22;j++)
				if((i>>j)&1)
					b[i^(1<<j)] = b[i];
	}
	for(i=1;i<=n;i++)
	{
		if(b[a[i]]>=0)
			printf("%d ",b[a[i]]);
		else
			printf("-1 ");
	}
	return 0;
}
