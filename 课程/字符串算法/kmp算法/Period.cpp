#include<cstdio>
char s[1000005];
int nxt[1000005];

int main()
{
	int n;
	register int i,j,k = 0;
	while(scanf("%d",&n))
	{
		if(!n) break;
		++ k;
		scanf("%s",s+1);
		printf("Test case #%d\n",k);
		nxt[1] = 0;
		for(i = 2,j = 0;i <= n;++ i)
		{
			while(j > 0&&s[i] != s[j+1]) j = nxt[j];
			if(s[i] == s[j+1]) ++j;
			nxt[i] = j;
		}
		for(i = 2;i <= n;++ i)
		{
			int t = i - nxt[i];
			if(i % t == 0&&nxt[i])
				printf("%d %d\n",i,i/t);
		}
		printf("\n");
	}
	return 0;
}
