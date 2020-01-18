#include<cstdio>
int a[500005];

int main()
{
	int n,ans = 0;
	register int i,j;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
	{
		scanf("%d",&a[i]);
		ans ^= a[i];
	}
	if(!ans)
	{
		puts("lose");
		return 0;
	}
	for(i = 1;i <= n;++ i)
		if((a[i] ^ ans) <= a[i])
		{
			printf("%d %d\n",a[i] - (a[i] ^ ans),i);
			for(j = 1;j <= n;++ j)
				if(i != j)
					printf("%d ",a[j]);
				else printf("%d ",a[i] ^ ans);
			return 0;
		}
	return 0;
 } 
